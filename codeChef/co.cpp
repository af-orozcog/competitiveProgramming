/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

string toRead;
void exchange(int x, int y){
	char temp = toRead[x];
	toRead[x] = toRead[y];
	toRead[y] = temp;
}
int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int val;
		cin >> val;
		cin >> toRead;
		string copy = toRead;
		string copy2 = copy;
		sort(copy.begin(),copy.end());
		cout << "ordered: "<< copy << endl;
		int differs;
		for(int i = 0; i < val;++i){
			if(toRead[i] != copy[i]){
				int lastpos;
				for(int j = i + 1;j < val;++j){
					if(toRead[j] == copy[i])
						lastpos = j;
				}
				differs = i;
				exchange(i,lastpos);
				break;
			}
		}
		char save = copy2[differs];
		copy2.erase(differs,1);
		copy2 += save;
		if(copy2.compare(toRead) < 0)
			cout << copy2 << endl;
		else
			cout << toRead <<  endl;
	}
	return 0;
}