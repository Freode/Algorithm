// 골드 5 - 1263번 : 시간 관리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 자식 연결 정보
struct Node
{
    vector<int> childs;
};

// 트리 연결 정보
vector<Node> g_nodes;

// 노드 찾기
int search(int num, int cut)
{
    // 리프 노드
    if(g_nodes[num].childs.size() == 0) return 1;

    // 잘라내는 노드를 자식으로 가지는데 본인이 리프 노드가 되는 경우
    if(g_nodes[num].childs.size() == 1 && g_nodes[num].childs[0] == cut) return 1;

    int result = 0;

    // 리프 노드가 아님
    for(const int& idx : g_nodes[num].childs)
    {
        if(idx != cut) result += search(idx, cut);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 노드 개수 입력
    int N;
    cin >> N;

    // 트리 할당
    g_nodes = vector<Node>(N);

    // 연결 정보 입력
    int temp_parent, parent;
    for(int i = 0; i < N; i++)
    {
        cin >> temp_parent;
        // 가장 부모 노드
        if(temp_parent == -1) parent = i;
        // 다른 노드는 연결
        else g_nodes[temp_parent].childs.push_back(i);
    }

    // 노드 끊을 지점 입력
    int cut;
    cin >> cut;

    // 리프 수 찾기
    int counts = 0;

    // 최상단의 부모를 자르지 않을 때, 검사
    if(cut != parent) counts = search(parent, cut);

    cout << counts << "\n";
}