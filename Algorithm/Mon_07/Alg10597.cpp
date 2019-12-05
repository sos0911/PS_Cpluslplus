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
// bitmask
string in;
int ans[51];
int slen;
bool Find(int idx, int aidx, ll visit){
	// string idx
	// 1-2자리
	if(idx==slen){
		ll temp=((ll)1<<(aidx+1))-2;
		if(temp==visit){
		for(int i=0;i<aidx;i++)
			cout<<ans[i]<<" ";
		cout<<'\n';
		return true;
		}
		return false;
	}
	for(int i=1;i<3;i++){
		if(idx+i>slen)
			return false;
		int temp=stoi(in.substr(idx,i));
		if(!(visit&((ll)1<<temp))){
			ans[aidx]=temp;
			if(Find(idx+i,aidx+1,visit|((ll)1<<temp)))
				return true;
		}
	}
	return false;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>in;
	slen=in.size();
	memset(ans,0,sizeof(ans));
	Find(0,0,0);
	return 0;
}