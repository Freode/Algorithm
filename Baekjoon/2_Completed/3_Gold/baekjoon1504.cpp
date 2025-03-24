// 골드 4 - 1504번 : 특정한 최단 경로
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 간선 중복 이동 가능

// 1->a->b->n
// 1->b->a->n


const int MAX_VALUE = numeric_limits<int>::max();

// 간선 정보
struct Line
{
    int opponent = 0;
    int cost = 0;
};

// 노드 정보
struct Node
{
    vector<int> costs;
    vector<Line> lines;

    Node() { costs = vector<int>(4, MAX_VALUE); }
};

// 탐색 정보
struct Info
{
    int idx = 0;
    int cost = 0;

    // 우선 순위 큐에서 오름차순 대입이 되도록 오버라이딩
    bool operator<(const Info& other) const
    {
        return cost > other.cost;
    }
};

vector<Node> g_nodes;

// 최소 비용 탐색 시뮬레이션
void search(const int start, const int option)
{
    priority_queue<Info> pq;
    pq.push({start, 0});
    g_nodes[start].costs[option] = 0;

    while(pq.empty() == false)
    {
        Info info = pq.top();
        int idx = info.idx;
        int cost = info.cost;
        pq.pop();

        // 비용이 더 큰 경우는 무시
        if(cost > g_nodes[idx].costs[option]) continue;

        // 연결된 노드 모두 확인
        for(const Line& line : g_nodes[idx].lines)
        {
            // 크거나 같으면, 무시
            if((line.cost + cost < g_nodes[line.opponent].costs[option]) == false) continue;

            // 더 거리가 짧은 경우이므로 추가
            pq.push({line.opponent, line.cost + cost});
            g_nodes[line.opponent].costs[option] = line.cost + cost;
        }
    }
}

// 결과 계산
int calculate(const int N, const int v1, const int v2)
{
    // 1->a->b->n
    // 1->b->a->n
    int result = -1;

    int ab_seq = 0, ba_seq;
    ab_seq = g_nodes[v1].costs[0] + g_nodes[v2].costs[1] + g_nodes[N].costs[2];
    ba_seq = g_nodes[v2].costs[0] + g_nodes[v1].costs[2] + g_nodes[N].costs[1];

    // v1 - v2 간선은 최대 1개 존재
    // 도달하지 못하는 경우 확인
    // 1~v1, v1~v2, v2~N
    if(g_nodes[v1].costs[0] == MAX_VALUE || g_nodes[v2].costs[1] == MAX_VALUE || g_nodes[N].costs[2] == MAX_VALUE) ab_seq = -1;
    // 1~v2, v2~v1, v1~N
    if(g_nodes[v2].costs[0] == MAX_VALUE || g_nodes[v1].costs[2] == MAX_VALUE || g_nodes[N].costs[1] == MAX_VALUE) ba_seq = -1;

    result = (ab_seq == -1 && ba_seq == -1) ? -1 : min(ab_seq, ba_seq);

    return result;
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

        g_nodes[in_start].lines.push_back({in_opponent, in_cost});
        g_nodes[in_opponent].lines.push_back({in_start, in_cost});
    }
    // 중간점 입력 v1, v2
    int v1, v2;
    cin >> v1 >> v2;

    // 시작점에서부터 검사
    search(1, 0);
    // 중간점에서 검사 1
    search(v1, 1);
    // 중간점에서 검사 2
    search(v2, 2);
    // 끝점에서부터 검사
    search(N, 3);

    // 둘 중 최소 비용 선택
    // 1->a->b->n
    // 1->b->a->n
    int result = calculate(N, v1, v2);
    cout << result << "\n";
}