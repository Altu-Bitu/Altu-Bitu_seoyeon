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


	vector <int> v; //n개의 좌표를 저장할 컨테이너 
	set <int> s; //n개의 좌표를 중복되지 않도록 저장할 컨테이너. 
	

	for (int i = 0; i < N; i++) {

	     long n;
		cin >> n;

		v.push_back(n);
		s.insert(n);


	}
	//음수가 더 앞에 저장되나 ,,? -> YES
	
	
	int k; //set에서 i가 몇번째로 큰 원소인지. 

	for (int i = 0; i < N; i++) {

		k = 0;
		for (auto iter = s.rbegin(); iter != s.rend(); iter++) { // 내림차순으로 접근하기 위해서 거꾸로 접근. 
			
		k++;
				
			if (v[i] == *iter)
				break;
 
		}

		cout << s.size() - k <<" ";

	}
	
	//O(N2)이어서 시간초과남..  -> 다른 알고리즘 찾기.

	
}
