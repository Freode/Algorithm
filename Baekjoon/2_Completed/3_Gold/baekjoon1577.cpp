// 골드 5 - 17070번 : 파이프 옮기기 1
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 구역
struct Area
{
    bool b_left = false;
    bool b_right = false;
    bool b_up = false;
    bool b_down = false;
    long long cases;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int n, m;
    cin >> n >> m;

    // 할당
    vector<vector<Area>> areas(m+1, vector<Area>(n+1));

    // 공사 구간 입력 및 저장
    int k;
    int x1, y1, x2, y2;
    int x_diff, y_diff;
    
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        // 차이로 방향 판단
        x_diff = x1 - x2;
        y_diff = y1 - y2;

        // 왼쪽
        if(x_diff == 1)
        {
            areas[y1][x1].b_left = true;

            areas[y2][x2].b_right = true;
        }
        // 위쪽
        else if(y_diff == 1)
        {
            areas[y1][x1].b_up = true;

            areas[y2][x2].b_down = true;
        }
        // 아래쪽
        else if(y_diff == -1)
        {
            areas[y1][x1].b_down = true;

            areas[y2][x2].b_up = true;
        }
        // 오른쪽
        else
        {
            areas[y1][x1].b_right = true;

            areas[y2][x2].b_left = true;
        }
    }

    // 계산
    areas[0][0].cases = 1;
    for(int i = 0; i < m + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            // 왼쪽 도로 공사 아님 && 0번째 열 아님
            if(areas[i][j].b_left == false && j != 0)
            {
                areas[i][j].cases += areas[i][j-1].cases;
            }

            // 위쪽 도로 공사 아님 && 0번째 행 아님
            if(areas[i][j].b_up == false && i != 0)
            {
                areas[i][j].cases += areas[i-1][j].cases;
            }
        }
    }

    cout << areas[m][n].cases << "\n";
}