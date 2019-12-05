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
int q;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>q;
	for(int i=0;i<q;i++){
		ll a,b;
		cin>>a>>b;
		ll rep=b, cycle=0;
		bool visit[10]={};
		while(rep<=a&&!visit[rep%10]){
			cycle+=rep%10;
			visit[rep%10]=true;
			rep+=b;
		}
		if(rep>a)
			cout<<cycle<<'\n';
		else{
			// 주기 찾아냄
			rep-=b;
			cycle*=a/rep;
			a%=rep;
			ll rep2=b;
			while(rep2<=a){
				cycle+=rep2%10;
				rep2+=b;
			}
			cout<<cycle<<'\n';
		}
	}
	return 0;
}