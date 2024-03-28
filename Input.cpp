#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

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