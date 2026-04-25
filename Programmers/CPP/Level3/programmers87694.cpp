// Lv.3 - 87694번 : 아이템 줍기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Loc
{
    int y = 0;
    int x = 0;
    int dist = 0;
};

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    
    const int dy[] = {1, -1, 0, 0};
    const int dx[] = {0, 0, 1, -1};
    
    vector<vector<bool>> boards = vector<vector<bool>>(101, vector<bool>(101, false));
    // 2배로 확장 사각형 내부 통과하는 경우 방지
    for(vector<int>& rect : rectangle)
    {
        for(int& pos : rect)
        {
            pos = pos << 1;
        }
    }
    
    // 사각형 먼저 채우기
    for(const vector<int>& rect : rectangle)
    {
        for(int y = rect[1]; y <= rect[3]; y++)
        {
            for(int x = rect[0]; x <= rect[2]; x++)
            {
                boards[y][x] = true;
            }
        }
    }
    
    // 내부 제거
    for(const vector<int>& rect : rectangle)
    {
        for(int y = rect[1] + 1; y <= rect[3] - 1; y++)
        {
            for(int x = rect[0] + 1; x <= rect[2] - 1; x++)
            {
                boards[y][x] = false;
            }
        }
    }
    
    // 2배 반영
    characterY = characterY << 1;
    characterX = characterX << 1;
    itemY = itemY << 1;
    itemX = itemX << 1;
    
    // 출발
    queue<Loc> q;
    q.push({characterY, characterX, 0});
    boards[characterY][characterX] = false;
    
    while(q.empty() == false)
    {
        Loc cur = q.front();
        q.pop();
        
        for(int dir = 0; dir < 4; dir++)
        {
            int nextY = cur.y + dy[dir];
            int nextX = cur.x + dx[dir];
            
            if((nextX >= 0 && nextY >= 0 && nextX < 101 && nextY < 101) == false)
                continue;
            
            if(boards[nextY][nextX] == false)
                continue;
            
            if(nextY == itemY && nextX == itemX)
            {
                return (cur.dist + 1) >> 1;
            }
            
            boards[nextY][nextX] = false;
            q.push({nextY, nextX, cur.dist + 1});
        }
    }
    
    
    return answer;
}