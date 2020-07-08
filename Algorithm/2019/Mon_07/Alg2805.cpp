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
	int lo=0, hi=-1; // hi는 가장 큰 나무의 높이이다. f(lo)>=ans,f(hi)=0
	FOR1(i,n){
		cin>>in[i];
		hi=max(hi,in[i]);
	}
	// f(h)는 감소함수
	// 이분탐색으로 찾아본다.
	// hi-lo=1이면 정수 mid가 없음 => 중단
	while(hi-lo!=1){
		int mid=(hi+lo)/2;
		// mid 높이로 몇미터를 가져가나 본다.
		ll sum=0;
		FOR1(i,n)
			sum+=in[i]-mid>0? in[i]-mid:0;
		if(sum>=m)
			lo=mid;
		else
			hi=mid;
	}
	cout<<lo<<'\n';
	return 0;
}