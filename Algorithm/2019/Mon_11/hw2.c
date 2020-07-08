#include <stdio.h>
#include <malloc.h>
#include <cstring>
int price[100], cache[100], dp[100];
// cache[i] : i길이 통나무 자를때 fc
int n;
int solve(int len){
	if(!len)
		return 0;
	if(dp[len]!=-1)
		return dp[len];
	int* ret=&dp[len];
	for(int i=1;i<=len;i++){
		int temp=price[i]+solve(len-i);
		if(temp>*ret){
			*ret=temp;
			cache[len]=i;
		}
	}
	return *ret;
}
int main(){
	scanf("%d", &n);
	for(int i=1;i<=n;i++)
		scanf("%d", &price[i]);
	memset(dp,-1,sizeof(dp)); // -1 초기화
	printf("%d\n",solve(n));
	int ilen=n;
	while(ilen){
		printf("%d\n",cache[ilen]);
		ilen-=cache[ilen];
	}
}