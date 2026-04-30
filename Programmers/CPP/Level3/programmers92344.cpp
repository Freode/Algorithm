// Lv.3 - 92344번 : 다른 사람의 풀이
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>

using namespace std;

// 영향이 시작되는 지점에 + 기록
// 영향이 끝나는 지점에 - 기록
// 왼 -> 오, 위 -> 아래

// acc[r1][c1] += val;
// acc[r2 + 1][c1] -= val;
// acc[r1][c2 + 1] -= val;
// acc[r2 + 1][c2 + 1] += val;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    int y_size = board.size();
    int x_size = board[0].size();
    
    vector<vector<int>> acc = vector<vector<int>>(y_size + 1, vector<int>(x_size + 1, 0));
    
    // 각 스킬마다 누적값 기록
    for(const vector<int>& sk : skill)
    {
        int val = (sk[0] == 1) ? -sk[5] : sk[5];
        int r1 = sk[1], c1 = sk[2], r2 = sk[3], c2 = sk[4];
        
        acc[r1][c1] += val;
        acc[r2 + 1][c1] -= val;
        acc[r1][c2 + 1] -= val;
        acc[r2 + 1][c2 + 1] += val;
    }
    
    // 가로 누적
    for(int y = 0; y < y_size; y++)
    {
        for(int x = 1; x < x_size; x++)
        {
            acc[y][x] += acc[y][x - 1];
        }
    }
    
    // 세로 누적
    for(int y = 1; y < y_size; y++)
    {
        for(int x = 0; x < x_size; x++)
        {
            acc[y][x] += acc[y - 1][x];
        }
    }
    
    // 멀쩡한 건물 찾기
    int answer = 0;
    
    for(int y = 0; y < y_size; y++)
    {
        for(int x = 0; x < x_size; x++)
        {
            if(board[y][x] + acc[y][x] > 0)
                answer++;
        }
    }
    
    return answer;
}