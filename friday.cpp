/*
 ID: xuczhou1
 PROG: friday
 LANG: C++11
 */


#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    
    int N;
    int year=1900;
    int days=0;
    int log[7];
    for(int i=0; i<7;i++){
        log[i]=0;
    }
    fin>>N;
    for(int i=1900; i<1900+N; i++){
        days+=13;
        log[days%7]++;//jan
        days+=31;
        log[days%7]++;//feb
        if(i%400==0||(i%4==0&&i%100!=0)){
            days+=29;
        }else{
            days+=28;
        }
        log[days%7]++;//mar
        days+=31;
        log[days%7]++;//apr
        days+=30;
        log[days%7]++;//may
        days+=31;
        log[days%7]++;//june
        days+=30;
        log[days%7]++;//july
        days+=31;
        log[days%7]++;//aug
        days+=31;
        log[days%7]++;//sep
        days+=30;
        log[days%7]++;//oct
        days+=31;
        log[days%7]++;//nov
        days+=30;
        log[days%7]++;//dec
        days+=18;
    }
    fout<<log[6]<<" "<<log[0]<<" "<<log[1]<<" "<<log[2]<<" "<<log[3]<<" "<<log[4]<<" "<<log[5]<<endl;
}
