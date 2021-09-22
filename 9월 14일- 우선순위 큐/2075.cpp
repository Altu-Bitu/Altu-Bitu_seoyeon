
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> heap_vec;


//최소 힙의 크기를 N으로 유지하며 입력을 처리하자.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, input;
    priority_queue<int, vector<int>, greater<>> pq; //greater<> 을 쓸경우 최소 힙(오름차순), 정렬이랑 반대

    cin >> n;
    int size = n * n;
    while (size--) {
        //입력
        cin >> input;

        //연산
        if (pq.size() < n) //우선순위 큐의 크기가 N보다 작다면 그냥 투입
            pq.push(input);
        else if (pq.top() < input) { //우선순위 큐의 크기가 N 이상이라면 root 노드보다 input이 클 때만 갱신
            pq.pop();
            pq.push(input);
        }
    }
 
    //출력
    cout << pq.top();
}
//Q. 우선순위 큐의 크기가 N이상일때 root노드보다 input이 클때만 갱신하는이유? 
//A. 우리가 구해야하는 것은 N번째 '큰' 수이다. 즉, 우선순위 큐에 들어가는것은 가장 큰수부터 차례로 N개의 값이 들어가야한다.
// 따라서 최소 힙이 꽉차있는 상태에서 root노드(최솟값)보다 작다는 것은 나머지 root노드가 아닌 값들과 비교했을때에도 가장 작다는 의미이므로
// N번째를 넘어서는 작은 값이 되고 필요가 없다(=지금까지 구해놓은 N번째 큰 수보다도 작은 수이기 때문에 고려할 필요가 없다)