#include <iostream>
#include <string>
#include <cstring>
#include <deque>
// deque는 vector로 대체할 수 있는듯?
using namespace std;
int main(){
	int noftc;
	cin>>noftc;
	cin.get(); // 개행 제거 
	for(int i=0;i<noftc;i++){
		string inst;
		getline(cin, inst);
		int nofe;
		cin>>nofe; 
		cin.get();
		string mem;
		getline(cin, mem);
		// cin 버퍼에서 한 줄 긁어와서 mem에 저장
		mem=mem.substr(1, mem.length()-2);
		// 앞뒤 자름
		deque<int> cont;
		char* cstr=const_cast<char*>(mem.c_str());
		// 강제 형변환(const -> char)
		char* sp=nullptr;
		sp=strtok(cstr, ",");
		while(sp!=nullptr){
			cont.push_back(stoi(string(sp)));
			sp=strtok(NULL, ",");
		}
		bool rev=false; // 지금 순서가 반대인가?
		bool error=false;
		// 지시를 읽는다.
		for(size_t i=0;i<inst.length();i++){
			char temp=inst[i];
			error=false;
			switch(temp){
				case 'R':
					rev=!rev;
					break;
				case 'D':
					if(!cont.empty())
					rev? cont.pop_back():cont.pop_front();
					else{
					cout<<"error"<<'\n';
					error=true;
					}
					break;
			}
			if(error)
				break;
		}
		// 결과 출력
		if(!error){
			cout<<'[';
			if(!cont.empty()){
		if(!rev){
			deque<int>::iterator iter;
			for(iter=cont.begin();iter!=cont.end()-1;++iter)
				cout<<*iter<<",";
			cout<<*iter;
		}
		else{
			deque<int>::reverse_iterator riter;
			for(riter=cont.rbegin();riter!=cont.rend()-1;++riter)
				cout<<*riter<<",";
			cout<<*riter;
		}
			}
			cout<<']'<<'\n';
		}
	}
	return 0;
}