// 실버 2 - 16945번 : 매직 스퀘어로 변경하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

// 순서에 따라 위치 정하기
pair<int, int> LocBySeq(int seq)
{
    // y x
    pair<int, int> loc;
    switch (seq)
    {
    case 1:
        loc.first = 0;
        loc.second = 0; 
        break;
    case 2:
        loc.first = 0;
        loc.second = 2; 
        break;
    case 3:
        loc.first = 1;
        loc.second = 1; 
        break;
    case 4:
        loc.first = 2;
        loc.second = 0; 
        break;
    case 5:
        loc.first = 2;
        loc.second = 2; 
        break;
    }
    return loc;
}

// 완성되었는지 확인
bool IsComplete(vector<vector<int>> &in_square)
{
    return (in_square[0][0] + in_square[1][1] + in_square[2][2] == in_square[2][0] + in_square[1][1] + in_square[0][2]);
}

int Search(vector<vector<int>> in_square, int cost, int seq)
{
    int result = numeric_limits<int>::max();
    // 완료 단계
    if(seq == 6)
    {
        return IsComplete(in_square) ? cost : result;
    }

    pair<int, int> loc = LocBySeq(seq);

    int prev = in_square[loc.first][loc.second];
    // 수 대입
    for(int i = 1; i <= 9; i++)
    {   
        // 다음 진행
        int diff = abs(i - prev);
        in_square[loc.first][loc.second] = i;
        result = min(result, Search(in_square, cost + diff, seq + 1));
    
        // 원래대로 되돌리기
        in_square[loc.first][loc.second] = prev;
    }
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    vector<vector<int>> squares(3, vector<int>(3, 0));
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> squares[i][j];
        }
    }

    int result = Search(squares, 0, 1);
    cout << result << "\n";
}