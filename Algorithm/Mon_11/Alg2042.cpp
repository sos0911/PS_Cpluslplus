// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1048576; //1024*1024 >> 1000000과 가장 가까운 2의 배수
// 실제 leaf node가 시작되는 index = maxd (조금 loss..)
// 0번 노드부터 시작한다고 생각
int n,m,k;
ll tree[maxd*2]={0};
ll query(int left, int right, int nleft, int nright, int node){
	if(left<=nleft && nright<=right)
		return tree[node];
	if(right<nleft || left>nright)
		return 0;
	int mid=(nleft+nright)/2;
	return query(left,right,nleft,mid,node*2)+query(left,right,mid+1,nright,node*2+1);
}
void update(int num, ll val){ // num번째 node = val
	num+=maxd;
	tree[num]=val;
	while(num>1){
		num/=2;
		tree[num]=tree[num*2]+tree[num*2+1];
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n,m,k;
	for(int i=0;i<n;i++)
		cin>>tree[maxd+i];
	for(int i=maxd-1;i>=1;i--) // initialization
		tree[i]=tree[i*2]+tree[i*2+1];
	for(int i=0;i<m+k;i++){
		int a,b;
		ll c;
		cin>>a>>b>>c;
		if(a==1)
			update(b-1,c)
		else
			cout<<sum(b-1,c-1,0,n-1,1);
	}
	return 0;
}