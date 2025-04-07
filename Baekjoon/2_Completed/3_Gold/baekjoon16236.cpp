// 골드 3 - 16236번 : 아기 상어
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 같은 거리에 다른 크기의 물고기가 존재 -> 같은 크기의 물고기부터 섭취

// N*N 크기 (최댓값 20)
// 물고기 M마리

// 입력
// 0 : 빈칸, 1~6 : 물고기, 9 : 자기 자신 위치
// 초기 : 자기 자신 크기 2

// 먹을 수 있는 물고기가 존재할 때까지 진행

// 작은 크기의 물고기를 크기만큼의 수량을 먹으면, 크기 1씩 증가
// 1초씩 상하좌우 하나 이동 가능

// 출력 : 물고기를 잡아먹을 수 있는 시간

// 거리 : 칸의 개수 최솟값
// 1마리 -> 해당 물고기로 이동
// 여러 마리 -> 거리가 가장 가까운 몰고기로 이동
// 거리가 같은 물고기 여러 마리 -> 가장 위 -> 그 중에서 가장 왼쪽 


// 더 큰 크기의 물고기여도 해당 칸으로 이동 가능(겹치기 가능)
// 좌표 차이로 바로 이동 -> 이동 시간 더하기

const int MAX_VALUE = numeric_limits<int>::max();

struct Area
{
    int fish = 0;
    int visit = MAX_VALUE;
};

struct Loc
{
    int y;
    int x;
};

// 순서 - 상좌우하
int dy[] = {-1, 0, 0, 1};
int dx[] = {0, -1, 1, 0};

Loc g_baby_loc;
vector<vector<Area>> g_areas;
int g_size = 2;
int g_count = 0;

// 물고기 정보 입력
void input(const int N)
{
    g_areas = vector<vector<Area>>(N, vector<Area>(N));

    int fish;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_areas[i][j].fish;
            // 아기 상어 위치
            if(g_areas[i][j].fish == 9)
            {
                g_baby_loc = {i, j};
                g_areas[i][j].fish = 0;
            }
        }
    }
}

void print(int result)
{
    cout << "===\n";
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas.size(); j++)
        {
            if(g_baby_loc.y == i && g_baby_loc.x == j)
                cout << "■ ";
            else
                cout << g_areas[i][j].fish << " ";
        }
        cout << "\n";
    }
    cout << "size : " << g_size << ", count : " << g_count << "\n";
    cout << "time : " << result << "\n";
}

// 이동 비용 초기화
void resetCost()
{
    for(int i = 0; i < g_areas.size(); i++)
    {
        for(int j = 0; j < g_areas.size(); j++)
        {
            g_areas[i][j].visit = MAX_VALUE;
        }
    }
}

// 범위 안인지 확인
bool isInBoard(const Loc& loc)
{
    return loc.y >= 0 && loc.x >= 0 && loc.y < g_areas.size() && loc.x < g_areas.size();
}

// 가장 가까운 물고기 탐색
int search()
{
    resetCost();

    queue<Loc> q;
    q.push(g_baby_loc);
    g_areas[g_baby_loc.y][g_baby_loc.x].visit = 0;

    // 거리가 같은 물고기 모음
    vector<Loc> fishes;
    int dist = 0;

    // BFS
    while(q.empty() == false)
    {
        Loc loc = q.front();
        q.pop();

        // 방향별로 검사
        for(int dir = 0; dir < 4; dir++)
        {
            int nextY = loc.y + dy[dir];
            int nextX = loc.x + dx[dir];

            // 범위 안이 아니면, 무시
            if(isInBoard({nextY, nextX}) == false)
                continue;

            // 이미 방문했으면, 무시
            if(g_areas[nextY][nextX].visit != MAX_VALUE)
                continue;

            // 자신보다 큰 물고기는 못 지나감
            if(g_areas[nextY][nextX].fish > g_size)
                continue;

            // 이동 기록
            g_areas[nextY][nextX].visit = g_areas[loc.y][loc.x].visit + 1;

            // 물고기가 존재하는데 크기보다 작은 경우, 일단 존재한다고 판단
            if(g_areas[nextY][nextX].fish != 0 && g_areas[nextY][nextX].fish < g_size)
            {
                if(dist == 0 || dist == g_areas[nextY][nextX].visit)
                    fishes.push_back({nextY, nextX});
                if(dist == 0)
                    dist = g_areas[nextY][nextX].visit;
            }

            // 가장 가까운 물고기가 나온 경우에는 더 이상 이동 경우 추가 X
            if(dist == 0 || dist <= g_areas[nextY][nextX].visit)
            {
                q.push({nextY, nextX});
            }
        }
    }

    if(fishes.size() > 0)
    {
        // 가장 위쪽, 가장 왼쪽에 있는 물고기부터 섭취
        sort(fishes.begin(), fishes.end(), [](const Loc& a, const Loc& b)
        {
            // 가장 위쪽 우선
            if(a.y != b.y)
                return a.y < b.y;
            // 가장 왼쪽 우선
            return a.x < b.x;
        });
        // 물고기 섭취 후 이동
        g_baby_loc = fishes[0];
        g_areas[g_baby_loc.y][g_baby_loc.x].fish = 0;

        // 경험치 증가
        g_count++;
        // 레벨업
        if(g_count == g_size)
        {
            g_count = 0;
            g_size++;
        }

        return dist;
    }
    // 물고기가 존재하지 않음
    else
        return 0;
}

// 실험 시작
int simulate()
{
    int result = 0;

    int turn = 0;
    while(true)
    {
        turn = search();
        // 더 이상 물고기를 찾지 못할 때까지 이동
        if(turn == 0)
            break;

        // 물고기를 찾으러 이동 가능
        result += turn;
        // print(result);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 맵 크기 N
    int N;
    cin >> N;

    // 물고기 정보 입력
    input(N);

    // 시뮬레이션
    int result = simulate();

    cout << result << "\n";
}