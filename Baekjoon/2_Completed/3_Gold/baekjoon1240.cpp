// 골드 5 - 1240번 : 노드사이의 거리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 선 연결 정보
struct Line
{
    int oppo = 0;
    int cost = 0;

    Line() = default;
    Line(int oppo, int cost) : oppo(oppo), cost(cost) {}
};

// 노드에 대한 연결 정보
struct Node
{
    vector<Line> connects;
};

// 노드 전역 변수
vector<Node> g_nodes;

int search(const int start, const int end, const int N)
{
    // 방문 지점
    vector<int> costs(N+1, 0);
    queue<int> que;
    que.push(start);
    // 나중에 -1 해야 함.
    costs[start] = 1;

    int result = 0;
    // BFS
    while(que.empty() == false)
    {
        int cur = que.front();
        que.pop();

        for(const Line& line : g_nodes[cur].connects)
        {
            // 목표 지점에 도달한 경우
            if(line.oppo == end)
            {
                return costs[cur] + line.cost - 1;
            }

            // 방문하지 않은 경우에만 추가 검사
            if(costs[line.oppo] == 0)
            {
                costs[line.oppo] = costs[cur] + line.cost;
                que.push(line.oppo);
            }
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 노드 N개, 쌍 개수 M개
    int N, M;
    cin >> N >> M;

    g_nodes = vector<Node>(N+1);

    // 연결 정보 입력
    int node_a, node_b, cost;
    for(int i = 0; i < N-1; i++)
    {
        cin >> node_a >> node_b >> cost;

        g_nodes[node_a].connects.push_back(Line(node_b, cost));
        g_nodes[node_b].connects.push_back(Line(node_a, cost));
    }

    // 연결 비용 확인
    int A, B;
    for(int i = 0; i < M; i++)
    {
        cin >> A >> B;
        cout << search(A, B, N) << "\n";
    }
}