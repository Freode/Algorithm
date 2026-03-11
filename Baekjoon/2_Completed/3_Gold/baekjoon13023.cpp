// 골드 5 - 13023번 : ABCDE
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 5 <= N <= 2'000
// 1 <= M <= 2'000

// Depth가 4로 존재하는지 확인
// 뭐지 이게

struct Node
{
    vector<int> connects;
    bool visit = false;

    Node()
    {
        connects.reserve(50);
    }
};

vector<Node> g_nodes;

void initData(const int N, const int M)
{
    g_nodes = vector<Node>(N);

    int y, x;
    for(int i = 0; i < M; i++)
    {
        cin >> y >> x;

        g_nodes[y].connects.push_back(x);
        g_nodes[x].connects.push_back(y);
    }
}

bool dfs(const int N, const int idx, const int depth)
{
    if(4 == depth)
        return true;

    bool found = false;
    for(const int& connect : g_nodes[idx].connects)
    {
        if(g_nodes[connect].visit)
            continue;

        g_nodes[connect].visit = true;
        found = dfs(N, connect, depth + 1);
        g_nodes[connect].visit = false;

        if(found)
            return true;
    }

    return found;
}

void simulate(const int N)
{
    bool result = false;
    for(int i = 0; i < N; i++)
    {
        g_nodes[i].visit = true;
        result = dfs(N, i, 0);
        g_nodes[i].visit = false;

        if(result)
        {
            cout << "1\n";
            return;
        }
    }

    cout << "0\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 사람 수 N, 친구 관계 M
    int N, M;
    cin >> N >> M;
    initData(N, M);
    simulate(N);
}