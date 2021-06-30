// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
typedef pair<int,int> pii;
using namespace std;
void cmp(pii a, pii b){
    return a
}
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<pii> input_vec(n,{0,0});
    // (ti, si)s
    for(int i=0;i<n;i++)
        cin>>input_vec[i].first>>input_vec[i].second;
    // 데드라인 si가 빠른 대로 정렬
    sort(input_vec.begin(), input_vec.end(), cmp);


	return 0;
}