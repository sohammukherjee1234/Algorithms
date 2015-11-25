#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *data, int begin, int end) {
    int i, pivot = data[end],  index = begin; // index will store the final position pivot element goes to, i.e the point of partition
    for (i = begin; i <= end-1; i++) {
        if (data[i] <= pivot) {
            swap(&data[i], &data[index]);
            index++;
        }
    }
    swap(&data[index], &data[end]);
    return index;
}

void quicksort(int *data, int begin, int end) {
    if (begin < end) { // begin == end is the case of single element and begin > end is an invalid case that occurs when one side of the partition is empty
        int index = partition(data, begin, end);
        quicksort(data, begin, index-1);
        quicksort(data, index+1, end);
    }
}

int main() {
    int n, *data, i;
    printf("Enter number of elements:\n");
    scanf("%d", &n);
    data = (int *) malloc(sizeof(int) * n);
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);
    quicksort(data, 0, n-1);
    printf("Sorted List:\n");
    for (i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");
    return 0;
}
