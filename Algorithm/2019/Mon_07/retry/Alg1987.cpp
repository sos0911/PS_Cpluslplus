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
int R,C,ans=0;
char cmap[21][21]; // 0-
int dir[][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool inrange(int r, int c){
	return r>=0&&r<R&&c>=0&&c<C? true:false;
}
void find(int r, int c, int visited){
	// visited 내 1의 개수가 정답
	ans=max(ans,__builtin_popcount(visited));
	FOR(i,0,4,1){
		int nextr=r+dir[i][0];
		int nextc=c+dir[i][1];
		if(inrange(nextr,nextc)&&!(visited&(1<<(cmap[nextr][nextc]-'A'))))
			find(nextr,nextc,visited|(1<<(cmap[nextr][nextc]-'A')));
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 26개이므로 bitmask
	cin>>R>>C;
	FOR(i,0,R,1){
		string temp;
		cin>>temp;
		FOR(j,0,C,1)
			cmap[i][j]=temp[j];
	}
	find(0,0,1<<(cmap[0][0]-'A'));
	cout<<ans<<'\n';
	return 0;
}