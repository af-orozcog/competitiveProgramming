#include<iostream>
#define ll long long

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	if((n %3) != 0){
		puts("NO");
		return 0;
	}
	puts("YES");
	int paL = (n)+2;
	int imB = 1;
	int paB = n+1;
	int nums[(n)<<1];
	int index = 0;
	for(int i = 0; i < (n/3)*2;++i){
		nums[index++] = imB;
		nums[index++] = paB;
		nums[index++] = paL;
		++imB;
		--paB;
		++paL;
	}
	for(int i = 0; i < (n<<1);++i){
		if(i == 0)
			printf("%d",nums[i]);
		else
			printf(" %d",nums[i]);
	}
	puts("");
	return 0;
}