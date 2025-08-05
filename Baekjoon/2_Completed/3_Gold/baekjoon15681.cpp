// 골드 5 - 15681번 : 트리와 쿼리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int count = 0;
    vector<int> connects;

    Node()
    {
        connects.reserve(10);
    }
};

vector<Node> g_nodes;

void initAndInputData(const int N)
{
    g_nodes = vector<Node>(N+1);

    int first, second;
    for(int i = 0; i < N - 1; i++)
    {
        cin >> first >> second;

        g_nodes[first].connects.push_back(second);
        g_nodes[second].connects.push_back(first);
    }
}

int search(const int idx)
{
    // 자기 자신 포함
    g_nodes[idx].count = 1;

    // 모든 간선 확인
    for(const int& connect : g_nodes[idx].connects)
    {
        // 이미 방문했다면, 무시
        if(g_nodes[connect].count != 0)
            continue;

        g_nodes[idx].count += search(connect);
    }

    return g_nodes[idx].count;
}

void inputQuery(const int Q)
{
    int query;
    for(int i = 0; i < Q; i++)
    {
        cin >> query;
        cout << g_nodes[query].count << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정점 수 N, 루트 번호 R, 쿼리 수 Q
    int N, R, Q;
    cin >> N >> R >> Q;

    initAndInputData(N);
    search(R);
    inputQuery(Q);
}