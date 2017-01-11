/*input
5
10 20 30 40 50
30
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void binary_search(int data[], int l, int r, int x) {
	int mid = (l+r) / 2;
	if (l > r) printf("Element not found.\n");
	else if (x < data[mid]) return binary_search(data, l, r-1, x);
	else if (x > data[mid]) return binary_search(data, l+1, r, x);
	else printf("Element found at position %d.\n", mid);
}

int compare(const void *a, const void *b) {
	return ((int *) a > (int *) b);
}

int main() {
	int i, j, n, data[10], x;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &data[i]);
	qsort(data, n, sizeof(int), compare);
	scanf("%d", &x);
	binary_search(data, 0, n-1, x);
	return 0;
}