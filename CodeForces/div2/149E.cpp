#include<bits/stdc++.h>
using namespace std;

#define INF 1e9
const int MAXN = 1e5+5;
int a1[MAXN],t1[4*MAXN],a2[MAXN],t2[4*MAXN];
//funcion para construir el segtree
void build1(int v,int tl,int tr){
	if(tl==tr)
		t1[v]=a1[tl];
	else{
		int tm = (tl+tr)/2;
		build1(v*2,tl,tm);
		build1(v*2+1,tm+1,tr);
		t1[v]=max(t1[v*2],t1[v*2+1]);

	}
}
//funcion para realizar range query.
int query1(int v, int tl, int tr, int l, int r){
	if(l>r)
		return -INF;
	if(tl==l&&tr==r){
		return t1[v];
	}
	int tm = (tl+tr)/2;
	return max(query1(v*2,tl,tm,l,min(r,tm)),query1(v*2+1,tm+1,tr,max(tm+1,l),r));
}
void build2(int v,int tl,int tr){
	if(tl==tr)
		t2[v]=a2[tl];
	else{
		int tm = (tl+tr)/2;
		build2(v*2,tl,tm);
		build2(v*2+1,tm+1,tr);
		t2[v]=min(t2[v*2],t2[v*2+1]);

	}
}
//funcion para realizar range query.
int query2(int v, int tl, int tr, int l, int r){
	if(l>r)
		return INF;
	if(tl==l&&tr==r){
		return t2[v];
	}
	int tm = (tl+tr)/2;
	return min(query2(v*2,tl,tm,l,min(r,tm)),query2(v*2+1,tm+1,tr,max(tm+1,l),r));
}


vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
     vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string &s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

pair<int,int> binarySearch(string &see, vector<int> &SA, string &look){
    pair<int,int> ans = {-1,-1};
    int lo = 0, hi = SA.size()-1, ans1 = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        int comp = look.compare(0,look.size(),see,SA[mid],min((int)look.size(),(int)SA.size()-SA[mid]));
        if(comp == 0){
            ans1 = mid;
            hi = mid - 1;
        }
        else if(comp < 0)
            hi = mid - 1;
        else lo = mid + 1;
    }
    ans.first = ans1;
    lo = 0, hi = SA.size()-1, ans1 = -1;
    while(lo <= hi){
        int mid = (lo+hi)>>1;
        int comp = look.compare(0,look.size(),see,SA[mid],min((int)look.size(),(int)SA.size()-SA[mid]));
        if(comp == 0){
            ans1 = mid;
            lo = mid + 1;
        }
        else if(comp < 0)
            hi = mid - 1;
        else lo = mid + 1;
    }
    ans.second = ans1;
    return ans;
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string re;
    cin >> re;
    vector<int> SA = suffix_array_construction(re);
    re.pop_back();
    for(int i = 0; i < SA.size();++i)
        a1[i] = a2[i] = SA[i];
    build1(1,0,(int)SA.size()-1);
    build2(1,0,(int)SA.size()-1);
    int n;
    cin >> n;
    int ans = 0;
    while(n--){
        string see;
        cin >> see;
        if((int)see.size() == 1) continue;
        for(int i = 1; i <= see.size()-1;++i){
            string one = see.substr(0,i);
            string two = see.substr(i,see.size());
            pair<int,int> see1 = binarySearch(re,SA,one);
            if(see1.first == -1) break;
            pair<int,int> see2 = binarySearch(re,SA,two);
            if(see2.first == -1) continue;
            int val1 = query2(1,0,(int)SA.size()-1,see1.first,see1.second);
            int val2 = query1(1,0,(int)SA.size()-1,see2.first,see2.second);
            if(val1 + (int)one.size()-1 < val2){
                ++ans;break;
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
