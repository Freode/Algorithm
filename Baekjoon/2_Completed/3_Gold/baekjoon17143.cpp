// 골드 1 - 17143번 : 낚시왕
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 낚시왕이 한 칸 오른쪽으로 이동 -> 가장 오른쪽 칸으로 이동하면 끝
// 낚시왕이 있는 열에 있는 상어 중에서 땅과 가장 가까운 상어 잡기
// 상어를 잡으면 격자판에서 잡은 상어가 사라짐
// 상어 이동

// 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력 유지 이동
// 상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있는 경우, 크기가 가장 큰 상어가 나머지 상어 모두 잡음

// 낚시왕이 잡은 상어 크기 합 구하기

// 2 <= R,C <= C
// 상어 수 : 0 <= M <= R * C
// 상어 정보 행 r, 열 c, 속력 s, 방향 d, 크기 z
// 같은 크기 상어 x
// 1 : 위, 2 : 아래, 3 : 오른쪽, 4 : 왼쪽

// 100 * 100 * 100

const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, 1, -1};

const int UP = 0;
const int DOWN = 1;
const int RIGHT = 2;
const int LEFT = 3;

struct Shark
{
    int y = 0;
    int x = 0;
    int dir = 0;
    int speed = 0;
    int size = 0;
    bool isAlive = true;
};

vector<vector<int>> g_areas;
vector<Shark> g_sharks;

void initData(const int R, const int C, const int M)
{
    g_sharks = vector<Shark>(M+1);
    g_areas = vector<vector<int>>(R, vector<int>(C, 0));

    for(int i = 1; i <= M; i++)
    {
        Shark& shark = g_sharks[i];
        cin >> shark.y >> shark.x >> shark.speed >> shark.dir >> shark.size;

        shark.y--;
        shark.x--;
        shark.dir--;

        g_areas[shark.y][shark.x] = i;
    }
}

void moveShark(const int R, const int C, const int idx)
{
    Shark& shark = g_sharks[idx];

    // 속도 없으면, 무시
    if(shark.speed == 0)
        return;

    // 죽은 상어면, 무시
    if(shark.isAlive == false)
        return;

    int remain = shark.speed;
    int count = 0;

    // 기존 위치는 모두 초기화
    g_areas[shark.y][shark.x] = 0;

    switch(shark.dir)
    {
    // 위쪽
    case UP:
        remain = shark.speed;
        // 방향 전환
        if(remain > shark.y)
        {
            remain -= shark.y;
            count = remain / (R - 1);
            remain %= (R - 1);

            shark.dir = (count % 2 == 0) ? DOWN : UP;
            shark.y = (shark.dir == UP) ? (R - remain - 1) : remain;
        }
        // 그냥 이동
        else
        {
            shark.y -= remain;
        }
        break;
    // 아래쪽
    case DOWN:
        remain = R - shark.y - 1 - shark.speed;
        // 방향 전환
        if(remain < 0)
        {
            remain = abs(remain);
            count = remain / (R - 1);
            remain %= (R - 1);

            shark.dir = (count % 2 == 0) ? UP : DOWN;
            shark.y = (shark.dir == UP) ? (R - remain - 1) : remain;
        }
        // 그냥 이동
        else
        {
            shark.y = shark.y + shark.speed;
        }
        break;
    // 오른쪽
    case RIGHT:
        remain = C - shark.x - 1 - shark.speed;
        // 방향 전환
        if(remain < 0)
        {
            remain = abs(remain);
            count = remain / (C - 1);
            remain %= (C - 1);

            shark.dir = (count % 2 == 0) ? LEFT : RIGHT;
            shark.x = (shark.dir == LEFT) ? (C - remain - 1) : remain;
        }
        // 그냥 이동
        else
        {
            shark.x = shark.x + shark.speed;
        }
        break;
    // 왼쪽
    case LEFT:
        remain = shark.speed;
        // 방향 전환
        if(remain > shark.x)
        {
            remain -= shark.x;
            count = remain / (C - 1);
            remain %= (C - 1);

            shark.dir = (count % 2 == 0) ? RIGHT : LEFT;
            shark.x = (shark.dir == LEFT) ? (C - remain - 1) : remain;
        }
        // 그냥 이동
        else
        {
            shark.x -= remain;
        }
        break;
    }
}

void duplicateShark(const int idx)
{
    Shark& shark = g_sharks[idx];

    // 죽은 상어는 무시
    if(shark.isAlive == false)
        return;

    // 만약에 현재 위치에 더 큰 상어가 있다면?
    int prev_idx = g_areas[shark.y][shark.x];
    if(shark.size < g_sharks[prev_idx].size)
    {
        shark.isAlive = false;
    }
    // 현재 상어가 더 크다면?
    else
    {
        g_sharks[prev_idx].isAlive = false;

        g_areas[shark.y][shark.x] = idx;
    }
}

void simulate(const int R, const int C, const int M)
{
    int total_size = 0;

    // 낚시왕 이동 횟수
    for(int turn = 0; turn < C; turn++)
    {
        // 2. 가장 가까운 상어 잡기
        for(int y = 0; y < R; y++)
        {
            if(g_areas[y][turn] == 0)
                continue;

            int shark_idx = g_areas[y][turn];

            total_size += g_sharks[shark_idx].size;

            g_sharks[shark_idx].isAlive = false;
            g_areas[y][turn] = 0;

            break;
        }

        // 3. 상어가 이동
        for(int i = 1; i <= M; i++)
        {
            moveShark(R, C, i);
        }

        // 4. 상어 최종 위치 동기화
        for(int i = 1; i <= M; i++)
        {
            duplicateShark(i);
        }

        // cout << "turn : " << turn << "\n";
        // for(int y = 0; y < R; y++)
        // {
        //     for(int x = 0; x < C; x++)
        //     {
        //         cout << g_areas[y][x] << " ";
        //     }
        //     cout << "\n";
        // }
    }

    cout << total_size << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 행 R, 열 C, 상어 마리 수 M
    int R, C, M;
    cin >> R >> C >> M;

    initData(R, C, M);
    simulate(R, C, M);
}