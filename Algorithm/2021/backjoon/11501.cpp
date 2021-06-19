// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
bool cmp(pii a, pii b){
    return a.first > b.first;
}
int main(){
    cin.tie(NULL);
	// cout.tie(NULL);
	// ios_base::sync_with_stdio(false);
    // (주가, 날짜)
    int noft;
    cin>>noft;
    for(int i=0;i<noft;i++){
        int n;
        cin>>n;
        vector<pii> sorted_info(n,{0,0});
        vector<int> input_val(n,0);
        for(int j=0;j<n;j++){
            cin>>input_val[j];
            sorted_info[j].first = input_val[j];
            sorted_info[j].second = j;
        }
        sort(sorted_info.begin(), sorted_info.end(), cmp);
        // 차례대로 하나씩 체크하면서 결과 추합
        ll ans=0;
        int checkidx=-1;
        for(int j=0;j<n;j++){
            for(int k=checkidx+1;k<sorted_info[j].second;k++){
                // cout<<sorted_info[j].first<<" "<<input_val[k]<<'\n';
                // assert(sorted_info[j].first - input_val[k] >= 0);
                ans += sorted_info[j].first - input_val[k];
            }
            checkidx=max(checkidx, sorted_info[j].second);
        }
        cout<<ans<<'\n';
    }
	return 0;
}