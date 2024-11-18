// Lv.2 - 250136번 : 석유 시추
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Area
{
    // 몇 번 구역
    int num = -1;
    // 방문하지 않음
    bool b_is_visited = false;
};

// DFS로 석유 양 탐사
int search(vector<vector<Area>> &areas, vector<vector<int>> &land, int y, int x, int area_num)
{
    int amount = 0;

    // 방문 했다고 설정
    areas[y][x].b_is_visited = true;
    areas[y][x].num = area_num;
    amount = 1;

    int temp_y, temp_x;
    // 4방향 확인
    for(int i = 0; i < 4; i++)
    {
        temp_y = y;
        temp_x = x;

        if(i == 0)
        {
            temp_y--;
        }
        else if(i == 1)
        {
            temp_x++;
        }
        else if(i == 2)
        {
            temp_y++;
        }
        else
        {
            temp_x--;
        }

        // 경계 밖이면 생략
        if(!(temp_y >= 0 && temp_x >= 0 && temp_y < land.size() && temp_x < land[0].size()))
        {
            continue;
        }

        // 방문하지 않고 석유일 때만 확인하러 감
        if(!areas[temp_y][temp_x].b_is_visited && land[temp_y][temp_x] == 1)
        {
            amount += search(areas, land, temp_y, temp_x, area_num);
        }
    }

    return amount;
}

int solution(vector<vector<int>> land) {
    int answer = 0;

    // 구역 생성
    vector<vector<Area>> areas(land.size(), vector<Area>(land[0].size()));

    int oil_num = 0;
    vector<int> area_oil_amount;

    // 모든 지점에 대한 검사 시작
    for(int i = 0; i < land.size(); i++)
    {
        for(int j = 0; j < land[0].size(); j++)
        {
            // 방문하지 않은 석유 지역
            if(!areas[i][j].b_is_visited && land[i][j])
            {
                area_oil_amount.push_back(search(areas,land,i,j,oil_num));
                oil_num++;
            }
        }
    }
    
    // 모든 열에 대한 검사 진행
    vector<int> same_row_oil;
    int cur_row_total_oil = 0;
    int cur_oil_area_num;
    for(int i = 0; i < land[0].size(); i++)
    {
        cur_row_total_oil = 0;
        same_row_oil.clear();
        // 같은 열에 대한 모든 행 검사 진행
        for(int j = 0; j < land.size(); j++)
        {
            if(areas[j][i].num != -1)
            {
                // 새로운 석유 지역 발견
                bool b_is_duplicate = false;
                // 이전에 발견한 구역과 겹치지 않는지 확인
                for(int &k : same_row_oil)
                {
                    if(k == areas[j][i].num)
                    {
                        b_is_duplicate = true;
                        break;
                    }
                }
                // 겹치지 않을 때, 추가
                if(!b_is_duplicate)
                {
                    same_row_oil.push_back(areas[j][i].num);
                    cur_row_total_oil += area_oil_amount[areas[j][i].num];
                }
            }
            // 최댓값으로 반환
            answer = max(cur_row_total_oil, answer);
        }
    }

    return answer;
}