// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
const int maxd=3e5+1;
int n,l;
int p[maxd], crank[maxd];
bool full[maxd]={}; // 서랍이 다 차 있나?
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
	// 합칠 때 비어 있는 노드가 루트가 되도록 조작
	if(!full[a]){
		p[b]=a;
		if(crank[a]==crank[b])
		crank[a]++;
	}
	else if(!full[b]){
		p[a]=b;
		if(crank[a]==crank[b])
		crank[b]++;
	}
	else{ 
	if(crank[a]>crank[b])
		swap(a,b);
	p[a]=b;
	if(crank[a]==crank[b])
		crank[b]++;
	}
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>l;
	for(int i=1;i<=l;i++){
		p[i]=i;
		crank[i]=1;
	}
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		// 술병 처리한 후 merge
		// 항상 비어 있는 서랍이 루트 쪽으로 가도록 조작
		bool possi=true;
		if(!full[a])
			full[a]=true;
		else if(!full[b])
			full[b]=true;
		else if(!full[find(a)])
			full[find(a)]=true;
		else if(!full[find(b)])
			full[find(b)]=true;
		else
			possi=false;
		cout<<(possi? "LADICA":"SMECE")<<'\n';
		merge(a,b);
	}
	return 0;
}