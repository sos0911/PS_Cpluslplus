#include <bits/stdc++.h>
using namespace std;
string answer = "";
string num;
int tok;
void solve(int st, int n){
	cout<<"solve st : "<<st<<" n : "<<n<<'\n';
    if(n==0)
        return;
    // 한개씩 찾아본다.
    // 같을 경우 앞쪽에 위치한 걸 가져가므로 괜찮
    // 뒤에 일정량 남겨둔다
    int maxd=num[st]-'0', idx=st;
	cout<<"st : "<<st<<" ed : "<<num.size()-n<<'\n';
    for(int i=st;i<=num.size()-1-(n-1);i++)
       if(num[i]-'0'>maxd){
           maxd=num[i]-'0';
           idx=i;
       }
	cout<<"maxd : "<<maxd<<'\n';
    answer+=to_string(maxd);
    solve(idx+1,n-1);
}
string solution(string number, int k) {
    num=number;
    tok=k;
    solve(0,(int)number.size()-k);
    // number.size()-k개를 뽑아야 함.
    return answer;
}
int main(){
	int k;
	string temp;
	cin>>k>>temp;
	cout<<solution(temp,k)<<'\n';
	return 0;
}