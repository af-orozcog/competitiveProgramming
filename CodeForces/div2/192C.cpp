    #include<iostream>
    #include<string>
    #include<cstring>
    #define max(x,y)(x > y? x:y)
     
    using namespace std;
     
    int dp[500000][26];
    string vals[500000];
    int n;
     
    int solve(int p, int l){
    	if(p == n)
    		return -1000000000;
    	if(dp[p][l] != -1)
    		return dp[p][l];
    	int ans = -1000000000;
    	if(vals[p][vals[p].size()-1] - 'a' == l)
    		ans = (int)vals[p].size();
    	//cout <<"word " <<vals[p] <<" " <<p<<endl;
    	char las = vals[p][vals[p].size()-1];
    	for(int i = p+1;i < n;++i){
    		char le = vals[i][0];
    		if(le == las){
    			//cout << "le " << le << " " << "las " << las;
    			//cout << " "<<vals[i] << " first is "<<vals[i][0]<<endl;
    			ans = max(ans,solve(i,l)+(int)vals[p].size());
    		}
    	}
    	return dp[p][l] =ans;
    }
     
    int main(){
    	memset(dp,-1,sizeof(dp));
        ios::sync_with_stdio(0);
        cin.tie(0);
    	cin >> n;
    	for(int i = 0; i < n;++i){
    		string re;
    		cin >> re;
    		vals[i] = re;
    	}
    	int ans =0;
    	for(int i = 0; i < n;++i){
    		int f = vals[i][0] - 'a';
    		ans = max(ans,solve(i,f));
    		//cout <<"!!!!!!!!!!!!!!!!!!!!!!!!" <<ans << endl;
    	}
    	cout << ans<<"\n";
    	return 0;
    }