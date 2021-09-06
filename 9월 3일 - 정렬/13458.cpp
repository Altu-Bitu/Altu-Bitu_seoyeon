#include <iostream>
#include <vector> 

using namespace std;


int main() {



	int n;//시험장 갯수
	int B, C;
    long long cnt=0; //감독관수 (최대 백만 *백만)

	cin >> n;
	int* A = new int[n]; //각 시험장에 있는 응시자의 수를 저장할 배열 동적할당.


	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}

	cin >> B; //총감독관이 감시할 수 있는 사람수
	cin >> C; //부감독관이 감시할 수 있는 사람수


	
	for (int i = 0; i < n; i++) {

		A[i] -= B; //총감독관이 감시할수 있는 사람수를 빼줌. 
		cnt++; //총감독관 한명

		
		//그래도 감시해야할 인원이 남으면, 부감독관을 둘수 있는 만큼 더둠.
			if (A[i]>0) 
				cnt+= (A[i]-1) / C + 1; 
			
	}

	cout << cnt;
	free(A);
}
