// 골드 5 - 25427번 : DKSH를 찾아라
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> g_boards(9, vector<int>(9));
vector<int> g_counts(10, 0);

// 보드 정보 입력
void inputBoard()
{
    string input;
    for(int i = 0; i < 9; i++)
    {
        cin >> input;
        for(int j = 0; j < 9; j++)
        {
            g_boards[i][j] = input[j] - '0';
        }
    }
}



bool check(const int y, const int x)
{
    int h_level = y / 3;
    int w_level = x / 3;

    bool b_last_y = (y == 8);
    bool b_last_x = (x == 8);
    bool b_last_area = (y % 3 == 0 && x % 3 == 0);

    // 열 검사


    // 줄 검사
}

bool simulate(const int y, const int x)
{
    bool b_pass = check(y, x);

    if((y == 8 && x == 8) || b_pass == false)
        return b_pass;

    // 다음 위치로 이동
    int next_x = x + 1;
    int next_y;
    if(next_x == 9)
    {
        next_y = y + 1;
        next_x = 0;
    }

    bool b_result = false;

    // 숫자가 이미 입력되어 있는 경우는 바로 다음으로 이동
    if(g_boards[next_y][next_x] != 0)
        return simulate(next_y, next_x);
    
    else
    {
        for(int i = 1; i <= 9; i++)
        {
            if(b_result == false)
            {
                g_boards[next_y][next_x] = i;
                b_result = simulate(next_y, next_x);
                g_boards[next_y][next_x] = 0;
            }
        }
    }

    return b_result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

}