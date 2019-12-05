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
	int n,t,g;
	cin>>n>>t>>g;
	// int로 핸들링
	int stn[6];
	int temp=1;
	FOR(i,0,6,1){
		stn[i]=temp;
		temp*=10;
	}
	queue<int> bfsq;
	bfsq.push(n);
	int ret=0;
	bool possi=false;
	bool visit[100001];
	fill(visit, visit+100001, false);
	visit[n]=true;
	while(!bfsq.empty()){
		if(ret>t)
			goto esc;
		int len=bfsq.size();
		FOR(i,0,len,1){
			int here=bfsq.front();
			bfsq.pop();
			if(here==g){
				possi=true;
				goto esc;
			}
			// A
			if(here+1<=99999&&!visit[here+1]){
				bfsq.push(here+1);
				visit[here+1]=true;
			}
			// B
			int Br=here*2;
			int temp2=stn[to_string(Br).size()-1];
			int temp=Br/temp2; // 가장 앞자리
			int res=Br%temp2;
			if(temp!=0&&Br<=99999){
				Br=(temp-1)*temp2+res;
				if(!visit[Br]){
					bfsq.push(Br);
					visit[Br]=true;
				}
			}
		}
		ret++;
	}
	esc:
	cout<<(possi? to_string(ret):"ANG")<<'\n';
	return 0;
}