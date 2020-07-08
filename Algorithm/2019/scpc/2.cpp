
#include <bits/stdc++.h>
#define fi dirst;
#define se second;
#define _USE_MATH_DEFINES
#define cond(rad) ((rad*180)/M_PI)
using namespace std;
typedef vector<pair<pair<int,int>, int>> vpi;
double Answer;
int main(int argc, char** argv)
{
	int T, test_case;
	// freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		int r,s,e,n;
		scanf("%d %d %d", &r,&s,&e);
		scanf("%d", &n);
		Answer = e-s;
		for(int i=0;i<n;i++){
			int le,ri,h;
			scanf("%d %d %d", &le, &ri, &h);
			if(h>=r){
				Answer+=2*(h-r);
				Answer-=2*r;
				Answer+=r*M_PI;
			}
			else{ // 높이가 작은 경우
				double rad=acos((r-h)/r);
				Answer-=2*(r/sin(rad));
				cout<<"test : "<<r/sin(rad)<<'\n';
				Answer+=2*2*r*M_PI*(cond(rad)/360);
				cout<<"rad : "<<rad<<'\n';
				cout<<"test3 : "<<rad*180<<'\n';
				cout<<"PI : "<<M_PI<<'\n';
				cout<<"test2 : "<<((rad*180)/M_PI)<<'\n';
			}
		}
		printf("Case #%d\n",test_case+1);
		printf("%lf\n", Answer);
		//cout << "Case #" << test_case+1 << endl;
		//cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}