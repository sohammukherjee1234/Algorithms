#include <bits/stdc++.h>
using namespace std;

void markMultiples (bool arr[], long long int a, long long int n) {
    long long int num;
    for (long long int i = 2; (num  = i * a) <= n; i++)
        arr[num-1] = false;
}

void sieve(long long int n) {
    if (n >= 2)
    {
        bool arr[n];
        //The property we assume in array is that if arr[i] = true then number i+1 is prime; else not prime
        memset(arr, true, sizeof(arr)); //initialize all array elements to zero
        for (long long int i = 1; i < n; i++) { // first index i = 0 is not checked as we already know that 2 is the first prime number
            if (arr[i]) {
                printf("%lld ", i+1);
                markMultiples(arr, i+1, n);
            }
        }
    }
}

int main ()
{
    long long int n;
    cout << "Enter the number up to which prime number generation is to be done:" << endl;
    cin >> n;
    sieve(n);
    return 0;
}
