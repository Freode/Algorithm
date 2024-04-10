// 실버 1 - 1991번 : 트리 순회
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 노드 정보
struct NodeInfo
{
    char letter;
    int left = -1;
    int right = -1;
};

// 전위 순회
void PreorderTraversal(const vector<NodeInfo>& nodes, int index)
{
    cout << nodes[index].letter;
    // 왼쪽 자식 존재할 때, 순회
    if(nodes[index].left != -1){ PreorderTraversal(nodes, nodes[index].left); }
    // 오른쪽 자식 존재할 때, 순회
    if(nodes[index].right != -1){ PreorderTraversal(nodes, nodes[index].right); }
}

// 중위 순회
void MiddleTraversal(const vector<NodeInfo>& nodes, int index)
{
    // 왼쪽 자식 존재할 때, 순회
    if(nodes[index].left != -1){ MiddleTraversal(nodes, nodes[index].left); }
    cout << nodes[index].letter;
    // 오른쪽 자식 존재할 때, 순회
    if(nodes[index].right != -1){ MiddleTraversal(nodes, nodes[index].right); }
}

// 후위 순회
void PostorderTraversal(const vector<NodeInfo>& nodes, int index)
{
    // 왼쪽 자식 존재할 때, 순회
    if(nodes[index].left != -1){ PostorderTraversal(nodes, nodes[index].left); }
    // 오른쪽 자식 존재할 때, 순회
    if(nodes[index].right != -1){ PostorderTraversal(nodes, nodes[index].right); }
    cout << nodes[index].letter;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<NodeInfo> nodes(N);

    char let, left, right;
    int index = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> let >> left >> right;
        index = (int)let - 65;
        // 자식 노드 존재 여부 확인 및 입력
        nodes[index].letter = let;
        if(left != '.'){ nodes[index].left = (int)left - 65; }
        if(right != '.'){ nodes[index].right = (int)right - 65; }
    }

    // 출력
    PreorderTraversal(nodes, 0);
    cout << "\n";
    MiddleTraversal(nodes, 0);
    cout << "\n";
    PostorderTraversal(nodes, 0);
    cout << "\n";
}