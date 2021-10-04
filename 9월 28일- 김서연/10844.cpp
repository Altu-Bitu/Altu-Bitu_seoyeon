#include<iostream>
#include<cstring>
using namespace std;

#define M 1000000000

int	n, dp[101][10];

int main()
{
	int i, j;

	cin >> n;
	for (i = 1; i < 10; dp[1][i++] = 1);
	for (i = 2; i <= n; i++)
	{
		for (j = 1; j < 9; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % M;
		dp[i][0] = dp[i - 1][1];
		dp[i][9] = dp[i - 1][8];
	}
	for (i = 0; i < 9; i++)
		dp[n][9] = (dp[n][9] + dp[n][i]) % M;
	cout << dp[n][9];
}