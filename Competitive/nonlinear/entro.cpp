/**
*for the team and валентина в
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

int main(){
	string finish = "****END_OF_INPUT****";
	string next = "****END_OF_TEXT****";
	string entrada;
	map<string,int> count;
	while(cin >> entrada){
		if(entrada.compare(finish) == 0){
			cout << "entro aqui " << entrada <<endl;
			return 0;
		}
		else if(entrada.compare(next) == 0){
			cout << "aqui?" << endl;
			double val1 = 0;
			for(const auto &mypair: count){
				double helper = ((double)count.size())/((double)mypair.second);
				helper = log(helper);
				helper /= log(10); 
				val1 += helper;
			}
			val1 /= ((double)count.size());
			double val2 = count.size();
			val2 = log(val2);
			val2 /= log(10);
			double ans = (val1 / val2)*100;
			int third = round(ans);
			cout << count.size() << " ";
			std::cout << std::fixed;
    		std::cout << std::setprecision(1);
    		std::cout << val1;
    		cout << " " << third << endl;
			map<string,int> cont;
			count = cont;
			continue;
		}
		transform(entrada.begin(), entrada.end(), entrada.begin(), ::tolower);
		for(int i = 0,len = entrada.size(); i < len;i++){
			if(ispunct(entrada[i])){
				entrada.erase(i--,1);
				len = entrada.size();
			}
		}
		cout << entrada << endl;
		if(count.count(entrada) == 0){
			count[entrada] = 0;
		}
		count[entrada] = count[entrada] + 1;
	}

	return 0;
}