// 골드 4 - 19952번 : 인성 문제 있어?
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 상하좌우 1칸 이동 -> 힘 1씩 감소
// 높이가 더 낮으면, 제약 x
// 높이가 더 높으면, (이동할 곳 높이 - 현재 위치 높이) >= 남아 있는 힘 -> 이동 가능

// 목적지 도착 가능 -> 잘했어!! 출력
// 목적지 도착 불가능 -> 인성 문제있어?? 출력

const int MAX_VALUE = numeric_limits<int>::max();

struct Loc
{
    int y;
    int x;

    Loc& operator--()
    {
        --y;
        --x;
        return *this;
    }
};

struct Info
{
    int height = 0;
    int cost = MAX_VALUE;
};

// 방향
int dy[] = {1,0,-1,0};
int dx[] = {0,1,0,-1};

vector<vector<Info>> g_areas;

// 장애물 정보 입력
void inputArea(const int H, const int W, const int O)
{
    Loc loc;
    int height;
    g_areas.clear();
    g_areas = vector<vector<Info>>(H, vector<Info>(W));
    for(int i = 0; i < O; i++)
    {
        cin >> loc.y >> loc.x >> height;
        g_areas[loc.y-1][loc.x-1].height = height;
    }
}

// 경계 내부인지 확인
bool isInBoard(const Loc& loc)
{
    return loc.y >= 0 && loc.x >= 0 && loc.y < g_areas.size() && loc.x < g_areas[0].size();
}

// 도착지에 도착했는지 확인
bool isDest(const Loc& loc, const Loc& end)
{
    return loc.y == end.y && loc.x == end.x;
}

// 출발지에서 도착지로 이동 가능한지 판단
bool simulate(const Loc& start, const Loc& end, const int F)
{
    g_areas[start.y][start.x].cost = 0;
    queue<Loc> q;
    q.push(start);

    bool b_dest = false;
    while(q.empty() == false)
    {
        Loc loc = q.front();
        q.pop();

        // 방향에 따라 검사
        for(int dir = 0; dir < 4; dir++)
        {
            int nextY = loc.y + dy[dir];
            int nextX = loc.x + dx[dir];

            // 경계 내부인지 확인
            if(isInBoard({nextY, nextX}) == false)
                continue;

            // 이미 이동한 공간이면, 무시
            if(g_areas[nextY][nextX].cost != MAX_VALUE)
                continue;

            // 높이가 더 높은 장애물인 경우, 힘이 부족할 때면, 무시
            int necessary = max(0, g_areas[nextY][nextX].height - g_areas[start.y][start.x].height);
            int cost = g_areas[start.y][start.x].cost;
            int remain = F - cost;
            if((necessary <= remain) == false)
                continue;

            // 만약에 남은 힘이 0인 경우, 무시
            if(remain <= 0)
                continue;

            // 도착지에 도착했다면, 모두 무시
            if(isDest({nextY, nextX}, end))
            {
                b_dest = true;
                break;
            }

            // 이동
            q.push({nextY, nextX});
            g_areas[nextY][nextX].cost = cost + 1;
        }
    }
    return b_dest;
}

// 결과 출력
void printResult(const bool b_result)
{
    if(b_result)
        cout << "잘했어!!\n";
    else
        cout << "인성 문제있어??\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        // 세로 길이 H, 가로 길이 W, 장애물 개수 O, 초기 힘 F
        int H, W, O, F;
        cin >> H >> W >> O >> F;

        // 출발지 y, x ,, 도착지 y, x
        Loc start, end;
        cin >> start.y >> start.x >> end.y >> end.x;
        --start;
        --end;

        // 장애물 정보 입력
        inputArea(H, W, O);

        bool b_result = simulate(start, end, F);
        printResult(b_result);
    }
}
