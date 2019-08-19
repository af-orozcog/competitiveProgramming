/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<string>

using namespace std;

string sumStrings(string a, string b){
	int sizA = a.size()-1;
	int sizB = b.size()-1;
	int carry = 0;
	string ans = "";
	while(sizA >= 0 || sizB >= 0){
		if(sizA >= 0 && sizB >= 0){
			int val1 = a[sizA] - '0';
			int val2 = b[sizB] - '0';
			int sum = val1 +val2 + carry;
			if(sum >= 10)
				carry = 1;
			else 
				carry = 0;
			ans = to_string(sum%10) + ans;
		}
		else if(sizA >= 0)
			ans = a[sizA] + ans;
		else if(sizB >= 0)
			ans = b[sizB] + ans;
		--sizA;
		--sizB;
	}
	return ans;
}

int main(){
	int val;
	cin >> val;
	string toRead;
	cin >> toRead;
	int i = 0, j = val >> 1;
	string oneval = "";
	string otherval = "";
	if(val % 2 == 0){
		int look1 = j;
		int look2 = j;
		while(toRead[look1] == '0'){++look1;}
		while(toRead[look2] == '0'){--look2;}
		//cout <<"attention!! " <<look1 << " " << look2 << endl;
		if(j - look2 <  look1 - j)
			j = look2;
		else if(j - look2 > look1 - j)
			j = look1;
		else{
			if(toRead[look1] > toRead[look2])
				j = look2;
			else if(toRead[look1] < toRead[look2])
				j = look1;
			else if(toRead[look1] < toRead[i])
				j = look1;
			else
				j = look2;
		}
	}
	else{
		if(toRead[j] == '0'){
			int look1 = j;
			int look2 = j;
			while(toRead[look1] == '0'){++look1;}
			while(toRead[look2] == '0' && look2 > i + 1){--look2;}
	//		cout << look1 << " " << look2 << endl;
			if(j - look2 < look1 - j && j - look2 != 0 && toRead[look2] <= toRead[i])
				j = look2;
			else if(j - look2 > look1 - j || j - look2 == 0)
				j = look1;
			else{
				if(toRead[look1] > toRead[look2])
					j = look2;
				else if(toRead[look1] < toRead[look2])
					j = look1;
				else if(toRead[look1] < toRead[i])
					j = look1;
				else
					j = look2;
			}
		}
		else{
			if(toRead[j] > toRead[i])
				++j;
		}
	}
	for(int m = 0; m < j;++m){
		oneval += toRead[m];
	}
	while(j < val){
		otherval += toRead[j];
		++j;
	}
	//cout << oneval << " " << otherval << endl;
	cout << sumStrings(oneval,otherval) << endl;
}