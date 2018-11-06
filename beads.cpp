/*
 ID: xuczhou1
 PROG: beads
 LANG: C++11
 */


#include <iostream>
#include <fstream>
#include <string>

using namespace std;



int main(){
    ofstream fout("beads.out");
    ifstream fin("beads.in");
    
    int beads;
    fin>>beads;
    string necklace;
    fin>>necklace;
    
    int left, right, left1, right1;
    int countleft=1;
    int countright=1;
    char log='w';
    int count=0;
    
    for(int i=0; i<beads; i++){
        left=i-1;
        left1=i-2;
        right=i;
        right1=i+1;
        countleft=1;
        countright=1;
        
        log='w';
        
        for(int j=0; j<beads;j++){
            if(left<0){
                left=beads+left;
            }
            if(left1<0){
                left1=beads+left1;
            }
            if(necklace[left]!='w'){
                log = necklace[left];
            }
            if(necklace[left1]!=log&&necklace[left1]!='w'&&log!='w'){
                break;
            }
            countleft++;
            left--;
            left1--;
        }
        
        log='w';
        
        for(int j=0; j<beads;j++){
            if(right>=beads){
                right=right-beads;
            }
            if(right1>=beads){
                right1=right1-beads;
            }
            if(necklace[right]!='w'){
                log = necklace[right];
            }
            if(necklace[right1]!=log&&necklace[right1]!='w'&&log!='w'){
                break;
            }
            countright++;
            right++;
            right1++;
        }
        if(countleft+countright>count){
            count=countleft+countright;
        }
    }
    if(count>beads){
        count=beads;
    }
    fout<<count<<endl;
}
