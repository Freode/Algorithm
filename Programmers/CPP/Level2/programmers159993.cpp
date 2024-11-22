// Lv.2 - 159993번 : 미로 탈출
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int search(vector<string> &maps, int start_y, int start_x, int end_y, int end_x)
{
    // 방문 여부
    vector<vector<bool>> visits(maps.size(), vector<bool>(maps[0].size(), false));
    vector<vector<int>> distance(maps.size(), vector<int>(maps[0].size(), 0));
    // 초기 설정
    queue<pair<int, int>> que_search;
    que_search.push(make_pair(start_y, start_x));
    visits[start_y][start_x] = true;

    int cur_y, cur_x;
    int next_y, next_x;
    bool b_is_finish = false;
    int final_distance = -1;
    while(!que_search.empty())
    {
        // 현재 위치
        cur_y = que_search.front().first;
        cur_x = que_search.front().second;

        // 4방향 검사
        for(int i = 0; i < 4; i++)
        {
            next_y = cur_y;
            next_x = cur_x;
            switch (i)
            {
            case 0:
                next_y--;
                break;
            
            case 1:
                next_x++;
                break;

            case 2:
                next_y++;
                break;

            case 3:
                next_x--;
                break;
            }

            // 범위 내인지 확인
            if(next_y >= 0 && next_x >= 0 && next_y < maps.size() && next_x < maps[0].size())
            {
                // 이미 방문했거나 벽인 경우는 무시
                if(visits[next_y][next_x] || maps[next_y][next_x] == 'X')
                {
                    continue;
                }

                // 목적지일 경우
                if(next_y == end_y && next_x == end_x)
                {
                    b_is_finish = true;
                    final_distance = distance[cur_y][cur_x] + 1;
                    break;
                }

                // 목적지가 아닐 경우
                else
                {
                    visits[next_y][next_x] = true;
                    distance[next_y][next_x] = distance[cur_y][cur_x] + 1;
                    que_search.push(make_pair(next_y, next_x));
                }
            }
        }

        que_search.pop();

        // 이미 목적지를 찾은 경우
        if(b_is_finish)
        {
            break;
        }
    }

    return final_distance;
}

int solution(vector<string> maps) {

    int start_x, start_y;
    int lever_x, lever_y;
    int dest_x, dest_y;
    
    // 시작, 레버, 출구 위치 찾기
    for(int i = 0; i < maps.size(); i++)
    {
        for(int j = 0; j < maps[0].size(); j++)
        {
            // 시작 위치
            if(maps[i][j] == 'S')
            {
                start_x = j;
                start_y = i;
            }
            // 출구 위치
            else if(maps[i][j] == 'E')
            {
                dest_x = j;
                dest_y = i;
            }
            // 레버 위치
            else if(maps[i][j] == 'L')
            {
                lever_x = j;
                lever_y = i;
            }
        }
    }

    int first_distance, second_distance;
    // 출발지에서 레버까지 이동하기
    first_distance = search(maps, start_y, start_x, lever_y, lever_x);

    // 레버에서 출구까지 이동하기
    second_distance = search(maps, lever_y, lever_x, dest_y, dest_x);

    // 레버나 출구까지 도달하지 못하는 경우
    if(first_distance == -1 || second_distance == -1)
    {
        return -1;
    }

    return first_distance + second_distance;
}
