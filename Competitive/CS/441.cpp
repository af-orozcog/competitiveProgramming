#include<iostream>

using namespace std;

int main(){
	bool first = true;
	while(true){
		int nums;
		cin >> nums;
		if(nums == 0)
			break;
		if(!first)
			cout << endl;
		int values[nums];
		for(int i = 0; i < nums;i++){
			int val;
			cin >> val;
			values[i] = val;
		}
		for(int i1 = 0; i1 < nums;i1++){
			for(int i2 = i1+1; i2 < nums;i2++){
				for(int i3 = i2 +1 ; i3 < nums; i3++){
					for(int i4 = i3 + 1; i4 < nums; i4++){
						for(int i5 = i4 + 1; i5 < nums; i5++){
							for(int i6 = i5 + 1; i6 < nums; i6++){
								cout << values[i1] << " " << values[i2] << " " << values[i3]<< " "<< values[i4] <<" " << values[i5] << " " <<values[i6] << endl;
							}
						}
					}
				}
			}
		}
		first = false;
	}
	return 0;
}