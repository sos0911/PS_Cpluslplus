#include <iostream>
#include <vector>
using namespace std;
const int maxn=2e9+1;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> arr;
	arr.reserve(n);
	int input;
	for(int i=0;i<n;i++){
		cin>>input;
		arr.push_back(input);
	}
	int st=0,ed=n-1,sti,edi, diff=maxn;
	while(st<ed){
		if(abs(arr[st]+arr[ed])<diff){
			sti=st;
			edi=ed;
			diff=abs(arr[st]+arr[ed]);
		}
		if(arr[st]+arr[ed]>0)
			ed--;
		else if(arr[st]+arr[ed]<0)
			st++;
		else // 답을 찾음(0)
			break;
	}
	cout<<arr[sti]<<" "<<arr[edi]<<'\n'; 
	return 0;
}