// 골드 3 - 2638번 : 치즈
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 세로 N, 가로 M : 5~100
// 치즈 1, 없음 0

// 1초 후, 외부 공기와 2면 이상 접촉해 있는 치즈는 녹음
// 내부와 접촉해 있는 면은 포함 x

enum State : int
{
    AIR = 0,
    CLOSED_AIR,
    NORMAL_CHEESE,
    REMOVE_CHEESE,
};

struct Area
{
    State state = State::AIR;
    bool b_visit = false;
};

vector<vector<Area>> g_areas;

// 정보 입력
void inputArea(const int N, const int M)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(M));

    int num;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> num;
            g_areas[i][j].state = static_cast<State>(num + 1);
        }
    }
}

// 방문 초기화
void resetVisit()
{
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            g_areas[i][j].b_visit = false;
        }
    }
}

// 경계 안인지 확인
bool isInBoard(const int y, const int x)
{
    return y >= 0 && x >= 0 && y < g_areas.size() && x < g_areas[0].size();
}

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

// 각 외부 공기를 모두 확인
void checkAir(const int y, const int x)
{
    for(int dir = 0; dir < 4; dir++)
    {
        int nextY = y + dy[dir];
        int nextX = x + dx[dir];

        // 경계 안인지 확인
        if(isInBoard(nextY, nextX) == false)
            continue;
        
        // 이미 방문했다면, 무시
        if(g_areas[nextY][nextX].b_visit)
            continue;

        // 공기가 아니라면, 이동
        if((g_areas[nextY][nextX].state <= State::CLOSED_AIR) == false)
            continue;
        
        g_areas[nextY][nextX].b_visit = true;
        g_areas[nextY][nextX].state = AIR;
        checkAir(nextY, nextX);
    }
}

// 없어질 치즈 확인
void removeCheese(const int y, const int x)
{
    // 치즈는 항상 가장자리에 위치하지 않음.

    int count = 0;
    for(int dir = 0; dir < 4; dir++)
    {
        // 외부 공기인 경우 count + 1
        if(g_areas[y + dy[dir]][x + dx[dir]].state == AIR)
            count++;
    }
    // 제거할 치즈 예약
    if(count >= 2)
        g_areas[y][x].state = State::REMOVE_CHEESE;
}

// 모든 치즈가 없어졌는지 확인
bool allChesseRemove()
{
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            if(g_areas[i][j].state == NORMAL_CHEESE)
                return false;
        }
    }
    return true;
}

// 치즈 시뮬레이션 1번 진행
bool simulate()
{
    // 외부 공기인지 검사
    g_areas[0][0].state = AIR;
    resetVisit();
    checkAir(0, 0);

    // 제거할 수 있는 치즈인지 검사
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            // 치즈인 경우 검사
            if(g_areas[i][j].state == NORMAL_CHEESE)
                removeCheese(i,j);
        }
    }

    // 치즈 제거
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas[0].size(); j++)
        {
            // 제거할 치즈이면, 제거
            if(g_areas[i][j].state == REMOVE_CHEESE)
                g_areas[i][j].state = AIR;
        }
    }

    // 모두 제거되었는지 검사 후, 반환
    return allChesseRemove();
}

// 총 진행
int total()
{
    int result = 0;

    while(true)
    {
        // 턴 증가
        result++;

        // 치즈가 제거될 때까지 진행
        if(simulate())
            break;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 세로 N, 가로 M
    int N, M;
    cin >> N >> M;

    // 맵 입력
    inputArea(N, M);

    int result = total();
    cout << result << "\n";
}