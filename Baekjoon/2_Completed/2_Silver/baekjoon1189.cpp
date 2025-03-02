// 실버 1 - 1189번 : 컴백홈
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};

vector<string> g_maps;
vector<vector<bool>> g_b_visits;

// 경계 안에 있는지 확인
bool IsInBoard(const int in_y, const int in_x)
{
    return in_y >= 0 && in_x >= 0 && in_y < g_maps.size() && in_x < g_maps[0].size();
}

int Search(const int in_y, const int in_x, const int in_cost, const int& in_target)
{
    int next_y, next_x;
    int result = 0;

    // 목표 지점 도달
    if(in_y == 0 && in_x == g_maps[0].size()-1 && in_cost == in_target) return 1;
    

    // 방향별로 이동
    for(int i = 0; i < 4; i++)
    {
        next_y = in_y + dy[i];
        next_x = in_x + dx[i];

        // 경계 밖이면, 무시
        if(IsInBoard(next_y, next_x) == false) continue;

        // 방문했다면, 무시
        if(g_b_visits[next_y][next_x]) continue;

        // 벽이라면 무시
        if(g_maps[next_y][next_x] == 'T') continue;

        // 이동 거리가 목표 거리보다 긴 경우, 무시
        int next_cost = in_cost + 1;
        if(next_cost > in_target) continue;

        g_b_visits[next_y][next_x] = true;
        result += Search(next_y, next_x, next_cost, in_target);
        g_b_visits[next_y][next_x] = false;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 세로 R, 가로 C, 거리 K
    int R, C, K;
    cin >> R >> C >> K;

    // 지도 입력
    g_maps = vector<string>(R);
    g_b_visits = vector<vector<bool>>(R, vector<bool>(C, false));
    for(string& line : g_maps)
    {
        cin >> line;
    }

    g_b_visits[R-1][0] = true;
    int result = Search(R-1, 0, 1, K);

    cout << result << "\n";
}