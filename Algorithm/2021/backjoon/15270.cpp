// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef vector<bool> vb;
int n,m;
// 그때마다의 답
// visited -> 비트연산으로 대체 가능(..)
int sum=0, ans=0;
void solve(int idx, vvi& cgraph, vb& visited){
    if(idx == n+1){
        ans = sum < n? max(ans, sum+1) : max(ans, sum);
        return;
    }

    // 이 친구를 누군가하고 매치하는 경우의 수는?
    for(int i=0;i<cgraph[idx].size();i++){
        if(!visited[cgraph[idx][i]]){
            visited[idx] = true;
            visited[cgraph[idx][i]] = true;
            // cout<<idx<<" :: "<<cgraph[idx][i]<<'\n';
            sum+=2;
            for(int j=idx+1;j<=n+1;j++){
                if(!visited[j])
                    solve(j, cgraph, visited);
            }
            visited[idx] = false;
            visited[cgraph[idx][i]] = false;
            sum-=2;
        }
    }    
}
int main(){
    cin>>n>>m;
    // index 1번부터 시작
    vvi cgraph(n+1, vi());
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        cgraph[a].push_back(b);
        cgraph[b].push_back(a);
    }
    // 완전탐색을 해보자.
    vb visited(n+2, false);
    for(int i=1;i<=n+1;i++)
        if(!visited[i])
            solve(i, cgraph, visited);
    cout<<ans<<'\n';
	return 0;
}