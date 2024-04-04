#include <iostream>
using namespace std;
#include <vector>

bool **memVsSlot;
bool **memVsSeries;
int **slotVsSeries;

void storeData(int memTotal, int slotTotal, int seriesTotal){
    memVsSlot = new bool*[memTotal];
    for(int i = 0; i < memTotal; i++){
        memVsSlot[i] = new bool[slotTotal](); // Initialize with default value (false)
    }
    memVsSeries = new bool*[memTotal];
    for(int i = 0; i < memTotal; i++){
        memVsSeries[i] = new bool[seriesTotal](); // Initialize with default value (false)
    }
    for(int i = 0; i < memTotal; i++){
        cout << "Member " << i+1 << " : " << endl;

        int avail;
        cout << "Total slots : ";
        cin >> avail;
        for(int j = 0; j < avail; j++){
            int k;
            cin >> k;
            if(k > 0 && k <= slotTotal)
                memVsSlot[i][k-1] = true;
            else
                cout << "Invalid slot index!" << endl;
        }

        int fav;
        cout << "Total series : ";
        cin >> fav;
        for(int j = 0; j < fav; j++){
            int k;
            cin >> k;
            if(k > 0 && k <= seriesTotal)
                memVsSeries[i][k-1] = true;
            else
                cout << "Invalid series index!" << endl;
        }
    }
}


void deallocateMemory(int memTotal){
    for(int i = 0; i < memTotal; i++){
        delete[] memVsSlot[i];
        delete[] memVsSeries[i];
    }
    delete[] memVsSlot;
    delete[] memVsSeries;
}


int main() {
    int members, slots, series;
    cout << "Members : ";
    cin >> members;
    cout << "Slots : ";
    cin >> slots;
    cout << "Series : ";
    cin >> series;
    storeData(members, slots, series);
    return 0;
}