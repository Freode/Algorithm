// 골드 4 - 17069번 : 파이프 옮기기 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 처음에는 0,0과 0,1 차지
// 가로 -> 가로 & 대각선
// 세로 -> 세로 & 대각선
// 대각선 -> 가로 & 대각선 & 세로

// 오른쪽 끝까지 이동할 수 있는 가짓 수

// 빈칸 0, 벽 1
// 3 <= N <= 32
// 3차원 [y][x][dir]

using ll = long long;

vector<vector<vector<ll>>> g_areas;

void initData(const int N)
{
    g_areas = vector<vector<vector<ll>>>(N, vector<vector<ll>>(N, vector<ll>(3, 0)));

    int state = 0;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> state;
            if(state == 0)
                continue;

            for(int dir = 0; dir < 3; dir++)
            {
                g_areas[y][x][dir] = -1;
            }
        }
    }
}

ll simulate(const int N)
{
    // 0 : 가로
    // 1 : 세로
    // 2 : 대각선
    g_areas[0][1][0] = 1;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            // 무시
            if((y == 0 && x == 0) || (y == 0 && x == 1))
                continue;

            // 현재 위치가 벽
            if(g_areas[y][x][0] == -1)
                continue;

            // 가로
            if(x - 1 >= 0 && g_areas[y][x - 1][0] != -1)
            {
                g_areas[y][x][0] = g_areas[y][x - 1][0] + g_areas[y][x - 1][2];
            }
            // 세로
            if(y - 1 >= 0 && g_areas[y - 1][x][0] != -1)
            {
                g_areas[y][x][1] = g_areas[y - 1][x][1] + g_areas[y - 1][x][2];
            }
            // 대각선
            if(x - 1 >= 0 && y - 1 >= 0 && g_areas[y - 1][x - 1][0] != -1 && g_areas[y - 1][x][0] != -1 && g_areas[y][x - 1][0] != -1)
            {
                g_areas[y][x][2] = g_areas[y - 1][x - 1][0] + g_areas[y - 1][x - 1][1] + g_areas[y - 1][x - 1][2];
            }
        }
    }

    ll result = g_areas[N - 1][N - 1][0] + g_areas[N - 1][N - 1][1] + g_areas[N - 1][N - 1][2];
    return (result < 0) ? 0 : result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 칸 N
    int N;
    cin >> N;

    initData(N);
    cout << simulate(N) << "\n";
}
