#include <iostream>
#include <vector>

using namespace std;


vector< ci >  tree;
typedef pair<int, int> ci;
int max_diameter;
vector<int> leafs;


// 리프노드를 찾고 부모로 거슬러 올라가면서
// 또 다른 리프노드를 만날때까지 숫자를 더해감.
int findLeaf(int node, int parent) {
    if (tree[node].empty()) //자식노드가 없다면 (leaf)
        return node;

   
    for (ci child : tree[node])
    {
        if( child.first != parent)
            leafs.push_back( findLeaf(child.first,node));

    }
 
}

// 현재 leaf -> leaf 를 만날때까지 거슬러 올라감. 
int back(int node, int child,int diameter) { 

    
  
    if (tree[node].empty()) //leaf노드를 만났다면 
    {
        max_diameter = max(max_diameter, diameter);
        return;
    }


    diameter+= tree[node]
        back
    

}

int main() {
    int n, a, b,w ,test_case = 0;
   
        //입력
        cin >> n;
        tree.assign(n + 1, vector<ci>(0)); // 정점간의 연결관계 저장

 
        while (n--) { //무방향 그래프
            cin >> a >> b>> w;
       
            tree[a].push_back(ci{ b,w }); // a->b 연결
            tree[b].push_back(ci{ a,w }); // b->a 연결 
           
        }
        
        //연산
        findLeaf(1,0);

        for (int i = 0; i < leafs.size(); i++) { //부모 노드로 거슬러 올라가면서
            
        }
}