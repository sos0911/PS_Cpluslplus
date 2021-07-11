// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<vector<bool>> vvb;
typedef vector<bool> vb;
typedef pair<int,int> pii;
bool check(int s, int t, int vectorSize, vvb& visited){
    return s<vectorSize && t<vectorSize && !visited[s][t] && s<=t;
}
int main(){
    // bfs 각!
    // 항상 내 점수가 상대 점수보다 낮거나 같다.
    int noft;
    cin>>noft;
    int vectorSize = 201;
    vvb visited(vectorSize, vb(vectorSize, false));
    for(int i=0;i<noft;i++){
        for(int j=0;j<vectorSize;j++)
            fill(visited[j].begin(), visited[j].end(), false);
        queue<pii> bfsq;
        int s,t;
        cin>>s>>t;
        int ans=0;
        bfsq.push({s,t});
        while(!bfsq.empty()){
            int queueLength = bfsq.size();
            for(int j=0;j<queueLength;j++){
                pii here=bfsq.front();
                bfsq.pop();
                // cout<<"here : "<<here.first<<" :: "<<here.second<<'\n';
                if(here.first == here.second)
                    goto end;
                if(check(here.first*2, here.second+3, vectorSize, visited)){
                    visited[here.first*2][here.second+3] = true;
                    bfsq.push({here.first*2, here.second+3});
                }
                if(check(here.first+1, here.second, vectorSize, visited)){
                    visited[here.first+1][here.second] = true;
                    bfsq.push({here.first+1, here.second});
                }
            }
            ans++;
            // cout<<"ans increased"<<'\n';
        }
        end:
        cout<<ans<<'\n';
    }
	return 0;
}