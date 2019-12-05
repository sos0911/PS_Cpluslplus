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
int main(){
	// 그냥 격차 큰것부터 본다음 빼 주면 된다.
	// 너무 복잡하게 생각했다.
	// 빼는 범위가 붙어 있어도 해당 부위에 [x,x]인 집중국을 세우면 그만이다.
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	int sensor[n]; // 센서 위치
	int diff[n-1]; // 격차 수치, index a(a번 센서와 a+1번 센서 사이 뜻함)
	FOR1(i,n)
		cin>>sensor[i];
	sort(sensor, sensor+n); // 오름차순 정렬
	int ret=0;
	FOR1(i,n-1){
		diff[i]=sensor[i+1]-sensor[i];
		ret+=sensor[i+1]-sensor[i];	
	}
	sort(diff, diff+n-1, greater<int>());
	int itern=0;
	FOR1(i,(k-1>n-1? n-1:k-1))
		ret-=diff[i];
	cout<<ret<<'\n';
	return 0;
}
/*
1  3  6  7  9

 +2 +3 +1 +2

격차 중 하나씩 건너뛰어야 한다. (아니 모두 다 포함하면 오히려 안된다)
건너뛰는 수는 k번이다.
그냥 격차들 다 센다음에 격차 내림차순 정렬해서 앞 k개 빼면 되지않을까??
 
1 3 6 10 11 13

 2 3 4 1 2

k=3

어차피 그 수 기준으로 앞뒤 격차 중 작은 건 무조건 선택해야 한다.
1번 빼면 2개
2번 빼면 3개
..
격차 내림차순 정렬 -> 하나씩 k-1번이 될 때까지 빼보는데
센서가 고립되면 안되므로 visit 표시 하면서 빼보기
a번 격차 뺄때 a번 센서의 오른쪽과 a+1번 센서의 왼쪽이 고립된다.
*/