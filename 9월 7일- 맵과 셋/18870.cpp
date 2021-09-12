#include <iostream>
#include <set> 
#include <vector> 
#include <algorithm> 


using namespace std;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);


	int N; //주어질 좌표의 개수 

	cin >> N;


	vector <int> v_ascending; //n개의 좌표를 중복되지 않도록 오름차순으로 저장할 컨테이너. 
	vector <int> v; ////n개의 좌표를 저장할 배열


	for (int i = 0; i < N; i++) {

	     int n;
		cin >> n;

		v.push_back(n);

		v_ascending.push_back(n);


	}

	sort(v_ascending.begin(), v_ascending.end()); // 오름차순 정렬
	v_ascending.erase (unique(v_ascending.begin(), v_ascending.end()) , v_ascending.end()); //중복원소를 vector의 제일 뒷부분으로 보낸다음 쓰레기 값 삭제.


   //   lowerbound 값 = 좌표압축한 결과 

	for (int i=0;i<N;i++){

		
		int pos = lower_bound(v_ascending.begin(), v_ascending.end(), v[i]) - v_ascending.begin(); //O(logn)

		cout << pos <<" ";
	}

	
}
