#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	pair<int,int> in[n];
	FOR1(i,n)
		cin>>in[i].second>>in[i].first;
	// sa<=ea<=sb<=eb
	// 끝나는 시간이 작은 순서대로 정렬하되
	// 하나씩 붙여보는데 겹치면 out
	sort(in, in+n);
	int ed=-1, ret=0;
	FOR1(i,n)
		if(in[i].second>=ed){
			// 다음 회의 시작시간이 전 회의 끝나는 시간보다 크거나 같으면
			ret++;
			ed=in[i].first;
		}
	cout<<ret<<'\n';
	return 0;
}