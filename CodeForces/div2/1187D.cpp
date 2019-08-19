/**
* I'm sorry I was an Idiot
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int cas;
	cin >> cas;
	while(cas--){
		int siz;
		cin >> siz;
		vector<int> unor(siz);
		vector<int> ord(siz);
		for(int i = 0; i < siz;++i){
			cin >> unor[i];
		}
		for(int i = 0; i < siz;++i){
			cin >> ord[i];
		}
		bool posi = true;
		for(int i = 0; i < siz && posi;++i){
			if(unor[i] != ord[i]){
				int m = 1;
				while(i + m < siz){
					if(unor[i + m] == ord[i+ m])
						break;
					++m;
				}
				m;
				if(i +m == siz)
					sort(unor.begin()+i,unor.end());
				else
					sort(unor.begin()+i,unor.begin()+i+m-1);
				cout << "m es " <<m << endl;
				int oldi = i;
				while(i < m+ oldi){
					//cout << "i es: " << i << endl;
					if(unor[i] != ord[i]){
						//cout << unor[i] << " "<< ord[i] << endl;
						posi = false;
						break;
					}
					++i;
				}
				--i;
			}
		}
		if(posi)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}