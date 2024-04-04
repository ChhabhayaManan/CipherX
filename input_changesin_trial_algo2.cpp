#include <iostream>
using namespace std;
#include <vector>

bool **memVsSlot;
bool **memVsSeries;
short int **slotVsSeries;

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


void findMax(int memTotal, int slotTotal, int seriesTotal){
    vector<int> mAX;
    mAX.push_back(-1);
    mAX.push_back(-1);
    mAX.push_back(-1);
    
    while(mAX[2] != 0){
        mAX.clear();
        mAX.push_back(0);
        mAX.push_back(0);
        mAX.push_back(0);
        for(int i = 0; i < slotTotal; i++){
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
                }
            }
        }   
        cout << "Slot " << mAX[0]+1 << " Series " << mAX[1]+1 << " : " << endl;

        for(int l= 3; l < mAX.size(); l++){
            for(int k = 0; k < slotTotal; k++){
                if(memVsSlot[mAX[l]][k] == true && memVsSeries[mAX[l]][mAX[1]] == true){
                    slotVsSeries[k][mAX[1]]--;
                    slotVsSeries[slotTotal][mAX[1]]--;
                }
            }
            memVsSeries[mAX[l]][mAX[1]] = false;
        }
        for(int k = 0; k < memTotal; k++){
            memVsSlot[k][mAX[0]] = false;
        }
        slotVsSeries[mAX[0]] = {0};
        storeSlotVsSeries(memTotal, slotTotal, seriesTotal);
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
    storeSlotVsSeries(members, slots, series);
    findMax(members, slots, series);
    deallocateMemory(members);
    return 0;
}
