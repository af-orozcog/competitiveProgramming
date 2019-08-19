#include<iostream> 
using namespace std;

int main(){
	while(true){
		int que;
		cin >> que;
		if(que == 0)
			return 0;
		int xdiv,ydiv;
		cin >> xdiv >> ydiv;
		while(que--){
			int X,Y;
			cin >> X >> Y;
			if(X == xdiv || Y == ydiv)
				cout << "divisa" << endl;
			else if(X > xdiv && Y > ydiv)
				cout << "NE" << endl;
			else if(X < xdiv && Y > ydiv)
				cout << "NO" << endl;
			else if(X > xdiv && Y < ydiv)
				cout << "SE" << endl;
			else
				cout << "SO" << endl;
		}
	}
	return 0;
}