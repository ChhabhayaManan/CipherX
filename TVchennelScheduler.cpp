#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <queue>
using namespace std; 

// Global variables
vector<vector<bool>> memVsSeries;
vector<vector<bool>> memVsSlot;
vector<vector<bool>> memVsSeries2;
vector<vector<bool>> memVsSlot2;
vector<vector<int>> slotVsSeries;
vector<string> show;
vector<string> Name;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

// converts slot(string) to integer from 1 to 168
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

// converts integer slot(1-168) to string slot(MON 0-1, TUE 0-1, ...)
string slotToString(int num){
    string slot;
    num++;
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

// reads input from file
void input(string &filePath, int &seriesTotal, int &memTotal, vector<vector<bool>> &memVsSeries, vector<vector<bool>> &memVsSlot)
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
    memVsSeries2.resize(memTotal);
    memVsSlot2.resize(memTotal);

    for (size_t i = 0; i < memTotal; i++)
    {
        memVsSeries[i].resize(seriesTotal, false);
        memVsSlot[i].resize(168, false);
        memVsSeries2[i].resize(seriesTotal, false);
        memVsSlot2[i].resize(168, false);
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
            if (slot >= 0 && slot < 168) {memVsSlot[k][slot] = true; memVsSlot2[k][slot] = true;
            countAvailslots++;
            }
        }

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
            if (token2 == show[j]){ memVsSeries[k][j] = true;memVsSeries2[k][j] = true; countfavoriteshow++;}
            }
        }
    }  
    inputFile.close();
}

// stores the number of members who are available for slot (i) and has the favorite series (j)
void storeSlotVsSeries(int memTotal,int slotTotal, int seriesTotal){
    slotVsSeries.resize(168);

    for(int i = 0; i < 168; i++){
        slotVsSeries[i].resize(seriesTotal, 0);
    }

    for(int i = 0; i < 168; i++){
        for(int j = 0; j < seriesTotal; j++){
            for(int k = 0; k < memTotal; k++){
                if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                    slotVsSeries[i][j]++;
                }
            }
        }
    }
}

// schedules series in the slot where the maximum number of members are available
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
                    // if the current slot and series has more members than the previous slot and series
                    if(count1 < count2){
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
        if(mAX[2] == 0)
        {
            return;
        }
        pq.push(make_pair(mAX[0], mAX[1]));

       // removing the members who are scheduled for the current slot and series
        for(int l= 3; l < mAX.size(); l++){
            for(int k = 0; k < 168; k++){
                if(memVsSlot[mAX[l]][k] == true && memVsSeries[mAX[l]][mAX[1]] == true){
                    slotVsSeries[k][mAX[1]]--;
                }
            }
            memVsSeries[mAX[l]][mAX[1]] = false;
        }
  
        for(int k = 0; k < memTotal; k++){
            memVsSlot[k][mAX[0]] = false;
        }

        for(int k = 0; k < seriesTotal; k++){
            slotVsSeries[mAX[0]][k] = 0;
        }

    } while (mAX[2] != 0);
}

// displays the remaining members who will miss the show
void showRemainedMembers(int memTotal, int seriesTotal) {

    cout << "------------------------------------------------------------------------\n";
    cout << "Remaining members: \n";
    cout << "------------------------------------------------------------------------\n";

    for(int i = 0; i < memTotal; ++i) {
        for(int j = 0; j < seriesTotal; ++j) {
            if(memVsSeries[i][j] == true) {
                cout << setw(10) << left << Name[i] << " : " << show[j] << endl;
            }
        }
    }
}

void schedule(string path){
    int seriesTotal = 0;

    int memTotal = 0;
    input(path, seriesTotal, memTotal, memVsSeries, memVsSlot);
    storeSlotVsSeries(memTotal, 168, seriesTotal);
    findMax(memTotal, 168, seriesTotal);
    cout << "========================================================================\n";
    cout << "                           THE SCHEDULE\n";
    cout << "========================================================================\n";
    while(!pq.empty()){
        pair<int, int> p = pq.top();
        pq.pop();
        cout << setw(10) << left << slotToString(p.first) << " : " << show[p.second] << endl;
    }
    showRemainedMembers(memTotal, seriesTotal);
    cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
}

// displays the schedule of a person
void scheduleOfPerson(string name, string path){    
    int seriesTotal= 0;
    int memTotal= 0;
    input(path, seriesTotal, memTotal, memVsSeries, memVsSlot);
    storeSlotVsSeries(memTotal, 168, seriesTotal);
    
    int memNUM = -1;
    for(int i = 0; i < memTotal; i++){
        if(Name[i] == name){
            memNUM = i;
            break;
        }
    }
    if(memNUM == -1){
        cout << "No such person found!" << endl;
        return;
    }

    findMax(memTotal, 168, seriesTotal);    

    bool found = false;    
    pair<int, int> p;
    cout << "------------------------------------------------------------------------\n";
    cout << "Schedule of " << name << ":\n";
    while (!pq.empty()) {
        p = pq.top();
        pq.pop();
        int a = p.first;
        int b = p.second;
        int c = memNUM;

        if(memVsSlot2[c][a]){
            if(memVsSeries2[c][b]){
                cout << setw(10) << left << slotToString(p.first) << " : " << show[p.second] << endl;
                found = true;
            }
            else{
                cout << setw(10) << left << slotToString(p.first) << " : No show" << endl;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "No schedule found" << endl;
        return;
    } 
    cout << "------------------------------------------------------------------------\n";   
}


// ====== MAIN FUNCTION ====== //
int main()
{
    int a;
    do
    {
        cout << "\n\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n";
        cout << "Welcome to TV Channel Scheduler!\n";
        cout << "1. Schedule TV Shows\n";
        cout << "2. Show Schedule of a person\n";
        cout << "0. Exit\n";
        cout << "Enter your choice : ";
        cin >> a;
        if(a == 1){
            string path;
            cout << "Enter The File Path : ";
            cin >> path;
            schedule(path);
        }
        else if(a == 2){
            string filePath;
            cout << "Enter path of the file : ";
            cin >> filePath;
            cout << "Name of the person : ";
            string name;
            cin >> name;
            scheduleOfPerson(name, filePath);
        }
        else if(a == 0){
            cout << "do you really want to exit? (Y/N) : " ;
            char c;
            cin >> c;
            if(c == 'Y' || c == 'y'){
                cout << "Thank you for using our TV Channel Scheduler!" << endl;
            }
            else{
                a = 1;
            }
        }
        else{
            cout << "Invalid input!" << endl;
        }
        
    } while (a);

    return 0;
}
