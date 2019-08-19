#include<iostream>
#include<string>
#define min(x,y)(x < y? x:y)

using namespace std;

int main(){	
	int n;
	scanf(" %d",&n);
	string re;
	cin >> re;
	int i = 0;
	int j = 0;
	int siz = re.size();
	while(re.size() != 11){
		while(i < re.size() && (re[i] == '8' || re[i] == 'A')){++i;}
		if(i ==re.size()){
			puts("YES");
			return 0;
		}
		else{
			re.erase(re.begin() + i);
			if(j > i)
				--j;
		}
		while(j < re.size() && re[j] != '8'){++j;}
		if(j == re.size()){
			puts("NO");
			return 0;
		}
		else{
			re.erase(re.begin() + j);
			if(i > j)
				--i;
		}
	}
	if(re[0] == '8')
		puts("YES");
	else 
		puts("NO");
	return 0;
}