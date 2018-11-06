/*
 ID: xuczhou1
 PROG: milk
 LANG: C++11
 */

#include<iostream>
#include<fstream>
#include <vector>
#include <algorithm>

using namespace std;

class farmer{
public:
	int price;
	int units;
	friend bool operator<(const farmer& lhs, const farmer& rhs){
		return lhs.price < rhs.price;
	}
};

int main(){
	ofstream fout("milk.out");
	ifstream fin("milk.in");
	int sum, num;
	farmer curr;
	vector<farmer> farmers;
	fin>>sum>>num;
	for(int i=0; i<num; i++){
		fin>>curr.price>>curr.units;
		farmers.push_back(curr);
	}
	sort(farmers.begin(), farmers.end());
	int money=0;
	for(int i=0; sum>0; i++){
		if(farmers[i].units>sum){
			money+=sum * farmers[i].price;
			sum=0;
		}else{
			money+=farmers[i].units*farmers[i].price;
			sum-=farmers[i].units;
		}
	}
	fout<<money<<endl;
}