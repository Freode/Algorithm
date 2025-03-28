// 골드 2 - 1167번 : 트리의 지름
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 정점 개수 V : 최대 100'000
// 두 번째 줄 : 간선 정보
// 정점, 다른 연결 정점, 비용, 다른 연결 정점, 비용, -1(끝)
// 간선 -> 양방향 -> 중복 입력되는 것 조심

// 거리는 10'000 이하 자연수

// 트리의 지름 : 임의의 두 점 사이의 거리가 가장 긴 것

struct Line
{
    int dest = 0;
    int cost = 0;
};

struct Node
{
    int cost = 0;
    vector<Line> lines;
};

vector<Node> g_nodes;

// 모든 노드 비용 초기화
void initNode(const int N)
{
    for(int i = 1; i <= N; i++)
    {
        g_nodes[i].cost = 0;
    }
}

// 간선 정보 입력
void inputInfo(const int N)
{
    g_nodes = vector<Node>(N+1);

    int start, end, cost;
    for(int i = 1; i <= N; i++)
    {
        cin >> start;

        // -1이 입력되면, 끝
        while(cin >> end && end != -1)
        {
            // 연결 정보 입력
            cin >> cost;
            g_nodes[start].lines.push_back({end, cost});
        }
    }
}

// 탐색 시작
int search(const int start)
{
    // 비용 기준 내림차순
    priority_queue<Line> pq;
    pq.push({start, 0});

    int result = 0;

    while(pq.empty() == false)
    {
        Line move = pq.top();
        pq.pop();

        // 현재 검사하는 비용이 기존보다 더 적은 경우 무시
        if(move.cost < g_nodes[move.dest].cost) continue;

        // 무한 반복 방지 - 이전 목적지
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

}