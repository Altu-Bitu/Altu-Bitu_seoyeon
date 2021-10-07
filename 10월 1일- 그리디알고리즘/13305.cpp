#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n; 
	cin >> n;
	vector<long long> oil(n); //i번째 도시의 기름값
	vector<long long> distance(n - 1); // i번째 도시와 i+1번쨰 도시를 잇는 도로의 길이

	for (int i = 0; i < n - 1;i++ ){
		cin >> distance[i];}	

	for (int i = 0; i < n;i++ ) {
		cin >> oil[i];}

	long long cost = distance[0] * oil[0]; // 첫도시에서는 반드시 기름넣고 출발

	//그때까지의 최소 기름값으로 도시를 이동하자.
	int oil_min = oil[0]; // 가장 싼 도시의 기름값

	for (int i = 1; i < n - 1; i++) {

		if (oil_min > oil[i])
			oil_min = oil[i];//최소 기름값 갱신

		cost += distance[i] * oil_min;
	}
	cout << cost;

}