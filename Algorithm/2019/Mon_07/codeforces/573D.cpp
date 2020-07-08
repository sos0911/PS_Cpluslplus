#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n;
	cin>>n;
	ll in[n+1];
	FOR(i,0,n,1)
		cin>>in[i];
	in[n]=2e9;
	sort(in,in+n);
	// 조건 2개(0이 2개 이상, 0밖에 없음)
	if(upper_bound(in,in+n,0)-in>=2||(in[0]==0&&in[n-1]==0)){
			cout<<"cslnb"<<'\n';
			return 0;
		}
	ll stn=in[0], s=1, acc=0, sum=0; // 기준수, stn과 같은 개수, 2개중복 누적값
	FOR(i,0,n,1)
		sum+=in[i]-i;
	FOR(i,1,n+1,1){
		if(in[i]==stn)
			s++;
		else{
			if(s==2){ // 2개 pair개수가 2개 이상이거나 2개 pair 이전에 seq 존재
				if((++acc)>=2||in[i-3]==in[i-1]-1){
				cout<<"cslnb"<<'\n';
			return 0;
				}
			}
			if(s>2){ // 같은게 3개이상
				cout<<"cslnb"<<'\n';
			return 0;
			}
			s=1;
			stn=in[i];
		}
	}
	cout<<(sum%2==1? "sjfnb":"cslnb")<<'\n';
	return 0;
}