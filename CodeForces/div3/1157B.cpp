#include<iostream>
#include<map>
using namespace std;

int main(){
	int siz;
	scanf( " %d",&siz);
	char num[siz+1];
	scanf(" %s",num);
	map<char,char> tra;
	bool pos = false;
	for(int i = 1; i < 10;++i){
		char c;
		scanf(" %c",&c);
		tra[i+'0'] = c;
		if(tra[i+'0'] > (i+'0'))
			pos = true;   
	}
	if(!pos){
		printf("%s\n",num);
		return 0;
	}
	bool beg= false;
	for(int i = 0; i < siz;++i){
		if(beg && num[i] > tra[num[i]])
			break;
		if(beg && num[i] <= tra[num[i]])
			num[i] = tra[num[i]];
		else if(!beg && num[i] < tra[num[i]]){
			num[i] = tra[num[i]];
			beg = true;
		}
	}
	printf("%s\n",num);
	return 0;
}