#include <bits/stdc++.h>
using namespace std;
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
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
	int n,k;
	// k번째 수를 구하라.
	cin>>n>>k;
	int lo=1, hi=1e9+1;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		// f(mid) = mid 이하의 값이 배열 내에 몇 개인가?
		int sum=0;
		FOR(i,1,n+1,1)
			if(mid/i==0)
				break;
			else
				sum+=mid/i>=n? n:mid/i;
		if(sum<k)
			lo=mid+1;
		else
			hi=mid-1;
	}
	cout<<lo<<'\n';
	return 0;
}