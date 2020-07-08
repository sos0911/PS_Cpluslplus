// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
// sliding window
int be[10001], af[10001], in[101];
// 전 단계까지 k를 완성하는 가짓수 저장
int n,k;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	memset(be,0,sizeof(be));
	memset(af,0,sizeof(af));
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>in[i];
	int trep=0;
	while(trep<=k){
		be[trep]=1;
		trep+=in[0];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=k;j++)
			if(be[j]){
				int rep=j;
				while(rep<=k){
					af[rep]+=be[j];
					rep+=in[i];
				}
			}
		copy(af,af+k+1,be);
		memset(af,0,sizeof(af));
	}
	cout<<be[k]<<'\n';
	return 0;
}