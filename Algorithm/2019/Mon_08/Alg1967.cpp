// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vp;
int n;
vvp child; // (상대 노드, 가중치)
// tree므로 노드<>노드 간 경로 유일
int main(){
	scanf("%d", &n);
	child.assign(n+1,vp());
	for(int i=0;i<n-1;i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		child[a].push_back({b,c});
	}
	int maxi=dist(1); // 1에서 가장 먼 노드 구함
	int maxi2=dist(maxi); // maxi에서 가장 먼 노드
	
	return 0;
}