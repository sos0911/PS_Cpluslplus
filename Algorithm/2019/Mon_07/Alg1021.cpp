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
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// just simulation
	// deque
	// no reserve method
	int n,m,temp;
	cin>>n>>m;
	deque<int> cont(n,0); // n개의 0으로 초기화
	int in[m]; // 찾아야 하는 index
	FOR(i,0,m,1){
		cin>>temp;
		in[i]=temp;
		cont[temp-1]=temp; // index 처리
	}
	int ret=0; // ans
	FOR(i,0,m,1){
		bool two=false;
		FOR(j,0,cont.size(),1)
			if(cont[j]==in[i]){
				if(j<=cont.size()-j){
					two=true;
					ret+=j;
				}
				else
					ret+=cont.size()-j;
				break;
			}
		if(two){
			while(cont.front()!=in[i]){
				temp=cont.front();
				cont.pop_front();
				cont.push_back(temp);
			}
			cont.pop_front();
		}
		else{
			while(cont.front()!=in[i]){
				temp=cont.back();
				cont.pop_back();
				cont.push_front(temp);
			}
			cont.pop_front();
		}
	}
	cout<<ret<<'\n';
	return 0;
}