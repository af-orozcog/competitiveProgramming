/**
* Why the hell am I doing this
*/
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int main(){
	int t;
	scanf(" %d",&t);
	while(t--){
		string re;
		cin >> re;
		string pos1 = "";
		string pos2 = "";
		for(int i = 0; i < re.size();++i)
			if((re[i]-'a')%2)
				pos2 += re[i];
			else
				pos1 += re[i];
		sort(pos1.begin(),pos1.end());
		sort(pos2.begin(),pos2.end());
		if(((pos1[pos1.size()-1]-'a') > (pos2[0]-'a') + 1) ||((pos1[pos1.size()-1]-'a') < (pos2[0]-'a')-1))
			cout << pos1 << pos2<<endl;
		else if(((pos2[pos2.size()-1]-'a') > (pos1[0]-'a') + 1) ||((pos2[pos2.size()-1]-'a') < (pos1[0]-'a')-1))
			cout << pos2 << pos1 << endl;
		else
			cout << "No answer\n";
	}
	return 0;
}