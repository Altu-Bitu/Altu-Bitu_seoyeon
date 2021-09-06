#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;
 struct point {

	int x;
	int y;

};

bool cmp(const point& p1, const point& p2) {
	//const로 선언하는 이유 및 &의 역할?

	if (p1.y != p2.y) //y좌표가 같지 않으면
		return p1.y < p2.y; //y좌표가 증가하는 순으로

	return p1.x < p2.x; // y좌표가 같으면 x좌표가 증가하는 순서로.


}

int main() {

	int n;

	cin >> n;
	
	vector <point> p(n);

	
	for (int i = 0; i < n; i++) {

		cin >> p[i].x >> p[i].y;
	}

	sort(p.begin(), p.end(), cmp);

	for (int i = 0; i < n; i++) {

		cout << p[i].x <<" "<< p[i].y<<endl;
	}

}
*/