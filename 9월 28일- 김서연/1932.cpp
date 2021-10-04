#include <iostream>
#include <memory.h>

using namespace std;

int triangle[501][501];

int dp[501][501];

//top down.
int top_down(int row, int col) {

	if (row == 1)
		return triangle[1][1];
	if (row == 0 || col==0 ||col>row) // 유효하지 않은 인덱스에 접근하려고 할경우
		return 0;
	if (dp[row][col] >= 0) //값이 이미 존재한다면
		return dp[row][col]; // 더이상 함수호출을 일으키지 않고 있는값 그대로 사용.

	return dp[row][col] = max(top_down(row - 1, col - 1), top_down(row - 1, col)) + triangle[row][col];


}
int main() {

	
	
	int n; //삼각형의 크기
	cin >> n;
	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= i; j++) {

			cin >> triangle[i][j];
			
		}
	}


	//2차원 배열 -1로 초기화
	for (int i = 0; i < 501; i++) {

		memset(dp[i],-1, sizeof(dp[i]));
	}
	
	
	/*
	//bottom-up
	dp[1][1] = triangle[1][1];

	for (int i = 2; i <= n; i++) {

		for (int j = 1; j <= i; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
		}
	}
	*/

	dp[1][1] = triangle[1][1];
	for (int i = 1; i <= n; i++) {

		top_down(n, i);
	}
	/*
	for (int i = 0; i <=20; i++) {

		for (int j = 0; j <=20; j++) {
			cout << dp[i][j]<<' ';
		}
		cout << '\n';
	}
	*/

	int max = -1;
	for (int j = 1; j <= n;j++) {

		if (max < dp[n][j])
			max = dp[n][j];
	}


	cout << max;
	


}