// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
// union-find
// 집합 만들어서 다 먹어보면 됨
const int maxd=10001;
// 친구 번호는 1부터
int n,m,orik,k;
int minv[maxd],p[maxd],crank[maxd];
bool visit[maxd]={};
// minv[maxd]는 해당 노드가 루트일 시 해당 트리를 다 먹는 최소비용 저장
int find(int node){
	if(p[node]==node)
		return node;
	return p[node]=find(p[node]);
}
void merge(int a, int b){
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(crank[a]>crank[b])
		swap(a,b);
	p[a]=b;
	minv[b]=min(minv[a],minv[b]);
	if(crank[a]==crank[b])
		crank[b]++;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	orik=k;
	for(int i=1;i<=n;i++){
		cin>>minv[i];
		p[i]=i;
		crank[i]=1;
	}
	// merge 후 각 집합의 루트가 main
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
	int temp;
	for(int i=1;i<=n;i++){
		temp=find(i);
		if(!visit[temp]){
			k-=minv[temp];
			if(k<0){
				cout<<"Oh no"<<'\n';
				return 0;
			}
			visit[temp]=true;
		}
	}
	cout<<orik-k<<'\n';
	return 0;
}