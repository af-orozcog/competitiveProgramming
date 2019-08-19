#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int books;
	while(cin >> books){
		vector<int> prices(books);
		for(int i = 0; i < books;++i){
			cin >> prices[i];
		}
		sort(prices.begin(),prices.end());
		int val;
		cin >> val;
		vector<int>::iterator low = lower_bound(prices.begin(),prices.end(),val/2);
		int one;
		int two;
		int ind1 = low - prices.begin();
		//cout << ind1 << endl;
		while(ind1 != -1){
			int search = val - prices[ind1];
			vector<int>::iterator low2 = lower_bound(prices.begin() + ind1 + 1,prices.end(),search);
			int ind2 = low2 - prices.begin();
			//cout << ind2 << " " << ind1 <<"prices: "<< prices[ind2] <<endl;
			//cout << "search " << search << endl;
			if(prices[ind2] == search){
				//cout << "here?" << endl;
				if((ind1 != ind2) ||(ind1 == 0 && ind2 == 0) || (ind1 == prices.size()-1 && ind2 == prices.size()-1)){
					//cout << ind1 << " " <<ind2<< endl;
					one = prices[ind1];
					two = prices[ind2];
					if(one > two){
						int temp = two;
						two = one;
						one = temp;
					}
					break;
				}
			}
			--ind1;
		}
		cout << "Peter should buy books whose prices are " << one << " and " << two << ".\n";
		cout << endl;
	}
	return 0;
}