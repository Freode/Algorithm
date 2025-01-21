// 골드 5 - 17070번 : 파이프 옮기기 1
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구역
struct Area
{
    bool b_is_wall = false;
    int cases_left = 0;
    int cases_up = 0;
    int cases_cross = 0;
};

// 대각선 이동 확인
bool canCross(vector<vector<Area>> &areas, int y, int x)
{
    return !(areas[y][x].b_is_wall || areas[y-1][x].b_is_wall || areas[y][x-1].b_is_wall || areas[y-1][x-1].b_is_wall);
}

// 시뮬레이션
void simulation(vector<vector<Area>> &areas)
{

    for(int i = 0; i < (int)areas.size(); i++)
    {
        for(int j = 1; j < (int)areas.size(); j++)
        {

            // 현재 위치 벽인 경우
            if(areas[i][j].b_is_wall == true)
            {
                areas[i][j].cases_cross = 0;
                areas[i][j].cases_left = 0;
                areas[i][j].cases_up = 0;
                continue;
            }

            // 0번째 줄
            if(i == 0)
            {
                areas[i][j].cases_left = areas[i][j-1].b_is_wall ? 0 : 1;
                continue;
            }

            // 1. 위가 벽이 아닌 경우, 위로 연결
            if(areas[i-1][j].b_is_wall == false)
            {
                areas[i][j].cases_up = areas[i-1][j].cases_cross + areas[i-1][j].cases_up;
            }

            // 2. 대각선이 벽이 아닌 경우, 대각선 연결
            if(canCross(areas, i, j))
            {
                areas[i][j].cases_cross = areas[i-1][j-1].cases_cross + areas[i-1][j-1].cases_left + areas[i-1][j-1].cases_up;
            }

            // 3. 옆이 벽이 아닌 경우, 옆으로 연결
            if(areas[i][j-1].b_is_wall == false)
            {
                areas[i][j].cases_left = areas[i][j-1].cases_cross + areas[i][j-1].cases_left;
            }
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int n;
    cin >> n;

    // 구역 할당
    vector<vector<Area>> areas(n, vector<Area>(n));
    int temp;
    for(int i = 0; i < (int)areas.size(); i++)
    {
        for(int j = 0; j < (int)areas.size(); j++)
        {
            cin >> temp;
            areas[i][j].b_is_wall = (temp == 1);
        }
    }

    // 시작점
    areas[0][1].cases_left = 1;

    // 시뮬레이션
    simulation(areas);

    // 출력
    cout << areas[n-1][n-1].cases_cross + areas[n-1][n-1].cases_left + areas[n-1][n-1].cases_up << "\n";
}