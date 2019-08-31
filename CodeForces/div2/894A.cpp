#include<iostream>
#include<cstring>
#include<string>

using namespace std;

int main(){
	string re;
	cin >> re;
	int dpQ[re.size()];
	memset(dpQ,0,sizeof(dpQ));
	for(int i = 0; i < re.size();++i){
		if(i == 0)
			dpQ[i] = (re[i] == 'Q');
		else
			dpQ[i] = (dpQ[i-1] + (re[i] == 'Q'));
	}
	int ans = 0;
	for(int i = 1; i < re.size()-1;++i){
		if(re[i] == 'A')
			ans += (dpQ[i]*(dpQ[re.size()-1]-dpQ[i]));
	}
	printf("%d\n",ans);
	return 0;
}