

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

	cin >> T;
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = 0;
		int n;
		cin>>n;
		int a[n], b[n]; // 0-(n-1)
		FOR1(i,n)
			cin>>a[i];
		FOR1(i,n)
			cin>>b[i];
		int ret=0; // 유사도
		int psum[n]; // 0-n까지의 부분합
		psum[0]=a[0]==b[0]? 1:0;
		ret=psum[0];
		for(int i=1;i<n;i++){
			if(a[i]==b[i]){
				ret++;
				psum[i]=psum[i-1]+1;
			}
			else
				psum[i]=psum[i-1];
		}
		int init=ret; // 안 바꿀 시 유사도
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){ // [i,j]
				int st=i, ed=j, sum=0;
				while(st!=j+1)
					if(b[st++]==a[ed--])
						sum++;
				ret=max(ret,init-(psum[j]-(i-1>=0? psum[i-1]:0))+sum);
			}
		Answer=ret;
		cout << "Case #" << test_case+1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}