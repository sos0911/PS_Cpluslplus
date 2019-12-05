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
int input[100001];
int solve(int s, int e){
	if(s==e)
		return 0;
	if(s+1==e)
		return input[s];
	int mid=(s+e)/2;
	int ret=max(solve(s,mid), solve(mid,e));
	int l=mid-1, r=mid+1, w=1, minv=input[mid];
	ret=max(ret,input[mid]);
	while(r-l<=e-s){
		// [s,e)에 대해 모두 조사
		int p=l>=s? input[l]:-1;
		int q=r<e? input[r]:-1;
		w++;
		if(p>=q){
			minv=min(minv,p);
			ret=max(ret,w*minv);
			l--;
		}
		else{
			minv=min(minv,q);
			ret=max(ret,w*minv);
			r++;
		}
	}
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	FOR1(i,n)
		cin>>input[i];
	cout<<solve(0,n)<<'\n';
	return 0;
}