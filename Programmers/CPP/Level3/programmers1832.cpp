// Lv.3 - 1832번 : 보행자 천국
// 작성자 : jeonghoe22(최정호)

#include <vector>

using namespace std;

int MOD = 20170805;

// 오른쪽과 아래 방향만 이동 가능
// dp[y][x][dir]
// dir : 0 왼쪽에서 온 경우, dir : 1 위쪽에서 온 경우

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    
    vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(2, 0)));
    
    dp[0][0][0] = 1;
    
    for(int y = 0; y < m; y++)
    {
        for(int x = 0; x < n; x++)
        {
            // 위에서 오는 경우 검사
            if(y > 0)
            {
                // 자유 통행
                if(city_map[y-1][x] == 0)
                    dp[y][x][1] = (dp[y-1][x][0] + dp[y-1][x][1]) % MOD;
                
                // 직진
                else if(city_map[y-1][x] == 2)
                    dp[y][x][1] = dp[y-1][x][1];
            }
            // 왼쪽에서 오는 경우 검사
            if(x > 0)
            {
                // 자유 통행
                if(city_map[y][x-1] == 0)
                    dp[y][x][0] = (dp[y][x-1][0] + dp[y][x-1][1]) % MOD;
                
                // 직진
                else if(city_map[y][x-1] == 2)
                    dp[y][x][0] = dp[y][x-1][0];
            }
        }
    }
    
    answer = (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    
    return answer;
}