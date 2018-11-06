/*
 ID: xuczhou1
 PROG: milk2
 LANG: C++11
 */

#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

class interval{
public:
	int beginning;
	int ending;
};

bool operator<(const interval& i, const interval& j){
	return i.beginning < j.beginning;
}

int main(){
	freopen("milk2.in","r", stdin);
    freopen("milk2.out","w", stdout);
	int milking=0, idle=0;
	int start=36727; 
	int end=0;
	int tempMilking=0, tempIdle=0;
	int people;
	cin>>people;
	interval times[people];
	for(int i=0; i<people; i++){
		cin>>times[i].beginning>>times[i].ending;
	}
	for(int i=0; i<people; i++){
		if(times[i].beginning<start){
			start = times[i].beginning;
		}
		if(times[i].ending>end){
			end = times[i].ending;
		}
	}
	bool slots[end];
	for(int i=0; i<end; i++){
		slots[i]=0;
	}
	for(int i=0; i<people; i++){
		for(int j=times[i].beginning; j<times[i].ending; j++){
			slots[j]=1;
		}
	}
	for(int i=start; i<end; i++){
		if(slots[i]==1){
			tempIdle=0;
			tempMilking++;
			if(tempMilking>milking){
				milking=tempMilking;
			}
		}else{
			tempMilking=0;
			tempIdle++;
			if(tempIdle>idle){
				idle=tempIdle;
			}
		}
	}

	cout<<milking<<" "<<idle<<endl;


}