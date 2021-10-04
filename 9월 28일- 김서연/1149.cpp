#include <iostream>
using namespace std;
int main() {
    int r, g, b, i; cin >> i; int dp[i] = {};
    while (i--) {
        cin >> r >> g >> b;
        int t0 = dp[0], t1 = dp[1], t2 = dp[2];
        dp[0] = r + min(t1, t2);
        dp[1] = g + min(t0, t2);
        dp[2] = b + min(t0, t1);
    }cout << min(dp[0], min(dp[1], dp[2]));
}