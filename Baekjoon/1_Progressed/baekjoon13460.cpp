// 골드 1 - 13460번 : 구슬 탈출 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

using v1i = vector<int>;
using v2i = vector<v1i>;
using v3i = vector<v2i>;
using v4i = vector<v3i>;

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct Loc
{
    int red_y = 0;
    int red_x = 0;
    int blue_y = 0;
    int blue_x = 0;
};

vector<vector<char>> g_area;
v4i g_visits;

// 구역 및 방문 기록 초기화와 데이터 입력
void inputData(const int N, const int M, Loc& start)
{
    g_area = vector<vector<char>>(N, vector<char>(M));
    g_visits = v4i(N, v3i(M, v2i(N, v1i(M, false))));

    for(int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        for(int j = 0; j < M; j++)
        {
            g_area[i][j] = input[j];

            if(input[j] == 'R')
            {
                start.red_y = i;
                start.red_x = j;
            }
            else if(input[j] == 'B')
            {
                start.blue_y = i;
                start.blue_x = j;
            }
        }
    }
}

// 방문했다고 설정
void setVisit(const Loc& visit)
{
    g_visits[visit.red_y][visit.red_x][visit.blue_y][visit.blue_x] = true;
}

// 특정 방향으로 구슬을 기울려서 보내기
bool calculateMove(const Loc& start, Loc& next, const int dir)
{
    Loc cur = start;

    // 왼쪽으로 굴릴 때, 더 왼쪽에 있는 구슬부터 한 칸씩 옮겨야 함.

    // 벽이 아닐 때까지 이동
    if()
    while(true)
    {
        // 이동하는 구간에 출구가 있는 경우
        if(g_area[nextY][nextX])
            return true;

        nextY += dy[dir];
        nextX += dx[dir];
    }

    // 마지막 칸은 벽이므로 1칸 다시 되돌리기
    nextY -= dy[dir];
    nextX -= dx[dir];

    // 구슬 색상에 맞춰서 대입
    if(isRed)
    {
        next.red_y = nextY;
        next.red_x = nextX;
    }
    else
    {
        next.blue_y = nextY;
        next.blue_x = nextX;
    }

    return false;
}

int simulate(const int N, const int M, const Loc& start)
{
    int result = 0;

    queue<Loc> q;
    q.push(start);
    setVisit(start);

    while(q.empty() == false)
    {
        Loc cur = q.front();
        q.pop();

        // 방향별로 검사
        for(int dir = 0; dir < 4; dir++)
        {
            Loc next;
            // 특정 방향에 따라 공의 위치 계산
            calculateMove(cur, next, dir);

            // 다음 지역이 이미 방문한 곳이라면, 
        }
    }

}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 세로 N, 가로 M
    int N, M;
    cin >> N >> M;

    Loc start;
    inputData(N, M, start);

}