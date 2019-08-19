#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
	int cas;
	cin >> cas;
	cin.ignore();
	while(cas--){
		//cout << "aqui?" << endl;
		char ans[1000000];
		char c;
		int pos = 0;
		while(cin.get(c)){
			//cout << c << endl;
			if(c == 'a' || c == 'e'
				|| c == 'i' || c == 'o'
				|| c == 'u'){
				ans[pos++] = c;
				ans[pos++] = 'p';
				ans[pos++] = c;
			}
			else
				ans[pos++] = c;
			if(c == '\n'){
				ans[pos] = '\0';
				break;
			}
		}
		printf("%s",ans);
	}
	return 0;
}