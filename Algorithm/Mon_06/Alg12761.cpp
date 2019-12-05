#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int check(queue<int>& bfsq, vector<bool>& visited, int temp, int mode, int m){
	if(mode==1){
		if(temp+m>=0&&temp+m<=100000&&!visited[temp+m]){
			bfsq.push(temp+m);
			visited[temp+m]=true;
			return 1;
		}
	}
	else{
		if(temp*m>=0&&temp*m<=100000&&!visited[temp*m]){
			bfsq.push(temp*m);
			visited[temp*m]=true;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// 이동 가능 종류는 8개
	// 0-100000
	int a,b,n,m;
	cin>>a>>b>>n>>m;
	vector<bool> visited(100001,false);
	queue<int> bfsq;
	bfsq.push(n);
	visited[n]=true;
	int ans=0;
	int be=1, af=0;
	while(!bfsq.empty()){
		for(int i=0;i<be;i++){
		int temp=bfsq.front();
			bfsq.pop();
		if(temp==m){ // 정답 도달
			cout<<ans<<'\n';
			return 0;
		}
		af+=check(bfsq, visited, temp, 1, 1);
		af+=check(bfsq, visited, temp, 1, -1);
		af+=check(bfsq, visited, temp, 1, a);
		af+=check(bfsq, visited, temp, 1, b);
		af+=check(bfsq, visited, temp, 1, -a);
		af+=check(bfsq, visited, temp, 1, -b);
		af+=check(bfsq, visited, temp, 2, a);
		af+=check(bfsq, visited, temp, 2, b);
		}
		be=af;
		af=0;
		ans++;
	}
	return 0;
}