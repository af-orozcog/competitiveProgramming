/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long
#define min(x,y)(x < y? x:y)
#define max(x,y)(x > y?x:y)

using namespace std;

bool com(const ll a,const ll b){
	return a > b;
}

int main(){
	int n,m;
	scanf(" %d %d",&n,&m);
	vector<ll> num1(n);
	for(int i = 0; i < n;++i){
		cin >> num1[i];
	}
	sort(num1.begin(),num1.end(),com);
	vector<ll> num2(m);
	for(int i = 0; i < m;++i){
		cin >> num2[i];
	}
	sort(num2.begin(),num2.end(),com);
	if(num1[0] >= 0 && num1[num1.size()-1] >= 0){
		if(num2[0] <= 0 && num2[num2.size()-1] <= 0)
			cout << num1[num1.size()-2] * num2[0] << endl;
		else
			cout << num1[1] * num2[0] << endl;
	}
	else if(num1[0] <= 0 && num1[num1.size()-1] <= 0){
		if(num2[0] <= 0 && num2[num2.size()-1] <= 0)
			cout << num1[num1.size() - 2]*num2[num2.size()-1] << endl;
		else if(num2[0] >= 0 && num2[num2.size() - 1]>= 0)
			cout << num1[1]*num2[num2.size()-1] << endl;
		else{
			cout << num1[num1.size()-2]*num2[num2.size()-1] << endl;
		}
	}
	else{
		if(num2[0] >= 0 && num2[num2.size()-1] >= 0){
			if(num1[1] >= 0)
				cout << num1[1]* num2[0] << endl;
			else
				cout << num1[1]*num2[num2.size()-1] << endl;
		}
		else if(num2[0] <= 0 && num2[num2.size()-1] <= 0){
			if(num1[num1.size()-2] <= 0)
				cout << num1[num1.size()-2]*num2[num2.size()-1] << endl;
			else
				cout << num1[num1.size()-2]*num2[0] << endl;
		}
		else{
			//cout << "aqui" << endl;
			ll min1 = num1[num1.size()-1]*num2[num2.size()-1];
			ll min2 = num1[0]*num2[0];
			if(min1 > min2){
				cout << max(num1[num1.size()-2]*num2[num2.size()-1],min2) << endl;
			}
			else if(min2 > min1){
				cout << max(min1,num1[1]*num2[0]) << endl;
			}
			else{
				cout << min(num1[1]*num2[0],num1[num1.size()-2]*num2[num2.size()-1]) << endl;
			}
			//ll min3 = num1[0]*num2[0];
			//ll min4 = num1[num1.size()-2]*num2[num2.size()-1];
			//cout << ans << endl;
		}
	}
	return 0;
}