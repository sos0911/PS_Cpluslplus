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
int n;
ll cube[20]={0}; // 2^n이 변의 크기인 큐브가 x개 있음
ll decube[20]={0}; // 이상적인 큐브 개수
void solve(int x, int y, int z){
	// (x,y,z)를 채우는 큐브 개수 최솟값 반환
	// 큐브 수 상관없이 일단 가능한 적게 채워본다.
	if(x<=0||y<=0||z<=0)
		return;
	for(int i=19;i>=0;i--){
		int stn=1<<i;
		if(x>=stn&&y>=stn&&z>=stn){
			decube[i]+=(ll)(x/stn)*(y/stn)*(z/stn);
			solve(x%stn,y,z);
			solve(x-(x%stn),y%stn,z);
			solve(x-(x%stn),y-(y%stn),z%stn);
			break;
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//memset(decube, 0, sizeof(decube));
	int x,y,z; // length width height
	cin>>x>>y>>z;
	cin>>n;
	FOR1(i,n){
		ll a,b;
		cin>>a>>b;
		cube[a]=b;
	}
	solve(x,y,z);
	ll ret=0;
	for(int i=19;i>0;i--)
		if(decube[i]){
			if(cube[i]>=decube[i]){
				ret+=decube[i];
				//cout<<"i : "<<i<<" ret added : "<<decube[i]<<'\n';
			}
			else{
				ret+=cube[i];
				//cout<<"i : "<<i<<" ret added : "<<cube[i]<<'\n';
				decube[i]-=cube[i];
				decube[i-1]+=decube[i]*8;
			}
		}
	// cube[0] 정산
	cout<<(cube[0]>=decube[0]? ret+decube[0]:-1)<<'\n';
	return 0;
}
/*반례 ; 
30 30 30
3
0 10000
1 10000
2 10000
	*/