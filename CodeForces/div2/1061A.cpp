#include<iostream>
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){
	int n,s;
	scanf(" %d %d",&n,&s);
	int ans = s/n;
	if(ans * n < s)
		++ans;
	printf("%d\n",ans);
	return 0;
}