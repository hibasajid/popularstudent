#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    const int SIZE = 40;  
    string st[SIZE];  
    string f[SIZE][5];  
    int fC[SIZE] ={0};
    ifstream in("Friends Dataset.csv");  
    for(int i=0;i<SIZE;i++){
        string l;
        getline(in,l);
        stringstream ss(l); 
        getline(ss,st[i],',');  
        for (int j=0;j<5;j++){
            getline(ss,f[i][j],',');  
    }
    }
    for (int i=0;i<SIZE;i++){
        for (int j=0;j<SIZE;j++){
            for (int k=0;k<5;k++){
                if (f[j][k]==st[i]){
                    fC[i]++;  
        }
        }
        }
    }
    int max=0;
    int mf=0;
    for (int i=0;i<SIZE;i++) {
        if(fC[i]>mf){
            mf=fC[i];
            max=i; 
        }
    }
    cout<<st[max]<<" is the most popular student with "<<mf<<"friends"<<endl;
    return 0;
}
