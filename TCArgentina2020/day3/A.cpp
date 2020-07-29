#include<bits/stdc++.h>
using namespace std;

char vowels[] = {'a','e','i','o','u'};


class  EllysPronunciation{
    public:
    int getGood(vector <string> words){
        int ans = 0;
        for(auto &va:words){
            vector<int> coun(255,0);
            for(auto ve:va)
                ++coun[ve];
            int sum = 0;
            for(int i = 0; i < 5;++i)
                sum += coun[vowels[i]];
            if(sum*2 == (int)va.size())
                ++ans;
        }
        return ans;
    }
};

int main(){
    return 0;
}
