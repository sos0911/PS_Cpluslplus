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
	int n;
	cin>>n;
	int in[n];
	int lo=0,hi=-1;
	int minv=1e9;
	FOR1(i,n){
		cin>>in[i];
		hi=max(hi,in[i]);
		minv=min(minv,in[i]);
	}
	hi++;
	int m;
	cin>>m; // limit
	while(hi-lo!=1){
		int mid=(lo+hi)/2;
		ll sum=0;
		FOR1(i,n)
			sum+=min(mid, in[i]);
		if(sum>m)
			hi=mid;
		else
			lo=mid;
	}
	cout<<lo<<'\n';
	return 0;
}