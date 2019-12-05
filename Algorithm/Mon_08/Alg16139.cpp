// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
string in;
int q;
int psum[200001][26];
int main(){
	// 문자열 받으므로 cin/cout
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>in;
	for(int i=0;i<26;i++)
		psum[0][i]=0;
	int len=in.size();
	for(int i=0;i<len;i++)
		for(int j=0;j<26;j++)
			if(j==in[i]-'a')
				psum[i+1][j]=psum[i][j]+1;
			else
				psum[i+1][j]=psum[i][j];
	cin>>q;
	for(int i=0;i<q;i++){
		string temp;
		int a,b;
		cin>>temp>>a>>b;
		cout<<psum[b+1][temp[0]-'a']-psum[a][temp[0]-'a']<<'\n';
	}
	return 0;
}