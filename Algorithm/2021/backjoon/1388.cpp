// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int ans=0;
int n,m;
bool check(int h, int w){
    return h>=0 && h<n && w>=0 && w<m;
}
void solve(int h, int w, vector<vector<char>>& map, vector<vector<bool>>& visited){
    // (n,m)은 방문했다고 생각한다.
    visited[h][w] = true;
    if(map[h][w] == '-' && check(h,w+1) && !visited[h][w+1] && map[h][w+1] == '-')
        solve(h,w+1, map, visited);
    if(map[h][w] == '|' && check(h+1,w) && !visited[h+1][w] && map[h+1][w] == '|')
        solve(h+1,w, map, visited);
}
int main(){
    // dfs로 해볼까?
    cin>>n>>m;
    vector<vector<char>> map(n, vector<char>(m, 'a'));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>map[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            if(!visited[i][j]){
                solve(i,j,map,visited);
                ans++;
            }
        }
    cout<<ans<<'\n';
	return 0;
}