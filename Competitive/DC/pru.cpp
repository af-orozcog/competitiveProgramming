#include<iostream>
#include<stdio.h>
#include<cmath>

using namespace std;

long long NLoc[33001];
char Sequ[1000000];
void Build() {
	int i, length, totlen = 0;
	char *s = Sequ;
	NLoc[0] = 0;
	for(i = 1; i <= 33000; i++) {
		sprintf(s, "%d", i);
		length = (int)log10(i)+1;
		s += length;
		totlen += length;
		NLoc[i] = totlen + NLoc[i-1];
	}
}

int main(){
	Build();
	cout << Sequ << endl;
}