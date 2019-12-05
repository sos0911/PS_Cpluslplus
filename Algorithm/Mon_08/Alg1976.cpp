// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
const int maxd=201; // 1-200
// 노드 번호는 1부터 시작
int p[maxd], crank[maxd];
int n,m,temp;
int find(int node){
	if(p[node]==node)
		return node;
	return p[node]=find(p[node]); 
}
void merge(int a,int b){
	a=find(a);
	b=find(b);
	if(a==b)
		return;
	if(crank[a]>crank[b])
		swap(a,b);
	p[a]=b;
	if(crank[a]==crank[b])
		crank[b]++;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		p[i]=i;
		crank[i]=1;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>temp;
			if(temp)
				merge(i+1,j+1);	
		}
	int be,af;
	cin>>be;
	bool possi=true;
	for(int i=1;i<m;i++){
		cin>>af;
		if(find(be)!=find(af)){
			possi=false;
			break;
		}
		be=af;
	}
	cout<<(possi? "YES":"NO")<<'\n';
	return 0;
}