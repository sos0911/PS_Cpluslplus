// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef pair<int,int> pii;
int n;
const int maxd=1e5, INF=1e9;
string in[maxd];
vector<vector<pii>> cont;
// 알파벳별로 결과 저장
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>in[i];
	// 완전탐색
	cont.assign(26,vector<pii>());
	for(int i=0;i<n;i++)
		for(int j=0;j<in[i].size();j++)
			cont[in[i][j]-'a'].push_back({i,j});
	// (단어 idx, 단어 내 위치idx)
	int ans=INF;
	for(int i=0;i<26;i++){
		if(cont[i].size()<2)
			continue;
		// 이제 해당 알파벳을 가지는 단어는 2개이상
		int fminv,fmind=INF;
		for(auto& p:cont[i])
			if(in[p.fi].size()-p.se-1<fmind){
				fmind=in[p.fi].size()-p.se-1;
				fminv=p.fi;
			}
		int rminv, rmind=INF;
		for(auto& p:cont[i]){
			if(p.fi==fminv)
				continue;
			if(p.se<rmind){
				rmind=p.se;
				rminv=p.fi;
			}
		}
		ans=min(ans,fmind+rmind);
		rmind=INF;
		for(auto& p:cont[i])
			if(p.se<rmind){
				rmind=p.se;
				rminv=p.fi;
			}
		fmind=INF;
		for(auto& p:cont[i]){
			if(p.fi==rminv)
				continue;
			if(in[p.fi].size()-p.se-1<fmind){
				fmind=in[p.fi].size()-p.se-1;
				fminv=p.fi;
			}
		}
			ans=min(ans,fmind+rmind);
	}
	cout<<(ans==INF? -1:ans)<<'\n';
	return 0;
}