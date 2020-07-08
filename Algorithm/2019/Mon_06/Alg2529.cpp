#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	int k;
	cin>>k;
	cin.get(); // \n
	vector<int> cont;
	vector<bool> visit(20,false); // 0-19
	cont.reserve(k+1);
	cont.push_back(10); // 첫 원소는 10
	visit[10]=true;
	int maxn=10, minn=10;
	char input;
	for(int i=0;i<k;i++){
		cin>>input;
		cout<<input<<endl;
		int temp=cont[i];
		if(input=='<')
			while(visit[++temp]);
		else
			while(visit[--temp]);
		cont.push_back(temp);
		visit[temp]=true;
		maxn=max(maxn, temp);
		minn=min(minn, temp);
	}
	string maxs, mins;
	for(int i=0;i<k+1;i++)
		maxs.append(to_string(cont[i]-(maxn-9)));
	for(int i=0;i<k+1;i++)
		mins.append(to_string(cont[i]-minn));
	cout<<maxs<<'\n'<<mins<<'\n';
	return 0;
}