/*input
1
FOOD
MONEY 
*/

/*~~~~~~~~~~~~~~~~~~~~dwij28 == Abhinav Jha~~~~~~~~~~~~~~~~~~~~*/

#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define MAX(a, b) ((a > b) ? a : b)
#define MIN3(a, b, c) ((a < b) ? (a < c ? a : c) : (b < c ? b : c))
#define MIN(a, b) ((a < b) ? a : b)
#define set_bit(n, x, i) (n ^ ((-x ^ n) & (1 << i)))
#define get_bit(n, i) ((n >> i) & 1) 
using namespace std;
char a[2001], b[2001];
int t, dp[2001][2001];

template<typename T>void scan(T&x){bool n=false;register T c=getchar();x=0;if(c=='-'){n=true;c=getchar();}for(;(c>47&&c<58);c=getchar()){x=(x<<1)+(x<<3)+c-48;}if(n){x*=-1;}}
template<typename T>void allocate(T **x,T n){*x=(T*)malloc(sizeof(T)*n);}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", a, b);
		for (int i = 0; i < strlen(a) + 1; i++) {
			for (int j = 0; j < strlen(b) + 1; j++) {
				if (i == 0) dp[i][j] = j;
				else if (j == 0) dp[i][j] = i;
				else if (a[i-1] != b[j-1]) dp[i][j] = MIN3(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]) + 1;
				else dp[i][j] = dp[i-1][j-1];
			}
		}
		printf("%d\n", dp[strlen(a)][strlen(b)]);
	}
	return 0;
}