#include <iostream>

using namespace std;

int countNums(int n) {
    long long s[n][6];
    const long long MOD = 1000000007;
    s[0][0] = 1;
    for (int i = 1; i < 6; i++) {
        s[0][i] = 0;
    }
    for (int i = 1; i < n; i++) {
        s[i][0] = {1};
        s[i][1] = (s[i - 1][0] + s[i - 1][1] * 2) % MOD;
        s[i][2] = (s[i - 1][0] + s[i - 1][2]) % MOD;
        s[i][3] = (s[i - 1][1] + s[i - 1][3] * 2) % MOD;
        s[i][4] = (s[i - 1][1] + s[i - 1][2] + s[i - 1][4] * 2) % MOD;
        s[i][5] = (s[i - 1][3] + s[i - 1][4] + s[i - 1][5] * 2) % MOD;
    }
    return (int) (s[n - 1][5]);
}

int main() {
    int n = 0;
    cin >> n;
    cout << countNums(n);
    return 0;
}