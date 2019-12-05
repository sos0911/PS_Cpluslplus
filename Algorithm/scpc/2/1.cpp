
#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=0;i<n;i++)
#define FOR2(i,j,k) for(int i=j;i<k;i++)
#define fi first
#define se second
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef long long ll;
typedef priority_queue<int> pq;
typedef vector<pii> vpi;
int Answer;
bool prime[30001];
int solve(int tar){
	// 완전탐색으로 찾아낼 수 있는 최대 소수개수를 찾는다.
	if(to_string(tar).size()==1) // 1자리수
		return prime[tar];
	if(!prime[tar])
		return 0;
	int ret=0;
	string temp=to_string(tar);
	int len=temp.size();
	for(int i=0;i<len;i++){
		string temp2=temp;
		ret=max(ret,solve(stoi(temp2.erase(i,1)))+1); // 자기 자신은 소수
	}
	return ret;
}
int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */	

	// freopen("input.txt", "r", stdin);
	fill(prime, prime+30001, true);
	prime[1]=false; prime[0]=false;
	for(int i=2;i<=sqrt(30000);i++){
		if(prime[i])
			for(int j=2*i;j<=30000;j+=i)
				prime[j]=false;
	}
	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
		int a,b;
		cin>>a>>b;
		int ansa=solve(a), ansb=solve(b);
		if(ansa>ansb)
			Answer=1;
		else if(ansa<ansb)
			Answer=2;
		else
			Answer=3;
		// Print the answer to standard output(screen).
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}