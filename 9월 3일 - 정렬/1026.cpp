#include <iostream>
#include <vector> 
#include <algorithm> //sort

using namespace std;

bool cmp(int a, int b) {

	return a > b; //왼쪽에 있는것이 더 클 수 있도록 정렬. (내림차순)
}

int main() {


	int n;
	int S = 0;

	cin >> n;

	vector<int> A(n); //int형 벡터 생성 후 크기를 n으로 할당. 동시에 모든 요소 0으로 초기화
	vector<int> B(n);


	//A배열은 오름차순, B배열은 내림차순으로 정렬하면 S의 최솟값을 구할 수 있다.

	for (int i = 0; i < n; i++) {

		cin >> A[i];
	}

	for (int i = 0; i < n; i++) {

		cin >> B[i];

	}

	//sort함수는 퀵정렬을 이용한다. 
	sort(A.begin(),A.end()); // A는 오름차순 정렬
	sort(B.begin(), B.end(), cmp); //B는 내림차순 정렬
	//sort(start,end,greater<int>()); //내림차순으로 정렬하는 방법 2

	for (int i = 0; i < n; i++) {

		S += A[i] * B[i];
	}


	cout << S;

}