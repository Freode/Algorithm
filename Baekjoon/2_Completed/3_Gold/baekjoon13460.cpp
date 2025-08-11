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

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

enum Dir
{
    UP = 0,
    DOWN,
    LEFT,
    RIGHT
};

enum Result
{
    ESCAPE = 0,
    RETURN,
    VISIT,
    PASS
};

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
    g_visits = v4i(N, v3i(M, v2i(N, v1i(M, -1))));

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
                g_area[i][j] = '.';
            }
            else if(input[j] == 'B')
            {
                start.blue_y = i;
                start.blue_x = j;
                g_area[i][j] = '.';
            }
        }
    }
}

// 방문했다고 설정
void setVisit(const Loc& visit, const int& cnt)
{
    g_visits[visit.red_y][visit.red_x][visit.blue_y][visit.blue_x] = cnt;
}

int getVisit(const Loc& visit)
{
    return g_visits[visit.red_y][visit.red_x][visit.blue_y][visit.blue_x];
}

bool isVisit(const Loc& visit)
{
    return g_visits[visit.red_y][visit.red_x][visit.blue_y][visit.blue_x] != -1;
}

// 누가 더 앞에 있는지
bool whoIsFront(const int dir, const Loc& loc)
{
    bool result = false;
    switch (dir)
    {

    case UP:
        result = loc.red_y < loc.blue_y; 
        break;
    
    case DOWN:
        result = loc.red_y > loc.blue_y;
        break;

    case LEFT:
        result = loc.red_x < loc.blue_x;
        break;

    case RIGHT:
        result = loc.red_x > loc.blue_x;
        break;

    default:
        break;
    }

    return result;
}

bool executeMove(const int dir, const bool isRed, const Loc& start, Loc& next)
{
    int nextY = isRed ? start.red_y : start.blue_y;
    int nextX = isRed ? start.red_x : start.blue_x;
    int opponentY = isRed ? start.blue_y : start.red_y;
    int opponentX = isRed ? start.blue_x : start.red_x;
    bool result = false;
    while(true)
    {
        nextY += dy[dir];
        nextX += dx[dir];

        // 1. 벽 또는 상대방인지 확인
        if(g_area[nextY][nextX] == '#' || (nextY == opponentY && nextX == opponentX))
        {
            nextY -= dy[dir];
            nextX -= dx[dir];
            break;
        }
        // 2. 출구가 있는지 확인
        if(g_area[nextY][nextX] == 'O')
        {
            nextY = 0;
            nextX = 0;
            result = true;
            break;
        }

        // 3. 계속 이동
    }

    next.red_y = isRed ? nextY : start.red_y;
    next.red_x = isRed ? nextX : start.red_x;
    next.blue_y = isRed ? start.blue_y : nextY;
    next.blue_x = isRed ? start.blue_x : nextX;

    return result;
}

// 특정 방향으로 구슬을 기울려서 보내기
int calculateMove(const int dir, const Loc& start, Loc& next)
{
    // 왼쪽으로 굴릴 때, 더 왼쪽에 있는 구슬부터 한 칸씩 옮겨야 함.
    bool isRedFront = whoIsFront(dir, start);

    Loc cur = start;

    // 구슬 이동
    bool redResult, blueResult;
    if(isRedFront)
    {
        redResult = executeMove(dir, true, start, cur);
        blueResult = executeMove(dir, false, cur, next);
    }
    else
    {
        blueResult = executeMove(dir, false, start, cur);
        redResult = executeMove(dir, true, cur, next);
    }

    // 파란공이 떨어지면, 무시
    if(blueResult == true)
        return RETURN;

    // 빨간공만 떨어지면, 정답 반환
    if(redResult == true)
        return ESCAPE;

    // 이미 방문했는지 확인
    if(isVisit(next) == true)
        return VISIT;

    return PASS;
}

int simulate(const int N, const int M, const Loc& start)
{
    queue<Loc> q;
    q.push(start);
    setVisit(start, 0);

    while(q.empty() == false)
    {
        Loc cur = q.front();
        q.pop();

        int cnt = getVisit(cur);
        // 방문 횟수가 10인 경우면 무시
        if(cnt == 10)
            continue;

        // cout << "Cur " << cnt << " : " << cur.red_y << " " << cur.red_x << ", " << cur.blue_y << " " << cur.blue_x << "\n";

        // 방향별로 검사
        for(int dir = 0; dir < 4; dir++)
        {
            Loc next = cur;
            // 특정 방향에 따라 공의 위치 계산
            int move = calculateMove(dir, cur, next);
            // cout << "dir : " << dir << ", " << cnt << " : " << next.red_y << " " << next.red_x << ", " << next.blue_y << " " << next.blue_x << "\n";

            // 빨간공만 출구로 나오는 경우
            if(move == ESCAPE)
                return cnt + 1;

            // 다음 지역이 이미 방문한 곳이라면, 무시
            if(move == VISIT)
                continue;

            // 파란공이 출구로 나오는 경우, 무시
            if(move == RETURN)
                continue;

            setVisit(next, cnt + 1);
            q.push(next);
        }
    }

    return -1;
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
    cout << simulate(N, M, start) << "\n";
}