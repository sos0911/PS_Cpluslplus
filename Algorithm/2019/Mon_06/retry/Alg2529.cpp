#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <functional>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
int main(){
	// char를 공백으로 입력받을 때 조심
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int k;
	char input;
	cin>>k;
	cin.get();
	vvi cont(k+1,vi()); // 개수는 k+1. index 0-
	vi deg(k+1, 0);
	// < 반대방향으로 간선을 설정
	// 간선 번호 : index
	for(int i=0;i<k;i++){
		cin>>input;
		if(input=='>'){
			cont[i].push_back(i+1);
			deg[i+1]++;
		}
		else{
			cont[i+1].push_back(i);
			deg[i]++;	
		}
	}
	vi maxd(deg), mind(deg); // 간선 정보 복사
	vi maxs(k+1, -1); // 정답
	vi mins(k+1, -1);
	int maxn=9,minn=k;
	priority_queue<int, vector<int>, greater<int>> maxq; // 가장 작은 놈이 앞으로
	priority_queue<int> minq; 
	// maxq
	for(int i=0;i<k+1;i++)
		if(!maxd[i])
			maxq.push(i);
	while(!maxq.empty()){
		int temp=maxq.top();
		maxq.pop();
		for(int i:cont[temp]){
			maxd[i]--;
			if(!maxd[i])
				maxq.push(i);
		}
		maxs[temp]=maxn--;
	}
	// minq
	for(int i=k;i>=0;i--)
		if(!mind[i])
			minq.push(i);
	while(!minq.empty()){
		int temp=minq.top();
		minq.pop();
		for(int i=cont[temp].size()-1;i>=0;i--){
			mind[cont[temp][i]]--;
			if(!mind[cont[temp][i]])
				minq.push(cont[temp][i]);
		}
		mins[temp]=minn--;
	}
	for(int i:maxs)
		cout<<i;
	cout<<'\n';
	for(int i:mins)
		cout<<i;
	cout<<'\n';
	return 0;
}