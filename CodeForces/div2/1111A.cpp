#include<iostream>
#include<string>

using namespace std;

bool vowel(char a){
	if(a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u' )
		return true;
	return false;
}

int main(){
	string a,b;
	cin >> a >> b;
	if(a.size() != b.size()){
		puts("No");
		return 0;
	}
	for(int i = 0; i < a.size();++i){
		bool a1,b1;
		a1 = vowel(a[i]);
		b1 = vowel(b[i]);
		if(a1 != b1){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}