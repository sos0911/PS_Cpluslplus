/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

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
int Answer;
int m,n;
const int MAXC=51, MAXR=501;
int imap[MAXC][MAXR];
bool inrange(int y, int x){ // (y,x)가 왼쪽 위인 3*3이 가능한가?
	if(y>=1&&y+2<=m&&x>=1&&x+2<=n)
		return true;
	else
		return false;
}
int solve(int y, int x, int mode){ // (y,x)가 왼쪽 위인 3*3 내에서 공장수
	int ret=0;
	FOR2(i,y,y+3)
		FOR2(j,x,x+3)
			if(imap[i][j]==1){
				if(mode==1)
					imap[i][j]=0;
				ret++;
			}
	return ret;
}
int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T, test_case;
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		cin>>m>>n;
		FOR2(i,1,m+1){
			string temp;
			cin>>temp;
			FOR2(j,1,n+1){
				//cout<<"temp : "<<temp[j]-'0'<<'\n';
				imap[i][j]=temp[j-1]-'0';
			}
		}
		vpi ret; // 폭탄 좌표 저장
		FOR2(i,1,m+1)
			FOR2(j,1,n+1)
				if(imap[i][j]==1){
					int maxn=-1, temp;
					pii maxc={-1,-1};
					for(int y=i-2;y<=i;y++)
						for(int x=j-2;x<=j;x++)
							if(inrange(y,x)&&(temp=solve(y,x,0))>maxn){
								maxn=temp;
								maxc={y,x};
							}
					solve(maxc.fi,maxc.se,1); // 공장제거
					ret.push_back(maxc);
					Answer++;
				}
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
		for(auto& p:ret)
			cout<<p.fi<<" "<<p.se<<'\n';
	}

	return 0;//Your program should return 0 on normal termination.
}