#include <iostream>
#include <string>
#include <sstream>
#include <array>
using namespace std;
class Node{
	int data;
	// 정수형 저장. template pass
	Node* prev;
	Node* next;
	public:
	Node(int data=0, Node* prev=nullptr, Node* next=nullptr):data(data),prev(prev),next(next){}
	Node* getprev() const{return prev;}
	Node* getnext() const{return next;}
	int getdata() const{return data;}
	void setprev(Node* _prev){
		prev=_prev;
	}
	void setnext(Node* _next){
		next=_next;
	}
};
class Deque{
	// 맨 앞과 맨 뒤를 가리킨다.
	Node* front;
	Node* back;
	int size;
	public:
	Deque():front(nullptr),back(nullptr),size(0){}
	~Deque(){} // delete할 떄마다 메모리 해제하니 할 게 없음
	void push_front(int data);
	void push_back(int data);
	int pop_front();
	int pop_back();
	int getsize();
	// size 반환
	bool empty();
	int getfront();
	int getback();
};
void Deque::push_front(int data){
	// 앞에 data를 넣는다.
	Node* newnode=new Node(data); // default
	if(empty())
		front=back=newnode;
	else{
		// 하나 이상 있을때
		newnode->setnext(front);
		front->setprev(newnode);
		front=newnode;
	}
	size++;
}
void Deque::push_back(int data){
	Node* newnode=new Node(data);
	if(empty())
		front=back=newnode;
	else{
		newnode->setprev(back);
		back->setnext(newnode);
		back=newnode;
	}
	size++;
}
int Deque::pop_front(){
	// 앞에서 하나 뽑아내고 제거
	if(empty())
		return -1;
	else{
		int ret=getfront();
		Node* temp=front;
		front=front->getnext();
		if(front!=nullptr)
			front->setprev(nullptr);
		delete temp;
		size--;
		return ret;
	}
}
int Deque::pop_back(){
	// 뒤에서 하나 뽑아냄
if(empty())
		return -1;
	else{
		int ret=getback();
		Node* temp=back;
		back=back->getprev();
		if(back!=nullptr) // 방금 뺴낸 게 last면 deque는 비게 된다.
			back->setnext(nullptr);
		delete temp;
		size--;
		return ret;
	}
}
int Deque::getsize(){
	return size;
}
bool Deque::empty(){
	return size==0;
}
int Deque::getfront(){
	// 제일 앞 반환
	if(!empty())
	return front->getdata();
	else
		return -1;
}
int Deque::getback(){
		if(!empty())
	return back->getdata();
	else
		return -1;
}
int main(){
	array<string, 8> menu={"push_front", "push_back", "pop_front", "pop_back", "size", "empty", "front", "back"}; // 유니폼 초기화
	string nofi;
	getline(cin, nofi);
	string input;
	stringstream ss;
	Deque dq; // deque 생성
	for(int i=0;i<stoi(nofi);i++){ // ++i?
		getline(cin, input);
		// 한 줄 입력받음
		ss.str(input); // ss에 문자열 집어넣음
		string temp;
		ss>>temp;
		if(temp.compare(menu[0])==0){
			ss>>temp;
			dq.push_front(stoi(temp));
		}
		else if(temp.compare(menu[1])==0){
			ss>>temp;
			dq.push_back(stoi(temp));
		}
		else if(temp.compare(menu[2])==0)
			cout<<dq.pop_front()<<endl;
		else if(temp.compare(menu[3])==0)
			cout<<dq.pop_back()<<endl;
		else if(temp.compare(menu[4])==0)
			cout<<dq.getsize()<<endl;
		else if(temp.compare(menu[5])==0)
			cout<<dq.empty()<<endl;
		else if(temp.compare(menu[6])==0)
			cout<<dq.getfront()<<endl;
		else if(temp.compare(menu[7])==0)
			cout<<dq.getback()<<endl;
	ss.clear();
	}
	return 0;
}