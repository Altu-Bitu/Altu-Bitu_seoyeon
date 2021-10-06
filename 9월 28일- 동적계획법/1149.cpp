#include <iostream>
#include <vector>

using namespace std;

int main() {

    //2차원 dp풀이

	/*int dp[1000][3];


		int n;
		cin >> n;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				cin >> dp[i][j];
			}
		}

		for (int i = 1; i <= n - 1; i++) {

			dp[i][0] += min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] += min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] += min(dp[i - 1][0], dp[i - 1][1]);
		}

		cout << min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
		*/

    //1차원 dp풀이
    int r, g, b, n; 
    cin >> n; 
    
    vector <int> dp(n);

    while (n--) {

        cin >> r >> g >> b;

        int t0 = dp[0], t1 = dp[1], t2 = dp[2];

        dp[0] = r + min(t1, t2);
        dp[1] = g + min(t0, t2);
        dp[2] = b + min(t0, t1);

    }
    cout << min(dp[0], min(dp[1], dp[2]));
}