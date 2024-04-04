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
void storeSlotVsSeries(int memTotal,int slotTotal, int seriesTotal){
    slotVsSeries = new short int*[slotTotal+1];
    for(int i = 0; i < slotTotal+1; i++){
        slotVsSeries[i] = new short int[seriesTotal+1](); // Initialize with default value (0)
    }

    for(int i = 0; i < slotTotal; i++){
        for(int j = 0; j < seriesTotal; j++){
            for(int k = 0; k < memTotal; k++){
                if(memVsSlot[k][i] == true && memVsSeries[k][j] == true){
                    slotVsSeries[i][j]++;
                }
            }
            slotVsSeries[i][seriesTotal] += slotVsSeries[i][j];
            slotVsSeries[slotTotal][j] += slotVsSeries[i][j];
        }
    }
}

void displaySlotVsSeries(int slotTotal, int seriesTotal){
    for(int i = 0; i < slotTotal+1; i++){
        for(int j = 0; j < seriesTotal+1; j++){
            cout << slotVsSeries[i][j] << " ";
        }
        cout << endl;
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
