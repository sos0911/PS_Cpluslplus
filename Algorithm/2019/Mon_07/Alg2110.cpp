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
	int n,c;
	cin>>n>>c;
	int in[n];
	FOR1(i,n)
		cin>>in[i];
	sort(in, in+n); // 오름차순 정렬
	ll lo=1,hi=1e11;
	while(lo<=hi){
		ll mid=(lo+hi)/2;
		// f(mid) => 최인접 공유기 간 거리가 mid라는 조건 내에서 설치 가능한 공유기 최대개수
		// 그러려면 최대한 앞에 붙여서 앞부터 mid~마다 설치해야함
		int nofw=1, bidx=0;
		// 시작점에 설치
		FOR2(i,1,n)
			if(in[i]-in[bidx]>=mid){
				nofw++;
				bidx=i;
			}
		if(nofw>=c)
			lo=mid+1;
		else
			hi=mid-1;
	}
	cout<<hi<<'\n';
	return 0;
}