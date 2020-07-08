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
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,p;
	cin>>n>>p;
	stack<int> cont[7]; // 1-
	// 기타 줄은 6개. 문제 잘못읽고 뇌절 ㅅㅂ
	// 프랫은 최대 p
	// tc:O(n)
	int ret=0;
	FOR(i,0,n,1){
		int a,b;
		cin>>a>>b;
		while(!cont[a].empty()&&cont[a].top()>b){ // 같거나 작게 될 때까지 돌림
			cont[a].pop();
			ret++;
		}
		if(cont[a].empty()||cont[a].top()!=b){
			cont[a].push(b);
			ret++;
		}
	}
	cout<<ret<<'\n';
	return 0;
}