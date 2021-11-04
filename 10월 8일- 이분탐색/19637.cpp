#include <iostream>
#include <map>

using namespace std;

/**
 * 모든 캐릭터와 칭호를 매칭하는 브루트 포스를 사용하기엔 최대 연산 횟수 10^5 * 10^5 -> 100억!
 * 특정 전투력 '이하'까지 해당하는 칭호를 받을 수 있음
 * -> 이분 탐색
 *
 * 맵과 셋은 원소를 정렬된 상태로 저장하기 때문에 알고리즘 헤더 없이 자체적으로 이분 탐색 함수를 사용할 수 있음
 */
int main() {
    ios::sync_with_stdio(false); //c와 c++ 입출력의 synchronization을 false로 바꿔준다
    //동기화를 꺼줌으로써 c++ 입출력시 독립된 자신만의 버퍼를 사용하게 된다.
    cin.tie(NULL); //cin을 cout으로부터 untie한다.

    map<int, string> title; //칭호와 그 칭호의 전투력 상한값

    int n, m, power; //칭호의 개수, 칭호를 출력해야하는 캐릭터들의 개수, 전투력
    string name; // 칭호명

    //입력
    cin >> n >> m; //칭호 수, 캐릭터 수 입력받기
    while (n--) { //칭호의 개수는 총 n개 
        cin >> name >> power; //칭호명, 전투력 상한값 입력.
        if (title[power].empty()) //아직 power를 key값으로 하는 요소가 없다면,
            title[power] = name; // 해당 power에 이름을 붙여준다.
    }

    //출력
    while (m--) { //캐릭터수 m개 입력받기
        cin >> power; //전투력입력
        //lowerbound -> 찾고자 하는 값 이상이 처음 나타나는 위치 
        // 즉 , 캐릭터의 전투력 이상이 처음 나타나는 위치를 반환하므로
        // 9999 -> 10000 반환 (WEAK)   100000-> 100000반환 (NORMAL) ... 
        cout << title.lower_bound(power)->second << '\n'; //출력
    }
}