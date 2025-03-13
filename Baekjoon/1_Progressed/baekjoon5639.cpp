// 골드 4 - 5639번 : 이진 검색 트리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int num = 0;
    Node* parent = nullptr;
    Node* left = nullptr;
    Node* right = nullptr;

    Node() = default;
    Node(int num) : num(num) {}
    Node(Node* parent, int num) : parent(parent), num(num) {}
};

Node* g_parent = nullptr;

void createNodes()
{
    int num, previous_num;
    // 유효한 입력이 들어올 때까지
    while(cin >> num)
    {
        // 어떤 노드도 없는 경우
        if(g_parent == nullptr)
        {
            g_parent = new Node(num);
            previous_num = num;
            continue;
        }

        // 자식 생성
        // 왼쪽 자식
        if(previous_num > num)
        {

        }
        // 오른쪽 자식
        else
        {

        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}