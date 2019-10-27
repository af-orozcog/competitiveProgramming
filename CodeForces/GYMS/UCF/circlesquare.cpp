#include<bits/stdc++.h>

using namespace std;


int main(){
	int x,y,r;
	scanf(" %d %d %d",&x,&y,&r);
	int tx,ty,s;
	scanf(" %d %d %d",&tx,&ty,&s);
	pair<int,int> rXC = {x-r,x+r};
	pair<int,int> rYC = {y-r,y+r};
	pair<int,int> rXS = {tx,tx+s};
	pair<int,int> rYS = {ty,ty+s};
	if(rXC.second < rXS.first || rXC.first > rXS.second || 
		rYS.first > rYC.second || rYS.second < rYC.first){
		puts("0");
		return 0;
	}
	if(rXC.first >= rXS.first && rXC.second <= rXS.second && 
		rYC.first >= rYS.first && rYC.second <= rYS.second){
		puts("2");
		return 0;
	}
	pair<int,int> xIntersect,yIntersect;
	xIntersect.first = max(rXC.first,rXS.first);
	xIntersect.second = min(rXC.second,rXS.second);
	yIntersect.first = max(rYC.first,rYS.first);
	//cout << rYC.first << " " << rYS.first <<" " <<max(rYC.first,rYS.first) << endl;
	yIntersect.second = min(rYS.second,rYC.second);
	int inside = 0;
	int touches = 0;
	for(int i = xIntersect.first; i <= xIntersect.second && !inside;++i){
		if((i-x)*(i-x) + (ty-y)*(ty-y) < r*r)
			inside = 1;
		else if((i-x)*(i-x) + (ty-y)*(ty-y) == r*r)
			touches = 1;
		if((i-x)*(i-x) + (ty+s-y)*(ty+s-y) < r*r)
			inside = 1;
		else if((i-x)*(i-x) + (ty+s-y)*(ty+s-y) == r*r)
			touches = 1;
	}
	for(int i = yIntersect.first; i <= yIntersect.second && !inside;++i){
		if((i-y)*(i-y) + (tx-x)*(tx-x) < r*r)
			inside = 1;
		else if((i-y)*(i-y) + (tx-x)*(tx-x) == r*r)
			touches = 1;
		if((i-y)*(i-y) + (tx+s-x)*(tx+s-x) < r*r)
			inside = 1;
		else if((i-y)*(i-y) + (tx+s-x)*(tx+s-x) == r*r)
			touches = 1;
	}
	if(inside)
		puts("2");
	else if(touches)
		puts("1");
	else
		puts("0");
	return 0;
}