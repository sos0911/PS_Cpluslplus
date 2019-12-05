// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxd=1e5+1;
int t,f;
map<string,int> cont;
// (이름, idx)만 저장
// 이외의 것은 union-find
int p[maxd],crank[maxd],tsize[maxd];
// 노드 idx는 1부터 시작
// tsize : 노드가 루트일때 트리 사이즈
int find(int node){
	if(p[node]==node)
		return node;
	return p[node]=find(p[node]);
}
int merge(int a, int b){
	// a+b 반환
	a=find(a);
	b=find(b);
	if(a==b)
		return tsize[a];
	if(crank[a]>crank[b])
		swap(a,b);
	p[a]=b;
	if(crank[a]==crank[b])
		crank[b]++;
	return tsize[b]+=tsize[a];
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>t;
	for(int i=0;i<t;i++){
		int rep=1;
		cin>>f;
		for(int j=0;j<f;j++){
			string in[2];
			cin>>in[0]>>in[1];
			map<string,int>::iterator itr[2];
			for(int k=0;k<2;k++)
			if((itr[k]=cont.find(in[k]))==cont.end()){
				p[rep]=rep;
				crank[rep]=1;
				tsize[rep]=1;
				itr[k]=cont.insert({in[k],rep}).fi;
				rep++;
			}
			// merge
			cout<<merge(itr[0]->se,itr[1]->se)<<'\n';
		}
		cont.clear();
	}
	return 0;
}