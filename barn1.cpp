/*
 ID: xuczhou1
 PROG: barn1
 LANG: C++11
 */

#include<iostream>
#include<fstream>
#include <vector>
#include <algorithm>

using namespace std;


bool larger(int a, int b){
	return (a>b);
}


int main(){
	ofstream fout("barn1.out");
	ifstream fin("barn1.in");
	int k, total, ftotal, n;
	int num, diff;
	vector<int> numlist;
	vector<int> difflist;
	fin>>k>>total>>n;
	if(n==1){
		fout<<total-1<<endl;
		return 0;
	}
	for(int i=0; i<n; i++){
		fin>>num;
		numlist.push_back(num);
	}
	sort(numlist.begin(),numlist.end());
	for(int i=0; i<numlist.size(); i++){
		//cout<<numlist[i]<<endl;
	}

	ftotal=total;
	ftotal-=numlist[0]-1;
	ftotal-=total-numlist[numlist.size()-1];
	//cout<<n<<endl;
	for(int i=0; i<n-1; i++){
		diff=numlist[i+1]-numlist[i];
		difflist.push_back(diff);
		//cout<<diff<<" "<<i<<endl;
	}
	sort(difflist.begin(), difflist.end(),larger);
	//cout<<"k is "<<k<<endl;
	int limit=0;
	if(k-1>difflist.size()){
		limit=difflist.size();
	}else{
		limit=k-1;
	}
	for(int i=0; i<limit; i++){
		ftotal-=difflist[i]-1;
		//cout<<difflist[i]<<endl;
	}
	//cout<<ftotal<<endl;
	fout<<ftotal<<endl;
}