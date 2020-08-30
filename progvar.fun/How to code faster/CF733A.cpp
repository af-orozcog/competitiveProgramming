#include<bits/stdc++.h>
using namespace std;

int main(){
    string re;
    cin >> re;
    int last = re.size();
    int nums[255] = {0};
    nums['A'] = nums['E'] = nums['I'] = nums['O'] = nums['U'] = nums['Y'] = 1;
    int ans = 1;
    for(int i = re.size()-1; i > -1;--i)
        if(nums[re[i]])
            ans = max(last-i,ans), last = i;
    ans = max(ans,last+1);
    printf("%d\n",ans);
    return 0;
}
