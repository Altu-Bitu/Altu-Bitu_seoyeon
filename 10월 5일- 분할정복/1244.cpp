#include <iostream>
#include <vector>

using namespace std;


void changeMultiple(int n, int n_switch, vector <int>&  swt) { //n의 배수번째 스위치를 바꿈

	for (int i = n; i <= n_switch; i += n) {

		swt[i] = !swt[i]; //swap
	}
}


void changeSymmetric(int n, int n_switch, vector <int>& swt) { //n을 기준으로 대칭인곳의 스위치를 전부 바꿈.

	// 기준점 :3 일때 01 1 10 이면 cnt=2
	int max_symmetric = min(n - 1, n_switch - n);

		swt[n] = !swt[n];
		for (int i = 1; i <= max_symmetric; i++) {

			if (swt[n - i] == swt[n + i])
			{
				swt[n - i] = !swt[n - i]; //swap
				swt[n + i] = !swt[n + i];
			}

			else break;

		}

}


int main() {

	int n_switch;
	
	cin >> n_switch;

	vector <int> swt(n_switch + 1);

	for (int i = 1; i <= n_switch; i++) {

		cin >> swt[i];
	}

	int n_person; 
	cin >> n_person;
	vector<pair<int, int>> cmd(n_person); //성별, 기준스위치

	for (int i = 0; i < n_person; i++) {

		cin >> cmd[i].first >> cmd[i].second;

	}

	//연산
	for (int i = 0; i < n_person; i++) {

		if (cmd[i].first == 1) //남학생이라면
			changeMultiple(cmd[i].second, n_switch, swt);

		else //여학생이라면
			changeSymmetric(cmd[i].second, n_switch, swt);

	}



	//출력
	for (int i = 1; i <= n_switch; i++) {

		cout << swt[i]<<' ';
		if (i % 20 == 0)
			cout << '\n';

	}
}