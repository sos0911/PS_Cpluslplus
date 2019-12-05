#include <iostream>
#include <queue>
#include <functional>
using namespace std;
int main(){
	// 수 받으면서 저장할 필요없이
	// n순위 안에 들어가면 저장, 아니면 skip(pq)
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	priority_queue<int, vector<int>, greater<int>> pq; // 제일 작은 놈이 우선순위가 높게
	int size=0, input;
	for(int i=0;i<n*n;i++){
		cin>>input;
		if(size<n){
			pq.push(input);
			size++;
		}
		else if(input>pq.top()){
			pq.pop();
			pq.push(input);
		}
	}
	cout<<pq.top()<<'\n';
	return 0;
}