#include<iostream>
#include<cstring>

using namespace std;

int main(){
	int n;
	scanf(" %d",&n);	
	bool rooms[10];
	memset(rooms,false,sizeof(rooms));
	for(int i = 0; i < n;++i){
		char c;
		scanf(" %c",&c);
		if(c -'0' >= 0 && c -'0' <= 9){
			rooms[(c-'0')] = false;
		}
		else if(c == 'L'){
			int co = 0;
			while(rooms[co]){++co;}
			rooms[co] = true;
		}
		else{
			int co = 9;
			while(rooms[co]){--co;}
			rooms[co] = true;
		}
	}
	for(int i = 0; i < 10;++i){
		printf("%d",(rooms[i]?1:0));
	}
	puts("");
	return 0;
}