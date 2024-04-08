// 실버 2 - 2630번 : 색종이 만들기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 현재 색종이 크기만큼 색깔 검사
void CheckArea(vector<vector<bool>> &areas, int start_x, int start_y, int interp, int& white, int& blue)
{
    // 현재 사각형에서의 첫 위치 색깔
    bool first_color = areas[start_y][start_x];

    // 현재 자른 사각형 내에서 검사
    bool b_is_stop = true;
    for(int i = start_y; i < start_y + interp; i++)
    {
        // 색조이를 잘라서 더 이상 검사할 필요가 없는 경우
        if(b_is_stop == false) { break; }

        for(int j = start_x; j < start_x + interp; j++)
        {
            // 색깔이 다른 경우
            if( b_is_stop == true && first_color != areas[i][j])
            {
                // 색종이 4등분
                CheckArea(areas, start_x, start_y, interp / 2, white, blue);
                CheckArea(areas, start_x + interp / 2, start_y, interp / 2, white, blue);
                CheckArea(areas, start_x, start_y + interp / 2, interp / 2, white, blue);
                CheckArea(areas, start_x + interp / 2, start_y + interp / 2, interp / 2, white, blue);
                b_is_stop = false;
                break;
            }
        }
    }

    // 현재 색종이가 모두 같은 색깔일 때
    if(b_is_stop == true)
    {
        // 파란색
        if(first_color){ blue++; }
        // 하얀색
        else { white++; }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<vector<bool>> areas(N, vector<bool>(N, false));

    int temp;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> temp;
            areas[i][j] = (temp == 1);
        }
    }

    // 색종이 검사
    int white = 0, blue = 0;
    CheckArea(areas, 0, 0, N, white, blue);

    // 출력
    cout << white << "\n" << blue << "\n";
}