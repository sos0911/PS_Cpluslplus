// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<string> vs;
bool sub_search(int st, int ed, string str){
    // 만약 부분수열이 팰린드롬이면 true
    while(st<ed){
        if(str[st] != str[ed])
            return false;
        st++;
        ed--;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    vs input_string(t, "");
    for(int i=0;i<t;i++)
        cin>>input_string[i];
    // 처음과 끝에서부터 차례로 비교
    for(int i=0;i<t;i++){
        int st=0,ed=input_string[i].size()-1;
        int ans=0;
        while(st<ed){
            if(input_string[i][st] != input_string[i][ed]){
                ans=1;
                if(sub_search(st+1, ed, input_string[i]) || sub_search(st, ed-1, input_string[i]))
                    break;
                else{
                    ans=2;
                    break;
                }
            }
            else{
                st++;
                ed--;
            }
        }
        cout<<ans<<'\n';
    }
	return 0;
}