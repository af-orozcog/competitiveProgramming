#include<bits/stdc++.h>
using namespace std;

int movesX[] = {0,1,0,-1};
int movesY[] = {1,0,-1,0};
char temp[20];


pair<int,int> simulation(char moves[],int n){
    pair<int,int> ans = {0,0};
    int pos = 0;
    for(int i = 0; i < n;++i){
        if(moves[i] == 'L'){
            --pos;
            if(pos == -1) pos = 3;
        }
        else if(moves[i] == 'R'){
            ++pos;
            if(pos == 4) pos = 0;
        }
        else{
            ans.first += movesX[pos];
            ans.second += movesY[pos];
        }
    }
    return ans;
}


int main(){
    int Xtar,Ytar;
    scanf(" %d %d",&Xtar,&Ytar);
    int n;
    scanf(" %d",&n);
    char moves[n];
    for(int i = 0; i < n;++i){
        scanf(" %s",temp);
        moves[i] = temp[0];
    }
    char changed;
    int where;
    pair<int,int> check;
    for(int i = 0; i < n;++i){
        char original = moves[i];
        moves[i] = 'F';
        check = simulation(moves,n);
        if(check.first == Xtar && check.second == Ytar){
            changed = 'F';
            where = i + 1;
            break;
        }
        moves[i] = 'L';
        check = simulation(moves,n);
        if(check.first == Xtar && check.second == Ytar){
            changed = 'L';
            where = i + 1;
            break;
        }
        moves[i] = 'R';
        check = simulation(moves,n);
        if(check.first == Xtar && check.second == Ytar){
            changed = 'R';
            where = i + 1;
            break;
        }
        moves[i] = original;
    }
    printf("%d ",where);
    if(changed == 'F') puts("Forward");
    else if(changed == 'R') puts("Right");
    else puts("Left");
    return 0;
}
