#include<bits/stdc++.h>
using namespace std;

int temp[100000];

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n;
        scanf(" %d",&n);
        vector<int> nums;
        for(int i = 0; i < n;++i){
            int temp;
            scanf(" %d",&temp);
            if(nums.size() && nums.back() == temp) continue;
            nums.push_back(temp);
        }
        int ans = 0;
        vector<int> lastF(4,-1);
        if((int)nums.size() > 1 && nums[1] >= nums[0])
            lastF[0] = nums[0],temp[0] = 0;
        else
            lastF[3] = nums[0],temp[0] = 3;
        for(int i = 1; i < nums.size();++i){
            int index = -1;
            for(int j = 0; j < 4 && index == -1;++j)
                if(lastF[j] == nums[i])
                    index = j;
            if(index != -1){
                temp[i] = index; continue;
            }
            if(nums[i] < nums[i-1] && temp[i-1] == 0)
                ++ans;
            if(nums[i] > nums[i-1] && temp[i-1] == 3)
                ++ans;
            if(i != n-1 && nums[i] < nums[i+1] && nums[i-1] > nums[i])
                lastF[0] = nums[i], temp[i] = 0;
            else if(i != n-1 && nums[i] > nums[i+1] && nums[i-1] < nums[i])
                lastF[3] = nums[i],temp[i] = 3;
            else{
                if(nums[i] < nums[i-1])
                    lastF[(((-temp[i-1]-1)%4)+4)%4] = nums[i], temp[i] = (((temp[i-1]-1)%4)+4)%4;
                else
                    lastF[(temp[i-1]+1)%4] = nums[i], temp[i] = (temp[i-1]+1)%4;
            }
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
    return 0;
}
