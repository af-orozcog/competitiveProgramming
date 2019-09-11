#include<iostream>
#include<stack>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);
	int b= -1;
	stack<int> tr;
	for(int i = 0; i< n;++i){
		char re;
		scanf(" %c",&re);
		if(re == ')'){
			if(tr.size() == 0 && b == -1)
				b = 1;
			else if(tr.size() == 0){
				puts("No");
				return 0;
			}
			else
				tr.pop();
		}
		else
			tr.push(i);
	}
	if(b == -1 && tr.size() == 0){
		puts("Yes");
		return 0;
	}
	if(b != -1 && tr.size() == 1)
		puts("Yes");
	else
		puts("No");
	return 0;
}