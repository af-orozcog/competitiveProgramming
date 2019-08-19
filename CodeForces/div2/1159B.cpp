#include<iostream>
#include<cmath>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int ar[n];
	for(int i = 0; i < n;++i){
		scanf(" %d",&ar[i]);
	}
	int minn = 1000000001;
	for(int i = 1; i < n-1;++i){
		int a = min(ar[0],ar[i]) / i;
		int b = min(ar[n-1],ar[i]) / (n-1-i);
		b = min(a,b);
		if(b < minn)
			minn = b;
	}
	int a = min(ar[0],ar[n-1]) / (n-1);
	minn = min(a,minn);
	printf("%d\n",minn);
	return 0;
}