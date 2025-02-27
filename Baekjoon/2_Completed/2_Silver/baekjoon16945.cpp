// 실버 2 - 16945번 : 매직 스퀘어로 변경하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int len_y = 3;
const int len_x = 3;

vector<vector<int>> squares(3, vector<int>(3));
vector<vector<int>> in_squares(3, vector<int>(3));
vector<bool> uses(10, false);

// 비용 체크
int CheckCost()
{
    int cost = 0;
    for(int y = 0; y < len_y; y++)
    {
        for(int x = 0; x < len_x; x++)
        {
            cost += abs(squares[y][x] - in_squares[y][x]);
        }
    }
    return cost;
}

// 완성된 경우에만 값을 변경
bool IsComplete()
{
    // 대각선과 행, 열이 모두 15
    bool b_correct = true;
    for(int i = 0; i < 3; i++)
    {
        // 행 검사
        b_correct = 15 == in_squares[i][0] + in_squares[i][1] + in_squares[i][2];
        if(b_correct == false) return false;

        // 열 검사
        b_correct = 15 == in_squares[0][i] + in_squares[1][i] + in_squares[2][i];
        if(b_correct == false) return false;
    }
    // 대각선 검사
    return (in_squares[0][0] + in_squares[1][1] + in_squares[2][2]) == (in_squares[0][2] + in_squares[1][1] + in_squares[2][0]);
}

// 탐색
int Search(int y, int x)
{
    int result = numeric_limits<int>::max();
    // 범위를 벗어난 경우는 다음으로 진행
    if(x == len_x)
    {
        return Search(y + 1, 0);
    }

    // 목표치에 도달한 경우
    if(y == len_y)
    {
        return IsComplete() ? CheckCost() : result;
    }

    // 아직 검사를 더 해야하는 경우
    for(int i = 1; i < 10; i++)
    {
        // 아직 사용하지 않은 수일 때만 진행
        if(uses[i] == false)
        {
            int prev = in_squares[y][x];

            uses[i] = true;
            in_squares[y][x] = i;

            // 오른쪽으로 이동
            result = min(result, Search(y, x+1));

            uses[i] = false;
            in_squares[y][x] = prev;
        }
    }
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> squares[i][j];
            in_squares[i][j] = squares[i][j];
        }
    }

    int result = Search(0, 0);

    cout << result << "\n";
}