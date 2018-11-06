/*
 ID: xuczhou1
 PROG: namenum
 LANG: C++11
 */


#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include <algorithm>
#include <iterator> 

using namespace std;

string lToNum(char letter){
	if(int(letter)<68){
		return "2";
	}else if(int(letter)<71){
		return "3";
	}else if(int(letter)<74){
		return "4";
	}else if(int(letter)<77){
		return "5";
	}else if(int(letter)<80){
		return "6";
	}else if(int(letter)<84){
		return "7";
	}else if(int(letter)<87){
		return "8";
	}else{
		return "9";
	}
}

string ToNum(string name){
	string num;
	for(int i=0; i<name.size(); i++){
		num+=lToNum(name[i]);
	}
	return num;
}



int main(){
	ofstream fout("namenum.out");
    ifstream fin1("namenum.in");
    ifstream fin2("dict.txt");
    vector<string> accp;
    vector<string> accpnum;
    string currName;
    string serial;
    while(fin2>>currName){
    	accp.push_back(currName);
    	//fout<<currName<<endl;
    	serial=ToNum(currName);
    	accpnum.push_back(serial);
    	//fout<<serial<<endl;
    }
    while(fin1>>serial){
    vector<string>::iterator it;
    it = find(accpnum.begin(),accpnum.end(),serial);
    if(it!=accpnum.end()){
    	int index = distance(accpnum.begin(),it);
    	fout<<accp[index]<<endl;
    	while(it!=accpnum.end()){
    		it = find(it+1,accpnum.end(),serial);
    		if(it==accpnum.end()){
    			break;
    		}else{
    			index = distance(accpnum.begin(),it);
    			fout<<accp[index]<<endl;
    		}
    	}
    }else{
    	fout<<"NONE"<<endl;
    }
	}

}