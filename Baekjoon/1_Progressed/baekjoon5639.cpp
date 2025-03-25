// 골드 4 - 5639번 : 이진 검색 트리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Node
{
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;
    int cost = 0;

    Node() = default;
    Node(int cost) : cost(cost) {}
};

Node* g_root = nullptr;

// 수 입력
void inputNode()
{
    int num = 0;
    stack<Node*> stk;
    while(cin >> num)
    {
        // 첫 노드 생성
        if(num == 0)
        {
            g_root = new Node(num);
            stk.push(g_root);
            continue;
        }

        // 첫 노드 생성이 아닐 때

        // 현재 노드보다 수가 큰 경우
        Node* previous_top = nullptr;
        while(stk.empty() == false && stk.top()->cost < num)
        {
            previous_top = stk.top();
            stk.pop();
        }

        // 왼쪽 노드에 추가 가능
        if(previous_top == nullptr)
        {
            Node* new_node = new Node(num);
            
            

        }
        // 오른쪽 노드에 추가 가능

        
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}