#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, input, ans=0;
	cin>>n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<n;i++){
		cin>>input;
		pq.push(input);
	}
	while(pq.size()!=1){
		int a=pq.top();
		pq.pop();
		int b=pq.top();
		pq.pop();
		ans+=a+b;
		pq.push(a+b);
	}
	cout<<ans<<'\n';
	return 0;
}