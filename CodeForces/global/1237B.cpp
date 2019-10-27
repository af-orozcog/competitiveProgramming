    /**
    * ALL I DO IS WRONG
    */
    #include<bits/stdc++.h>
    #define ll long long
     
    using namespace std;
    typedef pair<ll,ll> pii;
    typedef vector<ll> vi;
    typedef vector<vector<ll>> vii;
    typedef vector<vector<pii>> vpii;
     
    int main(){
    	int n;
    	scanf(" %d",&n);
    	queue<int> q;
    	for(int i = 0; i < n;++i){
    		int va;scanf(" %d",&va);
    		q.push(va);
    	}	
    	vector<bool> fined(n,false);
    	int ans = 0;
    	for(int i = 0; i < n;++i){
    		int va;scanf(" %d",&va);
    		if(va == q.front())
    			q.pop();
    		else{
    			fined[va] = true;
    			++ans;
    		}
            while(q.size() && fined[q.front()])
                q.pop();
    	}
    	printf("%d\n",ans);
    	return 0;
    }