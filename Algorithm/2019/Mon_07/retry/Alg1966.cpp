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
typedef vector<pii> vpi;
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
		int tar=input[m], tari; // target
		vi same; // tar과 중요도 같은 것들의 index 모아놓음
		FOR1(j,n){
			if(input[j]>tar) // 큰 것만 집어넣음
			pq.push({input[j],j});
			if(input[j]==tar){
				if(j==m)
					tari=same.size();
				same.push_back(j);
			}
		}
		int samelen=same.size();
		if(samelen==1){
			cout<<pq.size()+1<<'\n';
			continue;
		}
		// 같은게 2개이상
		for(int i:same)
			cout<<i<<" ";
		cout<<'\n';
		int ret=pq.size(), fridx=0; // ans, front index
		while(!pq.empty()&&pq.top().fi!=tar){
			int temp=pq.top().se;
			cout<<"deleted : "<<pq.top().fi<<" "<<pq.top().se<<'\n';
			pq.pop();
			int temp2=upper_bound(same.begin(), same.end(), temp)-same.begin();
			if(temp2==samelen)
				fridx=0;
			else
				fridx=temp2;
			cout<<"fridx : "<<fridx<<'\n';
		}
		ret+=fridx<=tari? tari-fridx+1:samelen-fridx+tari+1;
		cout<<ret<<'\n'; 
	}
	return 0;
}