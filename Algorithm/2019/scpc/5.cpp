/*
You should use the standard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful. 
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Answer;
int main(int argc, char** argv)
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	//setbuf(stdout, NULL);
	int T, test_case;
	

	// freopen("input.txt", "r", stdin);

	cin >> T;
	//scanf("%d", &T);
	for(test_case = 0; test_case  < T; test_case++)
	{
		Answer = -1;
		ll le,ri;
		//scanf("%lld %lld", &le, &ri);
		cin>>le>>ri;
		ll nofo;
			//scanf("%lld", &nofo);
			cin>>nofo;
			 vector<pair<ll,ll>> cont(nofo);
		for(int i=0;i<nofo;i++)
			cin>>cont[i].first>>cont[i].second;
		    //scanf("%lld %lld", &cont[i].first, &cont[i].second);
		// 모든 두 점 쌍의 x좌표 중앙값을 구한다.
		for(ll i=0;i<nofo;i++){
			for(ll j=i+1;j<nofo;j++){
				ll cx2=cont[i].first+cont[j].first;
				if(cx2<le*2||cx2>ri*2)
				continue;
				ll temp=1e14;
				for(ll k=0;k<nofo;k++){
					ll temp2=-1;
					 temp2=max(temp2, abs(2*cont[k].first-cx2));
		    		temp2=max(temp2, abs(cont[k].second)*2);
					temp=min(temp,temp2);
				}
				//cout<<"temp : "<<temp<<'\n';
				Answer=max(Answer, temp);
			}
		}
		// Print the answer to standard output(screen).
		//printf("Case #%d\n", test_case+1);
		//printf("%lld\n", Answer);
		cout << "Case #" << test_case+1 << '\n';
		cout << Answer << '\n';
	}

	return 0;//Your program should return 0 on normal termination.
}