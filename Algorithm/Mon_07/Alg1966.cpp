#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
struct comp{
	bool operator()(pii a, pii b){
		return a.fi==b.fi? a.se>b.se:a.fi<b.fi;
	}
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int noft;
	cin>>noft;
	FOR1(i,noft){
		int n,m;
		cin>>n>>m;
		priority_queue<pii, vector<pii>, comp> pq; // (중요도, index)
		// 중요도 내림차순, 같으면 index 오름차순
		int input[n];
		FOR1(j,n)
			cin>>input[j];
		int tar=input[m]; // target
		FOR1(j,n)
			if(input[j]>=tar)
			pq.push({input[j],j});
		int ret=0, fridx=0; // ans, front index
		while(pq.top().fi!=tar){
			int temp=pq.top().se+1;
			pq.pop();
			ret++;
			while(input[temp]!=tar)
				temp=(++temp)%n;
			fridx=temp;
		}
		if(pq.size()==1){
			cout<<ret+1<<'\n';
			continue;
		}
		int ret2=0, tart, frontt;
		while(!pq.empty()){
			if(pq.top().se==m)
				tart=ret2;
			if(pq.top().se==fridx)
				frontt=ret2;
			pq.pop();
			ret2++;
		}
		// size : n-ret-1
		ret+=frontt<=tart? tart-frontt+1:n-ret-frontt+tart+1;
		cout<<ret<<'\n'; 
	}
	return 0;
}
/*
1 1 9 1. 1 1
0 1 2 3  4 5

9 출력

1 1 1 1 1
3 4 5 0 1

5번째
*/