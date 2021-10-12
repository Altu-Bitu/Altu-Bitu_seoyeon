#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//conquer
int findSecondLargest(int row, int col , vector <vector<int>> matrix) { //2x2공간에서 두번째로 큰 수를 반환해주는 함수
	
	vector<int> arr;
	for (int i = row; i < row + 2; i++) {

		for (int j = col; j < col + 2; j++) {

			arr.push_back(matrix[i][j]);
		}	
	}

	sort(arr.begin(), arr.end()); 
	return  arr[2];//두번째로 큰 수 반환
}

int ans;
//divide
void divide(int size , vector<vector<int>> matrix) { // size: matrix한변의 길이
	

	if (size == 2)  //기저조건 
	{   
		ans =findSecondLargest(0, 0, matrix);
		return;
	}
	
	

	int sub_size = size / 2;
	vector<vector<int>> part(sub_size, vector<int>(sub_size, 0));//부분 행렬

	//Divide : 2 X 2 사각형으로 쪼갤수있는데까지 쪼개기
	
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

	divide(n, matrix);

	cout << ans;

}