// 골드 3 - 2146번 : 다리 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 1 <= N <= 100
// 0 : 바다, 1 : 육지
// 1. 대륙별로 번호 매기기
// 2. 대륙의 땅별로 다른 대륙의 땅과 거리 계산
// 3. 최솟값 구하기

struct Loc
{
    int y = 0;
    int x = 0;
};

struct Group
{
    vector<Loc> locs;

    Group()
    {
        locs.reserve(50);
    }
};

const int dy[] = {0, 0, 1, -1};
const int dx[] = {1, -1, 0, 0};

vector<vector<int>> g_areas;
vector<Group> g_groups;

void initData(const int N)
{
    g_areas = vector<vector<int>>(N, vector<int>(N));
    g_groups.reserve(50);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_areas[i][j];

            if(g_areas[i][j] == 1)
                g_areas[i][j] = -1;
        }
    }
}

bool isInBoard(const int N, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < N && x < N;
}

void findGroup(const int N)
{
    queue<Loc> q;
    int group_idx = 0;

    for(int y = 0; y < N; y++)
    {
        for(int x = 0; x < N; x++)
        {
            if(g_areas[y][x] != -1)
                continue;

            g_groups.push_back(Group());
            g_groups[group_idx].locs.push_back({y, x});

            ++group_idx;
            q.push({y, x});
            g_areas[y][x] = group_idx;

            while(q.empty() == false)
            {
                Loc cur = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++)
                {
                    int next_y = cur.y + dy[dir];
                    int next_x = cur.x + dx[dir];

                    if(isInBoard(N, next_y, next_x) == false)
                        continue;

                    if(g_areas[next_y][next_x] != -1)
                        continue;

                    g_areas[next_y][next_x] = group_idx;
                    g_groups[group_idx - 1].locs.push_back({next_y, next_x});
                    q.push({next_y, next_x});
                }
            }
        }
    }
}

int simulate(const int N)
{
    int result = 100'000;

    for(int idx = 0; idx < (int)g_groups.size() - 1; idx++)
    {
        for(int other = idx + 1; other < (int)g_groups.size(); other++)
        {
            for(const Loc& base : g_groups[idx].locs)
            {
                for(const Loc& check : g_groups[other].locs)
                {
                    result = min(result, abs(base.y - check.y) + abs(base.x - check.x) - 1);
                }
            }
        }
    }
    
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 지도 크기 N
    int N;
    cin >> N;

    initData(N);
    findGroup(N);
    cout << simulate(N) << "\n";
}