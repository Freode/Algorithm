// 골드 3 - 20057번 : 마법사 상어와 토네이도
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//  1/1/2/2/3/3/4/4/...
// 방향은 왼/아래/오/위
// 격자 밖으로 나간 모래의 양 구하기

// 1'000 * 499 * 499 = 250'000'000

struct Loc
{
    int y, x;
};

vector<vector<int>> g_areas;

const int dy[] = {0, 1, 0, -1};
const int dx[] = {-1, 0, 1, 0};

const int mv_y[] = {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0};
const int mv_x[] = {0, -1, 0, 1, -2, -1, 0, 1, 0, -1};
const int mv_rt[] = {2, 10, 7, 1, 5, 10, 7, 1, 2, 100};

void initData(const int N)
{
    g_areas = vector<vector<int>>(N, vector<int>(N, 0));

    for(int r = 0; r < N; r++)
    {
        for(int c = 0; c < N; c++)
        {
            cin >> g_areas[r][c];
        }
    }
}

bool isInBoundary(const int N, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < N && x < N;
}

void rotate(int& y, int& x, const int dir)
{
    // 왼
    if(dir == 0)
    {
        return;
    }
    // 아래 - 반시계 90도
    else if(dir == 1)
    {
        int tmp = y;
        y = -x;
        x = tmp;
    }
    // 오 - 반시계 180도
    else if(dir == 2)
    {
        y = -y;
        x = -x;
    }
    // 위 - 반시계 270도
    else
    {
        // -2, 0 -> 0, 2
        int tmp = -y;
        y = x;
        x = tmp;
    }
}

int simulate(const int N)
{
    Loc loc = {N >> 1, N >> 1};

    int move = 1;
    int dir = 0;
    int result = 0;
    // 끝까지 이동
    while((loc.y == 0 && loc.x == 0) == false)
    {
        for(int cnt = 0; cnt < move; cnt++)
        {
            loc.y += dy[dir];
            loc.x += dx[dir];

            int sand = g_areas[loc.y][loc.x];

            for(int mv = 0; mv < 10; mv++)
            {
                int sand_dy = mv_y[mv];
                int sand_dx = mv_x[mv];
                rotate(sand_dy, sand_dx, dir);

                int sand_y = loc.y + sand_dy;
                int sand_x = loc.x + sand_dx;
                int sand_val = sand * mv_rt[mv] / 100;

                // 경계 밖
                if(isInBoundary(N, sand_y, sand_x) == false)
                    result += min(sand_val, g_areas[loc.y][loc.x]);
                
                    // 경계 안
                else
                    g_areas[sand_y][sand_x] += min(sand_val, g_areas[loc.y][loc.x]);
                
                g_areas[loc.y][loc.x] -= min(sand_val, g_areas[loc.y][loc.x]);
            }

            if(loc.y == 0 && loc.x == 0)
                return result;
        }

        ++dir;
        if(dir % 2 == 0)
            ++move;
        dir %= 4;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 격자의 크기 N
    int N;
    cin >> N;

    initData(N);
    cout << simulate(N) << "\n";
}