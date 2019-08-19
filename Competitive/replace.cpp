#include<iostream>
#include<string>
using namespace std;

int main(){
	string cadena;
	int flag = 0;
	while(getline(cin,cadena)){
		string answer = ""; 
		for(int i = 0; i < cadena.size(); i++){
			if(cadena[i] == '"' && flag == 0){
				answer += "``";
				flag = 1;
			}
			else if(cadena[i] == '"' && flag == 1){
				answer += "\'\'";
				flag = 0;
			}
			else
				answer += cadena[i];
		}
		cout << answer << endl;
	}
}