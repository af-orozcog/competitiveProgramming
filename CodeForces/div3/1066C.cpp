#include<iostream>
#include<map>
#define min(x,y)(x < y?x:y)
#define ll long long

using namespace std;

int main(){
	int q;
	scanf(" %d",&q);
	map<int,int> left,right;
	int sizL,sizR;
	sizL = sizR = 0;
	while(q--){
		char w;int n;
		scanf(" %c %d",&w,&n);
		if(w == 'L')
			left[n] = sizL++;
		else if(w == 'R')
			right[n] = sizR++;
		else{
			if(left.count(n)){
				ll pos1 = (sizL - left[n])-1;
				ll pos2 = left[n] +sizR; 
				cout << min(pos1,pos2) << endl;
			}
			else{
				ll pos1 = (sizR - right[n])-1;
				//cout <<"why  " <<pos1 << endl;
				ll pos2 = right[n] + sizL; 
				cout << min(pos1,pos2) << endl;
			}
		}
	}
	return 0;
}