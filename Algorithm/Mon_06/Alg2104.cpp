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
ll input[100001]; // 0-
int n;
ll divcon(int s, int e){ // (s,e]
	if(s==e)
		return 0;
	if(s+1==e)
		return input[s]*input[s];
	int mid=(s+e)/2;
	ll ret=max(divcon(s,mid), divcon(mid, e));
	// 두 구간에 걸친 답을 찾는다.
	// 두 방향 중 무조건 큰 놈이 있는 쪽으로 간다.
	ll sum=input[mid], minv=input[mid];
	ret=max(ret,sum*minv);
	int left=mid-1, right=mid+1;
	while(right-left<=e-s){
		ll lv=left>=s? input[left]:-1;
		ll rv=right<e? input[right]:-1;
		if(lv>=rv){
			sum+=lv;
			minv=min(minv,lv);
			ret=max(ret,sum*minv);
			left--;
		}
		else{
			sum+=rv;
			minv=min(minv,rv);
			ret=max(ret,sum*minv);
			right++;
		}
	}
	//cout<<"s : "<<s<<" e : "<<e<<'\n';
	//cout<<"ret : "<<ret<<'\n';
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	FOR1(i,n)
		cin>>input[i];
	cout<<divcon(0,n)<<'\n'; // (s,e]
	return 0;
}
/* 반례 :
6
6 5 4 3 2 1
55
*/