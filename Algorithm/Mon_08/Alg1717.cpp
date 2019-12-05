// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
// disjoint-set
const int maxd=1000001;
int parent[maxd], rank[maxd];
// rank : 초기에는 트리 높이를 의미했지만 전체적인 크기를 의미하게 됨
int n,m;
int find(int node){
	if(parent[node]==node)
		return node;
	return parent[node]=find(parent[node]);
	// 결국 parent[] 안에는 그 노드가 속한 집합의 루트가 들어감
	// 주의! 재귀함수에서 인자가 똑같은 자기 자신을 불러오면 안됨
}
void merge(int a, int b){
	a=find(a);
	b=find(b);
	// 무조건 작은 것이 큰 것에 들어가도록
	// 트리의 높이 같은 것도 저장이 가능
	if(a==b)
		return;
	if(rank[a]>rank[b])
		swap(a,b);
	parent[a]=b;
	if(rank[a]==rank[b])
		rank[b]++;
	// 크기 저장하던 곳을 이제 진짜 부모 포인터로 바꾼다
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		rank[i]=1;
		parent[i]=i;
	}
	// 초기 각 집합의 크기는 1
	for(int i=0;i<m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		if(!a)
			merge(b,c);
		else
			cout<<(find(b)==find(c)? "YES":"NO")<<'\n';
	}
	return 0;
}