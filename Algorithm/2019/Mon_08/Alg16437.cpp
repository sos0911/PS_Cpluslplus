// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef long long ll;
int n;
vvi adj;
struct Info{
	bool wolf;
	int num;
	Info(){}
	Info(bool Wolf, int Num):wolf(Wolf),num(Num){}
};
Info arr[123457];
bool visit[123457]={};
// 노드 번호 1부터 시작
// 컴포넌트!=1일수 있음에 유의
ll solve(int here){
	visit[here]=true;
	ll ret=0; // 이 노드에서 살아 나가는 양 수
	for(int next:adj[here])
		if(!visit[next])
			ret+=solve(next);
	if(arr[here].wolf){
		ret-=arr[here].num;
		arr[here].num=ret>=arr[here].num? 0:arr[here].num-ret;
	}
	else
		ret+=arr[here].num;
	cout<<"solve : "<<here<<" return : "<<ret<<'\n';
	return ret;
}
int main(){
	scanf("%d", &n);
	adj.assign(n+1,vi());
	for(int i=0;i<n-1;i++){
		char w;
		int a,b;
		scanf(" %c%d%d",&w,&a,&b);
		// 공백을 한칸 띄워줌으로써 버퍼 내 개행/공백 문자 무시
		arr[i+2]=(w=='S'? Info(false,a):Info(true,a));
		adj[i+2].push_back(b);
		adj[b].push_back(i+2);
	}
	printf("%lld\n", solve(1));
	return 0;
}