#include<iostream>
#include<stack>
#include<queue>
#include<string>

using namespace std;

int main(){

	while(true){
		queue<string> second;
		queue<string> first;
		for(int i = 0;i < 4;i++){
			for(int j = 0; j < 12;j++){
				string val;
				cin >> val;
				//cout << val << endl;
				if(val[0] == '#'){
				    //cout << "paso por aqui2?" << endl;
					return 0;
				}
				if((j+1) % 2 == 1){
					second.push(val);
				}
				else
					first.push(val);
			}
		}
		queue<string> played;
		int winner;
		int cards;
		int turn = 1;
		int flag = 0;
		while(true){
		    int flag2 = 0;
			if(turn % 2 == 1){
			    if(played.size() == 0){
			        played.push(second.front());
			        second.pop();
			        turn += 1;
			        if(second.size() == 0){
							winner = 1;
							cards = first.size();
							flag = 1;
							break;
						}
			    }
				else if(played.back()[1] == 'A'){
					for(int i = 0; i < 4; i++){
						played.push(second.front());
						second.pop();
						if(second.size() == 0){
							winner = 1;
							cards = first.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(first.size() > 0){
							copy.push(first.front());
							first.pop();
						}
						first = copy;
					}
				}
				else if(played.back()[1] == 'Q'){
					for(int i = 0; i < 2; i++){
						played.push(second.front());
						second.pop();
						if(second.size() == 0){
							winner = 1;
							cards = first.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(first.size() > 0){
							copy.push(first.front());
							first.pop();
						}
						first = copy;
					}
				}
				else if(played.back()[1] == 'J'){
					for(int i = 0; i < 1; i++){
						played.push(second.front());
						second.pop();
						if(second.size() == 0){
							winner = 1;
							cards = first.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(first.size() > 0){
							copy.push(first.front());
							first.pop();
						}
						first = copy;
					}
				}
				else if(played.back()[1] == 'K'){
					for(int i = 0; i < 3; i++){
						played.push(second.front());
						second.pop();
						turn += 1;
						if(second.size() == 0){
							winner = 1;
							cards = first.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(first.size() > 0){
							copy.push(first.front());
							first.pop();
						}
						first = copy;
					}
				}
				else{
					played.push(second.front());
					second.pop();
					if(second.size() == 0){
							winner = 1;
							cards = first.size();
							flag = 1;
							break;
					}
					turn +=1;
				}
				if(flag)
					break;
			}
			else if(turn % 2 == 0){
			    if(played.size() == 0){
			        played.push(first.front());
			        first.pop();
			        turn +=1;
			        if(first.size() == 0){
							winner = 2;
							cards = second.size();
							flag = 1;
							break;
						}
			    }
			    else if(played.back()[1] == 'A'){
					for(int i = 0; i < 4; i++){
						played.push(first.front());
						first.pop();
						if(first.size() == 0){
							winner = 2;
							cards = second.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(second.size() > 0){
							copy.push(second.front());
							second.pop();
						}
						second = copy;
					}
				}
				else if(played.back()[1] == 'Q'){
					for(int i = 0; i < 2; i++){
						played.push(first.front());
						first.pop();
						if(first.size() == 0){
							winner = 2;
							cards = second.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(second.size() > 0){
							copy.push(second.front());
							second.pop();
						}
						second = copy;
					}
				}
				else if(played.back()[1] == 'J'){
					for(int i = 0; i < 1; i++){
						played.push(first.front());
						first.pop();
						if(first.size() == 0){
							winner = 2;
							cards = second.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(second.size() > 0){
							copy.push(second.front());
							second.pop();
						}
						second = copy;
					}
				}
				else if(played.back()[1] == 'K'){
					for(int i = 0; i < 3; i++){
						played.push(first.front());
						first.pop();
						if(first.size() == 0){
							winner = 2;
							cards = second.size();
							flag = 1;
							break;
						}
						if(played.back()[1] == 'A' ||
							played.back()[1] == 'Q' ||
							played.back()[1] == 'J' ||
							played.back()[1] == 'K'){
							flag2 = 1;
							break;
						}
					}
					turn +=1;
					if(flag != 1 && flag2 != 1){
						queue<string> copy = played;
						queue<string> newp;
						played = newp;
						while(second.size() > 0){
							copy.push(second.front());
							second.pop();
						}
						second = copy;
					}
				}
				else{
					played.push(first.front());
					first.pop();
					if(first.size() == 0){
							winner = 2;
							cards = second.size();
							flag = 1;
							break;
					}
					turn +=1;
				}
				if(flag)
					break;
			}
			cout << second.size() << " " << first.size() << " " << played.size() << endl;
		}
		cout << winner << " " << cards <<  " " << second.size() << endl;
	}
	return 0;
}