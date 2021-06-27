// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
int n,m;
// 첫번째 열, 두번째 열 번갈아 사용
int dir1[6][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}, {-1,-1}, {1,-1}};
int dir2[6][2] = {{0,-1}, {0,1}, {1,0}, {-1,0}, {1,1}, {-1,1}};
int ans=0;
bool check(int h, int w){
    return h>=0 && h<n && w>=0 && w<m;
}
void solve(int h, int w, vvc& cmap){
    for(int d=0;d<6;d++){
        int nexth, nextw;
        if(!(h%2)){
            nexth = h + dir1[d][0], nextw = w + dir1[d][1];
        }
        else{
            nexth = h + dir2[d][0], nextw = w + dir2[d][1];
        }
        if(check(nexth, nextw) && cmap[nexth][nextw] == '.'){
            // cout<<h<<" : "<<w<<" ::: ("<<nexth<<","<<nextw<<")"<<'\n';
            ans++;
        }
    }
}
int main(){
    // 기본 idea : 땅 한 칸씩 네 방향을 모두 검사
    // visited 필수
    cin>>n>>m;
    vvc cmap(n, vc(m, '-'));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>cmap[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(cmap[i][j]=='#')
                solve(i,j,cmap);
    cout<<ans<<'\n';
	return 0;
}