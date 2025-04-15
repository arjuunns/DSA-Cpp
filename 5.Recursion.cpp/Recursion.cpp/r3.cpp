#include <bits/stdc++.h>
using namespace std;
long long countGoodNumbers(long long n) {
    long long MOD = 1e9 + 7;
    if (n % 2 == 0) return (long long)(pow(5, n / 2) * pow(4, n / 2)) % MOD;
    else return (long long)(pow(5, (n + 1) / 2) * pow(4, n / 2)) % MOD;
}
int main() {
    int n = 50;
    cout<<countGoodNumbers(n);
    return 0;
}