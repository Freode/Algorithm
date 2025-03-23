// 골드 5 - 15686번 : 치킨 배달
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

int dy[] = {1, 0, -1, 0};
int dx[] = {0, -1, 0, 1};

struct Loc
{
    int y = 0;
    int x = 0;
};

struct Area
{
    int cost = 0;
    int state = 0;
};

vector<vector<Area>> g_areas;
vector<Loc> g_chickens;
vector<Loc> g_selects;

// 장소 정보 입력
void inputArea(const int N)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_areas[i][j].state;
            // 치킨 집 좌표 입력
            if(g_areas[i][j].state == 2) g_chickens.push_back({i,j});
        }
    }
}

// 비용 초기화
void initCost()
{
    int size = g_areas.size();

    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            g_areas[i][j].cost = 0;
        }
    }
}

// 범위 안인지 확인
bool isInBoard(const Loc& loc, const int& size)
{
    return loc.y >= 0 && loc.x >= 0 && loc.y < size && loc.x < size;
}

// 시뮬레이션 시작
int simulate()
{
    queue<Loc> que;
    // 치킨 집 입력
    for(const Loc& loc : g_selects)
    {
        que.push(loc);
        g_areas[loc.y][loc.x].cost = 1;
    }

    // 
    int size = g_areas.size();
    int distance = 0;
    while(que.empty() == false)
    {
        Loc loc = que.front();
        que.pop();

        // 4방향 검사
        for(int dir = 0; dir < 4; dir++)
        {
            int y = loc.y + dy[dir];
            int x = loc.x + dx[dir];

            // 범위 밖이면, 무시
            if(isInBoard({y, x}, size) == false) continue;

            // 방문하지 않았을 때만, 진행
            if(g_areas[y][x].cost != 0) continue;

            g_areas[y][x].cost = g_areas[loc.y][loc.x].cost + 1;
            que.push({y,x});

            // 가정집일 경우, 치킨 거리로 포함
            // 시작할 때, 거리를 1로 설정했기 때문에, -1 계산
            if(g_areas[y][x].state == 1) distance += (g_areas[y][x].cost - 1);
        }
    }
    return distance;
}

// 남길 치킨 집 선택하고 시뮬레이션
int select(const int M, const int idx)
{
    // 모두 선택했으니, 시뮬레이션 시작
    if(M == 0)
    {
        int distance = simulate();
        initCost();
        return distance;
    }

    // 선택 중..
    int size = g_chickens.size();
    int result = MAX_VALUE;

    for(int i = idx; i < size; i++)
    {
        g_selects.push_back(g_chickens[i]);
        result = min(result, select(M-1, i+1));
        g_selects.pop_back();
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 길이 N, 치킨 집 M
    int N, M;
    cin >> N >> M;

    // 장소 정보 입력
    inputArea(N);

    // 남길 치킨 집 선택하고 시뮬레이션
    int result = select(M, 0);

    cout << result << "\n";
}