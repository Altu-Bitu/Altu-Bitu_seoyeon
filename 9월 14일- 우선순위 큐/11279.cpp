#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> heap_vec;

//empty
bool empty() {
    return heap_vec.size() == 1; //index 0은 항상 채워져 있는 상태.
}

//push
void push(int num) {
    int idx = heap_vec.size(); //이번에 push할 데이터의 인덱스
    heap_vec.push_back(num); //완전이진트리가 되도록 차례대로 채워나감.

    //부모노드로 거슬러 올라가며,상위노드와 교환해가면서 적절한 위치를 찾음. 최대힙이므로 부모노드값보다 작아야함.
    //그러나 부모노드보다 값이 크면 자리를 swap해줌.그러다가 이제 더이상 값이 크지 않거나 root=1에 도달하면 적정위치를 찾은것.
    for (int i = idx; i > 1; i /= 2) {

        if (heap_vec[i] > heap_vec[i / 2]) //자식 노드 값이 더크다면
            swap(heap_vec[i], heap_vec[i / 2]); //부모노드와 자리 교환

        else break;
    }
}

//pop
int pop() {

    int max = heap_vec[1]; //현재 우선순위큐에서 가장 큰 값은 root에 저장.
    //vector 는 pop_front하는 기능이 없기 때문에 일단 자리를 바꾸고 팝해주는 방식으로 root노드를 제거해주어야함.

    int idx = heap_vec.size(); //맨 마지막 데이터의 인덱스
    swap(heap_vec[1], heap_vec[idx - 1]); //맨마지막 <-> root값 교환 
    heap_vec.pop_back();



    //root 노드의 값이 child node 보다 작을 경우, root 노드의 child node 중 가장 큰 값을 가진 노드와 root 노드 위치를 바꿔주는 작업을 반복
    int parent = 1, child = 2;


    //아래로 내려가면서 자리교환
    while (child < heap_vec.size())
    {

        if (child + 1 < heap_vec.size() && heap_vec[child + 1] > heap_vec[child]) //오른쪽 노드가 존재하고, 왼쪽 노드보다 크다면
            child++; //오른쪽 노드값 갱신
       //즉, child에는 왼쪽,오른쪽 노드중 더 큰 값의 인덱스가 담김.
        if (heap_vec[child] <= heap_vec[parent]) //만일 부모노드가 더 크다면 
            break; // 그곳이 적정위치이므로 반복문을 빠져나감 (더이상 교환이 일어나지 X)

        swap(heap_vec[parent], heap_vec[child]);// 자식노드와 부모노드 값 교환.
        parent = child; //현재 자식을 부모로 초기화
        child = parent * 2; //초기화된 부모의 자식 인덱스 설정(왼쪽 노드) child인덱스를 왼쪽 노드로 초기화.



    }

    return max;


}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;

    heap_vec.push_back(0); //인덱스가 1부터 시작하도록

    cin >> n;
    while (n--) {
        cin >> x;
        if (x == 0) {
            if (empty())
                cout << 0 << '\n';
            else {
                cout << pop() << '\n';

            }
        }
        else
            push(x);
    }
}