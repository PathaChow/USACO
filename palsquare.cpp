/*
 ID: xuczhou1
 PROG: palsquare
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
	ofstream fout("palsquare.out");
	ifstream fin("palsquare.in");
	int base;
	fin>>base;
	//cin>>base;
	string inBase;
	string sqinBase;
	int isq;
	for(int i=1; i<=300; i++){
		isq=i*i;
		inBase=ConvertToBase(i,base,"");
		sqinBase=ConvertToBase(isq,base,"");
		if(CheckPal(sqinBase)){
			fout<<inBase<<" "<<sqinBase<<endl;
		}
	}
	//cout<<CheckPal("1521")<<endl;
	//cout<<ConvertToBase(50,base,"")<<endl;
}