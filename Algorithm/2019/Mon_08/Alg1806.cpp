// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
const int maxd=1e5;
int n,s;
int in[maxd+1];
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>in[i];
	// to pointer
	int st=0,ed=0,sum=0,ans=maxd*2;
	while(true){
		if(sum>=s){
			ans=min(ans,ed-st);
			sum-=in[st++];
		}
		else if(ed==n)
			break;
		else
			sum+=in[ed++];
	}
	cout<<(ans==maxd*2? 0:ans)<<'\n';
	return 0;
}