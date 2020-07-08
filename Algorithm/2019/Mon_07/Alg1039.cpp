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
const int MAXD=1000001;
int stn[7];
int cswap(int tar,int len,int ai,int bi){
	int a=(tar%stn[len-ai])/stn[len-ai-1];
	tar-=a*stn[len-ai-1];
	int b=(tar%stn[len-bi])/stn[len-bi-1];
	tar-=b*stn[len-bi-1];
	tar+=a*stn[len-bi-1];
	tar+=b*stn[len-ai-1];
	return tar;
}
int main(){
	//cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int temp=1;
	FOR(i,0,8,1){
		stn[i]=temp;
		temp*=10;
	}
	// queue<int>
	// queue에 들어가는 수는 실제로 <=1000000
	queue<int> bfsq;
	bool visit[MAXD];
	bfsq.push(n);
	visit[n]=true;
	int rep=0; 
	bool check=false;
	while(!bfsq.empty()){
		fill(visit,visit+MAXD,false); // visit 초기화
		int len=bfsq.size();
		FOR(i,0,len,1){
			int here=bfsq.front();
			bfsq.pop();
			// 노드이동
			int hlen=to_string(here).size();
			// 모든 경우의 수 시도
			int temp;
			FOR(j,0,hlen,1)
				FOR(k,j+1,hlen,1){
					temp=cswap(here,hlen,j,k); // j번째 idx, k번째 idx swap
				if(to_string(temp).size()==hlen&&!visit[temp]){
					bfsq.push(temp);
					visit[temp]=true;
				}
			}
		}
		rep++;
		if(rep==k){
			check=true;
			break;
		}
	}
	int ret=-1;
	if(check)
		while(!bfsq.empty()){
			ret=max(ret,bfsq.front());
			bfsq.pop();
		}
	cout<<ret<<'\n';
	return 0;
}