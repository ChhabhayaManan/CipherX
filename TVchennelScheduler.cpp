#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std; 
#include <cstring>
#include <iomanip>
#include <algorithm>

vector<vector<bool>> memVsSeries;
vector<vector<bool>> memVsSlot;
vector<vector<int>> slotVsSeries;
vector<pair<int, int>> sortedSlotNSeries;
vector<string> show;
vector<string> Name;

int Slottoint(string s)
{
    char str[4];
    for (int i = 0; i < 3; ++i)
    {
        str[i] = s[i];
    }
    str[3] = '\0';

    int n[2];
    int index_num;
    if (s[3] == ' ')
    {
        index_num = 4;
    }
    else
    {
        index_num = 5;
    }

    n[0] = s[index_num] - '0';
    n[1] = s[index_num + 1] - '0';
    
    if (strcmp(str, "MON") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+1;
    }
    if (strcmp(str, "TUE") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+25;
    }
    if (strcmp(str, "WED") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+49;
    }
    if (strcmp(str, "THU") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+73;
    }
    if (strcmp(str, "FRI") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+97;
    }
    if (strcmp(str, "SAT") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+121;
    }
    if (strcmp(str, "SUN") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+145;
    }

    return -1; 
}

string slotToString(int num){
    string slot;
    if(num <= 0 || num > 168){
        slot = "Invalid slot number!";
    }
    else{
        if(num>=1 && num<=24){
            slot = "MON " + to_string(num-1) + "-" + to_string(num);
        }
        else if(num>=25 && num<=48){
            slot = "TUE " + to_string(num-25) + "-" + to_string(num-24);
        }
        else if(num>=49 && num<=72){
            slot = "WED " + to_string(num-49) + "-" + to_string(num-48);
        }
        else if(num>=73 && num<=96){
            slot = "THU " + to_string(num-73) + "-" + to_string(num-72);
        }
        else if(num>=97 && num<=120){
            slot = "FRI " + to_string(num-97) + "-" + to_string(num-96);
        }
        else if(num>=121 && num<=144){
            slot = "SAT " + to_string(num-121) + "-" + to_string(num-120);
        }
        else if(num>=145 && num<=168){
            slot = "SUN " + to_string(num-145) + "-" + to_string(num-144);
        }
    }
    return slot;
}

void input(string &filePath, int &seriesTotal, int &memTotal, vector<vector<bool>> &memVsSeries, vector<vector<bool>> &memVsSlot, vector<int> &countAvailableslots, vector<int> &countfavoriteshows)
{
    ifstream inputFile(filePath);

    if (!inputFile.is_open() || inputFile.fail()) {
        cerr << "Failed to open file: " << filePath << endl;
        return ;
    }

    string line;
    if (!getline(inputFile, line)) {
        cerr << "Failed to read first line from file: " << filePath << endl;
        return ;
    }

    stringstream ss(line);
    if (!(ss >> seriesTotal)) {
        cerr << "Failed to read integer input from first line: " << filePath << endl;
        return;
    }
    if (!(ss >> memTotal)) {
        cout << "Failed to read total number of names from first line: " << filePath << endl;
        return;
    }

    show.resize(seriesTotal);
    int i = 0;

    while (getline(inputFile, line) && i < seriesTotal) {
        stringstream ss(line);
        string token;
        while (getline(ss, token, ','))
        {
            token.erase(0, token.find_first_not_of(' '));
            token.erase(token.find_last_not_of(' ') + 1);
            show[i] = token;
            i++;
        }
    }
    
    Name.resize(memTotal);
    memVsSeries.resize(memTotal);
    memVsSlot.resize(memTotal);
    countAvailableslots.resize(memTotal);
    countfavoriteshows.resize(memTotal);


    for (size_t i = 0; i < memTotal; i++)
    {
        memVsSeries[i].resize(seriesTotal, false);
        memVsSlot[i].resize(168, false);
    }
    for(int k = 0 ; k< memTotal; k++){
        getline(inputFile, line);
        Name[k] = line;

        getline(inputFile, line);

        stringstream sl(line);
        string token;
        int countAvailslots = 0;
        while (getline(sl, token, ',')) {
            if (token == "\n") break;
            token.erase(0, token.find_first_not_of(' '));
            token.erase(token.find_last_not_of(' ') + 1);
            int slot = Slottoint(token);
            if (slot >= 0 && slot < 168) {memVsSlot[k][slot] = true; 
            countAvailslots++;
            }
        }
        countAvailableslots[k] = countAvailslots;

        int countfavoriteshow = 0;
        getline(inputFile, line);
        stringstream sh(line);
        string token2;
        while (getline(sh, token2, ','))
        {
            if (token2 == "\n") break;
            token2.erase(0, token2.find_first_not_of(' '));
            token2.erase(token2.find_last_not_of(' ') + 1);
            for (size_t j = 0; j < seriesTotal; j++)
            {
            if (token2 == show[j]){ memVsSeries[k][j] = true; countfavoriteshow++;}
            }
        }
        countfavoriteshows[k] = countfavoriteshow;
    }  
    inputFile.close();
}

