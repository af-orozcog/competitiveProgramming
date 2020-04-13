#include<bits/stdc++.h>
using namespace std;

int which1(int val1,int val2, int val3, int val4){
    //cout << "wtf is "<< val1 << " = " << val3 << " , " << val2 << " = " << val4 << "\n";
    if(val1 == val3 && val2 == val4)
        return 4;
    if(val1 == val3 && val2 != val4)
        return 3;
    if(val1 != val3 && val2 != val4)
        return 2;
    return 1;
}
int which2(int val1, int val2){
    if(val1 == val2) return 4;
    else return 2;
}

void printAr(vector<int> &nums){
    for(int i = 1; i < nums.size();++i)printf("%d ",nums[i]);
    puts("");
}

int main(){
    int t,b;
    scanf(" %d %d",&t,&b);
    while(t--){
        vector<int> nums(b+1);
        for(int i = 1,j = b; i <= (b>>1);++i,--j){
            printf("%d\n",i);
            fflush(stdout);
            int re;scanf(" %d",&re);
            nums[i] = re;
            printf("%d\n",j);
            fflush(stdout);
            scanf(" %d",&re);
            nums[j] = re;
        }
        vector<int> dif((b/5)>>1,-1);
        vector<int> eq((b/5)>>1,-1);
        for(int i = 1,j = b,k = 0; i < (b>>1);i+=5,j-=5,++k){
            for(int w = 0; w < 5;++w){
                if(nums[i+w] != nums[j-w]) dif[k] = w;
                if(nums[i+w] == nums[j-w]) eq[k] = w;
            }
        }
        vector<int> two,one;
        for(int i = 0; i < dif.size();++i){
            if(eq[i] == -1 || dif[i] == -1) one.push_back(i);
            else two.push_back(i);
        }
        //cout << "one is: "<<one.size() << "\n";
        //for(auto va:two) printf("%d ",va);
        //puts("");
        int pivot = -1;
        if(two.size()) pivot = two.back(),two.pop_back();
        vector<pair<int,int>> seen;
        vector<pair<int,int>> addi;
        for(int j = 1;(two.size() || one.size()) && b != 10;++j){
            if(j%10 == 1 && pivot != -1){
                printf("%d\n",(pivot*5)+dif[pivot]+1);
                fflush(stdout);
                int resp1,resp2;
                scanf(" %d",&resp1);
                printf("%d\n",(pivot*5)+eq[pivot]+1);
                fflush(stdout);
                scanf(" %d",&resp2);
                int cas = which1(nums[(pivot*5)+dif[pivot]+1],nums[(pivot*5)+eq[pivot]+1],resp1,resp2);
                int where = (pivot*5)+1;
                for(int i = where,j = b- where+1; i < where+5;++i,--j){
                    if(cas == 2){
                        nums[i] = (nums[i]+1)%2;
                        nums[j] = (nums[j]+1)%2;
                    }
                    if(cas == 3){
                        swap(nums[i],nums[j]);
                        nums[i] = (nums[i]+1)%2;
                        nums[j] = (nums[j]+1)%2;
                    }
                    if(cas == 1)
                        swap(nums[i],nums[j]);
                }
                addi.push_back({cas,seen.size()});
                ++j;
            }
            else if(two.size()){
                int see = two.back();
                two.pop_back();
                printf("%d\n",(see*5)+dif[see]+1);
                fflush(stdout);
                int resp1,resp2;
                scanf(" %d",&resp1);
                printf("%d\n",(see*5)+eq[see]+1);
                fflush(stdout);
                scanf(" %d",&resp2);
                int moves = which1(nums[(see*5)+dif[see]+1],nums[(see*5)+eq[see]+1],resp1,resp2);
                seen.push_back({see,moves});
                ++j;
            }
            else{
                int see = one.back();
                one.pop_back();
                int ask;
                if(dif[see] == -1) ask = eq[see];
                else ask = dif[see];
                int resp;
                printf("%d\n",(see*5)+ask+1);
                fflush(stdout);
                scanf(" %d",&resp);
                int moves = which2(nums[(see*5)+ask+1],resp);
                seen.push_back({see,moves});
            }
        }
        for(int k = 0; k < seen.size();++k){
            if(seen[k].second == 4) continue;
            int where = (seen[k].first*5)+1;
            for(int i = where,j = b- where+1; i < where+5;++i,--j){
                if(seen[k].second == 2){
                    nums[i] = (nums[i]+1)%2;
                    nums[j] = (nums[j]+1)%2;
                }
                if(seen[k].second == 3){
                    swap(nums[i],nums[j]);
                    nums[i] = (nums[i]+1)%2;
                    nums[j] = (nums[j]+1)%2;
                }
                if(seen[k].second == 1)
                    swap(nums[i],nums[j]);
            }
        }
        //puts("before shit happens");
        //printAr(nums);
        //puts("wtf is addi");
        //for(auto va: addi) printf("%d %d ",va.first,va.second);
        //puts("");
        for(int w = 0; w < addi.size();++w){
            for(int k = 0; k < addi[w].second && addi[w].first != 4;++k){
                int where = (seen[k].first*5)+1;
                for(int i = where,j = b- where+1; i < where+5;++i,--j){
                    if(addi[w].first == 2){
                        nums[i] = (nums[i]+1)%2;
                        nums[j] = (nums[j]+1)%2;
                    }
                    if(addi[w].first == 3){
                        swap(nums[i],nums[j]);
                        nums[i] = (nums[i]+1)%2;
                        nums[j] = (nums[j]+1)%2;
                    }
                    if(addi[w].first == 1){
          //              cout << "entro aqui???" << endl;
                        swap(nums[i],nums[j]);
                    }
                }
            }
        }
        for(int i = 1; i <= b;++i) printf("%d",nums[i]);
        puts("");
        fflush(stdout);
        char what;
        scanf(" %c",&what);
        if(what == 'N') return 0;
    }
    return 0;
}
