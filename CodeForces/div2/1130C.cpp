    /**
    * I'm sorry I was an idiot
    */
    #include<iostream>
    #include<cstring>
    #include<climits>
    #include<string>
    #include<cmath>
    #include<vector>
    //#define min(x,y)(x < y? x:y)
    //#define abs(x)(x < 0?-x:x)
     
    using namespace std;
     
    bool map[50][50];
    int N;
     
    int dix[] = {0,0,1,-1};
    int diy[] = {1,-1,0,0};
    int dis = INT_MAX;
     
    int xA,yA;
    vector<pair<int,int>> con;
     
    void connected(int x, int y){
    	if(x < 0 || x >= N || y < 0 || y >= N)
    		return;
    	if(map[x][y] == false)
    		return;
    	map[x][y] = false;
    	con.push_back(make_pair(x,y));
    	for(int i = 0; i < 4;++i){
    		connected(x+dix[i],y+diy[i]);
    	}
    }
     
    void closest(int x, int y, int xto,int yto){
    	if(x < 0 || x >=N || y < 0 || y >= N){
    		return;
    	}
    	if(map[x][y] == false)
    		return;
    	map[x][y] = false;
    	int mine = abs(x-xto) + abs(y-yto);
    	if(mine < dis){
    		dis = mine;
    		xA = x;
    		yA = y;
    	}
    	for(int i = 0; i < 4;++i){
    		closest(x+dix[i],y+diy[i],xto,yto);
    	}
    }
     
    int main(){
    	memset(map,false,sizeof(map));
    	cin >> N;
    	int x1,y1,x2,y2;
    	cin >> x1 >> y1 >> x2 >> y2;
    	for(int i = 0; i < N;++i){
    		string toRead;
    		cin >> toRead;
    		for(int j = 0; j < N;++j){
    			if(toRead[j] == '0')
    				map[i][j] = true;
    		}
    	}
    	--x1;--y1;--x2;--y2;
    	if(x1 == x1 && y1 == y2){
    		cout << 0 << endl;
    		return 0;
    	}
    	bool copy[50][50];
    	memcpy(copy,map,sizeof(copy));
    	connected(x2,y2);
    	memcpy(map,copy,sizeof(map));
    	int ans = INT_MAX;
    	for(int i = 0; i < con.size();++i){
    		closest(x1,y1,con[i].first,con[i].second);
    		int cost = xA - con[i].first;
    		cost *= cost;
    		cost += (yA-con[i].second)*(yA-con[i].second);
    		ans = min(cost,ans);
    		memcpy(map,copy,sizeof(map));
            dis = INT_MAX;
    	}
    	cout << ans << endl;
    	return 0;
    }