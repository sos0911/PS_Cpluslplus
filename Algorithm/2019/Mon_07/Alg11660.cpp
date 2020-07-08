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
int psum[1025][1025];
// psum[i][j] : 앞에서 i행, j열만큼의 합
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	memset(psum,0,sizeof(psum));
	cin>>n>>m;
	FOR(i,0,n,1)
		FOR(j,0,n,1){
		int temp;
		cin>>temp;
		psum[i+1][j+1]=psum[i+1][j]+psum[i][j+1]-psum[i][j]+temp;
	}
	FOR(j,0,m,1){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		cout<<psum[x2][y2]-psum[x1-1][y2]-psum[x2][y1-1]+psum[x1-1][y1-1]<<'\n';
	}
	return 0;
}