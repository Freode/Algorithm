// 플레티넘 5 - 1799번 : 비숍
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 서로를 잡을 수 없는 상태인 비숍을 최대한 많이 배치하는 경우 구하기
// 10 * 10 -> 2^100 = 10^30

// 0 : 다른 기물이 있는 상태
// 1 : 비숍을 놓을 수 있는 자리
// 2 : 이미 비숍이 존재하는 자리

// 비숍을 배치할 때, 해당 비숍의 영향 거리에 미리 값을 넣어서 확인
// (해당 자리에 비숍 놓는게 가능한지 범위에 대한 검사 < 해당 위치에 영향력을 미치는 비숍의 수)로 검사

// 비숍 바로 옆에 대각선을 못 건들임 : 서로 다른 칸을 두 종류로 나눠서 계산
// 10 * 10 -> 2 * 5 * 5 -> 2 * 2^50 = 2 * 10^15

struct Loc
{
    int y = 0;
    int x = 0;
};

struct Checks
{
    int num = 0;
    vector<Loc> locs;

    Checks()
    {
        locs.reserve(100);
    }
};

const int dy[] = {1, 1, -1, -1};
const int dx[] = {-1, 1, 1, -1};

vector<vector<int>> g_areas;
vector<vector<Checks>> g_checks;

bool isInBoard(const int n, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < n && x < n;
}

// 체크해야할 위치들을 방향별로 모두 대입
void putCheckingArea(const int n, const int y, const int x)
{
    for(int dir = 0; dir < 4; dir++)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        while(isInBoard(n, nextY, nextX) == true)
        {
            g_checks[y][x].locs.push_back({nextY, nextX});

            nextY += dy[dir];
            nextX += dx[dir];
        }
    }

    // cout << "y : " << y << ", x : " << x << "\n";
    // for(const Loc& loc : g_checks[y][x].locs)
    // {
    //     cout << loc.y << " " << loc.x << "\n";
    // }
}

void initAntInputData(const int n)
{
    g_areas = vector<vector<int>>(n, vector<int>(n));

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            cin >> g_areas[y][x];
        }
    }

    // 위치별로 검사해야할 자리들을 미리 대입
    g_checks = vector<vector<Checks>>(n, vector<Checks>(n));

    for(int y = 0; y < n; y++)
    {
        for(int x = 0; x < n; x++)
        {
            putCheckingArea(n, y, x);
        }
    }
}

// 비숍을 현재 자리에 놓을 수 있는지 확인
bool canPlace(const int y, const int x)
{
    // 이미 다른 기물이 있는 경우는 무시
    if(g_areas[y][x] == 0)
        return false;

    return g_checks[y][x].num == 0;
}

// 현재 자리에 비숍을 두기
void setPlace(const int y, const int x)
{
    g_checks[y][x].num++;
    for(const Loc& loc : g_checks[y][x].locs)
    {
        g_checks[loc.y][loc.x].num++;
    }
}

// 현재 자리의 비숍을 제거
void removePlace(const int y, const int x)
{
    g_checks[y][x].num--;
    for(const Loc& loc : g_checks[y][x].locs)
    {
        g_checks[loc.y][loc.x].num--;
    }
}

int simulate(const int n, const int y, const int x, const int cnt, bool bIsFirst)
{
    // 끝까지 검사 완료
    if(y == n)
        return cnt;

    // 다음 위치를 미리 계산
    int nextY = y;
    int nextX = x + 2;
    if(nextX >= n)
    {
        nextY++;
        nextX = bIsFirst ? nextY % 2 : (nextY - 1) % 2;
    }

    int result = 0;
    // 현재 위치에 비숍을 두는 것이 가능한지 확인
    if(canPlace(y, x) == true)
    {
        // 비숍을 현재 자리에 두고 추가로 검사
        setPlace(y, x);
        result = max(result, simulate(n, nextY, nextX, cnt + 1, bIsFirst));
        removePlace(y, x);
    }

    // 비숍을 현재 자리에 두지 않고 추가로 검사
    result = max(result, simulate(n, nextY, nextX, cnt, bIsFirst));

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 체스판 크기 n
    int n;
    cin >> n;

    initAntInputData(n);
    int result = simulate(n, 0, 0, 0, true);

    if(n > 1)
        result += simulate(n, 0, 1, 0, false);

    cout << result << "\n";
}