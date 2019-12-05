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
int q,n;
int in[201]; // 0부터
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>n;
		int sti;
		for(int j=0;j<n;j++){
			cin>>in[j];
			if(in[j]==1)
				sti=j;
		}
		// c
		bool possi=true, possi2=true;
		for(int k=sti;k<sti+n-1;k++)
			if(in[k%n]+1!=in[(k+1)%n]){
				possi=false;
				break;
			}
		if(!possi)
		for(int k=sti;k>sti-(n-1);k--)
			if(in[k<0? k+n:k]+1!=in[k-1<0? k-1+n:k-1]){
				possi2=false;
				break;
			}
		cout<<(possi||possi2? "YES":"NO")<<'\n';
	}
	return 0;
}