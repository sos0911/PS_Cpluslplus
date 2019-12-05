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
struct Info{
	int s,e,inter; // 간격
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k,d;
	cin>>n>>k>>d;
	Info in[k];
	FOR1(i,k)
		cin>>in[i].s>>in[i].e>>in[i].inter;
	int lo=1, hi=1000001;
	while(lo<=hi){
		int mid=(lo+hi)/2;
		// f(mid)를 구한다.
		// mid번째 상자까지 몇 개의 도토리가 들어가는지 검사한다.
		// f(mid) 오버플로우 조심
		ll sum=0;
		// 정렬 안한 버전
		FOR1(i,k)
			if(in[i].s<=mid&&mid<in[i].e)
				sum+=(mid-in[i].s)/in[i].inter+1;
			else if(mid>=in[i].e)
				sum+=(in[i].e-in[i].s)/in[i].inter+1;
		if(sum>=(ll)d)
			hi=mid-1;
		else
			lo=mid+1;
	}
	cout<<lo<<'\n';
	return 0;
}