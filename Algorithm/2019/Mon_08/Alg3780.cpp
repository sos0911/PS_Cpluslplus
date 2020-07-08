// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int mod=1000, maxd=2e4+1;
int t,n,p[maxd],dist[maxd]; // 자신과 루트까지의 거리 저장
int find(int node){
	// 현재 node와 루트 간 거리를 갱신
	// 트리 루트와 루트까지의 거리 반환
	if(p[node]==node)
		return node;
	dist[node]+=dist[p[node]];
	int temp=find(p[node]);
	return p[node]=temp;
}
void merge(int a, int b){
	p[a]=b;
	dist[a]=abs(a-b)%mod;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		memset(dist,0,sizeof(dist));
		for(int j=1;j<=n;j++)
			p[j]=j;
		while(true){
			char mode;
			cin>>mode;
			if(mode=='O')
				break;
			else if(mode=='E'){
				int temp;
				cin>>temp;
				find(temp); // dist 갱신
				cout<<dist[temp]<<'\n';
			}
			else{
				int a,b;
				cin>>a>>b;
				merge(a,b);
			}
		}
	}
	return 0;
}