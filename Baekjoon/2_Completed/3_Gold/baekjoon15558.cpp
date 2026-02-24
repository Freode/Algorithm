// 골드 5 - 15558번 : 점프 게임
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 2줄
// 이동 경우
// 1. 같은 줄 앞으로 한 칸 이동 i+1
// 2. 같은 줄 뒤로 한 칸 이동 i-1
// 3. 반대편 줄로 이동 i+k 앞으로 이동

// 1초마다 각 줄의 첫 칸이 증발 a초에 a번째 칸이 사라짐
// 게임 클리어 여부 구하기

// 1 <= N <= 100,000
// 1 <= k <= 100,000

// 걍 BFS 같은데

// [0] -> 왼쪽 줄

struct Move
{
    int line = 0;
    int loc = 0;
    int time = 0;
};

vector<vector<bool>> g_visits;
vector<string> g_datas;

void inputData(const int N)
{
    g_visits = vector<vector<bool>>(2, vector<bool>(N, false));
    g_datas = vector<string>(2, "");

    for(string& data : g_datas)
    {
        cin >> data;
    }
}

bool canGo(int next_line, int next_cur)
{
    return g_datas[next_line][next_cur] == '1' && g_visits[next_line][next_cur] == false;
}

bool simulate(const int N, const int K)
{
    g_visits[0][0] = 1;
    
    queue<Move> q;
    q.push({0, 0, 0});

    while(q.empty() == false)
    {
        Move cur = q.front();
        q.pop();

        // N번칸보다 큰 경우
        if(cur.loc + 1 >= N || cur.loc + K >= N)
            return true;

        int next_line, next_cur, next_time;
        // 1번 경우 - 앞으로 한 칸
        next_line = cur.line;
        next_cur = cur.loc + 1;
        next_time = cur.time + 1;
        if(canGo(next_line, next_cur))
        {
            q.push({next_line, next_cur, next_time});
            g_visits[next_line][next_cur] = true;
        }

        // 2번 경우 - 뒤로 한 칸
        next_line = cur.line;
        next_cur = cur.loc - 1;
        next_time = cur.time + 1;
        if(next_cur > cur.time && canGo(next_line, next_cur))
        {
            q.push({next_line, next_cur, next_time});
            g_visits[next_line][next_cur] = true;
        }

        // 3번 경우 - 옆라인으로 점프
        next_line = !cur.line;
        next_cur = cur.loc + K;
        next_time = cur.time + 1;
        if(canGo(next_line, next_cur))
        {
            q.push({next_line, next_cur, next_time});
            g_visits[next_line][next_cur] = true;
        }
    }
    
    return false;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 칸 개수 N, 점프 시 이동할 k칸
    int N, K;
    cin >> N >> K;

    inputData(N);
    cout << simulate(N, K) << "\n";
}