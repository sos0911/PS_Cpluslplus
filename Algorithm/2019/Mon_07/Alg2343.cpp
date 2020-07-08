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
	ll sum=0;
	ll lo=0;
	// lo가 레슨 중 최대길이보다는 같거나 길어야 답이 나온다.
	FOR1(i,n){
		cin>>in[i];
		sum+=in[i];
		lo=max(lo,(ll)in[i]);
	}
	lo--;
	ll hi=sum+1;
	// lo가 답이 되도록 만든다.
	while(hi-lo!=1){
		ll mid=(lo+hi)/2;
		// 현재 bl크기
		// 이제 이 크기를 가진 bl들에 넣어본다.
		ll nofb=1, left=mid;
		FOR1(i,n){
			if(left>=in[i])
				left-=in[i];
			else{
				nofb++;
				left=mid;
				left-=in[i];
			}
		}
		// nofb=f(mid)
		if(nofb>m)
			lo=mid;
		else
			hi=mid;
	}
	cout<<hi<<'\n';
	return 0;
}