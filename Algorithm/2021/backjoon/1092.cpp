// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
bool cmp(int a, int b){
    return a<b;
}
int main(){
    int n, m;
    cin>>n;
    vi crane(n, -1);
    for(int i=0;i<n;i++)
        cin>>crane[i];
    cin>>m;
    vi box(m, -1);
    for(int i=0;i<m;i++)
        cin>>box[i];
    sort(crane.begin(), crane.end(), cmp);
    sort(box.begin(), box.end(), cmp);
    if(box[m-1] > crane[n-1]){
        cout<<-1<<'\n';
        return 0;
    }
    // 각 크레인당 할당된 박스들
    // 자기만 들수있고 다른 애들은 못 드는
    vi allocated_box(n, 0);
    int cur_crane_idx = 0;
    for(int i=0;i<m;i++){
        if(cur_crane_idx >= n)
            break;
        if(box[i] <= crane[cur_crane_idx])
            allocated_box[cur_crane_idx]++;
        else{
            while(box[i] > crane[cur_crane_idx])
                cur_crane_idx++;
            if(cur_crane_idx < n)
                allocated_box[cur_crane_idx]++;
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<allocated_box[i]<<" ";
    // cout<<'\n';
    int moved_box_cnt = 0;
    int ans=0;
    while(moved_box_cnt < m){
        for(int i=0;i<n;i++){
            if(allocated_box[i] > 0){
                allocated_box[i]--;
                moved_box_cnt++;
            }
            else{
                // 자신보다 작은 애들의 물품을 가져옴
                for(int j=i-1;j>=0;j--)
                    if(allocated_box[j] > 0){
                        allocated_box[j]--;
                        moved_box_cnt++;
                        break;
                    }
            }
        }
        ans++;
    }
    cout<<ans<<'\n';
	return 0;
}