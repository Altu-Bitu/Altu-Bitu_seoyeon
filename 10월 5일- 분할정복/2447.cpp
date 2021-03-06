#include <iostream>
#include <vector>

using namespace std;


vector <vector<char>> board;


void makeSqure(int size,int row,int col) { //(row,col)에서 size만큼 별 만들기

	//conquer
	if (size == 1)
	{
		board[row][col] = '*';
		return;
	}

	//divide ->하나의 문제를 아홉개의 문제로 작게 나눔
	int cnt = 0;
	int subsize = size / 3;

	//row+ subsize*2+1
	//col+ subsize *2+1
	for (int i = row; i < row + size; i+= subsize) {

		for (int j = col; j < col + size; j+= subsize) {

			cnt++;
			if (cnt == 5)//중간 구역은 아무것도 출력하지 않음
				continue;
			makeSqure(subsize, i, j);
			
		}

	}


}
int main() {


	int n;
	cin >> n;
	board.assign(n+1, vector<char>(n+1, ' '));


	makeSqure(n,1,1);

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= n; j++) {

			cout << board[i][j];
		}
		cout << '\n';
	}
	
}