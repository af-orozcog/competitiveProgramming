/**
*for the team and валентина в
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,int> values;
char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void initia(){
	int counter = 1;
	for(int i = 0; i < 26;i++){
		string toAdd = "";
		toAdd += alphabet[i];
		values[toAdd] = counter++;
	}
	for(int i = 0; i < 26; i++){
		for(int j = i + 1; j < 26; j++){
			string toAdd = "";
			toAdd += alphabet[i];
			toAdd += alphabet[j];
			values[toAdd] = counter++;
		}
	}
	for(int i = 0; i < 26;i++){
		for(int j = i + 1; j < 26;j++){
			for(int e = j + 1; e < 26; e++){
				string toAdd = "";
				toAdd += alphabet[i];
				toAdd += alphabet[j];
				toAdd += alphabet[e];
				values[toAdd] = counter++;
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = i +1 ; j < 26; j++){
			for(int e = j + 1; e < 26;e++){
				for(int n = e + 1; n < 26; n++){
					string toAdd = "";
					toAdd += alphabet[i];
					toAdd += alphabet[j];
					toAdd += alphabet[e];
					toAdd += alphabet[n];
					values[toAdd] = counter++;
				}
			}
		}
	}
	for(int i = 0; i < 26; i++){
		for(int j = i +1 ; j < 26; j++){
			for(int e = j + 1; e < 26;e++){
				for(int n = e + 1; n < 26; n++){
					for(int m = n + 1; m < 26;m++){
						string toAdd = "";
						toAdd += alphabet[i];
						toAdd += alphabet[j];
						toAdd += alphabet[e];
						toAdd += alphabet[n];
						toAdd += alphabet[m];
						values[toAdd] = counter++;
					}
				}
			}
		}
	}
}

int main(){
	initia();
	string toSee;
	while(cin >> toSee){
		if(values.count(toSee) > 0)
			cout << values[toSee] << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}