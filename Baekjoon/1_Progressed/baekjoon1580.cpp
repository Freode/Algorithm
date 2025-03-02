// 골드 3 - 1580번 : 위치 바꾸기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 지역
struct Area
{
    bool b_visit = false;
    int cost = -1;
};

// 위치 구조체
struct Loc
{
    int y = 0;
    int x = 0;

    Loc() = default;
    Loc(int y, int x) : y(y), x(x) {}
};

// 우선 순위 큐에 넣을 정보 구조체
struct Pinfo
{
    int y = 0;
    int x = 0;
    int cost = -1;

    Pinfo() = default;
    Pinfo(int cost, Loc loc) : cost(cost), y(loc.y), x(loc.x) {}
    Pinfo(int cost, int y, int x) : cost(cost), y(y), x(x) {}

    // 우선순위 큐에 넣기 위해 오버로딩
    bool operator<(const Pinfo& other) const
    {
        // cost 기준 오름차순 적용
        return cost > other.cost;
    }
};

vector<vector<char>> g_map;

const int dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

// 맵 입력
void InputMap(const int N, const int M, Loc& A, Loc& B)
{
    g_map = vector<vector<char>>(N, vector<char>(M));
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
                A.y = i;
                A.x = j;
            }
            else if(input[j] == 'B')
            {
                B.y = i;
                B.x = j;
            }
        }
    }
}

// 경계 안에 있는지 확인
bool IsInBoard(int next_y, int next_x)
{
    return next_y >= 0 && next_x >= 0 && next_y < g_map.size() && next_x < g_map[0].size();
}

// BFS 시뮬레이션
int Simulate(Loc in_init_loc, Loc in_target ,vector<vector<Area>> &base, vector<vector<Area>> &opponent)
{

    priority_queue<Pinfo> que;
    que.push(Pinfo(0, in_init_loc));
    base[in_init_loc.y][in_init_loc.x].b_visit = true;
    base[in_init_loc.y][in_init_loc.x].cost = 0;
    
    while(que.empty() == false)
    {
        // 현재 검사 지점
        Pinfo cur_loc = que.top();
        que.pop();
        cout << "cost : " << cur_loc.cost << ", y : " << cur_loc.y << ", x : " << cur_loc.x << "\n";

        // 목표 지점일 경우
        if(cur_loc.y == in_target.y && cur_loc.x == in_target.x) return base[cur_loc.y][cur_loc.x].cost;

        // 방향 별로 검사
        int next_y, next_x;
        for(int i = 0; i < 8; i++)
        {
            next_y = cur_loc.y + dy[i];
            next_x = cur_loc.x + dx[i];

            // 경계 밖이면, 무시
            if(IsInBoard(next_y, next_x) == false) continue;

            // 이동 지점이 벽이면, 무시
            if(g_map[next_y][next_x] == 'X') continue;

            // 이미 방문했으면, 무시
            if(base[next_y][next_x].b_visit) continue;

            // 이동 지점에 상대방이 있으면, 무시
            if(opponent[next_y][next_x].cost == base[cur_loc.y][cur_loc.x].cost) continue;

            // 비용 계산
            base[next_y][next_x].b_visit = true;
            base[next_y][next_x].cost = base[cur_loc.y][cur_loc.x].cost + 1;
            que.push(Pinfo(base[next_y][next_x].cost, next_y, next_x));
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

    Loc A, B;
    InputMap(N, M, A, B);

    vector<vector<Area>> a_area = vector<vector<Area>>(N, vector<Area>(M));
    vector<vector<Area>> b_area = vector<vector<Area>>(N, vector<Area>(M));

    cout << "A\n";
    int result_a = Simulate(A, B, a_area, b_area);
    cout << "B\n";
    int result_b = Simulate(B, A, b_area, a_area);

    cout << b_area[A.y][A.x].cost << "\n";
    cout << a_area[B.y][B.x].cost << "\n";

    int result = (result_a == -1 || result_b == -1) ? -1 : max(result_a, result_b);

    cout << result << "\n";
}