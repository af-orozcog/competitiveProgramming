#include<bits/stdc++.h>
#define ll long long
using namespace std;

int multiIte(int a, int b){
    int ans = 0;
    int temp = b;
    while(a){
        if(a&1) ans += temp;
        temp <<= 1;
        a >>= 1;
    }
    return ans;
}

string mov(int register1, int register2, int shift){
    return "MOV R" + to_string(register1) + ", R" + to_string(register2) + ", LSL #" + to_string(shift);
}

string add(int register1, int register2, int register3, int shift){
    string ans = "ADD R";
    ans += to_string(register1);
    ans += ", R";
    ans += to_string(register2);
    ans += ", R";
    ans += to_string(register3);
    ans += ", LSL #";
    ans += to_string(shift);
    return ans;
    //return "ADD R" + to_string(register1)+ ", R"+ to_string(register2) + ", R"+ to_string(register3)+ ", R LSL #" + to_string(shift);
}
string END = "END";

vector<string> answer(ll a){
    int left = 0;
    vector<string> send;
    while(a){
        if(a&1)
            send.push_back(add(1,1,0,left));
        ++left;
        a >>= 1;
    }
    send.push_back(mov(0,1,0));
    send.push_back(END);
    return send;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<string> toPrint = answer(n);
        for(auto &va:toPrint)
            cout << va << "\n";
    }
    return 0;
}
