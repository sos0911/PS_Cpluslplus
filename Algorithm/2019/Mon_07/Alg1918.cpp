#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
stack<int> cont;
char stn[][2]={{'+','-'},{'*','/'}};
bool pcheck(char tar){		
	if(cont.empty()||cont.top()=='(')
		return true;
	else{
		int tari, topi;
	FOR(i,0,2,1)
		FOR(j,0,2,1){
			if(stn[i][j]==tar)
				tari=i;
			if(stn[i][j]==cont.top())
				topi=i;
	}
		if(topi<tari)
			return true;
		else
			return false;
	}
}
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	string input, ret="";
	ret.reserve(101);
	cin>>input;
	int len=input.size();
	FOR(i,0,len,1){
		if(input[i]>='A'&&input[i]<='Z')
			ret+=input[i];
		else if(input[i]=='(')
			cont.push(input[i]);
		else if(input[i]==')'){ // '('까지 모두 꺼낸다.
				while(cont.top()!='('){
					ret+=cont.top();
					cont.pop();
				}
			cont.pop(); // '('까지 꺼내준다.
		}
		else{ // 연산기호.
			if(pcheck(input[i])) // push 조건 check
				cont.push(input[i]);
			else{
				while(!pcheck(input[i])){
					ret+=cont.top();
					cont.pop();
				}
				cont.push(input[i]);	
			}
		}
	}
	while(!cont.empty()){
		ret+=cont.top();
		cont.pop();
	}
	cout<<ret<<'\n';
	return 0;
}