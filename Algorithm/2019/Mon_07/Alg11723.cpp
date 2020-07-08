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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int m;
	cin>>m;
	string order;
	int visit=0, num;
	FOR(i,0,m,1){
		cin>>order;
		if(order=="add"){
			cin>>num;
			if(!(visit&(1<<num)))
				visit|=(1<<num);
		}
		else if(order=="remove"){
			cin>>num;
			if(visit&(1<<num))
				visit-=(1<<num);
		}
		else if(order=="check"){
			cin>>num;
			cout<<(visit&(1<<num)? 1:0)<<'\n';
		}
		else if(order=="toggle"){
			cin>>num;
			visit^=(1<<num); // 0001000.. 11=0 01,10=1 00=0
		}
		else if(order=="all"){
			visit=(1<<21)-1;
			
		}
		else
			visit=0;
	}
	return 0;
}