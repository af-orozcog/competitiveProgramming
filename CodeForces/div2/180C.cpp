#include<iostream>
#include<string>
#define min(x,y)(x < y?x:y)

using namespace std;

int main(){
	string re;
	cin >> re;
	int dpU[re.size()];
	int dpL[re.size()];
	if(re[0] >= 'a')
		dpU[0] = 0;
	else
		dpU[0] = 1;
	for(int i = 1; i < re.size();++i){
		if(re[i] < 'a'){
			//cout << "entra?" << endl;
			dpU[i] = dpU[i-1] +1;
		}
		else
			dpU[i] = dpU[i-1];
	}
	if(re[re.size()-1] >= 'a')
		dpL[re.size()-1] = 1;
	else
		dpL[re.size()-1] = 0;
	for(int i = re.size()-2;i >= 0;--i){
		if(re[i] >= 'a')
			dpL[i] = dpL[i+1] +1;
		else
			dpL[i] = dpL[i+1];
	}
	/*if(dpL[0] == re.size() || dpU[re.size()-1] == re.size()){
		puts("0");
		return 0;
	}*/
	int ans = re.size() - dpL[0];
	for(int i = 1; i < re.size();++i){
		int needL = re.size()-i;
		needL = needL - dpL[i];
		int needU = i - dpU[i-1];
		//cout << needU << " " << needL <<endl;
		ans = min(ans,needU+needL);
	}
	int le = re.size()- dpU[re.size()-1];
	ans = min(ans,le); 
	printf("%d\n", ans);
	return 0;
}