#include<iostream>
#include<stack>
#include<string>
#define ll long long
#define mod(x,y)(x%y < 0? (x%y + y):x%y)

using namespace std;
typedef pair<ll,ll> pii;


ll gcd(ll a, ll b){
	return b == 0? a: gcd(b,mod(a,b));
}

ll lcm(ll a, ll b){
	return (a/gcd(a,b))*b;
}

pii sum(pii &a, pii &b){
	ll fi = a.first*(lcm(a.second,b.second)/a.second) + b.first*(lcm(a.second,b.second)/b.second);
	return {fi,lcm(a.second,b.second)};
}
pii sub(pii &a, pii &b){
	ll fi = a.first*(lcm(a.second,b.second)/a.second) - b.first*(lcm(a.second,b.second)/b.second);
	return {fi,lcm(a.second,b.second)};
}

int main(){
	string re;
	while(getline(cin,re)){
		stack<pii> vals;
		stack<char> ope;
		pii ans = {0,1};
		pii temp = {0,0};
		char op = '+';
		bool nume = true;
		for(int i = 0; i < re.size();++i){
			if(re[i] == '('){
				vals.push(ans);
				ans = {0,1};
				ope.push(op);
				op = '+'; 
			}
			else if(re[i] == ')'){
			    char check = ope.top();
			    ope.pop();
				if(check == '+'){
					pii add = vals.top();
					vals.pop();
					ans = sum(add,ans); 
				}
				else{
					pii les = vals.top();
					vals.pop();
					ans = sub(les,ans);
				}
			}
			else if(re[i] <= '9' && re[i] >= '0'){
				string num = "";
				num += re[i];
				++i;
				while(i < re.size() && re[i] <= '9' && re[i] >= '0'){num += re[i];++i;}
				--i;
				if(nume){
					temp.first = (ll)stoi(num);
					nume = false;
				}
				else{
					nume = true;
					temp.second = (ll)stoi(num);
					if(op == '+')
						ans = sum(ans,temp);
					else
						ans = sub(ans,temp);
				}
			}
			else if(re[i] == '+' || re[i] == '-')
				op = re[i];
		}
		ll redu = gcd(ans.first,ans.second);
		printf("%lld/%lld\n",ans.first/redu,ans.second/redu);
	}
}