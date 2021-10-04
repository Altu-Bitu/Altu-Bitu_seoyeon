#include<iostream>
#include<deque>
#include<queue>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

	int n, m; cin >> n >> m;
	deque<int> D, S;
	queue<int> dq1, dq2;
	//D = dodo, S = suyeon, dq1 = dodo ground, dq2 = suyeon ground
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		D.push_front(a);
		S.push_front(b);
	}
	bool turn = true; //true = dodo, false = suyeon 
	int k1 = 0, k2 = 0;
	for (int i = 1; i <= m; i++) {
		if (turn) {
			k1 = D.front(); D.pop_front();
			dq1.push(k1);
		}
		else {
			k2 = S.front(); S.pop_front();
			dq2.push(k2);
		}
		if (D.empty()) {
			cout << "su";
			return 0;
		}
		if (S.empty()) {
			cout << "do";
			return 0;
		}
		if (k1 == 5 || k2 == 5) {
			while (!dq2.empty()) {
				D.push_back(dq2.front());
				dq2.pop();
			}
			while (!dq1.empty()) {
				D.push_back(dq1.front());
				dq1.pop();
			}
			k1 = k2 = 0;
		}
		else if (k1 + k2 == 5 && k1 != 0 && k2 != 0) {
			while (!dq1.empty()) {
				S.push_back(dq1.front());
				dq1.pop();
			}
			while (!dq2.empty()) {
				S.push_back(dq2.front());
				dq2.pop();
			}
			k1 = k2 = 0;
		}
		turn = !turn;
	}
	if (D.size() < S.size()) cout << "su";
	else if (D.size() > S.size()) cout << "do";
	else cout << "dosu";
}