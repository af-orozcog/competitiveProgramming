#include<iostream>
#include<queue>

using namespace std;

int main(){
	int ba,dis;
	cin >> ba >> dis;
	int first[ba];
	int second[ba];
	for(int i = 0; i < ba; i++){
		int val;
		cin >> val;
		first[i] = val;
	}
	for(int i = 0; i < ba; i++){
		int val;
		cin >> val;
		second[i] = val;
	}
	int fi[ba];
	int sec[ba];
	for(int i = 0; i < ba; i++){
		if(i != ba- 1){
			int dis1 = first[i+1] - first[i];
			int dis2 = second[i+1] - second[i];
			fi[i] = dis1;
			sec[i] = dis2;
		}
		else{
			int dis1 = (dis-first[i]) + first[0];
			int dis2 = (dis - second[i]) + second[0];
			fi[i] = dis1;
			sec[i] = dis2;
		}
	}
	for(int i = 0; i < ba; i++){
		int counter = 0;
		int equal = 0;
		int copy = i;
		while(counter < ba){
			if(fi[counter++] == sec[copy++])
				equal++;
			else
				break;
			copy = copy % ba;
			//cout << counter << endl;

		}
		if(equal == ba){
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}