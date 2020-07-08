#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
// use functor
struct comp{
	bool operator()(const string& a, const string& b){
		if(a.size()!=b.size())
			return a.size()<b.size();
		else{
			int rea=0,reb=0;
			for(int i=0;i<a.size();i++)
				if(a[i]>='0'&&a[i]<='9')
					rea+=a[i]-'0';
			for(int i=0;i<b.size();i++)
				if(b[i]>='0'&&b[i]<='9')
					reb+=b[i]-'0';
			if(rea!=reb)
				return rea<reb;
			else
				return a<b;
		}
	}	
};
int main(){
	int n;
	//cin>>n;
	scanf("%d", &n);
	vector<string> cont;
	cont.reserve(n);
	string input;
	for(int i=0;i<n;i++){
		//cin>>input;
		char temp[52];
		scanf("%s", temp);
		input=temp;
		cont.push_back(input);
	}
	sort(cont.begin(), cont.end(), comp());
	for(string s:cont)
		printf("%s\n", s.c_str());
	return 0;
}