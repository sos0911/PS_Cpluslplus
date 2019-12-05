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
	int n;
	cin>>n;
	int stn[]={1,3,2,0};
	int ind=1e9, ret=1e9; // 쓰는 index, 추가하는 수
	FOR(i,0,3,1)
		FOR(j,0,4,1)
			if((n+i)%4==stn[j]){
				if(j<ind){
					ind=j;
					ret=i;
				}
				break;
			}
	cout<<ret<<" "<<(char)(ind+'A')<<'\n';
	return 0;
}