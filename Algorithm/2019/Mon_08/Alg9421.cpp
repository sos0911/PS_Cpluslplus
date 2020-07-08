// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxd=1e6+1;
bool prime[maxd+1];
bool visit[600]={};
int orin;
vector<int> p;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 소수를 구함
	fill(prime,prime+maxd+1,true);
	p.reserve(100000);
	for(int i=2;i<=maxd;i++)
		if(prime[i]){
			p.push_back(i);
			for(ll j=1LL*i*i;j<=maxd;j+=i)
				prime[j]=false;
		}
	cin>>orin;
	for(int i=0;i<p.size();i++){
		if(p[i]>orin)
			break;
		int n=p[i];
		int temp2=0;
			while(n){
				temp2+=(n%10)*(n%10);
				n/=10;
			}
			n=temp2;
		while(!visit[n]){
			if(n==1){
				cout<<p[i]<<'\n';
				break;
			}
			visit[n]=true;
			int temp=0;
			while(n){
				temp+=(n%10)*(n%10);
				n/=10;
			}
			n=temp;
		}
		memset(visit,0,sizeof(visit));
	}
	return 0;
}