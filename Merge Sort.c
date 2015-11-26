#include <stdio.h>
#include <stdlib.h>

void merge(int *data, int begin, int end, int mid) { // n, nL and nR are lengths of actual, left and right subarrays, k is the point where merge starts
    int i, j , k, *left, *right, nL, nR;
    nL = mid - begin + 1; // extra 1 to include mid
    nR = end - mid;
    left = (int *) malloc(sizeof(int) * nL);
    right = (int *) malloc(sizeof(int) * nR);
    for (i = 0; i < nL; i++)
        left[i] = data[begin + i];
    for (j = 0; j < nR; j++)
        right[j] = data[mid + 1 + j];
    i = j = 0;
    k = begin;
    while (i < nL && j < nR) {
        if (left[i] <= right[j]) {
            data[k] = left[i];
            i++;
        }
        else {
            data[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nL) {
        data[k] = left[i];
        i++;
        k++;
    }
    while (j < nR) {
        data[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int *data, int begin, int end) {
    if (begin < end) { // if one or zero elements then array does not need to be overwritten after merging
        int mid;
        mid = begin + (end - begin) / 2; // equivalent to (begin + end) / 2 but avoids integer overflows due to begin + end
        mergesort(data, begin, mid);
        mergesort(data, mid+1, end);
        merge(data, begin, end, mid);
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
    mergesort(data, 0, n-1);
    printf("Sorted List:\n");
    for (i = 0; i < n; i++)
        printf("%d ", data[i]);
    printf("\n");
    return 0;
}
