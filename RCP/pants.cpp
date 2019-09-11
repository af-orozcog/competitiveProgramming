#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<queue>

using namespace std;

vector<string> byDot(string &line){
	string add = "";
	vector<string> ans; 
	for(int i = 0; i <line.size();++i){
		if(line[i] == ' '){
			ans.push_back(add);
			add = "";
		}
		else
			add += line[i];
	}
	ans.push_back(add);
	return ans;
}

int bfs(int s,int d, vector<vector<int>> &graph){
	queue<int> q;
	q.push(s);
	while(q.size()){
		int f = q.front();q.pop();
		for(int i = 0; i < graph[f].size();++i){
			if(graph[f][i] == d)
				return true;
			q.push(graph[f][i]);
		}
	}
	return false;
}

int main(){
	//sett();
	int n,m;
	cin >>n >>m;
	cin.ignore();
	int num = 0;
	vector<vector<int>> graph(200);
	map<string,int> tr;
	while(n--){
		string re;
		//cout << re << endl;
		getline(cin,re);
		vector<string> vals = byDot(re);
		int a,b;
		if(tr.count(vals[0]) == 0){
			tr[vals[0]] = num;
			a = num++;
		}
		else
			a = tr[vals[0]];
		if(tr.count(vals[vals.size()-1]) == 0){
			tr[vals[vals.size()-1]] = num;
			b = num++;
		}
		else
			b = tr[vals[vals.size()-1]];
		graph[b].push_back(a);
	}
	while(m--){
		int a,b;
		string re;
		getline(cin,re);
		vector<string> vals = byDot(re);
		if(tr.count(vals[0])== 0 || tr.count(vals[vals.size()-1]) == 0){
			puts("Pants on Fire");
			continue;
		}
		a = tr[vals[0]];
		b = tr[vals[vals.size()-1]];
		if(bfs(b,a,graph))
			puts("Fact");
		else if(bfs(a,b,graph))
			puts("Alternative Fact");
		else
			puts("Pants on Fire");
	}
	return 0;
}