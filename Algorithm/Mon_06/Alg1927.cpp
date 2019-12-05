#include <bits/stdc++.h>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, input;
	cin>>n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for(int i=0;i<n;i++){
		cin>>input;
		if(input==0){
			if(pq.empty())
				cout<<0<<'\n';
			else{
				cout<<pq.top()<<'\n';
				pq.pop();
			}
		}
		else
			pq.push(input);
	}
	return 0;
}