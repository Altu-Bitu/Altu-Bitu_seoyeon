#include <iostream>
#include <vector>
#include <queue>

using namespace std;


//사탕을 바꾸고 난 후에 먹을 수 있는 최대 사탕 구하기
int maxCandy(vector<vector<char>> &board,int n) {

	int max_candy=1;
	
	//행 확인
	for (int i = 0; i < n ; i++) {
		int cnt = 1;
		for (int j = 0; j < n-1; j++) {
			if (board[i][j] == board[i][j + 1])
				cnt++;
			else {

				max_candy = max(max_candy, cnt);
				cnt = 1;
			}
				
		}
		max_candy = max(max_candy, cnt);
		
			
	}

	//열 확인
	for (int j = 0; j < n; j++) {
		int cnt = 1;
		for (int i = 0; i < n -1 ; i++) {
			if (board[i][j] == board[i + 1][j])
				cnt++;
			else {

				max_candy = max(max_candy, cnt);
				cnt = 1;
			}
		}
		max_candy = max(max_candy, cnt);
	}
	return max_candy;
}


//인접한 사탕의 위치를 교환.
int change(vector<vector<char>> &board,int n) {

	int max_candy=1;//최대로 먹을수 있는 사탕 개수 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			// 오른쪽 
			if (j + 1 < n && board[i][j] != board[i][j + 1]) {
				swap(board[i][j], board[i][j+1]);
				max_candy = max (max_candy,maxCandy(board, n));
				swap(board[i][j], board[i][j + 1]);
			}
			
			//아래
			if (i+1<n && board[i][j]!= board[i + 1][j]) {
				swap(board[i][j], board[i+1][j]);
				max_candy = max(max_candy, maxCandy(board, n));
				swap(board[i][j], board[i+1][j]);
			}
			

		}
	}
	return max_candy;
}

int main() {
	int n; //보드의 크기

	cin >> n;
	vector<vector<char>> board(n, vector<char>(n,0));

	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin>>board[i][j];

		}
	}


	int max_candy = change(board, n);

	cout << max_candy;

}