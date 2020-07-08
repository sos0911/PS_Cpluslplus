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
	ll m,a,h;
	// m=1이면 몬스터, 2면 포션
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n,tsa; // sa=용사 공격력
	cin>>n>>tsa;
	Info in[n]; // 0-
	FOR1(i,n)
		cin>>in[i].m>>in[i].a>>in[i].h;
	ll lo=1,hi=1e18;
	while(lo<=hi){
		bool possi=true;
		ll tmid=(lo+hi)/2;
		ll mid=tmid;
		ll sa=tsa;
		// mid=용사 체력
		// f(mid)를 구한다 = simulation
		FOR1(i,n){
			if(in[i].m==1){
				ll y=mid%in[i].a==0? mid/in[i].a:mid/in[i].a+1;
				ll m=in[i].h%sa==0? in[i].h/sa:in[i].h/sa+1;
				if(y>=m) // 승리
					mid-=(m-1)*in[i].a;
				else{
					possi=false;
					break;
				}
			}
			else{
				sa+=in[i].a;
				mid=mid+in[i].h>tmid? tmid:mid+in[i].h;
			}
		}
		if(!possi)
			lo=tmid+1;
		else
			hi=tmid-1;
	}
	cout<<lo<<'\n';
	return 0;
}