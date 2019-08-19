#include<iostream>
using namespace std;
//<<" "<<king <<" " <<queen << " " << que <<
int main(){
	int king,queen,que;
	while(cin >> king >> queen >> que){
		if(que < 0 || que > 63 || queen == king){
			cout << "Illegal state" << endl;
		}
		else if(que == queen){
			cout << "Illegal move" << endl;
		}
		else if(que == king){
			cout << "Illegal move" << endl;
		}
		else if((que /8) != (queen/8) && (que%8) != (queen%8)){
			cout << "Illegal move" << endl;
		}
		else if((king/8) == que/8 && (king/8) == queen/8 && 
			((king > queen && king < que)||
				(king < queen && king > que))){
			cout << "Illegal move" << endl;
		}
		else if((king%8) == (queen%8) && (king%8) == que%8 &&((king > queen && king < que)||
				(king < queen && king > que))){
			cout << "Illegal move" << endl;
		}
		else if((king/8) == (que/8) && ((que%8) == ((king%8) + 1) || (que%8) == ((king%8) - 1))){
			cout <<  "Move not allowed" << endl;
		} 
		else if((king%8) == (que%8) && ((que/8) == ((king/8) + 1) || (que/8) == ((king/8)-1))){
			cout << "Move not allowed" << endl; 
		}
		else{
			int four = 0;
			if(king%8 == 7 || ((king%8) + 1) == que%8){
				four++;
			}
			if(king%8 == 0 || ((king%8) - 1) == que %8){
				four++;
			}
			if(king/8 == 0 || ((king/8) - 1) == que/8){
				four++;
			}
			if(king/8 == 7 || ((king/8) + 1) == que/8){
				four++;
			}
			if(four == 4)
				cout << "Stop" << endl;
			else
				cout << "Continue" << endl;
		}
	}
	cout << endl;
	return 0;	
}