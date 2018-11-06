/*
 ID: xuczhou1
 PROG: gift1
 LANG: C++11
 */


#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    ofstream fout("gift1.out");
    ifstream fin("gift1.in");
    
    unordered_map<string, int> accounts;
    
    
    int people;
    fin>>people;
    string name;
    string friends[people];
    int money, number=0;
    
    for(int i=0; i<people; i++){
        fin>>name;
        accounts[name]=0;
        friends[i]= name;
    }
    
    for(int i=0; i<people;i++){
        string recipient;
        fin>>name;
        fin>>money>>number;
        for(int j=0; j<number; j++){
            fin>>recipient;
            accounts[recipient]+=money/number;
            accounts[name]-=money/number;
        }
    }
    
    /*for (auto& x: accounts) {
        cout << x.first << " " << x.second << endl;
    }*/
    for(int i=0; i<people;i++){
        fout<<friends[i]<<" "<<accounts[friends[i]]<<endl;
    }
    

}
