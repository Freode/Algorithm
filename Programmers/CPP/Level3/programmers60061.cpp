// Lv.3 - 60061번 : 다른 사람의 풀이
// 작성자 : jeonghoe22(최정호)


#include <string>
#include <vector>

using namespace std;

// 기둥 - 바닥 위 / 보의 한쪽 끝 부분 위 / 또 다른 기둥 위
// 보 - 한쪽 끝 기둥 위 / 양쪽 끝이 다른 보와 연결

// 불가능한 명령은 무시
// 현재까지는 무조건 가능한 상태라고 판단 가능

// x, y, (0 : 기둥 / 1 : 보), (0 : 삭제 / 1 : 설치)

bool canBarrage(vector<vector<vector<int>>>& grids, const int y, const int x)
{
    int n = grids.size();
    
    // 한쪽 끝 기둥 위 - 바닥에 보를 설치하는 경우 없음
    if(y - 1 >= 0 && (grids[y - 1][x][0] == 1 || (x + 1 < n && grids[y - 1][x + 1][0] == 1)))
        return true;
    
    // 양쪽 끝이 다른 보와 연결
    if((x - 1 >= 0 && grids[y][x - 1][1] == 1) && (x + 1 < n && grids[y][x + 1][1] == 1))
        return true;
    
    return false;
}

bool canPillar(vector<vector<vector<int>>> &grids, const int y, const int x)
{
    // 바닥 위
    if(y == 0)
        return true;
    
    // 보의 한쪽 끝
    if(grids[y][x][1] == 1 || (x - 1 >= 0 && grids[y][x - 1][1] == 1))
        return true;
    
    // 또 다른 기둥 위
    if(y - 1 >= 0 && grids[y - 1][x][0] == 1)
        return true;
    
    return false;
}

void canOper(vector<vector<vector<int>>> &grids, const vector<int>& frame)
{
    int x = frame[0];
    int y = frame[1];
    int kind = frame[2];
    int oper = frame[3];
    // 설치
    if(oper == 1)
    {
        // 기둥
        if(kind == 0)
        {
            grids[y][x][0] = 1;
            if(canPillar(grids, y, x) == false)
                grids[y][x][0] = 0;
        }
        
        // 보
        else
        {
            grids[y][x][1] = 1;
            if(canBarrage(grids, y, x) == false)
                grids[y][x][1] = 0;
        }
    }
    
    // 삭제
    else
    {
        bool can_do = true;
        
        // 기둥
        if(kind == 0)
            grids[y][x][0] = 0;
        // 보
        else
            grids[y][x][1] = 0;
        
        // 주변 검사
        for(int dy = -1; dy <= 1; dy++)
        {
            for(int dx = -1; dx <= 1; dx++)
            {
                int check_y = y + dy;
                int check_x = x + dx;
                
                if((check_y >= 0 && check_x >= 0 && check_y < grids.size() && check_x < grids.size()) == false)
                    continue;
                
                if(can_do && grids[check_y][check_x][0] == 1)
                    can_do = canPillar(grids, check_y, check_x);
                
                if(can_do && grids[check_y][check_x][1] == 1)
                    can_do = canBarrage(grids, check_y, check_x);
            }
        }
        
        // 기둥
        if(can_do == false && kind == 0)
            grids[y][x][0] = 1;            
        // 보
        if(can_do == false && kind == 1)
            grids[y][x][1] = 1;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    
    vector<vector<vector<int>>> grids = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    
    for(const vector<int>& frame : build_frame)
    {
        canOper(grids, frame);
    }
    
    vector<vector<int>> answer;
    
    for(int x = 0; x <= n; x++)
    {
        for(int y = 0; y <= n; y++)
        {
            if(grids[y][x][0] == 1)
                answer.push_back({x, y, 0});
            if(grids[y][x][1] == 1)
                answer.push_back({x, y, 1});
        }
    }
    
    return answer;
}