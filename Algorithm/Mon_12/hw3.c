#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define max(a,b) ((a) > (b)? (a) : (b))
int n;
int adjm[26][26]; // edge들 저장
int dist[26]; // result
const int INF = 1e9;

// info
typedef struct Info {
	char node;
	int dist;
}Info;
// heap
Info* heap;
int heapsize;

void heapst_st(int n) {
	heap = (Info*)malloc(sizeof(Info) * (n + 1));
	heapsize = 0;
}
// 힙 메서드 구현
void min_heafify(int node) {
	// 작은 게 앞으로 오도록 조정
	// 가장 작은 값의 배열 내 index : sind
	int sind = node;
	if (node * 2 <= heapsize)
		if ((heap[node * 2].dist < heap[sind].dist) || ((heap[node * 2].dist == heap[sind].dist) && heap[node * 2].node < heap[sind].dist))
			sind = node * 2;
	if (node * 2+1 <= heapsize)
		if ((heap[node * 2+1].dist < heap[sind].dist) || ((heap[node * 2+1].dist == heap[sind].dist) && heap[node * 2+1].node < heap[sind].dist))
			sind = node * 2+1;
	if (sind != node) {
		Info temp = heap[node];
		heap[node] = heap[sind];
		heap[sind] = temp;
		min_heafify(sind);
	}
}
void build_heap(int n) {
	heapsize = n;
	for (int i = heapsize / 2; i >= 1; i--)
		min_heafify(i); // 실제 노드 번호는 1부터.
}

// pq

void priority_queue_st(int size) {
	heapst_st(size);
}

int Isempty()	{
	return !heapsize ? 1 : 0;
}

Info peektop() {
	return heap[1];
}
Info removetop() {
	Info temp = heap[1];
	heap[1] = heap[heapsize];
	heapsize--;
	min_heafify(1);
	return temp;
}
void decrease_key(int idx, int key) {
	heap[idx].dist = key;
	while (idx > 1 && ((heap[idx / 2].dist > heap[idx].dist) || ((heap[idx / 2].dist == heap[idx].dist) && (heap[idx / 2].node > heap[idx].node)))){
		Info temp = heap[idx / 2];
		heap[idx / 2] = heap[idx];
		heap[idx] = temp;
		idx /= 2;
	}
}
void insert(Info in) {
	heapsize++;
	heap[heapsize] = in;
	heap[heapsize].dist = INF;
	decrease_key(heapsize, in.dist);
}



int main() {
	char in[200];
	scanf("%s", in);
	scanf("%d", &n);
	// 알파벳 > index
	for (int i = 0; i < 26; i++)
		for(int j=0;j<26;j++)
			adjm[i][j]=INF;
	for (int i = 0; i < 26; i++)
		dist[i] = INF;
	// -1로 초기화
	char linein[200];
	for (int i = 0; i < n; i++) {
		scanf("%s", linein);
		char a, b;
		int dist;
		char* ptr = strtok(linein, ",");
		a = *ptr;
		ptr = strtok(NULL, ",");
		b = *ptr;
		ptr = strtok(NULL, ",");
		dist = atoi(ptr);
		adjm[(int)(a - 'A')][(int)(b - 'A')] = dist;
	}
	// dijkstra
	priority_queue_st(200);
	Info st = { 'A', 0 };
	insert(st);
	dist[0] = 0;
	while (!Isempty()) {
		Info temp = removetop();
		//printf("taken : %c %d\n", temp.node, temp.dist);
		for (int i = 0; i < 26; i++) {
			if (dist[temp.node - 'A'] + adjm[temp.node - 'A'][i] < dist[i]) {
				dist[i] = dist[temp.node - 'A'] + adjm[temp.node - 'A'][i];
				//temp = { (char)('A' + i), dist[i] };
				Info temp2;
				temp2.node = (char)('A' + i);
				temp2.dist = dist[i];
				//printf("insert : %c %d\n", temp2.node, temp2.dist);
				insert(temp2);
			}

		}
	}
	for (int i = 0; i < 26; i++)
		if (dist[i] != INF)
			printf("%d\n", dist[i]);
}