void storeSlotVsSeries(int memTotal,int slotTotal, int seriesTotal){
    slotVsSeries.resize(168);
    for(int i = 0; i < 168; i++){
        slotVsSeries[i].resize(seriesTotal+1, 0);
    }
    for(int i = 0; i < 168; i++){
        for(int j = 0; j < seriesTotal; j++){
            for(int k = 0; k < memTotal; k++){
                if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                    slotVsSeries[i][j]++;
                }
            }
            slotVsSeries[i][seriesTotal] += slotVsSeries[i][j];
        }
    }
}

void findMax(int memTotal, int slotTotal, int seriesTotal){
    vector<int> mAX(3);
    vector<int> cURR; 
    
    do {
        mAX.clear();
        mAX[2] = 0;
        mAX[1] = 0;
        mAX[0] = 0;
        for(int i = 0; i < 168; i++){
            for(int j = 0; j < seriesTotal; j++){
                if(slotVsSeries[i][j] > mAX[2]){
                    mAX.clear();
                    mAX.push_back(i);
                    mAX.push_back(j);
                    mAX.push_back(slotVsSeries[i][j]);
                    for(int k = 0; k < memTotal; k++){
                        if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                            mAX.push_back(k);
                        }
                    } 
                }
                else if(slotVsSeries[i][j] == mAX[2]){
                    if((slotVsSeries[i][seriesTotal] < slotVsSeries[mAX[0]][seriesTotal])  && (i != mAX[0])){
                        mAX.clear();
                        mAX.push_back(i);
                        mAX.push_back(j);
                        mAX.push_back(slotVsSeries[i][j]);
                        for(int k = 0; k < memTotal; k++){
                            if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                                mAX.push_back(k);
                            }
                        } 
                    }
                    else if((i == mAX[0]) || (slotVsSeries[i][seriesTotal] == slotVsSeries[mAX[0]][seriesTotal])){
                    cURR.clear();
                        for(int k = 0; k < memTotal; k++){
                            if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                                cURR.push_back(k);
                            }
                        } 
                        int count1 = 0, count2 = 0;
                        for(int k = 0; k < 168; k++){
                            for(int l = 0; l < cURR.size(); ++l){
                                if(memVsSlot[cURR[l]][k] == true && memVsSeries[cURR[l]][j] == true){
                                    count1++;
                                }
                            }
                            for(int l = 3; l < mAX.size(); ++l){
                            if(memVsSlot[mAX[l]][k] == true && memVsSeries[mAX[l]][j] == true){
                                count2++;
                            }
                            }
                        }
                        if(count1 > count2){
                            mAX.clear();
                            mAX.push_back(i);
                            mAX.push_back(j);
                            mAX.push_back(slotVsSeries[i][j]);
                            for(int k = 0; k < memTotal; k++){
                                if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                                    mAX.push_back(k);
                                }
                            } 
                        }
                    }
                }
            }
        }       
        if(mAX[2] == 0)
        {
            return;
        }
        
        sortedSlotNSeries.push_back(make_pair(mAX[0], mAX[1]));

        for(int l= 3; l < mAX.size(); l++){
            for(int k = 0; k < 168; k++){
                if(memVsSlot[mAX[l]][k] == true && memVsSeries[mAX[l]][mAX[1]] == true){
                    slotVsSeries[k][mAX[1]]--;
                    slotVsSeries[k][seriesTotal]--;
                }
            }
            memVsSeries[mAX[l]][mAX[1]] = false;
        }

        for(int k = 0; k < memTotal; k++){
            memVsSlot[k][mAX[0]] = false;
        }
        for(int k = 0; k < seriesTotal+1; k++){
            slotVsSeries[mAX[0]][k] = 0;
        }
    } while (mAX[2] != 0);

}

void showRemainedMembers(int memTotal, int seriesTotal) {
    cout << "========================================================================\n";
    cout << "Remaining members: \n";
    cout << "========================================================================\n";
    for(int i = 0; i < memTotal; ++i) {
        for(int j = 0; j < seriesTotal; ++j) {
            if(memVsSeries[i][j] == true) {
                cout << setw(10) << left << Name[i] << " : " << show[j] << endl;
            }
        }
    }
    cout << "========================================================================\n";
}

int main()
{
    string path;
    cout << "Enter The File Path : ";
    cin >> path;
    int seriesTotal=0;

    vector<int> countAvailableslots;
    vector<int> countfavoriteshows;
    int memTotal= 0;
    input(path, seriesTotal, memTotal, memVsSeries, memVsSlot, countAvailableslots, countfavoriteshows);
    storeSlotVsSeries(memTotal, 168, seriesTotal);
    findMax(memTotal, 168, seriesTotal);
    showRemainedMembers(memTotal, seriesTotal);
    cout << "The schedule is as follows: \n";
    cout << "========================================================================\n";
    sort(sortedSlotNSeries.begin(), sortedSlotNSeries.end());
    for(int i = 0; i < sortedSlotNSeries.size(); i++){
        cout << setw(10) << left << slotToString(sortedSlotNSeries[i].first) << " ---> " << show[sortedSlotNSeries[i].second] << endl;
    }
    cout << "========================================================================\n";
    return 0;
}
