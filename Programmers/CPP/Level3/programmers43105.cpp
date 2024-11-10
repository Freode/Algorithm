// Lv.3 - 42579번 : 베스트앨범 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    vector<vector<int>> dp = triangle;
    
    // 줄이 1개인 경우에는 무시
    for(int i = 1; i < dp.size(); i++)
    {
        for(int j = 0; j < dp[i].size(); j++)
        {
            // 왼쪽 끝
            if(j == 0)
            {
                // 상단 오른쪽만 고려
                dp[i][j] += dp[i-1][j];
            }
            // 오른쪽 끝
            else if(j == dp[i].size()-1)
            {
                // 상단 왼쪽만 고려
                dp[i][j] += dp[i-1][j-1];
            }
            // 중앙
            else
            {
                // 상단 왼쪽과 오른쪽 모두 고려
                dp[i][j] = max(dp[i][j] + dp[i-1][j-1], dp[i][j] + dp[i-1][j]);
            }
        }
    }

    // 마지막 줄 중에서 가장 큰 수 찾기
    for(int &each : dp[dp.size()-1])
    {
        if(answer < each)
        {
            answer = each;
        }
    }

    return answer;
}