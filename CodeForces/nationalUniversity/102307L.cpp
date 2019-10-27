    #include <bits/stdc++.h>
    using namespace std;
    #define MAX 1000001
     
    int main() {
    	int n;
    	cin >> n;
    	vector<int> arr(n);
    	for (int &x : arr) cin >> x;
    	
    	vector<bool> dp(MAX);
    	vector<int> choice(MAX);
    	vector<vector<int>> mat(MAX, vector<int>(n));
    	dp[0] = true;
    	for (int i = 0; i < n; ++i) {
    		for (int j = 0; j < MAX; ++j) {
    			if (dp[j]) continue;
    			if (j-arr[i] >= 0 and dp[j-arr[i]]) {
    				dp[j] = true;
    				choice[j] = i;
    			}
    		}
    	}
    	for (int i = 1; i < MAX; ++i) {
    		if (!dp[i]) continue;
    		for (int j = 0; j < n; ++j) mat[i][j] = mat[i-arr[choice[i]]][j];
    		mat[i][choice[i]]++;
    	}
    	
    	vector<int> vals;
    	for (int i = 1; i < MAX; ++i) if (dp[i]) vals.push_back(i);
    	
    	int lo = 1, hi = vals.size()-1, ans = -1;
        int loN = 1,hiN = 1000000;
    	for (int i = 0; lo <= hi && i < 29; ++i) {
    		int mid = (lo+hi)>>1;
    		
    		cout << 1 << endl;
    		for (int i = 0; i < n; ++i) {
    			if (i > 0) cout << " ";
    			cout << mat[vals[mid]][i];
    		}
    		cout << endl;
    		cout.flush();
    		string res;
    		cin >> res;
    		if (res[0] == 'g') {
    			lo = mid+1;
                loN = vals[lo];
    		} else if (res[0] == 'y') {
    			ans = vals[mid];
    			break;
    		} else {
    			hi = mid-1;
                hiN = vals[hi];
    		}
           // cout << "lo is " <<  loN << " hi is " << hiN << endl;
            if(loN +1 == hiN){
                ans = loN;
                break;
            }
        //    cout <<"lo is " <<loN << " hi is " <<hiN << endl;
    	}
    	cout << 2 << endl;
    	cout << ans << endl;
    	cout.flush();
    }