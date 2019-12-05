// 일반 문제풀이용 템플릿
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
class tree{
	public:
	int n;
	vi lc,rc;
	tree():n(0){}
	tree(int n):n(n){
		lc.resize(n,-1);
		rc.resize(n,-1);
	}
	void setchild(int p, int l, int r){
		lc[p]=l;
		rc[p]=r;
	}
	void preorder(int root){
		printf("%c",(char)(root+'A'));
		if(lc[root]!=-1)
			preorder(lc[root]);
		if(rc[root]!=-1)
			preorder(rc[root]);
	}
	void inorder(int root){
		if(lc[root]!=-1)
			inorder(lc[root]);
		printf("%c",(char)(root+'A'));
		if(rc[root]!=-1)
			inorder(rc[root]);
	}
	void postorder(int root){
		if(lc[root]!=-1)
			postorder(lc[root]);
		if(rc[root]!=-1)
			postorder(rc[root]);
		printf("%c",(char)(root+'A'));
	}
};
int main(){
	int N;
	scanf("%d\n", &N);
	tree t(N); // 노드 7개
	// 번호 0부터 시작
	for(int i=0;i<N;i++){
		char a,b,c;
		scanf("%c %c %c\n", &a, &b, &c);
		int b1=(b=='.'? -1:b-'A');
		int c1=(c=='.'? -1:c-'A');
		t.setchild(a-'A',b1,c1);
	}
	t.preorder(0);
	printf("\n");
	t.inorder(0);
	printf("\n");
	t.postorder(0);
	printf("\n");
	return 0;
}