/*
 ID: xuczhou1
 PROG: dualpal
 LANG: C++11
 */

#include<iostream>
#include<fstream>
#include<string>
#include <vector>

using namespace std;

string ConvertToBase(int num, int base, string ans){
	if(num<base){
		if(num+48>57){
			ans+=char(num+55);
		}else{
			ans+=char(num+48);
		}
		return ans;
	}else{
		ans=ConvertToBase(num/base, base, ans);
		if(num%base+48>57){
			ans+=char(num%base+55);
		}else{
			ans+=char(num%base+48);	
		}
		return ans;
	}
}

bool CheckPal(string input){
	double temp;
	temp=double(input.length()-1)/2;
	//cout<<temp<<endl;
	for(int i=0; i<temp; i++){
		if(input[i]!=input[input.length()-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
	ofstream fout("dualpal.out");
	ifstream fin("dualpal.in");
	int num;
	int threshold;
	int count;
	fin>>num>>threshold;
	//cin>>num>>threshold;
	for(int i=threshold+1; num>0; i++){
		count=0;
		for(int base=2; base<11; base++){
			if(CheckPal(ConvertToBase(i,base,""))){
				count++;
			}
			if (count>1){num--;break;}
		}
		if(count>1){fout<<i<<endl;}
	}

}