#include <iostream>
#include <queue>

using namespace std;



int main() {


	int n; //연산수

	priority_queue <int, vector<int>, greater<int>> positive; //양수만 담을 최소힙 (양수는 작을수록 절댓값이 작아진다)
	priority_queue <int, vector<int>> negative; //음수만 담을 최대힙 (음수는 클수록 절댓값이 작아진다)


	cin >> n; 

	while (n--) {


		int x; //2^31은 딱 INT_MAX범위
		cin >> x;

		if (x > 0)//양수라면
			positive.push(x); //양수힙에 저장

		else if (x<0)//음수라면
			negative.push(x);

		else  // x==0이라면 
		{
			int a , b , c;

			if (positive.empty() && negative.empty()) //둘다 비어있으면
			{
				cout << 0 << '\n';
				continue; //다음반복문으로 
			}
			//양수힙이 비어있다면 음수힙을 팝한값 출력. 

			if (positive.empty()) // 양수힙이 비어있다면
			{

				cout << negative.top() << '\n';
				negative.pop();
				continue;
			}

			else  
				a = positive.top(); //비교하기 위해 값 저장.


			if (negative.empty()) // 음수 힙이 비어있다면
			{
				cout << positive.top() << '\n';
				positive.pop();
				continue;
			}
			
				
			else
				b = negative.top();

			// a,b중에 절댓값이 더 작은 수를 출력 및 pop

			if (abs(a) < abs(b)) // 양수의 최솟값의 절댓값 < 음수의 최댓값의 절댓값
			{
				cout << positive.top() << '\n';
				positive.pop(); //제거
			}

			else // 양수의 최댓값의 절댓값 >= 음수의 최솟값의 절댓값 -> 두개의 절댓값이 같을경우에도 이 조건문에 걸려서 더 작은값을 반환함.
			{
				cout << negative.top() << '\n';
				negative.pop(); //제거
			}

		}
		

	}

}