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
const int mod=15746;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	int a=1, b=2, temp; // fibonacci
	FOR1(i,n-2){
		temp=b;
		b=(a+b)%mod;
		a=temp;
	}
	cout<<(n==1? 1:b)<<'\n';
	return 0;
}