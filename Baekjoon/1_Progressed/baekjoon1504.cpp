// 골드 4 - 1504번 : 특정한 최단 경로
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 간선 중복 이동 가능

// 1~a, a~b, b~n
// 1~b, b~a, a~n 중 최단 거리 구하기

// 간선 정보
struct Line
{
    int cost = 0;
    int opponent = 0;
    Line() = default;
    Line(int opponent, int cost) : opponent(opponent), cost(cost){}
};

// 노드 정보
struct Node
{
    int cost_1 = numeric_limits<int>::max();
    int cost_n = numeric_limits<int>::max();
    int cost_a = numeric_limits<int>::max();
    int cost_b = numeric_limits<int>::max();

    vector<Line> lines;
};

// 탐색 정보
struct Info
{
    int idx = 0;
    int cost = 0;
    Info() = default;
    Info(int idx, int cost) : idx(idx), cost(cost) {}

    // 우선 순위 큐에서 오름차순 대입이 되도록 오버라이딩
    bool operator<(const Info& other) const
    {
        return cost < other.cost;
    }
};

vector<Node> g_nodes;

void search(int start, bool b_start)
{
    priority_queue<Info> pq;
    pq.push(Info(start, 0));

    while(pq.empty() == false)
    {
        Info info = pq.top();
        int idx = info.idx;
        int cost = info.cost;
        pq.pop();

        // 연결된 노드 모두 확인
        for(const Line& line : g_nodes[idx].lines)
        {
            int& opponent_cost = (b_start) ? g_nodes[idx].cost_start : g_nodes[idx].cost_end;
            
            // 크거나 같으면, 무시
            if(line.cost + cost >= opponent_cost) continue;

            // 더 거리가 짧은 경우이므로 추가
            pq.push(Info(line.opponent, line.cost + cost));
            opponent_cost = line.cost + cost;
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정점 N, 간선 E
    int N, E;
    cin >> N >> E;

    g_nodes = vector<Node>(N+1);

    // 간선 정보 입력
    int in_start, in_opponent, in_cost;
    for(int i = 0; i < E; i++)
    {
        cin >> in_start >> in_opponent >> in_cost;

        g_nodes[in_start].lines.push_back(Line(in_opponent, in_cost));
    }

    // 시작점에서부터 검사
    search(1, true);
    // 끝점에서부터 검사
    search(N, false);

    // 반드시 지나야 하는 정점

}