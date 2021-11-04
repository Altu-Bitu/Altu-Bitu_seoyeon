#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;



//서로에게 다가가는 투포인터
bool checkGOOD(vector<int> arr,int i) { //target을 만들 수 있는지 판단
	

	int left = 0, right = arr.size() - 1;
	int target = arr[i];

	if (right==i)
		right--;
	if(left == i)
		left++;


	int sum = 0;

		while (left < right) {

			 sum= arr[left] + arr[right]; //두 수(left,right)의 합

			if (sum == target) {
				return true;
			}
			else if (sum > target) { //target보다 sum이 더크다면 sum을 줄여야함

				right--;

				if (right==i)
					right--;
			}
			else { //target보다 sum이 더작다면 sum을 키워야함

				left++;
				if (left == i)
					left++;

			}

		}

		return false;


}
int solution(vector<int> arr) {
	int cnt=0;

	for (int i = 0; i < arr.size(); i++) {

		
		if (checkGOOD(arr, i))
			cnt++;

		
	}


	return cnt;

}


int main() {


	int n;
	


	
	cin >> n;

	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end()); //오름차순정렬

	int len = arr.size();

	if (len <= 2) 
		cout << 0;
	else
	cout << solution(arr);
	
}