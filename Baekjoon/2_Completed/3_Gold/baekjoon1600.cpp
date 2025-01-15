// 골드 3 - 1600번 : 말이
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

// 이동 거리 미리 지정
int d_jump[8][2] = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}};
int d_normal[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

// 검사 지점 정보
struct sequence
{
    int y = -1;
    int x = -1;
    int jump = -1;

    sequence() = default;
    sequence(int y, int x, int jump) : y(y), x(x), jump(jump) {}
};

// 범위 안인지 확인
bool check_inner(vector<vector<int>>& _map, int _y, int _x)
{
    int y_size = _map.size();
    int x_size = _map[0].size();

    return _y >= 0 && _x >= 0 && _y < y_size && _x < x_size; 
}

void search(vector<vector<vector<int>>>& _area, vector<vector<int>>& _map)
{

    // 크기 확인
    int max_jump = _area[0][0].size() - 1;

    int temp_y, temp_x, cur_jump;
    queue<sequence> que_seq;
    // 시작점
    que_seq.push(sequence(0, 0, 0));
    _area[0][0][0] = 0;

    while(!que_seq.empty())
    {
        sequence cur_seq = que_seq.front();
        cur_jump = cur_seq.jump;

        // 점프 하기
        if(cur_jump < max_jump)
        {
            for(int dir = 0; dir < 8; dir++)
            {
                temp_y = cur_seq.y + d_jump[dir][0];
                temp_x = cur_seq.x + d_jump[dir][1];

                // 범위 안이 아니거나 평지가 아닌 경우 무시
                if(!(check_inner(_map, temp_y, temp_x) && _map[temp_y][temp_x] == 0))
                {
                    continue;
                }

                // 현재 점프할려고 할 때, 이동 거리가 더 짧은 경우만 진행
                if(_area[temp_y][temp_x][cur_jump + 1] > _area[cur_seq.y][cur_seq.x][cur_jump] + 1)
                {
                    _area[temp_y][temp_x][cur_jump + 1] = _area[cur_seq.y][cur_seq.x][cur_jump] + 1;
                    que_seq.push(sequence(temp_y, temp_x, cur_jump + 1));
                }
            }
        }

        // 점프 하지 않기
        for(int dir = 0; dir < 4; dir++)
        {
            temp_y = cur_seq.y + d_normal[dir][0];
            temp_x = cur_seq.x + d_normal[dir][1];

            // 범위 안이 아니거나 평지가 아닌 경우 무시
            if(!(check_inner(_map, temp_y, temp_x) && _map[temp_y][temp_x] == 0))
            {
                continue;
            }

            // 현재 이동 거리가 더 작은 경우에만 추가
            if(_area[temp_y][temp_x][cur_jump] > _area[cur_seq.y][cur_seq.x][cur_jump] + 1)
            {
                _area[temp_y][temp_x][cur_jump] = _area[cur_seq.y][cur_seq.x][cur_jump] + 1;
                que_seq.push(sequence(temp_y, temp_x, cur_jump));
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
    int w, h, k;
    cin >> k >> w >> h;

    // 맵 입력
    vector<vector<int>> map(h, vector<int>(w, false));
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            cin >> map[i][j];
        }
    }

    // 구역 정보
    vector<vector<vector<int>>> area(h, vector<vector<int>>(w, vector<int>(k + 1, 40001)));
    
    // 검사
    search(area, map);

    // 최단 거리 찾기
    int result = 40001;
    for(int i = 0; i < k + 1; i++)
    {
        result = min(result, area[h-1][w-1][i]);
    }

    // 최단 거리 찾기 불가능
    if(result == 40001)
    {
        result = -1;
    }

    cout << result << "\n";
}