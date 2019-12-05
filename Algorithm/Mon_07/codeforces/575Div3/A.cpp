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
	int q;
	cin>>q;
	FOR(i,0,q,1){
		int n,k;
		cin>>n>>k;
		int in[n];
		int cnt=0; // 홀수의 개수
		FOR(j,0,n,1){
			cin>>in[j];
			cnt+=in[j]%2;
		}
		if(cnt<k||cnt%2!=k%2)
			cout<<"NO"<<'\n';
		else{
			cout<<"YES"<<'\n';
			int rep=k;
			FOR(j,0,n,1){
				if(rep==1)
					break;
				if(in[j]%2){
					cout<<j+1<<" ";
					rep--;
				}
			}
			cout<<n<<'\n';
		}
	}
	return 0;
}