// 골드 4 - 11404번 : 플로이드
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

struct Line
{
    int dest = 0;
    int cost = 0;

    bool operator<(const Line& other) const
    {
        return cost > other.cost;
    }
};

struct Node
{
    int cost = MAX_VALUE;
    vector<Line> lines;
};

vector<Node> g_nodes;

// 연결 정보 입력
void inputLine(const int N, const int M, const int W)
{
    g_nodes = vector<Node>(N+1);

    int start;
    Line line;
    // 도로 연결 정보 입력
    for(int i = 0; i < M; i++)
    {
        // 도로는 방향이 없음.
        cin >> start >> line.dest >> line.cost;
        g_nodes[start].lines.push_back(line);
        g_nodes[line.dest].lines.push_back({start, line.cost});
    }

    // 웜홀 연결 정보 입력
    for(int i = 0; i < W; i++)
    {
        // 웜홀로 이동 시, 비용이 줄음
        cin >> start >> line.dest >> line.cost;
        g_nodes[start].lines.push_back({line.dest, -line.cost});
    }
}

// 지점 비용 초기화
void initCost(const int N)
{
    cout << "===\n";
    for(Node& node : g_nodes)
    {
        cout << node.cost << "\n";
        node.cost = MAX_VALUE;
    }
}

// 현재 위치에서 비용 탐색
bool simulate(const int start)
{
    priority_queue<Line> pq;
    pq.push({start, 0});

    while(pq.empty() == false)
    {
        Line move = pq.top();
        pq.pop();

        // 비용이 더 저렴한 경우에만 진행
        if(g_nodes[move.dest].cost <= move.cost) continue;

        // 각 선 및 웜홀 이동
        for(const Line& line : g_nodes[move.dest].lines)
        {
            int cost = line.cost + move.cost;
            // 비용이 더 비싼 경우는 무시
            if(cost >= g_nodes[line.dest].cost) continue;

            g_nodes[line.dest].cost = cost;
            pq.push({line.dest, cost});
        }
    }

    // 음수면, 시간 여행 가능
    return g_nodes[start].cost < 0;
}

// 시간 여행 지점 탐색
bool search(const int N)
{
    // 지점마다 시작한다고 판단
    for(int i = 1; i <= N; i++)
    {
        bool b_state = simulate(i);

        // 시간 여행 가능
        if(b_state) return true;

        initCost(N);
    }

    return false;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 개수 TC
    int TC;
    cin >> TC;

    for(int i = 0; i < TC; i++)
    {
        // 지점의 수 N, 도로의 개수 M, 웜홀의 개수 W
        int N, M, W;
        cin >> N >> M >> W;

        inputLine(N, M, W);
        bool b_state = search(N);

        if(b_state) cout << "YES\n";
        else cout << "NO\n";
    }
}