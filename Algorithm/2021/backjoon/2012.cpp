// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    int n;
    vector<int> input_vec;
    cin>>n;
    input_vec.reserve(n);
    for(int i=0;i<n;i++)
        cin>>input_vec[i];
    sort(input_vec.begin(), input_vec.end());
    queue<int> far_empty;
    vector<bool> empty(true, n+1);
    int ans=0;
    // far_empty : queue, 현재 자기 수 앞에서 빈 애들만 모아놓기
    for(int i=0;i<n;i++)
        if(i==0){
            for(int j=1;j<input_vec[i];j++)
                far_empty.push(j);
        }
        else{
            for(int j=input_vec[i-1]+1;j<input_vec[i];j++)
                far_empty.push(j);
        }
    for(int i=0;i<n;i++){
        if(empty[input_vec[i]]){
            empty[input_vec[i]] = false;
        }
        else{
            int cand = far_empty.front();
            far_empty.pop();
            cout<<"cand : "<<cand<<" , cur : "<<input_vec[i]<<'\n';
            empty[cand] = false;
            ans += input_vec[i] - cand;
        }
    }
    cout<<ans<<'\n';
	return 0;
}