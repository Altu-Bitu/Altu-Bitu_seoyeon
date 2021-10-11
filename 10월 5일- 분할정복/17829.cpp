#include <iostream>
#include <vector>

using namespace std;





//두번째로 크지 않은 수는 0으로


//conquer
int findSecondLargest(int row, int col , vector <vector<int>> matrix) { //2x2공간에서 두번째로 큰 수를 반환해주는 함수
	
	
	int first =INT_MIN, second= INT_MIN;
	for (int i = row; i < row + 2; i++) {

		for (int j = col; j < col + 2; j++) {

			if (matrix[i][j] >= first) {
				second = first;
				first = matrix[i][j];
			}

			else if (matrix[i][j] >= second && matrix[i][j] != first)
			{
				second = matrix[i][j];
			}
		}
		
	}

	return  second;
}

//divide
int divide(int size , vector<vector<int>> matrix) { // size: matrix한변의 길이


	if (size == 2)  //기저조건 
		return findSecondLargest(0, 0, matrix);
	

	int sub_size = size / 2;
	vector<vector<int>> part(sub_size, vector<int>(sub_size, 0));//부분 행렬

	//2 X 2 정사각형으로 나눈다.
	
	for (int i = 0; i < sub_size; i ++) // 2x2 사각형의 시작부분 인덱스 (왼쪽 위)
	{
		for (int j = 0; j < sub_size; j ++) {

			part[i][j]= findSecondLargest(i*2, j*2,matrix);

		}
	}
	/*
	for (int i = 0; i < sub_size; i++) 
	{
		for (int j = 0; j < sub_size; j++) {

			cout << part[i][j]<<' ';

		}
		cout << '\n';
	}
	cout << '\n';
	*/
	
	
	divide(sub_size, part); //2x2 사각형에서 두번째로 큰 수만 골라낸 행렬
	
}


int main() {

	vector <vector<int>> matrix;

	int n;

	cin >> n;
	matrix.assign(n, vector<int>(n, 0));

	

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cin >> matrix[i][j];
		}
	}

	cout << divide(n, matrix);

}