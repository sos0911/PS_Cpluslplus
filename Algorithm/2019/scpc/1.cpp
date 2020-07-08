/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;
int Answer;
vector<int> dp;
vector<int> sum;
const int stn=1000001;
int main(int argc, char** argv)
{
    //cin.tie(NULL);
	//cout.tie(NULL);
	//ios_base::sync_with_stdio(false);
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

	//freopen("sample_input.txt", "r", stdin);
    dp.assign(stn, -1);
    sum.assign(stn,0);
    dp[1]=0; dp[2]=1;
    int idx=4;
    while(idx!=stn-1){
        for(int i=0;i<2;i++)
            dp[idx-i]=((idx-i)%2==0? dp[(idx-i)/2]+1:dp[idx-i+1]+1);
            idx+=2;
    }
    int tsum=0;
    for(int i=1;i<=stn-1;i++){
        tsum+=dp[i];
        sum[i]=tsum;
    }
	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{

		Answer = 0;
	    int a,b;
	    scanf("%d %d", &a, &b);
	    Answer=sum[b]-sum[a-1];
		// Print the answer to standard output(screen).
		//cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
		printf("Case #%d\n", test_case+1);
		printf("%d\n", Answer);
	}

	return 0;//Your program should return 0 on normal termination.
}