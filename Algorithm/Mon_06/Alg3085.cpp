#include <bits/stdc++.h>
using namespace std;
const int dir[][2]={{0,1},{1,0}};
int solve(vector<string>& cont, int n){ // 현재 맵에서 연속한 같은 최대 개수 반환
	int ret=1;
	for(int i=0;i<n;i++){
		char cur=cont[i][0];
		int	maxl=1;
		for(int j=1;j<n;j++)
			if(cur==cont[i][j])
				ret=max(ret,++maxl);
			else{
				maxl=1;
				cur=cont[i][j];
			}
		ret=max(ret,maxl);
	}
	for(int i=0;i<n;i++){
		char cur=cont[0][i];
		int	maxl=1;
		for(int j=1;j<n;j++)
			if(cur==cont[j][i])
				ret=max(ret,++maxl);
			else{
				maxl=1;
				cur=cont[j][i];
			}
		ret=max(ret,maxl);
	}
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<string> cont;
	cont.reserve(n); // 0-
	for(int i=0;i<n;i++){
		string input;
		cin>>input;
		cont.push_back(input); // immutable
	}
	int maxn=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<2;k++){
				int nexty=i+dir[k][0];
				int nextx=j+dir[k][1];
			if(nexty>=0&&nexty<n&&nextx>=0&&nextx<n&&cont[i][j]!=cont[nexty][nextx]){
				swap(cont[i][j], cont[nexty][nextx]);
				for(string s:cont)
					cout<<s<<'\n';
				cout<<'\n';
				maxn=max(maxn,solve(cont,n));
					swap(cont[i][j], cont[nexty][nextx]);
				}
			}
	cout<<maxn<<'\n';
	return 0;
}