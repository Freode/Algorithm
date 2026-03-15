// 골드 5 - 6593번 : 상범 빌딩
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 단위 정육면체
// 동서남북상하로 이동 가능
// 인접면의 정육면체로 이동 가능

// 층 수 : 1 <= L <= 30
// 행 : 1 <= R <= 30
// 열 : 1 <= C <= 30

// # : 지나 갈 수 없는 칸
// . : 비어 있는 칸
// E : 출구

// 0 0 0 : 테스트 케이스 종료
// 시작 지점과 출구는 항상 하나

// 탈출하는데 필요한 최단 시간
// 탈출 가능 : Escaped in x minute(s)
// 탈출 불가능

const int dz[] = {1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 1, -1, 0, 0};
const int dx[] = {0, 0, 0, 0, 1, -1};

struct Loc
{
    int z, y, x, cost;
};

vector<vector<vector<int>>> g_areas;
Loc g_start;
Loc g_end;

void initData(const int L, const int R, const int C)
{
    g_areas = vector<vector<vector<int>>>(L, vector<vector<int>>(R, vector<int>(C, 0)));

    string input;
    for(int z = 0; z < L; z++)
    {
        for(int y = 0; y < R; y++)
        {
            cin >> input;
            for(int x = 0; x < C; x++)
            {
                if(input[x] == 'S')
                {
                    g_start = {z, y, x, 1};
                    g_areas[z][y][x] = 0;
                }
                else if(input[x] == 'E')
                {
                    g_end = {z, y, x, 0};
                    g_areas[z][y][x] = 0;
                }
                else if(input[x] == '.')
                {
                    g_areas[z][y][x] = 0;
                }
                else
                {
                    g_areas[z][y][x] = -1;
                }
            }
        }
    }
}

bool isInBoard(const int L, const int R, const int C, const int z, const int y, const int x)
{
    return x >= 0 && y >= 0 && z >= 0 && z < L && y < R && x < C;
}

void simulate(const int L, const int R, const int C)
{
    queue<Loc> q;
    q.push(g_start);
    g_areas[g_start.z][g_start.y][g_start.x] = 1;

    while(q.empty() == false)
    {
        Loc loc = q.front();
        q.pop();

        for(int dir = 0; dir < 6; dir++)
        {
            int next_z = loc.z + dz[dir];
            int next_y = loc.y + dy[dir];
            int next_x = loc.x + dx[dir];

            if(isInBoard(L, R, C, next_z, next_y, next_x) == false)
                continue;

            if(g_areas[next_z][next_y][next_x] != 0)
                continue;

            g_areas[next_z][next_y][next_x] = loc.cost + 1;
            q.push({next_z, next_y, next_x, loc.cost + 1});
        }
    }

    if(g_areas[g_end.z][g_end.y][g_end.x] == 0)
        cout << "Trapped!" << "\n";
    else
        cout << "Escaped in " << g_areas[g_end.z][g_end.y][g_end.x] - 1 << " minute(s).\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 층 수 L, 행 R, 열 C
    int L, R, C;
    while(true)
    {
        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0)
            break;

        initData(L, R, C);
        simulate(L, R, C);
    }
}