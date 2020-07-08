#include <bits/stdc++.h>
using namespace std;
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
#define fi first
#define se second
#define FOR(i,s,e,d) for(int i=s;i<e;i+=d)
#define FORL(i,s,e,d) for(ll i=s;i<e;i+=d)
#define RFOR(i,s,e,d) for(int i=s;i>=e;i+=d)
#define RFORL(i,s,e,d) for(ll i=s;i>=e;i+=d)
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	while(true){
		string in;
		getline(cin,in);
		if(in=="#") // == 오버로딩
			break;
		// 문자열 파싱
		stack<string> cont; // 단어 저장
		int size=in.size();
		bool ok=true;
		FOR(i,0,size,1){
			if(in[i]=='<'){
				int st=i;
				i++;
				while(in[i]!='>')
					i++;
				string word=in.substr(st+1,i-st-1);
				if(word[0]=='/'){
					if(cont.empty()||cont.top()!=word.substr(1,word.size()-1)){ // 비거나 no match
						ok=false;
						break;
					}
				else
					cont.pop();
					}
				else // start tag or st&end
					if(word[word.size()-1]!='/'){
						string temp;
						stringstream ss(word);
						ss>>temp;
					cont.push(temp); // 맨 처음 단어만 push
					}
			}
		}
		if(ok&&cont.empty())
			cout<<"legal"<<'\n';
		else
			cout<<"illegal"<<'\n';
	}
	return 0;
}