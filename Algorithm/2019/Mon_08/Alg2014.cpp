// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int k,n;
ll temp;
int in[101];
set<ll> visit;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>k>>n;
	priority_queue<ll> pq;
	for(int i=0;i<k;i++){
		cin>>in[i];
		pq.push(-in[i]);
	}
	for(int i=0;i<n;i++){
		temp=pq.top();
		pq.pop();
		for(int j=0;j<k;j++)
			if(visit.find(temp*in[j])==visit.end()){
				pq.push(temp*in[j]);
				visit.insert(temp*in[j]);
			}
	}
	cout<<-temp<<'\n';
	return 0;
}