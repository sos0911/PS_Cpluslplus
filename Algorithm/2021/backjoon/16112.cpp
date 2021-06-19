// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vector<int> input_val(n,0);
    for(int i=0;i<n;i++)
        cin>>input_val[i];
    sort(input_val.begin(), input_val.end());
    // 순서대로 계산
    int cur_act=0;
    ll ans=0;
    for(int i=0;i<n;i++){
        ans += (ll)cur_act * input_val[i];
        cur_act = min(cur_act+1, k);
    }
    cout<<ans<<'\n';
	return 0;
}