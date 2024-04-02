#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <string.h>
using namespace std;

int Slot(string s)
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
    
    // MONDAY---> SLOT FROM 1 TO 24
    if (strcmp(str, "MON") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+1;
    }
    // TUESDAY---> SLOT FROM 25 TO 48
    if (strcmp(str, "TUE") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+25;
    }
    // WEDNESDAY---> SLOT FROM 49 TO 72
    if (strcmp(str, "WED") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+49;
    }
    // THURSDAY---> SLOT FROM 73 TO 98
    if (strcmp(str, "THU") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+73;
    }
    // FRIDAY---> SLOT FROM 99 TO 120
    if (strcmp(str, "FRI") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+97;
    }
    // SATURDAY---> SLOT FROM 121 T0 144
    if (strcmp(str, "SAT") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+121;
    }
    // SUNDAY---> SLOT FROM 145 T0 168
    if (strcmp(str, "SUN") == 0)
    {
        int x = (n[0] * 10 + n[1]);
        return x+145;
    }

    return -1; 
}


void input(string &filePath, int &size, int &totalNames, bool **&Nametoshow, bool **&Nametoslot, int *&countAvailableslots, int *&countfavoriteshows)
{
    ifstream inputFile(filePath);

    if (!inputFile.is_open() || inputFile.fail())
    {
        cerr << "Failed to open file: " << filePath << endl;
        return nullptr;
    }

    string line;
    if (!getline(inputFile, line))
    {
        cerr << "Failed to read first line from file: " << filePath << endl;
        return nullptr;
    }

    stringstream ss(line);
    if (!(ss >> size))
    {
        cerr << "Failed to read integer input from first line: " << filePath << endl;
        return nullptr;
    }
    if (!(ss >> totalNames))
    {
        cout << "Failed to read total number of names from first line: " << filePath << endl;
        return;
    }
    string *show = new string[size];
    int i = 0;

    while (getline(inputFile, line) && i < size)
    {
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
    
    string Name[totalNames];
    Nametoshow = new bool *[totalNames];
    Nametoslot = new bool *[totalNames];
    countAvailableslots = new int[totalNames];
    countfavoriteshows = new int[totalNames];


    for (size_t i = 0; i < totalNames; i++)
    {
        Nametoshow[i] = new bool[size]{false};
        Nametoslot[i] = new bool[168]{false};
    }
    for(int k = 0 ; k< totalNames; k++){
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
            if (slot >= 0 && slot < 168) {Nametoslot[k][slot] = true; 
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
            for (size_t j = 0; j < size; j++)
            {
            if (token2 == show[j]){ Nametoshow[k][j] = true; countfavoriteshow++;}
            }
        }
        countfavoriteshows[k] = countfavoriteshow;
    }  
}
    inputFile.close();
    
}

int main()
{
    string filePath = "C:\\Users\\Manan\\Documents\\project\\in.txt";
    int size;
    bool **Nametoshow;
    bool **Nametoslot;
    int totalNames;
    int *countAvailableslots;
    int *countfavoriteshows;
    input(filePath, size, totalNames, Nametoshow, Nametoslot, countAvailableslots, countfavoriteshows);

    return 0;
}
