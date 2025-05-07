// 골드 5 - 1245번 : Guarding the Farm
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 가드가 얼마나 필요한지
// 정수형 행렬
// N : 행(2~100)
// M : 열(2~70)
// 각 요소 언덕 높이 (0~10'000)

// hilltop  
// 같은 고도 및 지금보다 낮은 고도를 모두 커버 가능
// 인접하다 -> x좌표와 y좌표의 차이가 각각 1 이하 -> 8방향
// 시작 지점 -> 높은 자리부터

struct Area
{
    int num = 0;
    bool b_visit = false;
};

struct Loc
{
    int y = 0;
    int x = 0;
    int num = 0;

    // 우선순위 큐에서 num 기준 내림차순 적용
    bool operator<(const Loc& other) const
    {
        return num < other.num;
    }
};

vector<vector<Area>> g_matrix;
priority_queue<Loc> g_pq;

int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

void inputMatrix(const int N, const int M)
{
    g_matrix = vector<vector<Area>>(N, vector<Area>(M));

    int input;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> input;
            g_matrix[i][j].num = input;
            g_pq.push({i, j, input});
        }
    }
}

bool isInBoard(const int N, const int M, const int i, const int j)
{
    return i >= 0 && j >= 0 && i < N && j < M;
}

bool search(const int N, const int M, const int i, const int j)
{
    if(g_matrix[i][j].b_visit)
        return false;

    queue<Loc> q;
    q.push({i, j, 0});
    g_matrix[i][j].b_visit = true;

    while(q.empty() == false)
    {
        Loc cur = q.front();
        q.pop();
        
        int cur_height = g_matrix[cur.y][cur.x].num;
        for(int dir = 0; dir < 8; dir++)
        {
            int nextY = cur.y + dy[dir];
            int nextX = cur.x + dx[dir];

            if(isInBoard(N, M, nextY, nextX) == false)
                continue;

            if(g_matrix[nextY][nextX].b_visit)
                continue;

            if(cur_height < g_matrix[nextY][nextX].num)
                continue;

            g_matrix[nextY][nextX].b_visit = true;
            q.push({nextY, nextX, 0});
        }
    }

    return true;
}

int simulate(const int N, const int M)
{
    int result = 0;

    while(g_pq.empty() == false)
    {
        Loc cur = g_pq.top();
        g_pq.pop();

        if(search(N, M, cur.y, cur.x))
            result++;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 행 N, 열 M
    int N, M;
    cin >> N >> M;

    inputMatrix(N, M);
    int result = simulate(N, M);

    cout << result << "\n";
}