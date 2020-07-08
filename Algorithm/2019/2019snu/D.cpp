// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
string sw[20];
vector<int> ans[201];
bool visit[201]={}, vs[21]={}; // 이미 해당 칸에 답이 있는가를 표시
// vs : 해당 스위치를 사용함?
void solve(int pos, int sum){
	// 모든 선택지를 재귀로 만든다.
	// 스위치를 누르냐 마냐
	if(pos==m)
		return;
	// 안누름
	if(!visit[sum+n]){
		visit[sum+n]=true;
		for(int i=0;i<m;i++)
			if(vs[i])
				ans[sum+n].push_back(i);
	}
	solve(pos+1,sum);
	// 누름
	vs[pos]=true;
	for(int i=0;i<n;i++)
		if(sw[pos][i]=='1'){
			if(s[i]=='0'){
				s[i]=='1';
				sum+=2;
			}
			else{
				s[i]=='0';
				sum-=2;
			}
		}
	if(!visit[sum+n]){
		visit[sum+n]=true;
		for(int i=0;i<m;i++)
			if(vs[i])
				ans[sum+n].push_back(i);
	}
	solve(pos+1,sum);
	vs[pos]=false;
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	int stn=0;
	for(int i=0;i<s.size();i++)
		if(s[i]=='0')
			stn--;
		else
			stn++;
	for(int i=0;i<m;i++)
		cin>>sw[i];
	solve(0,stn);
	for(int i=0;i<2*n+1;i++)
		if(!ans[i].size())
			cout<<-1<<'\n';
		else{
			cout<<ans[i].size()<<" ";
			for(int j=0;j<ans[i].size();j++)
				cout<<ans[i][j]<<" ";
			cout<<'\n';
		}
	return 0;
}