// 골드 4 - 2573번 : 빙산
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct Loc
{
    int y = 0;
    int x = 0;
};

struct Area
{
    int height = 0;
    bool bSea = true;
    bool bCheck = false;
};

vector<vector<Area>> g_areas;
int g_counts = 0;
Loc g_find_start = {0, 0};

void result(const int N, const int M)
{
    cout << "==========\n";
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < M; x++)
        {
            cout << g_areas[y][x].height << " ";
        }
        cout << "\n";
    }
}

void inputData(const int N, const int M)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(M));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> g_areas[i][j].height;

            if(g_areas[i][j].height != 0)
            {
                g_areas[i][j].bSea = false;
                g_counts++;
            }
        }
    }
}

// 1년이 지났을 때, 시뮬레이션 진행
void nextYear(const int N, const int M)
{
    // 빙하 녹이기
    for(int y = 1; y < N-1; y++)
    {
        for(int x = 1; x < M-1; x++)
        {
            // 현재 지점이 빙하가 아닌 경우에는 패스
            if(g_areas[y][x].bSea == true)
                continue;

            for(int dir = 0; dir < 4; dir++)
            {
                int nearY = y + dy[dir];
                int nearX = x + dx[dir];

                if(g_areas[nearY][nearX].bSea == true)
                    g_areas[y][x].height--;
            }
        }
    }

    // 빙하가 모두 녹아 바다가 된 경우 처리
    for(int y = 1; y < N-1; y++)
    {
        for(int x = 1; x < M-1; x++)
        {
            if(g_areas[y][x].bSea == false && g_areas[y][x].height <= 0)
            {
                g_areas[y][x].bSea = true;
                g_areas[y][x].height = 0;
                g_counts--;
            }
            // 마지막 빙하 지점 저장
            else if(g_areas[y][x].height > 0)
            {
                g_find_start = {y, x};
            }
        }
    }
}

// 빙하 덩어리가 2덩이 이상인지 확인
bool checkConnect(const int N, const int M)
{
    // 빙하가 이미 모두 다 녹은 경우는 무시
    if(g_areas[g_find_start.y][g_find_start.x].bSea == true)
        return true;

    // 마지막 위치에 있는 빙하 지점을 검사해서, 빙하 크기를 검사
    int count = 1;
    queue<Loc> q;
    q.push(g_find_start);
    g_areas[g_find_start.y][g_find_start.x].bCheck = true;

    while(q.empty() == false)
    {
        Loc cur = q.front();
        q.pop();

        for(int dir = 0; dir < 4; dir++)
        {
            int nextY = cur.y + dy[dir];
            int nextX = cur.x + dx[dir];

            // 이미 방문했다면 패스
            if(g_areas[nextY][nextX].bCheck == true)
                continue;

            // 빙하가 아니라면, 패스
            if(g_areas[nextY][nextX].bSea == true)
                continue;

            g_areas[nextY][nextX].bCheck = true;
            q.push({nextY, nextX});
            count++;
        }
    }

    // 모든 방문 지점 초기화
    for(int y = 1; y < N-1; y++)
    {
        for(int x = 1; x < M-1; x++)
        {
            g_areas[y][x].bCheck = false;
        }
    }

    // 한 덩이로 연결되어 있다면, true로 반환
    return g_counts == count;
}

int simulate(const int N, const int M)
{
    int count = 0;
    while(g_counts > 0)
    {
        nextYear(N, M);
        // result(N, M);
        count++;
        if(checkConnect(N, M) == false)
            return count;
    }

    return 0;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 행의 개수 N, 열의 개수 M
    int N, M;
    cin >> N >> M;

    inputData(N, M);
    cout << simulate(N, M) << "\n";
}