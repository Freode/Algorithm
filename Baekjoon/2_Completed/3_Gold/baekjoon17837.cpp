// 골드 2 - 17837번 : 새로운 게임 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// N*N 체스판
// 말 개수 K개
// 말 서로 겹치기 가능
// 체스판 - 흰색, 빨간색, 파란색
// 말 번호 - 1 ~ K번
// 이동 방향 - 4방향

// 턴 1번 - 1 ~ K번 말까지 모두 순서대로 이동
// 말이 4개 이상 쌓이면, 그 즉시 게임 종료
// 한 말이 이동할 때, 위에 올려져 있는 말도 함께 이동

// A번 말 이동
// 흰색 : 그 칸으로 이동 - 기존에 있는 말들의 가장 위에 A번 말을 둠
// 빨간색 : 그 칸으로 이동 후, A번 말과 그 위에 있는 말의 쌓여있는 순서가 바뀜.
// 파란색 : 방향을 반대로 바꿔서 한 칸 이동 - 이동하려는 칸이 파란색인 경우에는 이동하지 않고, 가만히 있음.
// 체스판을 벗어나는 경우에는 파란색과 같은 경우 -> 반대로 바꿔서 한 칸 이동하라는 소리

// 게임이 종료되는 턴을 구해라
// 1 : 오른쪽
// 2 : 왼쪽
// 3 : 위쪽
// 4 : 아래쪽

const int WHITE = 0;
const int RED = 1;
const int BLUE = 2;

const int dy[] = {0, 0, -1, 1};
const int dx[] = {1, -1, 0, 0};

// 말
struct Movable
{
    int y = -1;
    int x = -1;
    int dirt = -1;
    int height = -1;
};

// 구역
struct Area
{
    int color = -1;
    vector<int> objects;

    Area()
    {
        objects.reserve(10);
    }
};

vector<Movable> g_movables;
vector<vector<Area>> g_areas;

void initData(const int N, const int K)
{
    // 구역 초기화 및 입력
    g_areas = vector<vector<Area>>(N, vector<Area>(N));
    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            cin >> g_areas[y][x].color;
        }
    }

    // 말 정보 초기화 및 입력
    g_movables = vector<Movable>(K);
    for(int i = 0; i < K; i++)
    {
        int y, x, dirt;
        cin >> y >> x >> dirt;

        // 조정
        y--;
        x--;
        dirt--;

        g_movables[i] = {y, x, dirt, (int)g_areas[y][x].objects.size()};
        g_areas[y][x].objects.push_back(i);
    }
}

bool canGo(const int N, const int y, const int x)
{
    if(y >= 0 && x >= 0 && y < N && x < N && g_areas[y][x].color != BLUE)
        return true;

    return false;
}

void realMove(const int idx, const int y, const int x, const int next_y, const int next_x)
{
    Movable& cur_movable = g_movables[g_areas[y][x].objects[idx]];

    cur_movable.y = next_y;
    cur_movable.x = next_x;
    cur_movable.height = (int)g_areas[next_y][next_x].objects.size();

    g_areas[next_y][next_x].objects.push_back(g_areas[y][x].objects[idx]);
}

bool moveMovable(const int N, const int idx)
{
    Movable& movable = g_movables[idx];

    int next_y = movable.y + dy[movable.dirt];
    int next_x = movable.x + dx[movable.dirt];

    // 방향 전환
    if(canGo(N, next_y, next_x) == false)
    {
        movable.dirt++;
        if(movable.dirt % 2 == 0)
            movable.dirt-=2;

        next_y = movable.y + dy[movable.dirt];
        next_x = movable.x + dx[movable.dirt];
    }

    // 해당 방향으로 유효한지 확인
    if(canGo(N, next_y, next_x) == false)
        return false;

    int prev_y = movable.y;
    int prev_x = movable.x;
    int prev_height = movable.height;
    switch (g_areas[next_y][next_x].color)
    {
    // 하얀색
    case WHITE:
        for(int i = prev_height; i < (int)g_areas[prev_y][prev_x].objects.size(); i++)
        {
            realMove(i, prev_y, prev_x, next_y, next_x);
        }
        g_areas[prev_y][prev_x].objects.resize(prev_height);
        break;
    
    // 빨간색
    case RED:
        for(int i = (int)g_areas[prev_y][prev_x].objects.size() - 1; i >= prev_height; i--)
        {
            realMove(i, prev_y, prev_x, next_y, next_x);
        }
        g_areas[prev_y][prev_x].objects.resize(prev_height);
        break;

    // 파란색 - 이동하지 않음
    case BLUE:
        break;
    }

    return (int)g_areas[next_y][next_x].objects.size() >= 4;
}

void simulate(const int N, const int K)
{
    // 턴
    for(int turn = 1; turn <= 1000; turn++)
    {
        // 말 이동
        for(int idx = 0; idx < K; idx++)
        {
            // 게임 종료
            if(moveMovable(N, idx) == true)
            {
                cout << turn << "\n";
                return;
            }
        }
    }

    cout << "-1\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 크기 N, 말 개수 K
    int N, K;
    cin >> N >> K;

    initData(N, K);
    simulate(N, K);
}