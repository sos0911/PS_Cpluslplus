// 대회용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<list<int>> vli; 
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef double db;
typedef priority_queue<int> pq;
typedef vector<vector<pii>> vvp;
typedef vector<pii> vpi;
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
int n;
string s,t;
vector<string> cand;
bool visit[3]={};
char gen[3]; // abc 순열
void generate(int pos){
	if(pos==3){
		string temp(gen);
		string sum;
		for(int i=0;i<n;i++)
			sum+=temp;
		cand.push_back(sum);
		string sum2=string(n,gen[0])+string(n,gen[1])+string(n,gen[2]);
		cand.push_back(sum2);
		return;
	}
	for(int i=0;i<3;i++)
		if(!visit[i]){
			switch(i){
				case 0:
				gen[pos]='a';
				break;
				case 1:
				gen[pos]='b';
				break;
				case 2:
				gen[pos]='c';
				break;
			}
			visit[i]=true;
			generate(pos+1);
			visit[i]=false;
		}	
}
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	cin>>s>>t;
	generate(0);
	// 후보군 비교
	for(int i=0;i<cand.size();i++){
		bool possi=true;
		for(int j=0;j<cand[i].size()-1;j++)
			if((cand[i][j]==s[0]&&cand[i][j+1]==s[1])||(cand[i][j]==t[0]&&cand[i][j+1]==t[1])){
				possi=false;
				break;
			}
		if(possi){
			for(int j=0;j<cand[i].size();j++){
				if(cand[i][j]<'a'&&cand[i][j]>'z')
					cout<<"error!"<<'\n';
				cout<<cand[i][j];
			}
			cout<<'\n';
			return 0;
		}
	}
	cout<<"NO"<<'\n';
	return 0;
}