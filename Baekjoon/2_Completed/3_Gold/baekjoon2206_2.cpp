// 골드 3 - 2206번 : 벽 부수고 이동하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 검사할 위치에 대한 정보 구조체
struct sequence
{
    int y = -1;
    int x = -1;
    int broken = -1;

    sequence() = default;
    sequence(int y, int x, int broken) : y(y), x(x), broken(broken) {}
};

void search(vector<vector<vector<int>>> &_area, vector<vector<bool>> &_map)
{
    int y_size = _area.size();
    int x_size = _area[0].size();

    // 초기점 추가
    queue<sequence> que_seq;
    que_seq.push(sequence(0, 0, 0));
    _area[0][0][0] = 1;

    while(!que_seq.empty())
    {
        sequence current_seq = que_seq.front();

        // 4방향 조사
        for(int dir = 0; dir < 4; dir++)
        {
            int temp_y = current_seq.y;
            int temp_x = current_seq.x;
            int cur_broken = current_seq.broken;

            // 위쪽
            if(dir == 0)
            {
                temp_y--;
            }
            // 오른쪽
            else if(dir == 1)
            {
                temp_x++;
            }
            // 아래쪽
            else if(dir == 2)
            {
                temp_y++;
            }
            // 왼쪽
            else
            {
                temp_x--;
            }

            // 범위 안에서만
            if(!(temp_y >= 0 && temp_x >= 0 && temp_y < y_size && temp_x < x_size))
            {
                continue;
            }

            // 앞에 벽이 있는데, 부술 경우
            if(_map[temp_y][temp_x] == true && cur_broken == 0)
            {
                _area[temp_y][temp_x][1] = _area[current_seq.y][current_seq.x][0] + 1;
                que_seq.push(sequence(temp_y, temp_x, 1));
            }

            // 벽을 부쉈든 안 부쉈든, 진행가능한 경우에는 최단 거리일 경우에만 추가
            if(_map[temp_y][temp_x] == false)
            {
                if(_area[temp_y][temp_x][cur_broken] > _area[current_seq.y][current_seq.x][cur_broken] + 1)
                {
                    _area[temp_y][temp_x][cur_broken] = _area[current_seq.y][current_seq.x][cur_broken] + 1;
                    que_seq.push(sequence(temp_y, temp_x, cur_broken));
                }
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

    // 입력
    int n, m;
    cin >> n >> m;

    // 맵 생성
    vector<vector<bool>> map(n, vector<bool>(m));
    string line;

    // 맵 입력
    for(int i = 0; i < n; i++)
    {
        cin >> line;

        for(int j = 0; j < m; j++)
        {
            map[i][j] = line[j] == '1' ? true : false;
        }
    }

    // 할당
    vector<vector<vector<int>>> area(n, vector<vector<int>>(m, vector<int>(2, 1000001)));
    // 시작
    search(area, map);

    // 결과
    int result = min(area[n - 1][m - 1][0], area[n - 1][m - 1][1]);
    if(result == 1000001)
    {
        result = -1;
    }
    cout << result << "\n";
}