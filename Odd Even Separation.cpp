/*input
10
1 2 3 4 5 6 7 8 9 10
*/

/*~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~*/

/* Problem: All even numbers must occur before all odd numbers in the array */

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define MAX(a, b) ((a > b) ? a : b)
#define MIN(a, b) ((a < b) ? a : b)
#define set_bit(n, x, i) (n ^ ((-x ^ n) & (1 << i)))
#define get_bit(n, i) ((n >> i) & 1) 
using namespace std;

template<typename T>void scan(T&x){bool n=false;register T c=getchar();x=0;if(c=='-'){n=true;c=getchar();}for(;(c>47&&c<58);c=getchar()){x=(x<<1)+(x<<3)+c-48;}if(n){x*=-1;}}
template<typename T>void allocate(T **x,T n){*x=(T*)malloc(sizeof(T)*n);}

void swap(int *a, int *b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int main() {
	int n, arr[100], l, r;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	l = 0;
	r = n-1;
	while (l < r) {
		while (arr[l] % 2 == 0 && l < r) // increment l if even numbers found
			l++;
		while (arr[r] % 2 && l < r) // decrement r if odd numbers found
			r--;
		if (l < r) {
			swap(arr[l], arr[r]);
			l++;
			r--;
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	return 0;
}