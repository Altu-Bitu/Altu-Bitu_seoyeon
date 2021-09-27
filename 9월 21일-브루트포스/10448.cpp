#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 10

int main() {


	int n_testcase;
	

	cin >> n_testcase;

	int triangular_numbers[MAX]; //삼각수 저장


	for (int i = 1; i < MAX; i++) {

		triangular_numbers[i] = i * (i + 1) / 2;

	}


	/*
	for (int i = 1; i < MAX; i++) {
		cout << i << ' ' << triangular_numbers[i];
	}

	*/
	int n;
	while (n_testcase--){

		bool check = false; // 정확히 3개의 삼각수의 합으로 표현될 수 있는지 여부
		
		cin >> n;

		int sum;
		
		for (int i = 1; i < MAX; i++) {

			for (int j = 1; i < MAX; j++) {

				for (int k = 1; k < MAX; k++) {


					sum = triangular_numbers[i] + triangular_numbers[j] + triangular_numbers[k];
					if (sum == n)
					{
						check = true;
						
						

					}


				}
			}

			
		}

		if (check)
		cout << 1;
		else
			cout << 0;

	}



}