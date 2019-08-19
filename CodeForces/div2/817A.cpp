#include<i>

using namespace std;

int main(){
	int x1,y1,x2,y2;
	scanf(" %d %d %d %d",&x1,&y1,&x2,&y2);
	int md1,md2;
	scanf(" %d %d",&md1,&md2);
	int a = mod(x1,md1);
	if(mod(x2,md1) != a){
		puts("NO");
		return 0;
	}
	int b = mod(y1,md2);
	if(mod(y2,md2) != b){
		puts("NO");
		return 0;
	}
	if(a == b)
		puts("YES");
	else
		puts("NO");
	return 0;
}