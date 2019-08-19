#include<iostream>
#include<string>

using namespace std;

int main(){
	while(true){
		int num;
		cin >> num;
		if(num == 0)
			break;
		string que;
		cin >> que;
		int last = -1;
		int lastInd = -1;
		int min = -1;
		for(int i = 0; i < num; i++){
			if(que[i] == 'Z'){
				min  = 0;
				break;
			}
			if(que[i] == 'R'){
				if(last == 0){
					if((i - lastInd) < min || min == -1)
						min = (i - lastInd);
				}
				lastInd = i;
				last = 1; 
			}
			if(que[i] == 'D'){
				if(last == 1){
					if((i - lastInd) < min || min == -1)
						min = (i - lastInd);
				}
				lastInd = i;
				last = 0;
			}
		}
		cout << min << endl;
	}
	return 0;
}
