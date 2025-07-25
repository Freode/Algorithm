// 골드 1 - 1400번 : 화물차
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <string>

using namespace std;

// 남북 : 0
// 동서 : 1

const int MAX_VALUE = numeric_limits<int>::max() >> 3;

struct Loc
{
    int y = 0;
    int x = 0;
};

struct Road
{
    Loc dest = {0, 0};
    int cost = 0;

    bool operator<(const Road& other) const
    {
        return cost > other.cost;
    }
};

struct Area
{
    char state = ' ';
    int cost = MAX_VALUE;
};

struct Cross
{
    int start_dir = 0;
    int updown_time = 0;
    int leftright_time = 0;
};

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

vector<vector<Area>> g_areas;
vector<Cross> g_crosses;
Loc g_start;
Loc g_end;

void initAndInputData(const int m, const int n)
{
    g_areas = vector<vector<Area>>(m, vector<Area>(n));

    string line;
    int max_cross_num = -1;
    for(int i = 0; i < m; i++)
    {
        cin >> line;
        for(int j = 0; j < n; j++)
        {
            g_areas[i][j].state = line[j];

            if(line[j] == 'A')
                g_start = {i, j};
            
            else if(line[j] == 'B')
                g_end = {i, j};

            else if(line[j] >= '0' && line[j] <= '9')
                max_cross_num = max(max_cross_num, line[j] - '0');
        }
    }

    if(max_cross_num == -1)
        return;

    // 교차로 정보 입력
    g_crosses = vector<Cross>(max_cross_num + 1);

    char dir;
    int cross_num, ud_time, lr_time;
    for(int i = 0; i <= max_cross_num; i++)
    {
        cin >> cross_num >> dir >> lr_time >> ud_time;

        g_crosses[i] = {dir == '-', ud_time, lr_time};
    }
}

bool isInBoard(const int m, const int n, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < m && x < n;
}

bool canMove(const int y, const int x)
{
    return g_areas[y][x].state != '.';
}

bool isCross(const int y, const int x)
{
    return g_areas[y][x].state >= '0' && g_areas[y][x].state <= '9';
}

// 교차로에 진입 가능한 시간을 반환
int calNextTime(const int y, const int x, const int dir, const int cost)
{
    int num = g_areas[y][x].state - '0';
    int sum = g_crosses[num].updown_time + g_crosses[num].leftright_time;

    int remain_time = cost % sum;
    // g_dir = 0
    // 5 3 , > 
    // 5 3 , ^

    // g_dir = 1
    // 3 5, >
    // 3 5, ^

    // 남북 방향 먼저
    if(g_crosses[num].start_dir == 0)
    {
        // 남북 방향으로 이동할 때
        if(dir == 0)
        {
            // 바로 이동 가능
            if(remain_time >= 1 && remain_time <= g_crosses[num].updown_time)
                return cost;

            // 대기
            return ((cost - 1) / sum + 1) * sum + 1;
        }
        // 동서 방향으로 이동할 때
        if(dir == 1)
        {
            // 바로 이동 가능
            if(remain_time == 0 || remain_time > g_crosses[num].updown_time)
                return cost;

            // 대기
            return ((cost - 1) / sum) * sum + g_crosses[num].updown_time + 1; 
        }
    }

    // 동서 방향 먼저
    else
    {
        // 남북 방향으로 이동할 때
        if(dir == 0)
        {
            // 바로 이동 가능
            if(remain_time == 0 || remain_time > g_crosses[num].leftright_time)
                return cost;

            // 대기
            return ((cost - 1) / sum) * sum + g_crosses[num].leftright_time + 1; 
        }
        // 동서 방향으로 이동할 때
        if(dir == 1)
        {
            // 바로 이동 가능
            if(remain_time >= 1 && remain_time <= g_crosses[num].leftright_time)
                return cost;

            // 대기
            return ((cost - 1) / sum + 1) * sum + 1; 
        }
    }

}

void simulate(const int m, const int n)
{
    priority_queue<Road> pq;
    pq.push({g_start, 0});
    g_areas[g_start.y][g_start.x].cost = 0;

    while(pq.empty() == false)
    {
        Road cur = pq.top();
        pq.pop();

        // 현재 비용이 더 비싼 경우, 무시
        if(cur.cost > g_areas[cur.dest.y][cur.dest.x].cost)
            continue;

        // 이동 가능한 거리인지 검사
        for(int next_dir = 0; next_dir < 4; next_dir++)
        {
            int nextY = cur.dest.y + dy[next_dir];
            int nextX = cur.dest.x + dx[next_dir];

            // 범위 내에 없으면, 무시
            if(isInBoard(m, n, nextY, nextX) == false)
                continue;

            // 이동 불가능한 경우는 무시
            if(canMove(nextY, nextX) == false)
                continue;

            int cost = cur.cost;

            // 다음 지점이 교차로라면?
            if(isCross(nextY, nextX) == true)
                cost = calNextTime(nextY, nextX, next_dir % 2, cur.cost + 1);

            // 다음 지점이 일반도로라면?
            else
                cost++;
    
            // 비용이 더 비싸거나 같은 경우는 무시
            if(g_areas[nextY][nextX].cost <= cost)
                continue;

            g_areas[nextY][nextX].cost = cost;

            // 만약에 목적지에 도착한 경우면, 더 이상 추가하지 않음
            if(g_end.y == nextY && g_end.x == nextX)
                continue;

            pq.push({{nextY, nextX}, cost});
        }
    }
}

void printResult()
{
    int result = g_areas[g_end.y][g_end.x].cost;
    if(result == MAX_VALUE)
        cout << "impossible\n";
    else
        cout << result << "\n";

    // for(int y = 0; y < g_areas.size(); y++)
    // {
    //     for(int x = 0; x < g_areas[0].size(); x++)
    //     {
    //         if(g_areas[y][x].cost == MAX_VALUE)
    //             g_areas[y][x].cost = -1;

    //         cout << g_areas[y][x].cost << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "=========\n";

}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    // 행의 크기 m, 열의 크기 n
    int m, n;

    while(true)
    {
        cin >> m >> n;

        if(m == 0 && n == 0)
            break;

        initAndInputData(m, n);
        simulate(m, n);
        printResult();
    }
}