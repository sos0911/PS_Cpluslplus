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
// n-1개를 2번으로 이동 + 1개를 3번으로 이동
void solve(int n, int from, int to){
	// n개를 from->to로 옮기는 task
	if(n==0)
		return;
	int z=6-from-to; // x+y+z=6(123)
	solve(n-1, from, z);
	cout<<from<<" "<<to<<'\n';
	solve(n-1,z,to);
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	cout<<(1<<n)-1<<'\n'; // (1<<n)-1번 이동
	solve(n,1,3); // n개를 1번->3번 이동
	return 0;
}