#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// https://m.blog.naver.com/kks227/220781851401
	int n,k;
	cin>>n>>k;
	// 2글자-20글자
	queue<int> cont[21]; // 0-20
	// 각 큐에는 각 요소의 index 저장
	// 각 요소마다 최대 추가 1번, 최대 pop 1번 -> tc : O(N)
	ll ans=0;
	FOR(i,0,n,1){
		string in;
		cin>>in;
		int len=in.size();
		while(!cont[len].empty()&&i-cont[len].front()>k)
			cont[len].pop();
		ans+=cont[len].size();
		cont[len].push(i);
	}
	cout<<ans<<'\n';
	return 0;
}