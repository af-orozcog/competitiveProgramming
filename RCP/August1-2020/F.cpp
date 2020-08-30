#include<bits/stdc++.h>
#define ld long double
using namespace std;
typedef pair<int,int> pi;
#define EPS 1e-8


pi nums1[13];
pi nums2[13];
int n;

bool canConnect(int i, int j){
    if(nums1[i].first > nums1[j].first)
        swap(i,j);
    if(nums1[i].first == nums1[j].first && nums1[i].second > nums1[j].second)
        swap(i,j);
    for(int k = 0; k < n;++k){
        if(k == i || k == j)continue;
        if(nums1[k].first < nums1[i].first || nums1[k].first > nums1[j].first)
            continue;
        int num1 = (nums1[k].second-nums1[i].second)*(nums1[j].first-nums1[k].first);
        int num2 = (nums1[j].second-nums1[k].second)*(nums1[k].first-nums1[i].first);
        if(num1 == num2){
            if(num1 == 0 && ((nums1[k].second-nums1[i].second) == (nums1[j].second-nums1[k].second)))
                return 0;
            if(num1 == 0 && (nums1[j].first-nums1[k].first) == (nums1[k].first-nums1[i].first) && nums1[k].second > nums1[i].second && nums1[j].second > nums1[k].second)
                return 0;
            else if(num1 != 0)
                return 0;
        }
    }
    for(int k = 0; k < n;++k){
        if(nums2[k].first < nums1[i].first || nums2[k].first > nums1[j].first)
            continue;
        int num1 = (nums2[k].second-nums1[i].second)*(nums1[j].first-nums2[k].first);
        int num2 = (nums1[j].second-nums2[k].second)*(nums2[k].first-nums1[i].first);
        if(num1 == num2){
            if(num1 == 0 && ((nums2[k].second-nums1[i].second) == (nums1[j].second-nums2[k].second)))
                return 0;
            if(num1 == 0 && (nums1[j].first-nums2[k].first) == (nums2[k].first-nums1[i].first) && nums2[k].second > nums1[i].second && nums1[j].second > nums2[k].second)
                return 0;
            else if(num1 != 0)
                return 0;
        }
    }
    return 1;
}


int main(){
    cin >> n;
    for(int i = 0; i < n;++i)
        cin >> nums1[i].first >> nums1[i].second;
    for(int i = 0; i < n;++i)
        cin >> nums2[i].first >> nums2[i].second;
    vector<vector<int>> g(n);
    for(int i = 0; i < n;++i){
        for(int j = i+1; j < n;++j){
            if(canConnect(i,j)){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    vector<int> dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(q.size()){
        int dad = q.front();
        q.pop();
        for(auto va:g[dad]){
            if(dist[va] == -1){
                dist[va] = dist[dad]+1;
                q.push(va);
            }
        }
    }
    cout << dist[n-1] << "\n";
    return 0;
}
