#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




vector <vector<int>> matrix;

//(row,col)로부터 size만큼 두번째로 큰 수를 찾아주는함수
int findSecondLargest(int size ,int row, int col) { 

	//conquer
	if (size == 1)  //기저조건 
		return matrix[row][col];
		

	int sub_size = size / 2;
	vector < int> part;//4개의 조각에서 각각 두번째로 큰수만 모아서 push해 둘 곳.
	
	//divide -> 하나의 사각형을 4개의 사각형으로 나눔
	for (int i = row; i <= row+ sub_size; i += sub_size) 
	{
		for (int j = col; j <=col+sub_size; j += sub_size) {
			//cout << i << ' ' << j;
			part.push_back( findSecondLargest(sub_size,i,j));

		}
		
	}
	
	sort(part.begin(), part.end());
	return part[2]; //두번째로 큰수
	
}

int main() {

	

	int n;

	cin >> n;
	matrix.assign(n, vector<int>(n, 0));

	

	for (int i = 0; i < n; i++) {

		for (int j = 0; j < n; j++) {

			cin >> matrix[i][j];
		}
	}

	cout <<findSecondLargest(n, 0, 0);

	

}