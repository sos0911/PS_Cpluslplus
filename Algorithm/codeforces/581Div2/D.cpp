// 대회용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
string in;
char ans[2001];
bool solve(int pos){
	// 이번에 결정해야 할 idx
	// (pos-1,pos)
	if(pos==in.size())
		return true;
	if(in[pos-1]>in[pos]){
		if(ans[pos-1]=='0')
			return false;
		else{
			ans[pos]='0';
			if(solve(pos+1))
				return true;
		}
	}
	else{
		if(ans[pos-1]=='1'){
			ans[pos]='1';
			if(solve(pos+1))
				return true;
		}
		else{
			ans[pos]='0';
			if(solve(pos+1))
				return true;
			ans[pos]='1';
			if(solve(pos+1))
				return true;
		}
	}
	return false;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>in;
	// 2로 쪼개서 각 구간의 lcs를 구함
	if(in.size()==1){
		cout<<0<<'\n';
		return 0;
	}
	if(in[0]>in[1]){
		ans[0]='1';
		ans[1]='0';
		solve(2); // idx 2를 결정
	}
	else{
		ans[0]='0', ans[1]='0';
		if(solve(2))
			goto esc;
		ans[0]='0', ans[1]='1';
		cout<<"enter!"<<'\n';
		if(solve(2))
			goto esc;
		ans[0]='1', ans[1]='1';
	}
	esc:
	for(int i=0;i<in.size();i++)
		cout<<ans[i];
	cout<<'\n';
	return 0;
}