#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    scanf(" %d",&t);
    int cas = 1;
    while(t--){
        int n; ll w;
        scanf(" %d %lld",&n,&w);
        ll nums[n];
        for(int i = 0; i < n;++i)
            scanf(" %lld",&nums[i]);
        sort(nums,nums+n);
        ll left[n] = {0};
        ll right[n] = {0};
        int cornersL[n] = {0};
        int cornersR[n] = {0};
        int cornerL = n-1;
        while(cornerL > 0 && w-nums[cornerL]+nums[0] <= (w>>1)){
            --cornerL;
        }
        ++cornerL;
        cornerL %= n;
        int i = 0,j = cornerL;
        cornersL[0] = cornerL;
        while(j != i){
            if(nums[j] > nums[i])
                left[0] += w-nums[j]+nums[i];
            else
                left[0] += nums[i]-nums[j];
            ++j;
            if(j == n) j = 0;
        }
        for(int i = 1; i < n;++i){
            ll less = 0;
            if(cornerL >= i){
                while(cornerL >= i && (w-nums[cornerL]+nums[i] > (w>>1) || cornerL == i)){
                    less += (w-nums[cornerL]+nums[i-1]);
                    ++cornerL;
                    if(cornerL == n) cornerL = 0;
                }
            }
            if(cornerL < i){
                while(nums[i]-nums[cornerL] > (w>>1)){
                    less += (nums[i-1]-nums[cornerL]);
                    ++cornerL;
                }
            }
            if(cornerL > i)
                left[i] = left[i-1] - less + (nums[i]-nums[i-1])*(i+n-cornerL);
            else
                left[i] = left[i-1] - less + (nums[i]-nums[i-1])*(i-cornerL);
            cornersL[i] = cornerL;
        }
        int cornerR = 0;
        while(cornerR < n && w-nums[n-1]+nums[cornerR] <= (w>>1)){
            ++cornerR;
        }
        --cornerR;
        if(cornerR < 0) cornerR += n;
        i = n-1,j = cornerR;
        cornersR[n-1] = cornerR;
        while(j != i){
            if(nums[j] < nums[i])
                right[n-1] += w-nums[i]+nums[j];
            else
                right[n-1] += nums[j]-nums[i];
            --j;
            if(j < 0) j = n-1;
        }
        for(int i = n-2; i > -1;--i){
            ll less = 0;
            if(cornerR <= i){
                while(cornerR <= i && (w-nums[i]+nums[cornerR] > (w>>1) || cornerR == i)){
                    less += (w-nums[i+1]+nums[cornerR]);
                    --cornerR;
                    if(cornerR == -1) cornerR = n-1;
                }
            }
            if(cornerR > i){
                while(nums[cornerR]-nums[i] > (w>>1)){
                    less += (nums[i]-nums[cornerR]);
                    --cornerR;
                }
            }
            if(cornerR < i)
                right[i] = right[i+1] - less + (nums[i+1]-nums[i])*(n-i+cornerR);
            else
                right[i] = right[i+1] - less + (nums[i+1]-nums[i])*(cornerR-i);
            cornersR[i] = cornerR;
        }
        ll ans = LLONG_MAX;
        for(int i = 0; i < n;++i){
            ll less = 0;
            if(cornersL[i] == cornersR[i]){
                if(cornersL[i] > i){
                    less = w-nums[cornersL[i]]+nums[i];
                }
                else
                    less = nums[i]-nums[cornersL[i]];
            }
            ans = min(ans,left[i]+right[i]-less);

        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
    return 0;
}
