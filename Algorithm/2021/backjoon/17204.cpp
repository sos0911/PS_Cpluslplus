// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main(){
    // 보성이가 걸리지 않는 경우 : 이미 visited한 state를 방문할 때 보성이가
    // not visited.
    // loop
    int n,k;
    cin>>n>>k;
    vector<int> chosedPeoples(n, -1);
    for(int i=0;i<n;i++){
        cin>>chosedPeoples[i];
    }
    // 그래프를 그대로 따라간다.
    vector<bool> visited(n, false);
    visited[0]=true;
    int here=0, ans=0;
    bool check=false;
    while(here != k){
        if(visited[chosedPeoples[here]]){
            check=true;
            break;
        }
        here = chosedPeoples[here];
        visited[here] = true;
        ans++;
    }
    cout<<(check? -1 : ans)<<'\n';
	return 0;
}