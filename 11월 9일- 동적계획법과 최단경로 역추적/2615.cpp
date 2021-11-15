#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 검정: 1
// 흰색: 2
// 알X : 0

//검은색이 이기면 1, 흰색이 이기면 2, 승부결정전은 0 

// 2차원 DP배열을 만들고 몇번째 칸에서 왔는지 정보를 저장하자. 
// 우선, 알이 있는 곳은 1로 초기화.
// 근방에 동일한 숫자가 있으면 cnt+1. 
