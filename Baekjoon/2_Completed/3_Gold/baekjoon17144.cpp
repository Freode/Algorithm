// 골드 4 - 17144번 : 미세먼지 안녕!
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 미세먼지 -> 상하좌우 확산, [A/5] 내림만큼 확산
// 기존의 양에서 확산
// 공기청정기 -> 위쪽 : 반시계방향 순환, 아래쪽 : 시계방향 순환
// 바람 -> 미세먼지가 한 칸씩 이동
// 공기청정기로 들어간 미세먼지는 모두 제거

// 공기청정기는 가장 윗 행과 아랫 행 두 칸 이상씩 떨어져 있음.
// -1은 위 아래로만 배치

struct Area
{
    int cur = 0;
    int after = 0;
    bool fresher = false;
};

struct Loc
{
    int y = 0;
    int x = 0;
};

vector<vector<Area>> g_areas;
Loc g_up;
Loc g_down;

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

// 맵 입력
void inputArea(const int R, const int C)
{
    g_areas = vector<vector<Area>>(R, vector<Area>(C));

    for(int i = 0; i < R; i++)
    {
        for(int j = 0; j < C; j++)
        {
            cin >> g_areas[i][j].cur;
            // 공기청정기 위치
            if(g_areas[i][j].cur == -1)
            {
                g_areas[i][j].fresher = true;
                // 공기 청정기 윗 부분
                if(g_up.y == 0)
                    g_up = {i, j};
                // 공기 청정기 아랫 부분
                else
                    g_down = {i, j};
            }
        }
    }
}

// 범위 안에 있는지 확인
bool isInBoard(const int y, const int x)
{
    return y >= 0 && x >= 0 && y < g_areas.size() && x < g_areas[0].size();
}

// 이동 후 결과를 현재로 변경
void reset()
{
    //cout << "=====\n";
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            // 공기 청정기가 아닐 때
            if(g_areas[i][j].fresher == false)
                g_areas[i][j].cur = g_areas[i][j].after;

            g_areas[i][j].after = 0;
            //cout << g_areas[i][j].cur << " ";
        }
        //cout << "\n";
    }
}

// 미세먼지 확장
void spread()
{
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            // 미세먼지가 해당 칸에 존재할 때만 진행
            if(g_areas[i][j].cur <= 0)
                continue;
            
            g_areas[i][j].after += g_areas[i][j].cur;

            int div = g_areas[i][j].cur / 5;
            // 전달할 수 없으면, 무시
            if(div == 0)
                continue;
            // 방향별로 확산
            for(int dir = 0; dir < 4; dir++)
            {
                int nextY = i + dy[dir];
                int nextX = j + dx[dir];

                // 범위 밖이면, 무시
                if(isInBoard(nextY, nextX) == false)
                    continue;

                // 공기 청정기가 아닌 곳으로만, 확산
                if(g_areas[nextY][nextX].fresher)
                    continue;

                g_areas[i][j].after -= div;
                g_areas[nextY][nextX].after += div;
            }
        }
    }
}

// 공기 청정기로 인한 이동
void move()
{
    int right = g_areas[0].size()-1;
    int down = g_areas.size()-1;
    // 반시계 방향
    for(int i = g_up.x; i > 0; i--)
        g_areas[g_up.y][i].after = g_areas[g_up.y][i-1].after;

    g_areas[g_up.y][g_up.x].after = 0;

    for(int i = g_up.y; i > 0; i--)
        g_areas[i][0].after = g_areas[i-1][0].after;

    g_areas[g_up.y][g_up.x].after = 0;

    for(int i = 0; i < right; i++)
        g_areas[0][i].after = g_areas[0][i+1].after;

    for(int i = 0; i < g_up.y; i++)
        g_areas[i][right].after = g_areas[i+1][right].after;

    for(int i = right; i > g_up.x; i--)
        g_areas[g_up.y][i].after = g_areas[g_up.y][i-1].after;

    // 시계 방향
    for(int i = g_down.x; i > 0; i--)
        g_areas[g_down.y][i].after = g_areas[g_down.y][i-1].after;

    g_areas[g_down.y][g_down.x].after = 0;    
    for(int i = g_down.y; i < down; i++)
        g_areas[i][0].after = g_areas[i+1][0].after;

    g_areas[g_down.y][g_down.x].after = 0;   
    for(int i = 0; i < right; i++)
        g_areas[down][i].after = g_areas[down][i+1].after;

    for(int i = down; i > g_down.y; i--)
        g_areas[i][right].after = g_areas[i-1][right].after;

    for(int i = right; i > g_down.x; i--)
        g_areas[g_down.y][i].after = g_areas[g_down.y][i-1].after;
}

void simulate(const int T)
{
    for(int i = 0; i < T; i++)
    {
        spread();
        move();
        reset();
    }
}

void printResult()
{
    int result = 0;
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            if(g_areas[i][j].cur != -1)
                result += g_areas[i][j].cur;
        }
    }
    cout << result << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 R, 가로 C, 시간 T
    int R, C, T;
    cin >> R >> C >> T;

    // 입력
    inputArea(R, C);

    // 시뮬레이션
    simulate(T);

    // 결과 출력
    printResult();
}