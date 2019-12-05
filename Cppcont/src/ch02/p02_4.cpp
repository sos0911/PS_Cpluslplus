#include <iostream>
#include <cstring> // c++ 스타일 헤더인듯
using namespace std;
// cstring 내 표준 lib 함수를 사용한다.
int main(){
	// char* / char[] / string 세 가지 방법이 있다.
	// 동적 할당이 아닌 컴파일 할당이다.(보통 할당)
	char test[30], test2[30]; // 최대 30글자. 입력 시 자동으로 끝에 null이 붙는 모양이다!
	cin>>test>>test2; // 두 행에 걸쳐 입력
	cout<<"len of F: "<<strlen(test)<<endl;
	cout<<"concat result : "<<strcat(test, test2)<<endl;
	char test3[30];
	strcpy(test3, test);
	cout<<"copy result : "<<test3<<endl;
	if(strcmp(test3, test)==0)
		cout<<"same! : "<<test3<<" "<<test<<endl;
	else
		cout<<"not same! : "<<test3<<" "<<test<<endl;
	return 0;
}