#include<iostream>
#include<string>
#include<algorithm>
#define mod(x,y)(x % y < 0 ? (x %y)+y:x%y)

using namespace std;

string con1(string &re){
	int col = 0;
	int i = 0;
	for(; i < re.size();++i){
		if(re[i] >='A'){
			col *= 26;
			col += (re[i]-'A')+1;
		}
		else
			break;
	}
	int row = 0;
	for(; i < re.size();++i){
		row *= 10;
		row += re[i] - '0';
	}
	string ans = "R" + to_string(row) + "C" + to_string(col);
	return ans;
}

string con2(string &re){
	int num = 0;
	int i = 1;
	for(; i < re.size();++i){
		if(re[i] > '9')
			break;
		num *= 10;
		num += (re[i] -'0');
	}
	++i;
	int col = 0;
	for(; i < re.size();++i){
		if(re[i] > '9')
			break;
		col *= 10;
		col += re[i] -'0';
	}
	string colans = "";

	while(col){
		int res = col%26;
		//cout << "res is " << res << endl;
		colans += ('A' + mod(res-1,26));
		if(mod(res-1,26) == 25)
			col -= 26;
		col /= 26;
	}
	reverse(colans.begin(),colans.end());
	//colans += ('A' +(col-1));
	return colans + to_string(num);
}

bool type1(string &re){
	int lastR = 0;
	while(re[lastR] > '9'){++lastR;}
	--lastR;
	int le = re.size()-1;
	while(re[le] != 'C' &&le > lastR){--le;}
	return le > lastR +1; 
}

int main(){
	int n;
	scanf(" %d",&n);
	while(n--){
		string re;
		cin >> re;
		if(type1(re))
			cout << con2(re) << endl;
		else
			cout << con1(re) << endl;
	}
	return 0;
}