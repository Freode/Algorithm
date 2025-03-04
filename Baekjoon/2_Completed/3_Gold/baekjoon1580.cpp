// 골드 3 - 1580번 : 위치 바꾸기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;


// 위치 구조체
struct Loc
{
    int a_y = 0;
    int a_x = 0;
    int b_y = 0;
    int b_x = 0;

    Loc() = default;
    Loc(int a_y, int a_x, int b_y, int b_x) : a_y(a_y), a_x(a_x), b_y(b_y), b_x(b_x) {}
};

vector<vector<char>> g_map;
vector<vector<vector<vector<int>>>> g_cost;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1, 0};
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1, 0};

// 맵 입력
void InputMap(const int N, const int M, Loc& loc)
{
    g_map = vector<vector<char>>(N, vector<char>(M));
    g_cost = vector<vector<vector<vector<int>>>>(N, vector<vector<vector<int>>>(M, vector<vector<int>>(N, vector<int>(M, -1))));
    string input;

    for(int i = 0; i < N; i++)
    {
        cin >> input;
        
        for(int j = 0; j < M; j++)
        {
            g_map[i][j] = input[j];
            // A와 B 위치 기록
            if(input[j] == 'A')
            {
                loc.a_y = i;
                loc.a_x = j;
            }
            else if(input[j] == 'B')
            {
                loc.b_y = i;
                loc.b_x = j;
            }
        }
    }
}

// 경계 안에 있는지 확인
bool IsInBoard(int a_y, int a_x, int b_y, int b_x)
{
    return a_y >= 0 && a_x >= 0 && b_y >= 0 && b_x >= 0 && a_y < g_cost.size() && a_x < g_cost[0].size() && b_y < g_cost.size() && b_x < g_cost[0].size();
}

// 목적지에 도달했는지 확인
bool IsCompleted(const Loc& cur, const Loc& dest)
{
    // 단, A와 B 플레이어 위치가 겹치면, 안됨
    return cur.a_y == dest.b_y && cur.a_x == dest.b_x && cur.b_y == dest.a_y && cur.b_x == dest.a_x && (cur.a_y != cur.b_y || cur.a_x != cur.b_x );
}

// BFS 시뮬레이션
void Simulate(const Loc in_loc)
{
    queue<Loc> que;
    que.push(Loc(in_loc.a_y, in_loc.a_x, in_loc.b_y, in_loc.b_x));
    g_cost[in_loc.a_y][in_loc.a_x][in_loc.b_y][in_loc.b_x] = 0;
    
    while(que.empty() == false)
    {
        // 현재 검사 지점
        Loc cur_loc = que.front();
        que.pop();

        // 목표에 도달인데, A와 B가 서로 겹치면 안됨
        if(IsCompleted(cur_loc, in_loc)) return;

        // 방향 별로 검사
        int a_y, a_x, b_y, b_x, cost;

        // 양 플레이어의 경우를 모두 검사
        // A가 움직일 수 있는 경우의 수 * B가 움직일 수 있는 경우의 수
        // 9 * 9 = 81

        cost = g_cost[cur_loc.a_y][cur_loc.a_x][cur_loc.b_y][cur_loc.b_x];

        // 플레이어 A - 9방향 이동
        for(int a_dir = 0; a_dir < 9; a_dir++)
        {
            // 플레이어 B - 9방향 이동
            for(int b_dir = 0; b_dir < 9; b_dir++)
            {
                a_y = cur_loc.a_y + dy[a_dir];
                a_x = cur_loc.a_x + dx[a_dir];

                b_y = cur_loc.b_y + dy[b_dir];
                b_x = cur_loc.b_x + dx[b_dir];

                // 경계 밖이면, 무시
                if(IsInBoard(a_y, a_x, b_y, b_x) == false) continue;

                // 이동 지점이 벽이면, 무시
                if(g_map[a_y][a_x] == 'X' || g_map[b_y][b_x] == 'X') continue;

                // 서로 교차했으면, 무시
                if(a_y == cur_loc.b_y && a_x == cur_loc.b_x && b_y == cur_loc.a_y && b_x == cur_loc.a_x) continue;

                // 서로 같은 위치에 있으면, 무시
                if(a_y == b_y && a_x == b_x) continue;

                // 이미 방문했으면, 무시
                if(g_cost[a_y][a_x][b_y][b_x] != -1) continue;

                g_cost[a_y][a_x][b_y][b_x] = cost + 1;
                que.push(Loc(a_y, a_x, b_y, b_x));
            }
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

    Loc loc;
    InputMap(N, M, loc);

    Simulate(loc);

    cout << g_cost[loc.b_y][loc.b_x][loc.a_y][loc.a_x] << "\n";
}