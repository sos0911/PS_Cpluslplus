// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
int main(){
    int n,m;
    cin>>n>>m;
    vs input_strings(n, "");
    for(int i=0;i<n;i++)
        cin>>input_strings[i];
    int sum_len = 0;
    for(int i=0;i<n;i++)
        sum_len += input_strings[i].length();
    int min_cnt_under = (m - sum_len)/(n-1), remainder = (m - sum_len)%(n-1);
    // 순서대로 출력
    for(int i=0;i<n;i++){
        cout<<input_strings[i];
        if(i != n-1){
            for(int j=0;j<min_cnt_under;j++)
                cout<<"_";
            if((input_strings[i+1][0] >= 'a' || n-2 - i < remainder) && remainder > 0){
                cout<<"_";
                remainder--;
            }
        }
    }
    cout<<'\n';
	return 0;
}