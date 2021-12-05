#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;


// 예전에 해결했던 문제! 이번엔 LCS의 길이 + 수열이 무엇인지까지 출력해야함.
// 저장된 dp배열의 값을 활용하여 현재 값이 어디서 온건지 알아내자.
// 1. 문자가 동일할 경우 -> 왼쪽 대각선으로 이동.
// 2. 문자가 다를경우 
// 2.1 위 > 왼쪽 -> 위로 이동
// 2.2 왼쪽 > 위 -> 왼쪽으로 이동


//역추적
vector<char> back(vector<vector<int>>& board,string a,string b) {
	vector<char> result; //정답 string 

	int i = b.length(); //행
	int j = a.length(); //열
	
	while (i > 0 && j > 0) {
	

		if (b[i-1] == a[j-1]) {
			result.push_back(a[j-1]);
			i--; j--; //대각선 위로
			//cout << "대각선";
		}
		else {
			
			if (board[i - 1][j] > board[i][j - 1]) // 위 > 왼쪽
			{
				
				i--;
				//cout << "위";
			}
			else  //위 <= 왼쪽
			{
				j--;
				//cout << "왼쪽";
			}

		}


	}

	return result;
}

void printDP(vector<vector<int>>& board, string a, string b) {


	for (int i = 0; i <= b.length(); i++) {
		for (int j = 0; j <= a.length(); j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}

}
int LCS(vector<vector<int>>& board,string a,string b) {

	for (int i = 1; i <= b.length(); i++) {
		for (int j = 1; j <= a.length(); j++) {

			if (b[i-1] == a[j-1])
			{
				board[i][j] = board[i - 1][j - 1] + 1;
				
				
			}
			else
			{
				
				if (board[i - 1][j] > board[i][j - 1]) // 위 > 왼쪽
				{
					board[i][j] = board[i - 1][j];
					
				}
				else { // 왼쪽 >= 위 

					board[i][j] = board[i][j-1];
					
				}
			}

		}
			
	}
	return board[b.length()][ a.length()];

}



int main() {

	string a, b;
	cin >> a >> b;

	vector<vector<int>> board(b.length() + 1, vector<int>(a.length() + 1, 0));


	cout << LCS(board, a, b) << '\n';
	//printDP(board, a, b);
	
	vector<char> result = back(board, a, b);

	for (int i = result.size() - 1; i >= 0; i--)
		cout << result[i];


}