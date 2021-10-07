#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



void reverse(vector < vector <int> >&  matrix, int row, int col) { //행렬 A를 주어진 점으로 부터 3X3 공간을 뒤집는 함수


	for (int i = row; i < row+3; i++) {

		for (int j = col; j < col+3; j++) {

			matrix[i][j] = !matrix[i][j]; //toggle

		}
	}


}


bool check(vector < vector <int> >& m1, vector < vector <int> >& m2) { //m1,m2가 같은 매트릭스인지 확인

	
	
	for (int i = 0; i < m1.size(); i++) {

		for (int j = 0; j < m1[0].size(); j++) {

			if (m1[i][j] != m2[i][j])
				return false;

		}

	}


	return true;

}



int main() {


	

	int r, c;

	cin >> r >> c;

	//int matrix [r][c] 배열 선언. 0으로 값 초기화

	vector<vector<int> > A(r, vector<int>(c, 0));
	vector<vector<int> > B(r, vector<int>(c, 0));

	for (int i = 0;  i < r; i++) {

		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {

			A[i][j] = s[j] - '0';
		}
	}


	for (int i = 0; i < r; i++) {

		string s;
		cin >> s;

		for (int j = 0; j < c; j++) {

			B[i][j] = s[j] - '0';
		}
	}


	int cnt = 0; //연산횟수

	//0,0부터 비교하며 두 행렬의 문자가 다를 경우 바로 바꿔준다. 그리고 한번 바꾼부분은 두번 바꾸지 않는다.
	for (int i = 0; i < c-2; i++) {

		for (int j = 0; j < r-2; j++) {


			if (A[i][j] != B[i][j])
			{
				reverse(A, i, j);
				cnt++;

			}

			if(check(A, B))
				break; // 한번 변환할때마다 같은지 확인한다...? 
		}

	}


	cout << cnt;
}