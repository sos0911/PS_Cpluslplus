#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
char stn[4]={'A','C','G','T'};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	string input[n]; // 0-
	string ret; // ans
	int retn=0;
	FOR1(i,n)
		cin>>input[i];
	FOR1(i,m){
		int eme[26]; // A-Z
		memset(eme, 0, sizeof(eme));
		// 0,-1으로 초기화 할때만 쓰는 방법
		FOR1(j,n)
			eme[input[j][i]-'A']++;
		int maxn=-1;
		char maxc;
		FOR1(j,4)
			if(maxn<eme[stn[j]-'A']){
				maxn=eme[stn[j]-'A'];
				maxc=stn[j];
			}
		FOR1(j,n)
			if(input[j][i]!=maxc)
				retn++;
		ret+=maxc;
	}
	cout<<ret<<'\n'<<retn<<'\n';
	return 0;
}