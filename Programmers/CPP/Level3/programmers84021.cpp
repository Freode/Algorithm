// Lv.3 - 84021번 : 퍼즐 조각 채우기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

// 무조건 같은 모양의 도형만 가능
// 뒤집기만 불가능

// 1. 도형 반바퀴 회전 4번한 구조 저장 -> 중심점으로부터 떨어져 있는 칸의 +-만 조절
// 2. 해당 칸에 도형이 들어갈 수 있는지 확인
// 확인할 때, 중심점을 기준으로 확인
// 3. 칸별로 놓을 수 있는 도형 종류와 방향 저장
// 4. 

// 도형 정보
struct Polygon
{
    int size = 0;
    vector<vector<pair<int, int>>> shapes;
    bool b_is_used = false;

    Polygon() = default;
    Polygon(int size) : size(size) {};
};

// 도형 확인 함수
void check_polygon(vector<vector<int>> &table, vector<Polygon> &polygons, vector<vector<bool>> &table_visit,int y, int x)
{
    table_visit[y][x] = true;
    
    int size = 1;
    vector<pair<int, int>> shape;
    shape.push_back(make_pair(0, 0));

    // 기본 도형 모양 찾기
    queue<pair<int, int>> que_loc;
    que_loc.push(make_pair(y, x));

    // BFS로 찾기
    pair<int, int> cur_loc;
    int temp_y, temp_x;
    while(!que_loc.empty())
    {
        // 방문 설정 및 도형 모양 정보 추가
        cur_loc = que_loc.front();

        // 4방향 검사
        for(int i = 0; i < 4; i++)
        {
            temp_y = y;
            temp_x = x;

            if(i == 0)
            {
                temp_y++;
            }
            else if(i == 1)
            {
                temp_x++;
            }
            else if(i == 2)
            {
                temp_y--;
            }
            else
            {
                temp_x--;
            }

            // 범위 안
            if(!(temp_y >= 0 && temp_x >= 0 && temp_y < table.size() && temp_x < table.size()))
            {
                continue;
            }

            // 이미 방문 또는 벽일 때, 무시
            if(table_visit[temp_y][temp_x] || table[temp_y][temp_x] == 0)
            {
                continue;
            }

            // 추가
            que_loc.push(make_pair(temp_y, temp_x));
            size++;
            shape.push_back(make_pair(cur_loc.first - y, cur_loc.second -x));
            table_visit[cur_loc.first][cur_loc.second] = true;
        }

        que_loc.pop();
    }

    polygons.push_back(Polygon(size));
    polygons[polygons.size() - 1].shapes.push_back(shape);
}

// 도형 회전 함수
void turn_polygon(vector<Polygon> &polygons)
{
    vector<pair<int, int>> shape;
    int temp_y, temp_x, temp;
    for(Polygon &polygon : polygons)
    {
        for(int i = 0; i < 3; i++)
        {
            // 초기화 및 중심점 추가
            shape.clear();
            shape.push_back(make_pair(0, 0));

            //
            for(int j = 1; i < polygon.shapes[0].size(); j++)
            {
                temp_x = polygon.shapes[0][j].second;
                temp_y = polygon.shapes[0][j].first;

                // 교환
                temp = temp_x;
                temp_x = temp_y;
                temp_y = temp;

                // 대칭
                temp_x *= -1;

                shape.push_back(make_pair(temp_y, temp_x));
            }
            // 회전 도형 추가
            polygon.shapes.push_back(shape);
        }
    }
}

int input_polygon(vector<vector<int>> &game_board, vector<Polygon> &polygons, vector<vector<bool>> &game_board_visits, int y, int x)
{
    int count;

    queue<pair<int, int>> que_loc;
    que_loc.push(make_pair(y, x));
    game_board_visits[y][x] = true;
    
    int size = 1;
    vector<pair<int, int>> shapes;
    shapes.push_back(make_pair(0, 0));
    int cur_y, cur_x, temp_y, temp_x;
    while(!que_loc.empty())
    {
        cur_y = que_loc.front().first;
        cur_x = que_loc.front().second;

        // 4방향 검사
        for(int i = 0; i < 4; i++)
        {
            temp_y = cur_y;
            temp_x = cur_x;

            if(i == 0)
            {
                temp_y++;
            }
            else if(i == 1)
            {
                temp_x++;
            }
            else if(i == 2)
            {
                temp_y--;
            }
            else
            {
                temp_x--;   
            }

            // 범위 안
            if(!(temp_y >= 0 && temp_x >= 0 && temp_y < game_board.size() && temp_x < game_board.size()))
            {
                continue;
            }

            // 방문 여부 및 벽인지 확인
            if(game_board_visits[temp_y][temp_x] || !game_board[temp_y][temp_x])
            {
                continue;
            }

            que_loc.push(make_pair(temp_y, temp_x));
            shapes.push_back(make_pair(temp_y - y, temp_x - x));
            game_board_visits[temp_y][temp_x] = true;
            size++;
        }

        que_loc.pop();

    }

    // 도형 크기와 모양 검사
    bool b_is_same = true;
    for(Polygon& polygon : polygons)
    {
        if(polygon.b_is_used || !(polygon.size == size))
        {
            continue;
        }

        // 도형 검사
        for(int i = 0; i < 4; i++)
        {
            b_is_same = true;
            for(int j = 0; j < polygon.shapes[0].size() j++)
            {
                if(polygon.shapes[i][j].first != shapes[j].first || polygon.shapes[i][j].second != shapes[j].second)
                {
                    b_is_same = false;
                    break;
                }
            }

            if(!b_is_same)
            {
                break;
            }
            // 맞는 도형 찾음
            else
            {
                polygon.b_is_used = true;
                return size;
            }
        }
    }

    return 0;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;

    // 도형 정보 입력
    vector<Polygon> polygons;
    vector<vector<bool>> table_visit(table.size(), vector<bool>(table.size(), false));

    // 도형 찾기
    for(int i = 0; i < table.size(); i++)
    {
        for(int j = 0; j < table.size(); j++)
        {
            check_polygon(table, polygons, table_visit, i, j);
        }
    }

    vector<vector<bool>> game_board_visits(table.size(), vector<bool>(table.size(), false));
    // 도형 대입
    for(int i = 0; i < game_board.size(); i++)
    {
        for(int j = 0; j < game_board.size(); j++)
        {
            answer += input_polygon(game_board, polygons, game_board_visits, i, j);
        }
    }

    return answer;
}