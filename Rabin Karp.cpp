/*input
LookingForSomethingHere Something
*/

/*~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~*/

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

// Concept: Hashing used to check if one string is a substring of other (Pattern Search).
// Complexity: Best / Average: O(n+m); Worst: O(n*m); where n and m are length of strings
// Simple Hash Function i.e sum of ascii values used here, better hash functions could be used

bool check(char *a, char *b, int p) {
	for (int i = 0; b[i] != '\0'; i++)
		if (a[p+i] != b[i])
			return false;
	return true;
}

bool rabin_karp(char *text, char *s) {
	int hash = 0, c = 0, x = strlen(s), y = strlen(text);
	if (x > y) return false;
	for (int i = 0; i < x; i++) {
		hash += s[i];
		c += text[i];
	}
	if (hash == c && check(text, s, 0)) return true;
	for (int i = x; i < y; i++) {
		c += text[i] - text[i-x];
		if (hash == c && check(text, s, i-x+1)) return true;
	}
	return false;
}

int main() {
	char text[110], s[110];
	scanf("%s%s", text, s);
	printf("%s\n", rabin_karp(text, s) ? "Yes" : "No");
	return 0;
}