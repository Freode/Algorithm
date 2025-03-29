// 골드 2 - 1167번 : 트리의 지름
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

// 정점 개수 V : 최대 100'000
// 두 번째 줄 : 간선 정보
// 정점, 다른 연결 정점, 비용, 다른 연결 정점, 비용, -1(끝)
// 간선 -> 양방향 -> 중복 입력되는 것 조심

// 거리는 10'000 이하 자연수

// 트리의 지름 : 임의의 두 점 사이의 거리가 가장 긴 것

// 위 방식은 틀림

// 1. 임의의 점에서 가장 긴 지름 구하기 -> 끝점이 지름의 한 점과 일치
// 2. 해당 점에서 가장 긴 지름 구하기 -> 트리의 지름

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
void search(const int idx)
{
    // 연결된 점으로 이동 시도
    for(const Line& line : g_nodes[idx].lines)
    {
        // 이미 검사한 지점이면, 무시
        if(g_nodes[line.dest].cost != 0 ) continue;

        g_nodes[line.dest].cost = g_nodes[idx].cost + line.cost;
        search(line.dest);
    }
}

// 가장 비용이 큰 점과 거리 정보 가져오기
pair<int, int> getMaxCost()
{
    pair<int,int> result = {0, 0};
    for(int i = 1; i <= g_nodes.size(); i++)
    {
        if(result.first < g_nodes[i].cost)
        {
            result.first = g_nodes[i].cost;
            result.second = i;
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 노드 개수 N
    int N;
    cin >> N;

    // 간선 정보 입력
    inputInfo(N);

    // 탐색 시작
    g_nodes[1].cost = 1;
    search(1);

    // 끝점 하나 확인
    pair<int, int> end_point = getMaxCost();
    initNode(N);

    // 찾은 끝점 하나로 다른 끝점 찾기
    g_nodes[end_point.second].cost = 1;
    search(end_point.second);

    // 지름 확인
    pair<int, int> result = getMaxCost();

    cout << result.first-1 << "\n";
}