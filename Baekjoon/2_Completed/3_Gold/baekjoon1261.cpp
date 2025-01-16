// 골드 4 - 1261번 : 알고스팟
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

int MAX_CASE = 10001;
int dyx[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

// 구역 정보
struct Area
{
    bool b_is_wall = false;
    int cases = MAX_CASE;
};

// 순서 정보
struct Sequence
{
    int y = -1;
    int x = -1;
    int cases = -1;

    Sequence() = default;
    Sequence(int y, int x, int cases) : y(y), x(x), cases(cases){} 
};

void search(vector<vector<Area>> &_areas, int _size_y, int _size_x)
{
    // 시작점 입력
    queue<Sequence> que_seq;
    que_seq.push(Sequence(0,0,0));
    _areas[0][0].cases = 0;
     // BFS
    while(!que_seq.empty())
    {
        int cur_y = que_seq.front().y;
        int cur_x = que_seq.front().x;
        int cur_cases = que_seq.front().cases;
        int temp_y, temp_x, temp_cases;

        // 현재 검사하는 지점이 벽을 부순 횟수가 더 크거나 같다면, 무시
        if(_areas[cur_y][cur_x].cases < cur_cases && cur_y != 0 && cur_x != 0)
        {
            que_seq.pop();
            continue;
        }

        // 방향 회전
        for(int dir = 0; dir < 4; dir++)
        {
            temp_y = cur_y + dyx[dir][0];
            temp_x = cur_x + dyx[dir][1];

            // 범위 내 확인
            if(!(temp_y >= 0 && temp_x >= 0 && temp_y < _size_y && temp_x < _size_x))
            {
                continue;
            }
            
            temp_cases = _areas[temp_y][temp_x].b_is_wall ? cur_cases + 1 : cur_cases;
            // 해당 지점으로 이동할 때, 벽을 적게 이동할 수 있는 경우
            if(_areas[temp_y][temp_x].cases > temp_cases)
            {
                // 벽이 있는 여부를 통해 벽 부순 횟수 추가
                _areas[temp_y][temp_x].cases = temp_cases;
                que_seq.push(Sequence(temp_y, temp_x, temp_cases));
            }
        }
        que_seq.pop();
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int n, m;
    cin >> m >> n;

    // 구역 생성
    vector<vector<Area>> areas(n, vector<Area>(m));

    // 구역 기초 정보 입력
    string temp_line;
    for(int i = 0; i < n; i++)
    {
        cin >> temp_line;
        for(int j = 0; j < m; j++)
        {
            areas[i][j].b_is_wall = (temp_line[j] == '1');
        }
    }

    // 시뮬레이션
    search(areas, n, m);

    // 결과 출력
    int result = areas[n-1][m-1].cases;
    if(result == MAX_CASE)
    {
        result = 0;
    }

    cout << result << "\n";

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << areas[i][j].cases << " ";
        }
        cout << "\n";
    }
}