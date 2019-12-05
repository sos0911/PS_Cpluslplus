#include <bits/stdc++.h>
using namespace std;
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
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
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
struct comp{
	bool operator()(string s1, string s2){
		return s1[1]==s2[1]? s1[0]<s2[0]:s1[1]<s2[1];
	}	
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	string in[3];
	FOR(i,0,3,1)
		cin>>in[i]; // srring형 배열
	sort(in, in+3, comp()); // suit별 / number 오릅차순
	// 조건 2개 확인
	int ret=-1;
	string sts=in[0];
	int nofi=1, temp=1; // 동일한 것 갯수
	FOR(i,1,3,1)
		if(sts==in[i]){
			temp++;
			nofi=max(nofi,temp);
		}
		else{
			temp=1;
			sts=in[i];
		}
	ret=max(ret,nofi);
	// seq 찾음
	sts=in[0];
	int nofs=1, need=1e9; // seq 최대길이 / 필요한 타일수
	temp=1;
	FOR(i,1,3,1){
		int be=sts[0]-'0', af=in[i][0]-'0';
		if(sts[1]==in[i][1]&&be<af){
			if(be+1==af){
			temp++;
			nofs=max(nofs,temp);
			}
			else{
				temp=1;
				need=min(need,af-be-1);
			}
		}
		else
			temp=1;
		sts=in[i];
	}
	ret=max(ret,nofs);
	cout<<min(3-ret,need)<<'\n';
	return 0;
}