// 골드 4 - 4485번 : 녹색 옷 입은 애가 젤다지?
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 오른쪽 아래에 도달할 때까지 도둑루피 개수 최소화

const int MAX_VALUE = numeric_limits<int>::max();

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

struct Area
{
    int cost = 0;
    int total_cost = MAX_VALUE;
};

struct Loc
{
    int y = 0;
    int x = 0;
    int cost = 0;

    bool operator<(const Loc& other) const
    {
        return cost > other.cost;
    }
};

vector<vector<Area>> g_areas;

void initData(const int N)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(N));

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> g_areas[y][x].cost;
        }
    }
}

bool isInBoard(const int N, const int y, const int x)
{
    return x >= 0 && y >= 0 && x < N && y < N;
}

int simulate(const int N)
{
    priority_queue<Loc> pq;
    pq.push({0, 0, g_areas[0][0].cost});
    g_areas[0][0].total_cost = g_areas[0][0].cost;

    while(pq.empty() == false)
    {
        Loc cur = pq.top();
        pq.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int next_y = cur.y + dy[dir];
            int next_x = cur.x + dx[dir];

            // 범위 내
            if(isInBoard(N, next_y, next_x) == false)
                continue;

            // 기존 비용이 더 저렴할 경우만 이동
            Area& next = g_areas[next_y][next_x];
            int next_cost = next.cost + cur.cost;
            if((next_cost < next.total_cost) == false)
                continue;

            next.total_cost = next_cost;
            pq.push({next_y, next_x, next_cost});
        }
    }

    return g_areas[N - 1][N - 1].total_cost;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 칸
    int N;
    int idx = 0;
    while(true)
    {
        cin >> N;
        if(N == 0) 
            break;

        // 흠
        if(idx != 0)
            cout << "\n";

        ++idx;
        initData(N);
        cout << "Problem " << idx << ": " << simulate(N);
    }
}