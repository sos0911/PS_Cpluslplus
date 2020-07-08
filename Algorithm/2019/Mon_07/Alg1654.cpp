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
	// lo=ans, 각 단계의 lo는 정답이거나 정답 왼쪽에 항상 있어야 한다.
	// hi는 -1 넘어도 lo가 알아서 찾아가니까 상관없다.
	int k,n;
	cin>>k>>n;
	int in[k];
	FOR1(i,k)
		cin>>in[i];
	ll lo=1, hi=1e11;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		// f(mid)를 구한다.
		ll ret=0;
		FOR1(i,k)
			ret+=in[i]/mid;
		if(ret<n)
			hi=mid-1;
		else
			lo=mid+1;
	}
	cout<<hi<<'\n';
	return 0;
}