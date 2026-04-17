// Lv.3 - 92345번 : 사라지는 발판
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, 1, -1};

struct Result
{
    bool isWin = false;
    int count = 0;
};

bool canGo(vector<vector<int>>& board, int ySize, int xSize, int y, int x)
{
    return y >= 0 && x >= 0 && y < ySize && x < xSize && board[y][x] != 0;
}

Result minmax(vector<vector<int>> &board, int curY, int curX, int oppY, int oppX)
{
    // 보드가 없어져서 현재 턴의 캐릭터가 진 상황
    if(board[curY][curX] == 0)
        return {false, 0};
    
    bool canMove = false;
    int minWin = numeric_limits<int>::max();
    int maxLoss = numeric_limits<int>::min();
    
    // 4방향 검사
    for(int dir = 0; dir < 4; dir++)
    {
        int nextY = curY + dy[dir];
        int nextX = curX + dx[dir];
        
        if(canGo(board, board.size(), board[0].size(), nextY, nextX) == false)
            continue;
        
        canMove = true;
        
        board[curY][curX] = 0;
        Result result = minmax(board, oppY, oppX, nextY, nextX);
        board[curY][curX] = 1;
        
        // 내가 이기는 경우 = 상대가 지는 경우 
        if(result.isWin == false)
            minWin = min(minWin, result.count + 1);

        // 상대가 이기는 경우
        else
            maxLoss = max(maxLoss, result.count + 1);
    }
    
    // 이동하지 못하는 경우는 패배
    if(canMove == false)
        return {false, 0};

    // 이기는 경우가 하나라도 존재한다면, 가장 빨리 이기는 경우를 반환
    if(minWin != numeric_limits<int>::max())
        return {true, minWin};
    
    // 모든 경우가 지는 경우라면, 가장 늦게 지는 경우를 반환
    return {false, maxLoss};
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    Result answer;
    
    answer = minmax(board, aloc[0], aloc[1], bloc[0], bloc[1]);
    
    return answer.count;
}