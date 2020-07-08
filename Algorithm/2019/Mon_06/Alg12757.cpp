#include <iostream>
#include <map>
#include <cmath>
using namespace std;
const int maxn=1000100000;
const int minn=-20000;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	// input string이 없으므로 cin만 써야지
	int n,m,k;
	cin>>n>>m>>k;
	map<int, int> cont; 
	cont.insert({maxn,-1});
	cont.insert({minn,-1});
	// vector 정렬 기준 set 시 struct comp
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		cont.insert({a, b});
		// 기본적으로 key에 대해 오름차순 정렬
	}
	for(int i=0;i<m;i++){
		int ord;
		cin>>ord;
		switch(ord){
			case 1:{
				int key,val;
				cin>>key>>val;
				cont.insert({key, val});
				break;
			}
			case 2:{
				int key, val;
				cin>>key>>val;
				auto res=cont.find(key);
				if(res!=cont.end())
					res->second=val;
				else{ // 정확한 키를 갖는 info x
					// size=1이나 lowitr이 end일때 조심
					auto lowitr=cont.lower_bound(key);
					int hikey=lowitr->first;
					int lokey=(--lowitr)->first;
					if(abs(key-lokey)<=k||abs(key-hikey)<=k){
						// 하나라도 만족하는 key가 있는 경우
					if(abs(key-lokey)<abs(key-hikey))
						lowitr->second=val;
					else if(abs(key-lokey)>abs(key-hikey))
						(++lowitr)->second=val;
					}
				}
				break;
			}
			case 3:{
				int key;
				cin>>key;
				auto res=cont.find(key);
				if(res!=cont.end())
					cout<<res->second<<'\n';
				else{ // 정확한 키를 갖는 info x
					auto lowitr=cont.lower_bound(key);
					int hikey=lowitr->first;
					int hival=lowitr->second;
					int lokey=(--lowitr)->first;
					int loval=lowitr->second;
					if(abs(key-lokey)<=k||abs(key-hikey)<=k){
						// 하나라도 만족하는 key가 있는 경우
					if(abs(key-lokey)<abs(key-hikey))
						cout<<loval<<'\n';
					else if(abs(key-lokey)>abs(key-hikey))
						cout<<hival<<'\n';
					else
						cout<<"?"<<'\n';
					}
					else
					cout<<-1<<'\n';
				}
				break;
			}
		}
	}
	return 0;
}