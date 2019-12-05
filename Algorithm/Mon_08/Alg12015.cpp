// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int maxd=1e6, mind=-1;
int n,start=1;
pii in[maxd]; // 0
// (값, idx)
vector<int> tree;
bool comp(pii& a, pii& b){
	return a.fi==b.fi? a.se>b.se:a.fi<b.fi;
}
void update(int i, int val){
	i+=start;
	tree[i]=val;
	while(i>1){
		i/=2;
		tree[i]=max(tree[i*2],tree[i*2+1]);
	}
}
int query(int left, int right, int node, int nleft, int nright){
	if(right<nleft||nright<left)
		return mind;
	if(left<=nleft&&nright<=right)
		return tree[node];
	int mid=(nleft+nright)/2;
	return max(query(left,right,node*2,nleft,mid),query(left,right,node*2+1,mid+1,nright));
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// segtree 이용 풀이
	// 최대값 segtree
	// 값 오름차순 정렬, 같으면 idx 내림차순 정렬
	// segtree는 기본적으로 0~start-1
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>in[i].fi;
		in[i].se=i;
	}
	sort(in, in+n, comp());
	while(start<n)
		start*=2;
	tree.resize(start*2,0);
	for(int i=0;i<n;i++)
		update(in[i].se,query(0,i,1,0,start-1)+1);
	cout<<tree[1]<<'\n';
	return 0;
}