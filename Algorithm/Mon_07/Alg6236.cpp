#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	int in[n];
	ll lo=-1,hi=0;
	FOR1(i,n){
		cin>>in[i];
		lo=max(lo,(ll)in[i]);
		hi+=in[i];
	}
	hi++;
	while(lo<=hi){
		// f(mid)=금액 mid로 가능한 최소 인출 수
		// 각 lo는 답이 되고 hi는 불가능하므로 hi++해야 함
		ll mid=(hi+lo)/2;
		int nofo=1;
		ll left=mid;
		FOR1(i,n)
			if(left>=in[i])
				left-=in[i];
			else{
				nofo++;
				left=mid;
				left-=in[i];
			}
		//cout<<"lo : "<<lo<<" hi : "<<hi<<'\n';
		//cout<<"mid : "<<mid<<" nofo : "<<nofo<<'\n';
		if(nofo>m)
			lo=mid+1;
		else
			hi=mid-1;
	}
	cout<<lo<<'\n';
	return 0;
}