// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int r,c;
bool check(int curR, int curC){
    return curR>=0 && curR<r && curC>=0 && curC<c;
}
int main(){
    // 그냥 늑대 주변에 울타리를 설치하면 된다 ㅋㅋ
    cin>>r>>c;
    vector<vector<char>> cmap(r, vector<char>(c, '.'));
    int dir[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            cin>>cmap[i][j];
     for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if('W' == cmap[i][j]){
                for(int d=0;d<4;d++){
                    int nextr = i + dir[d][0];
                    int nextc = j + dir[d][1];
                    if(check(nextr, nextc)){
                        if('S' == cmap[nextr][nextc]){
                            cout<<0<<'\n';
                            return 0;
                        }
                        if('.' == cmap[nextr][nextc])
                            cmap[nextr][nextc] = 'D';
                    }
                }
            }
    cout<<1<<'\n';
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cout<<cmap[i][j];
        cout<<'\n';
    }
	return 0;
}