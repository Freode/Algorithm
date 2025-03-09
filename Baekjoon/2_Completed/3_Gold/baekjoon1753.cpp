// 골드 4 - 1753번 : 최단경로
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <utility>

using namespace std;

const int INF = numeric_limits<int>::max() - 10;

// 간선 정보
struct Line
{
    int opponent = 0;
    int cost = 0;

    Line() = default;
    Line(int opponent, int cost) : opponent(opponent), cost(cost) {}
};

// 정점 정보
struct Node
{
    int visit = INF;
    vector<Line> lines;
};

vector<Node> g_nodes;

// 탐색
void search(int start)
{   
    // 오름차순 우선 순위 큐
    priority_queue<pair<int,int>> que;
    que.push({0, start});
    g_nodes[start].visit = 0;

    // BFS
    while(que.empty() == false)
    {
        pair<int, int> info = que.top();
        int num = info.second;
        int cost = (-1) * info.first;
        que.pop();

        if(cost > g_nodes[num].visit) continue;

        // 간선 마다 확인
        for(const Line& line : g_nodes[num].lines)
        {
            // 추가로 방문할 이유가 없는 경우
            if(g_nodes[line.opponent].visit <= cost + line.cost)
                continue;

            // 상대 지점으로 이동
            que.push({(-1) * (cost + line.cost), line.opponent});
            g_nodes[line.opponent].visit = cost + line.cost;
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 정점 V, 간선 E
    int V, E;
    cin >> V >> E;

    // 시작 지점 k
    int k;
    cin >> k;

    // 간선 정보 입력
    g_nodes = vector<Node>(V+1);
    int in_node, in_opponent, in_cost;
    for(int i = 0; i < E; i++)
    {
        cin >> in_node >> in_opponent >> in_cost;
        g_nodes[in_node].lines.push_back(Line(in_opponent, in_cost));
    }

    // 정점에 대한 거리 결과 출력
    search(k);
    for(int i = 1; i <= V; i++)
    {
        int result = g_nodes[i].visit;

        if(result == INF) cout << "INF\n";
        else cout << result << "\n";
    }
}