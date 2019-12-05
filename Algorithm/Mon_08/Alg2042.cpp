// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
// n : input -> 세그 size : 2^n
struct seg{
	int size, start;
	// start : input들이 모여있는 노드의 시작 idx
	// 포화 이진 트리
	vector<ll> tree;
	seg():size(n){
		start=1;
		while(start<size)
			start*=2;
		tree.resize(start*2,0);
	}
	void init(){
		for(int i=start-1;i>0;i--)
			tree[i]=tree[i*2]+tree[i*2+1];
	}
	void update(int a, ll val){
		a+=start;
		tree[a]=val;
		while(a>1){
			a/=2;
			tree[a]=tree[a*2]+tree[a*2+1];
		}
	}
	ll query(int left, int right, int node, int nleft, int nright){
		if(left>nright||right<nleft)
			return 0;
		if(left<=nleft&&nright<=right)
			return tree[node];
		int mid=(nleft+nright)/2;
		return query(left,right,node*2,nleft,mid)+query(left,right,node*2+1,mid+1,nright);
	}
};
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	seg st; // 기본 생성자 호출
	for(int i=0;i<n;i++)
		cin>>st.tree[i+st.start];
	st.init();
	for(int i=0;i<m+k;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)
			st.update(b-1,c);
		else
			cout<<st.query(b-1,c-1,1,0,n-1)<<'\n';
	}
	return 0;
}