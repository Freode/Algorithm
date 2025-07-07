// 골드 1 - 1738번 : 골목길
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 금품 + or -
// 해당 라인 중복 이동 시, 증가 및 감소 진행

// 금품 -> 음수 유지 가능
// 집 -> 콘도 : 금품의 양 최대

// 교차 지점 : n 2~100
// 골목길 : m 1~20'000
// 출발 도착으로 주어짐(단방향)
// 금품 +- : -1'000 ~ 1'000
// 음수 : 갈취, 양수 : 획득

// 콘도 도착 시, 금품이 최대가 되는 교차 지점 경로 출력
// 최적의 경로가 없는 경우는 -1 -> 사이클이 발생해 무한 루프 타는 경우
 
// 일반적인 상황 -> 우선순위 큐(낮은 순서대로 실행)? BFS?

// 사이클 판단 -> 현재 교차 지점에 이전 교차 지점을 기록
// 이동했을 때, 이전 교차 지점이 갱신되지 않는다면, 사이클 발생
// 사이클 발생 시, -1로 기록
// 경로 역추적할 때, -1을 발견하면, -1만 출력

const int MIN_VALUE = -1'000'000'000;
const int MAX_VALUE = 1'000'000'000;

struct Line
{
    int dest = 0;
    int cost = 0;

    bool operator<(const Line& other) const
    {
        return cost < other.cost;
    }
};

struct Area
{
    vector<Line> connects;
    int prev = 0;
    int cost = MIN_VALUE;
    int count = 0;
};

vector<Area> g_areas;

void inputData(const int n, const int m)
{
    g_areas = vector<Area>(n+1);

    int start, dest, cost;
    for(int i = 0; i < m; i++)
    {
        cin >> start >> dest >> cost;
        g_areas[start].connects.push_back({dest, cost});
    }
}

void simualte(const int n, const int m)
{
    // 우선순위 초기화
    priority_queue<Line> pq;
    pq.push({1, 0});
    g_areas[1].cost = 0;

    while(pq.empty() == false)
    {
        Line cur_line = pq.top();
        Area& cur_area = g_areas[cur_line.dest];
        pq.pop();

        // 연결되어 있는 간선 확인
        for(const Line& line : cur_area.connects)
        {
            // 사이클이 발생한 경로로 온 경우
            if(cur_line.cost == MAX_VALUE)
            {
                // 만약에 다시 이동할 곳에 사이클이라고 이미 판단한 경우는 무시
                if(g_areas[line.dest].prev == -1)
                    continue;

                // 그렇지 않은 경우, 사이클로 인해 이득을 봤다고 판단하고, -1로 처리
                g_areas[line.dest].prev = -1;
                g_areas[line.dest].cost = MAX_VALUE;
                pq.push({line.dest, MAX_VALUE});
                continue;
            }

            int cur_cost = line.cost + cur_line.cost;
            // 비용이 더 큰 경우, 이동 가능
            if(cur_cost > g_areas[line.dest].cost == false)
                continue;

            // 이미 사이클이 발생한 경우, 무시
            if(g_areas[line.dest].prev == -1)
                continue;

            // 해당 지역을 골목길 개수보다 많이 방문하는 경우, 사이클 발생했다고 판단
            if(g_areas[line.dest].count > m)
            {
                g_areas[line.dest].prev = -1;
                g_areas[line.dest].cost = MAX_VALUE;
                pq.push({line.dest, MAX_VALUE});
                continue;
            }

            // 모두 통과했으므로 새로운 정보 등록
            g_areas[line.dest].cost = cur_cost;
            g_areas[line.dest].prev = cur_line.dest;
            g_areas[line.dest].count++;
            pq.push({line.dest, cur_cost});
        }
    }
}

void findPath(const int n)
{
    // 도착 지점에서 

    int cur = n;
    vector<int> paths;
    paths.reserve(n);
    paths.push_back(n);

    // 경로 찾기
    while(cur != 1)
    {
        // 이전 경로가 -1이 아닌 경우만 이동
        if(g_areas[cur].prev == -1 || g_areas[cur].cost >= MAX_VALUE)
        {
            cout << "-1\n";
            return;
        }

        paths.push_back(g_areas[cur].prev);
        cur = g_areas[cur].prev;
    }

    // 경로 출력
    for(int i = paths.size()-1; i >= 0; i--)
    {
        cout << paths[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 교차 지점 n, 골목길 m
    int n, m;
    cin >> n >> m;

    inputData(n, m);
    simualte(n, m);
    findPath(n);
}