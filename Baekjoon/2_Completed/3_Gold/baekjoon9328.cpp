// 골드 1 - 9328번 : 열쇠
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

const int MAX_KEY_COUNT = 26;

struct Loc
{
    int y = 0;
    int x = 0;
};

struct Key
{
    vector<Loc> locs;
    bool b_find = false;

    Key()
    {
        locs.reserve(10);
    }
};

struct Area
{
    Loc loc;
    bool b_visit = false;
    char state = ' ';
};

int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

vector<vector<Area>> g_areas;
vector<Key> g_keys;
queue<Loc> g_q;

// 구역 정보 초기화
void resetArea(const int h, const int w)
{
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            g_areas[i][j].b_visit = false;
        }
    }
}

// 키 정보 초기화
void resetKey()
{
    for(int i = 0; i < MAX_KEY_COUNT; i++)
    {
        g_keys[i].b_find = false;
        g_keys[i].locs.clear();
    }
}

// 구역 정보 입력
void inputArea(const int h, const int w)
{
    string input;
    for(int i = 0; i < h; i++)
    {
        cin >> input;

        for(int j = 0; j < w; j++)
        {
            g_areas[i][j].state = input[j];
            
            // 밖에 있는 입구부터 추가
            if(input[j] != '*' && (i == 0 || j == 0 || i == h-1 || j == w-1))
            {
                // 1. 문인 경우는 일단 대기
                if(input[j] >= 'A' && input[j] <= 'Z')
                {
                    g_keys[input[j] - 'A'].locs.push_back({i, j});
                    continue;
                }

                // 2. 열쇠인 경우에는 열쇠 소유를 하고 있다고 처리
                if(input[j] >= 'a' && input[j] <= 'z')
                    g_keys[input[j] - 'a'].b_find = true; 
                
                // 3. 문서, 바닥인 경우에는 바로 추가 가능
                g_q.push({i, j});
                g_areas[i][j].b_visit = true;
            }
        }
    }
}

// 미리 소지하고 있는 키 정보 입력
void inputKey()
{
    string input;
    cin >> input;

    if(input == "0")
        return;

    for(const char& key : input)
    {
        g_keys[key - 'a'].b_find = true;
    }
}

// 경계 안에 있는지 확인
bool isInBoard(const int h, const int w, const int y, const int x)
{
    return x >= 0 && y >= 0 && y < h && x < w;
}

// 시뮬레이션 시작
int simulate(const int h, const int w)
{
    // 키를 미리 소지한 경우면서, 대기하고 있는 위치를 먼저 처리
    for(Key& key : g_keys)
    {
        if(key.b_find)
        {
            for(const Loc& loc : key.locs)
                g_q.push({loc.y, loc.x});

            key.locs.clear();
        }
    }

    int count = 0;

    while(g_q.empty() == false)
    {
        Loc cur = g_q.front();
        g_q.pop();

        // 현재 위치에 보물이 있는 경우(가장자리)
        if(g_areas[cur.y][cur.x].state == '$')
        {
            g_areas[cur.y][cur.x].state = '.';
            count++;
        }

        // 다음 위치에 대한 검사
        for(int dir = 0; dir < 4; dir++)
        {
            int nextY = cur.y + dy[dir];
            int nextX = cur.x + dx[dir];

            // 1. 범위 안에 있는지 확인
            if(isInBoard(h, w, nextY, nextX) == false)
                continue;

            Area& next = g_areas[nextY][nextX];

            // 2. 벽이 아닌지 확인
            if(next.state == '*')
                continue;

            // 3. 이미 방문했다면, 무시
            if(next.b_visit)
                continue;

            // 방문했다고 설정
            next.b_visit = true;

            // 4. 문이 있다면, 열쇠가 있는지 검사
            if(next.state >= 'A' && next.state <= 'Z')
            {
                // 해당 문을 열 수 있는 열쇠가 있다면, 이동
                if(g_keys[next.state - 'A'].b_find)
                    g_q.push({nextY, nextX});

                // 해당 문을 열 수 있는 열쇠가 없다면, 대기
                else
                    g_keys[next.state - 'A'].locs.push_back({nextY, nextX});
            
                continue;
            }

            // 5. 열쇠라면, 이동하고 현재 대기하고 있던 문들도 모두 열기
            if(next.state >= 'a' && next.state <= 'z')
            {
                g_q.push({nextY, nextX});

                // 이미 발견한 열쇠는 단순히 이동
                if(g_keys[next.state - 'a'].b_find)
                    continue;
                
                // 새롭게 발견한 열쇠는 대기하고 있던 문들도 모두 개방
                else
                {
                    g_keys[next.state - 'a'].b_find = true;

                    for(const Loc& loc : g_keys[next.state - 'a'].locs)
                    {
                        g_q.push({loc.y, loc.x});
                    }

                    g_keys[next.state - 'a'].locs.clear();
                    continue;
                }
            }

            // 6. 보물이라면, 숫자 증가
            if(next.state == '$')
            {
                next.state = '.';
                g_q.push({nextY, nextX});
                count++;
                continue;
            }

            // 7. 그냥 바닥인 경우 이동
            if(next.state == '.')
            {
                g_q.push({nextY, nextX});
            }
        }
    }

    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 개수 T
    int T;
    cin >> T;

    g_areas = vector<vector<Area>>(100, vector<Area>(100));
    g_keys = vector<Key>(MAX_KEY_COUNT);

    int h, w;
    for(int i = 0; i < T; i++)
    {
        // 높이 h, 너비 w
        cin >> h >> w;

        inputArea(h, w);
        inputKey();

        cout << simulate(h, w) << "\n";

        resetArea(h, w);
        resetKey();
    }
}