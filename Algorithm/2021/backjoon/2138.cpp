// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string bef, af;
    cin>>bef>>af;
    vector<int> sum_res(n, 0);
    // 제일 앞에 따라 initiate 변경
    int ans=-1, cand=0;
    for(int i=1;i<n;i++){
        if(af[i-1] % 2 != (bef[i-1] + sum_res[i-1]) % 2){
            for(int j=-1;j<=1;j++){
                if(i+j >= n)
                    continue;
                sum_res[i+j]++;    
            }        
            cand++;
        }
    }
    if(af[n-1] % 2 == (bef[n-1] + sum_res[n-1]) % 2)
        ans = ans==-1? cand : min(ans,cand);
    // 이번엔 1로 초기화
    fill(sum_res.begin(), sum_res.end(), 0);
    cand=1;
    sum_res[0]=1, sum_res[1]=1;
    for(int i=1;i<n;i++)
        if(af[i-1] % 2 != (bef[i-1] + sum_res[i-1]) % 2){
            for(int j=-1;j<=1;j++){
                if(i+j >= n)
                    continue;
                sum_res[i+j]++;    
            }        
            cand++;
        }
    if(af[n-1] % 2 == (bef[n-1] + sum_res[n-1]) % 2)
        ans = ans==-1? cand : min(ans,cand);
    cout<<ans<<'\n';
	return 0;
}