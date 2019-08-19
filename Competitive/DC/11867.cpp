/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<bitset>
#include<cmath>
#include<algorithm>

using namespace std;
vector<int> sequence = {1};
int divisors(int n) 
{ 
    int cnt = 0; 
    for (int i = 1; i <= sqrt(n); i++) { 
        if (n % i == 0) { 
            // If divisors are equal, 
            // count only one 
            if (n / i == i) 
                cnt++; 
  
            else // Otherwise count both 
                cnt = cnt + 2; 
        } 
    } 
    return cnt; 
} 

void sett(){
	int i = 1;
	int add = sequence[i-1] + divisors(sequence[i-1]);
	while(add <= 1000000){
		sequence.push_back(add);
		++i;
		add = sequence[i-1] + divisors(sequence[i-1]);
	}
}

int main(){
	sett();
	int cas;
	cin >> cas;
	int a = 1;
	while(cas--){
		int x,y;
		cin >> x >> y;
		vector<int>::iterator low,up;
		low = lower_bound(sequence.begin(),sequence.end(),x);
		up = upper_bound(sequence.begin(),sequence.end(),y);
		cout << "Case " << a << ": " << up-low << endl;
		++a;
	}	
	return 0;	
}