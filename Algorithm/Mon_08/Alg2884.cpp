// string을 쓰는 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
int h,m;
int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>h>>m;
	m-=45;
	if(m<0){
		h--;
		m+=60;
	}
	if(h<0)
		h+=24;
	cout<<h<<" "<<m<<'\n';
	return 0;
}