// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int n,m;
vector<ll> tree;
int start=1;
int update(int i, int val){
	i+=start;
	tree[i]=val;
	while(i>1){
		i/=2;
		tree[i]=tree[i*2]+tree[i*2+1];
	}
}
ll query(int left, int right, int node, int nleft, int nright){
	if(right<nleft||left>nright)
		return 0;
	if(left<=nleft&&nright<=right)
		return tree[node];
	int mid=(nleft+nright)/2;
	return query(left,right,node*2,nleft,mid)+query(left,right,node*2+1,mid+1,nright);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	while(start<n)
		start*=2;
	tree.resize(start*2,0);
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(!a){
			if(b>c)
				swap(b,c);
			cout<<query(b-1,c-1,1,0,start-1)<<'\n';
		}
		else
			update(b-1,c);
	}
	return 0;
}