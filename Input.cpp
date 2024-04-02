#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
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


string *getm(const string &filePath, int &size)
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

    inputFile.close();
    return show;
}

int main()
{
    int size = 0;
    string *show = getm("C:\\Users\\Manan\\Documents\\project\\in.txt", size);
    if (show == nullptr)
    {
        return 1;
    }

    for (int i = 0; i < size; i++)
    {
        cout << show[i] << endl;
    }

    delete[] show;
    return 0;
}
