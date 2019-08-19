/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define min(x,y)(x < y?x:y)

using namespace std;

/*bool com(const string a, const string b){
	return a[0] < b[0] && a[1] < b[1];
}*/
int main(){
	vector<int> m(10,0);
	vector<int> s(10,0);
	vector<int> p(10,0);
	for(int i = 0; i < 3;++i){
		string l;
		cin >> l;
		if(l[1] == 'm'){
			++m[l[0]-'0'];
		}
		else if(l[1] == 's'){
			++s[l[0] -'0'];
		//	cout << "aqui" <<" " <<l[0]-'0' <<endl;
		}
		else
			++p[l[0] - '0'];
	}
	int minn = 4;
	for(int i = 0;i < 8;++i){
		int co = 3;
		int a = (m[i] >= 1?1:0)+(m[i+1]>= 1?1:0)+(m[i+2]>= 1?1:0);
		int b = (s[i]>= 1?1:0)+(s[i+1]>= 1?1:0)+(s[i+2]>= 1?1:0);
		//cout << "b " << b << endl;
		int c = (p[i]>= 1?1:0)+(p[i+1]>= 1?1:0)+(p[i+2]>= 1?1:0);
		a = a - co;
		b = b - co;
		c = c - co;
		//cout << a <<" "<< b <<" " << c << endl;
		if(a >= 0 || b >= 0 || c >= 0){
			puts("0");
			return 0;
		}
		minn = min(minn,-a);
		minn = min(minn,-b);
		minn = min(minn,-c);
	}
	for(int i = 0; i < 10;++i){
		int co = 3;
		int a = m[i];
		int b = s[i];
		int c = p[i];
		a -= co;
		b -= co;
		c -= co;
		if(a >= 0 || b >= 0 || c >= 0){
			puts("0");
			return 0;
		}
		minn = min(minn,-a);
		minn = min(minn,-b);
		minn = min(minn,-c);
	}
	printf("%d\n",minn);
	return 0;
}