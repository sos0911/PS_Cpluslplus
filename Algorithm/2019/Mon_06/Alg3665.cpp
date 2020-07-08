#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
typedef vector<list<int>> vli;
typedef vector<int> vi;
int main(){
	int noft;
	//cin>>noft;
	scanf("%d", &noft);
	for(int i=0;i<noft;i++){
		int n, temp;
		//cin>>n;
		scanf("%d", &n);
		vli adj(n+1, list<int>()); // 1-
		vi input;
		input.reserve(n);
		vi deg(n+1, 0);
		for(int j=0;j<n;j++){
			//cin>>temp;
			scanf("%d", &temp);
			input.push_back(temp);
		}
		// 간선 만들기
		for(int j=0;j<n;j++)
			for(int k=j+1;k<n;k++){
				adj[input[j]].push_back(input[k]);
				deg[input[k]]++;	
			}
		int m,a,b;
		//cin>>m;
		scanf("%d", &m);
		for(int j=0;j<m;j++){
			//cin>>a>>b;
			scanf("%d %d", &a, &b);
			bool error=false; // 구분자
			for(auto itr=adj[a].begin();itr!=adj[a].end();itr++)
				if(*itr==b){
					adj[a].erase(itr);
					deg[*itr]--;
					adj[b].push_back(a);
					deg[a]++;
					error=true;
					break;
				}
			if(!error)
				for(auto itr=adj[b].begin();itr!=adj[b].end();itr++)
				if(*itr==a){
					adj[b].erase(itr);
					deg[*itr]--;
					adj[a].push_back(b);
					deg[b]++;
					break;
				}
		}
			// 관계도 완성
		queue<int> q;
		vi ans;
		ans.reserve(n);
		bool error2=false;
		for(int j=1;j<=n;j++)
			if(!deg[j])
				q.push(j);
		for(int j=0;j<n;j++){
			if(q.size()>1){
				//cout<<"?"<<'\n';
				printf("?\n");
				error2=true;
				break;
			}
			if(q.empty()){
				//cout<<"IMPOSSIBLE"<<'\n';
				printf("IMPOSSIBLE\n");
				error2=true;
				break;
			}
			int temp=q.front();
			q.pop();
			ans.push_back(temp);
			for(auto itr=adj[temp].begin();itr!=adj[temp].end();itr++)
				if(!(--deg[*itr]))
					q.push(*itr);
		}
		if(!error2){
			for(int j:ans)
				printf("%d ", j);
				//cout<<j<<" ";
		//cout<<'\n';
		printf("\n");
		}
	}
	return 0;
}