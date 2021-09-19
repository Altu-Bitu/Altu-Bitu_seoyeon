#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> heap_vec;

//empty
bool empty() {
    return heap_vec.size() == 1; //index 0�� �׻� ä���� �ִ� ����.
}

//push
void push(int num) {
    int idx = heap_vec.size(); //�̹��� push�� �������� �ε���
    heap_vec.push_back(num); //��������Ʈ���� �ǵ��� ���ʴ�� ä������.

    //�θ���� �Ž��� �ö󰡸�,�������� ��ȯ�ذ��鼭 ������ ��ġ�� ã��. �ִ����̹Ƿ� �θ��尪���� �۾ƾ���.
    //�׷��� �θ��庸�� ���� ũ�� �ڸ��� swap����.�׷��ٰ� ���� ���̻� ���� ũ�� �ʰų� root=1�� �����ϸ� ������ġ�� ã����.
    for (int i = idx ; i > 1; i /= 2) {

        if (heap_vec[i] > heap_vec[i / 2]) //�ڽ� ��� ���� ��ũ�ٸ�
            swap(heap_vec[i], heap_vec[i / 2]); //�θ���� �ڸ� ��ȯ

        else break;
    }
}

//pop
int pop() {
   
    int max = heap_vec[1]; //���� �켱����ť���� ���� ū ���� root�� ����.
    //vector �� pop_front�ϴ� ����� ���� ������ �ϴ� �ڸ��� �ٲٰ� �����ִ� ������� root��带 �������־����.

    int idx = heap_vec.size(); //�� ������ �������� �ε���
    swap(heap_vec[1] , heap_vec[idx-1]); //�Ǹ����� <-> root�� ��ȯ 
    heap_vec.pop_back();

   

    //root ����� ���� child node ���� ���� ���, root ����� child node �� ���� ū ���� ���� ���� root ��� ��ġ�� �ٲ��ִ� �۾��� �ݺ�
    int parent = 1, child = 2;


    //�Ʒ��� �������鼭 �ڸ���ȯ
    while (child<heap_vec.size())
    {
        
        if (child + 1 < heap_vec.size() && heap_vec[child + 1] > heap_vec[child]) //������ ��尡 �����ϰ�, ���� ��庸�� ũ�ٸ�
            child++; //������ ��尪 ����
       //��, child���� ����,������ ����� �� ū ���� �ε����� ���.
        if (heap_vec[child] <= heap_vec[parent]) //���� �θ��尡 �� ũ�ٸ� 
            break; // �װ��� ������ġ�̹Ƿ� �ݺ����� �������� (���̻� ��ȯ�� �Ͼ�� X)
        
            swap(heap_vec[parent], heap_vec[child]);// �ڽĳ��� �θ��� �� ��ȯ.
            parent = child; //���� �ڽ��� �θ�� �ʱ�ȭ
        child = parent * 2; //�ʱ�ȭ�� �θ��� �ڽ� �ε��� ����(���� ���) child�ε����� ���� ���� �ʱ�ȭ.
            
            
    
    }

    return max;

   
}

int main() {
    //����� �ӵ� ���
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
   
    heap_vec.push_back(0); //�ε����� 1���� �����ϵ���

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