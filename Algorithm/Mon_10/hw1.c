#include <stdio.h>
#include <malloc.h>
int* heap;
int n, heapsize;
void max_heafify(int node) {
	// 큰 게 앞으로 오도록 조정
	int larind = node;
	if (node * 2 <= heapsize && heap[node * 2] > heap[larind])
		larind = node * 2;
	if (node * 2 + 1 <= heapsize && heap[node * 2 + 1] > heap[larind])
		larind = node * 2 + 1;
	if (larind != node) {
		int temp = heap[node];
		heap[node] = heap[larind];
		heap[larind] = temp;
		max_heafify(larind);
	}
}
void build_heap() {
	heapsize = n;
	for (int i = heapsize / 2; i >= 1; i--)
		max_heafify(i); // 실제 노드 번호는 1부터.
}
void heapsort() {
	build_heap();
	for (int i = n; i >= 2; i--) {
		int temp = heap[i];
		heap[i] = heap[1];
		heap[1] = temp;
		heapsize--;
		// 가장 큰 원소를 아래로 내렸으므로 이제 그건 힙에서 빼는 것을 묘사
		max_heafify(1);
	}
}
int main() {
	scanf("%d", &n);
	heap = (int*)malloc(sizeof(int) * (n + 1));
	for (int i = 1; i <= n; i++)
		scanf("%d", &heap[i]);
	// build heap complete
	heapsort();
	for (int i = 1; i <= n; i++)
		printf("%d\n", heap[i]);
}