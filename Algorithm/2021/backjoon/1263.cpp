// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
bool cmp(pii& a, pii& b){
    return a.second > b.second;
}
int main(){
    int n;
    cin>>n;
    // (ti, si)
    vpi input_vec(n, {-1,-1});
    for(int i=0;i<n;i++)
        cin>>input_vec[i].first>>input_vec[i].second;
    sort(input_vec.begin(), input_vec.end(), cmp);
    // 뒤에서부터 순서대로 붙인다.
    vector<int> over_time(n, 0);
    int first_time = input_vec[0].second - input_vec[0].first;
    for(int i=1;i<n;i++){
        if(first_time > input_vec[i].second)
            over_time[i] = first_time - input_vec[i].second;
        first_time = first_time - input_vec[i].first;
    }
    int max_overtime = 0;
    for(int i=0;i<n;i++){
        max_overtime = max(max_overtime, over_time[i]);
        // cout<<over_time[i]<<'\n';
    }
    // cout<<"first_time : "<<first_time<<'\n';
    cout<<(first_time - max_overtime < 0? -1 : first_time - max_overtime)<<'\n';
	return 0;
}