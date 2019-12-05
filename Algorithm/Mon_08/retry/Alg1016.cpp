// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1e6;
bool visit[maxd+1]={}; // [cmin, cmax]
ll cmin,cmax;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>cmin>>cmax;
	int cnt=0;
	for(int i=2;1LL*i*i<=cmax;i++){
		ll rep=1LL*i*i;
		ll temp=cmin%rep? rep*(cmin/rep+1):rep*(cmin/rep);
		while(temp<=cmax){
			if(!visit[(int)(temp-cmin)]){
				cnt++;
				visit[(int)(temp-cmin)]=true;
			}
			temp+=rep;
		}
	}
	cout<<cmax-cmin+1-cnt<<'\n';
	return 0;
}