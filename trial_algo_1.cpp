#include<iostream>
#include<vector>
using namespace std;

int main() {
    int noFM, noSE;
    int SLN, SEN;
    cout << "Enter how many family members in the family: ";
    cin >> noFM;
    cout << "Enter how many total series: ";
    cin >> noSE;

    vector<vector<int>> MSE(noFM+1, vector<int>(noSE + 1, 0));
    vector<vector<int>> MSL(noFM+1, vector<int>(169, 0));

    // Display initial state of arrays
    cout << "Initial state of arrays:" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            cout << MSL[i][j] << "," << MSE[i][j] << " ";
        cout << endl;
    }

    for (int i=0;i<=noFM;i++)
    {
        
        cout<<"Enter all slots when member "<<i+1<<" is free (0 to stop): "<<endl;
        while (1) {
            cin>>SLN;
            if ((SLN>0)&&(SLN<=168))
                MSL[i+1][SLN] = 1;
            else if (SLN == 0)
                break;
            else
                cout << "Enter a valid slot (0-168): ";
        }

        cout <<"Enter all series numbers that member "<<i+1<<" wants to watch (0 to stop): "<<endl;
        while(1){
            cin>>SEN;
            if((SEN>=1)&&(SEN<=noSE))
                MSE[i+1][SEN]=1;
            else if(SEN==0)
                break;
            else
                cout<<"Enter a valid series number (1-" << noSE << "): "<<endl;
        }
    }

    // Display updated state of arrays
    cout<<"Updated state of arrays:"<<endl;
    for(int i=0;i<=noFM;i++){
        cout<<"Member "<<i+1<<" free slots: "<<endl;
        for(int j=0;j<10;j++)
            cout<<MSL[i][j]<<" ";
        cout<<endl;

        cout<<"Member "<<i+1<<" preferred series: ";
        for(int j=1;j<=noSE;j++)
            cout<<MSE[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}