// Lv.2 - 12905번 : 가장 큰 정사각형 찾기
// 작성자 : jeonghoe22(최정호)

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 정사각형 조건 -> (y,x), (y+1,x), (y,x+1), (y+1, x+1)
// 1 1 1 1 ->   1 1 1 1
// 1 1 1 1 ->   1 2 2 2
// 1 1 1 1 ->   1 2 3 3
// 1 1 1 1 ->   1 2 3 4
// 사각형 최대 길이는 4

// 0 1 1 1 ->   0 1 1 1
// 1 1 1 1 ->   1 1 2 2
// 1 1 1 1 ->   1 2 2 3
// 0 0 1 0 ->   0 0 1 0

int solution(vector<vector<int>> board)
{
    // board가 1*1인 경우
    int answer = 0;

    // 첫 번째 열 및 행 빼고 검사
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[0].size(); j++)
        {
            // 현재 지점이 0일 경우에는 무시
            if(board[i][j] == 0)
            {
                continue;
            }
            // 검사하는 점을 제외한 세 지점 중 가장 작은 값 + 1
            // 정사각형이 아니면, 1개로 설정하는데, min 중에서 어차피 0으로 걸리므로 무시 가능
            if(i > 0 && j > 0)
            {
                board[i][j] = 1 + min(min(board[i-1][j-1], board[i-1][j]), board[i][j-1]);
            }
            // 해당 값이 가장 긴 정사각형인지 확인
            if(answer < board[i][j])
            {
                answer = board[i][j];
            }
        }
    }    

    // 넓이 반환
    return answer * answer;
}