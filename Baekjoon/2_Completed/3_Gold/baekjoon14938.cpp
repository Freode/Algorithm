// 골드 4 - 14938번 : 서강그라운드
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

// 길 정보
struct Line
{
    int dest = 0;
    int cost = 0;

    // 이동 비용 기준의 오름차순
    bool operator<(const Line& other) const
    {
        return cost > other.cost;
    }
};

// 지역 정보
struct Area
{
    int item_count = 0;
    int visit = MAX_VALUE;
    vector<Line> lines;
};

vector<Area> g_areas;

// 이동 비용 모두 초기화
int init(const int n)
{
    int count = 0;
    for(int i = 1; i <= n; i++)
    {
        // 아이템 개수 더하기
        if(g_areas[i].visit != MAX_VALUE)
            count += g_areas[i].item_count;
        
        g_areas[i].visit = MAX_VALUE;
    }

    return count;
}

// 각 종 정보 입력
void input(const int n, const int r)
{
    // 지역별 아이템 정보 입력
    g_areas = vector<Area>(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> g_areas[i].item_count;
    }

    // 이동 비용 입력
    int start, dest, cost;
    for(int i = 0; i < r; i++)
    {
        cin >> start >> dest >> cost;
        g_areas[start].lines.push_back({dest, cost});
        g_areas[dest].lines.push_back({start, cost});
    }
}

// 시작점에서 탐색 범위까지의 탐색 시작
void search(const int start, const int m)
{
    priority_queue<Line> pq;
    pq.push({start, 0});
    g_areas[start].visit = 0;

    while(pq.empty() == false)
    {
        Line move = pq.top();
        pq.pop();

        // 현재 검사하고 있는 비용보다 기존 비용이 저렴한 경우, 무시
        if(move.cost > g_areas[move.dest].visit)
            continue;

        // 현재점에서 다음으로 이동 가능한지 판단
        for(const Line& line : g_areas[move.dest].lines)
        {
            int cost = line.cost + move.cost;

            // 이동했을 때, 수색 비용보다 비싸면, 무시
            if(cost > m)
                continue;

            // 기존 비용보다 더 비싸거나 같은 경우, 무시
            if(cost >= g_areas[line.dest].visit)
                continue;

            // 추가
            pq.push({line.dest, cost});
            g_areas[line.dest].visit = cost;

        }
    }
}

// 전체 시뮬레이션
int simulateAll(const int n, const int m)
{
    int result = 0;
    // 1번부터 n번 지점에서 시작할 때의 시뮬레이션 진행
    for(int start = 1; start <= n; start++)
    {
        search(start, m);
        result = max(result, init(n));
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 지역의 개수 n, 수색 범위 m, 길의 개수 r
    int n, m, r;
    cin >> n >> m >> r;

    // 각 종 정보 입력
    input(n, r);

    // 시뮬레이션 시작
    int result = simulateAll(n, m);

    cout << result << "\n";
}