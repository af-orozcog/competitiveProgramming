#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(){
	string re;
	cin >> re;
	stack<char> let;
	for(int i = 0; i < re.size();++i){
		if(let.size() == 0)
			let.push(re[i]);
		else{
			if(let.top() == re[i])
				let.pop();
			else
				let.push(re[i]);
		}
	}
	stack<char> ans;
	if(let.size() == 0){
		puts("Empty String");
		return 0;
	}
	while(let.size()){
		ans.push(let.top());
		let.pop();
	}
	while(ans.size()){
		printf("%c",ans.top());

		ans.pop();
	}
	puts("");
	return 0;
}