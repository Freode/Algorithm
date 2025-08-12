// 골드 3 - 16724번 : 피리 부는 사나이
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

enum DIR
{
    UP = 0,
    DOWN = 1,
    LEFT = 2,
    RIGHT = 3
};

struct Area
{
    char state = ' ';
    bool visit = false;
};

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

vector<vector<Area>> g_areas;

int getDir(const int y, const int x, bool reverse)
{
    int result = 0;
    switch (g_areas[y][x].state)
    {
    case 'U':
        result = reverse ? DOWN : UP;
        break;
    
    case 'D':
        result = reverse ? UP : DOWN;
        break;

    case 'L':
        result = reverse ? RIGHT : LEFT;
        break;

    case 'R':
        result = reverse ? LEFT : RIGHT;
        break;
    }

    return result;
}

void initAndInputData(const int N, const int M)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(M));
    string input;

    for(int i = 0; i < N; i++)
    {
        cin >> input;

        for(int j = 0; j < M; j++)
        {
            g_areas[i][j].state = input[j];
        }
    }
}

bool isInBoard(const int y, const int x)
{
    return y >= 0 && x >= 0 && y < g_areas.size() && x < g_areas[0].size();
}

// 같은 그룹은 모두 방문으로 처리
void findSameGroup(const int y, const int x)
{
    if(g_areas[y][x].visit == true)
        return;

    // cout << y << " " << x << "\n";

    g_areas[y][x].visit = true;

    // 현재 위치에서의 이동 방향으로 이동
    int dir = getDir(y, x, false);
    findSameGroup(y + dy[dir], x + dx[dir]);

    // 현재 위치에 도착 가능한 방향
    for(int i = 0; i < 4; i++)
    {
        int prevY = y + dy[i];
        int prevX = x + dx[i];

        // 범위 밖인 경우, 무시
        if(isInBoard(prevY, prevX) == false)
            continue;

        int prevDir = getDir(prevY, prevX, true);
        // 이전 칸 방향이 현재 칸으로 향하는지 확인
        if(i != prevDir)
            continue;

        // cout << "prev\n";
        // cout << y << " " << x << " " << dir << "\n";
        findSameGroup(prevY, prevX);
    }
}

int simulate(const int N, const int M)
{
    int result = 0;
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            // 이미 방문했다면, 무시
            if(g_areas[y][x].visit == true)
                continue;

            result++;
            findSameGroup(y, x);
        }
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

    initAndInputData(N, M);
    cout << simulate(N, M) << "\n";

}