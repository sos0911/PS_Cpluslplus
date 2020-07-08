// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
const int maxd=1e5;
int n,start=1;
pii in[maxd]; // 0-
vector<int> tree;
// 구간 내 남아있는 수들의 개수를 저장
// (값, idx)
bool comp(pii& a, pii& b){
	return a.fi<b.fi;
}
void init(){
	for(int i=start-1;i>0;i--)
		tree[i]=tree[i*2]+tree[i*2+1];
}
void update(int i, int val){
	i+=start;
	tree[i]=val;
	while(i>1){
		i/=2;
		tree[i]=tree[i*2]+tree[i*2+1];
	}
}
int query(int left, int right, int node, int nleft, int nright){
	if(right<nleft||nright<left)
		return 0;
	if(left<=nleft&&nright<=right)
		return tree[node];
	int mid=(nleft+nright)/2;
	return query(left,right,node*2,nleft,mid)+query(left,right,node*2+1,mid+1,nright);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	while(start<n)
		start*=2;
	tree.assign(start*2,0);
	for(int i=0;i<n;i++){
		cin>>in[i].fi;
		in[i].se=i;
		tree[i+start]=1;
	}
	init();
	sort(in,in+n,comp); // 값 오름차순 정렬
	int st=0,ed=n-1;
	for(int i=0;i<n;i++){
		if(!(i%2)){
			cout<<query(0,in[st].se,1,0,start-1)-1<<'\n';
			update(in[st].se,0);
			st++;
		}
		else{
			cout<<query(in[ed].se,start-1,1,0,start-1)-1<<'\n';
			update(in[ed].se,0);
			ed--;
		}
	}
	return 0;
}