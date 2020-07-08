// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
const int maxd=1e5+1;
int g,p;
int par[maxd]; // 0 사용예정
int find(int node){
	if(par[node]==node)
		return node;
	return par[node]=find(par[node]);
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>g>>p;
	for(int i=0;i<=g;i++)
		par[i]=i;
	int ans=0;
	// 여기서는 어떤 트리가 더 큰가에 관계없이
	// 사용된 게이트 p가 p-1의 자식이 되어야만 한다.
	for(int i=0;i<p;i++){
		int temp;
		cin>>temp;
		if(find(temp)>0)
			ans++;
		else
			break;
		par[find(temp)]=find(temp)-1;
	}
	cout<<ans<<'\n';
	return 0;
}