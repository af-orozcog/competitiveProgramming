#include<iostream>

using namespace std;

int main(){
	int siz;
	scanf(" %d",&siz);
	int dpO[siz];
	char ar[siz];
	for(int i = 0; i < siz;++i){
		char c;
		scanf(" %c",&c);
		if(i == 0){
			if(c != '1')
				dpO[i] = 1;
			else
				dpO[i] = 0;
		}
		else{
			if(c != '1')
				dpO[i] = dpO[i-1] + 1;
			else
				dpO[i] = dpO[i-1];
		}
		ar[i] = c;
		//cout << ar[i] << endl;
	}
	if(dpO[siz-1] == siz || dpO[siz-1] == 0){
		puts("0");
		return 0;
	}
	int ans = 0;
	for(int i = 2; i <= siz;i += 2){
		for(int j = 0; j+i-1 < siz;++j){
			int zeros = dpO[j+i-1] - dpO[j];
			//cout << "i is " << i <<" j is " << j << endl; 
			if(ar[j] == '0')
				++zeros;
			//cout << zeros << endl;
			//cout << ones << endl;
			if((i-zeros) == (i/2)){
	//			cout << zeros << " " << i<< " " << j <<endl;
				ans = i;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}