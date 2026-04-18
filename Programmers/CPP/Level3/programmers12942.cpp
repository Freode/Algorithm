// Lv.3 - 12942번 : 최적의 행렬 곱셈
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <limits>
#include <iostream>

using namespace std;

// 5 * 3, 3 * 10, 10 * 6
// 5 * 3 * 10 = 150, 5 * 10 * 6 = 300 -> 450
// 3 * 10 * 6 = 180, 5 * 3 * 6 = 90 -> 270

// 2차원 배열
// dp[start][end] -> start ~ end까지 행렬 합칠 때, 최소
// dp[1][2] = 150, dp[2][3] = 180
// dp[1][3] = min(dp[1][2] + ms[1][0] * ms[3][0] * ms[3][1], dp[2][3] + ms[1][0] * ms[1][1] * ms[3][1]);

// dp[1][4] -> dp[1][3] ~ , dp[2][4] ~
// dp[1][5] -> dp[1][2] + dp[2][5], dp[1][3] + dp[3][5], dp[1][4] + dp[4][5]

// 시간 복잡도 : 200 * 200 * 200

int solution(vector<vector<int>> matrix_sizes) {
    int answer = 0;
    int size = matrix_sizes.size();
    int max_value = numeric_limits<int>::max() >> 2;
    
    vector<vector<int>> dp = vector<vector<int>>(size, vector<int>(size, max_value));
    
    // 자기 자신에 대한 행렬 계산을 모두 0으로 초기화
    for(int i = 0; i < size; i++)
    {
        dp[i][i] = 0; 
    }
    
    // 계산
    for(int length = 1; length < size; length++)
    {
        for(int start = 0; start < size - length; start++)
        {
            int end = start + length;
            
            for(int mid = start; mid < end; mid++)
            {
                int mid_value = dp[start][mid] + dp[mid + 1][end] + matrix_sizes[start][0] * matrix_sizes[mid][1] * matrix_sizes[end][1];
                
                dp[start][end] = min(dp[start][end], mid_value);
            }
        }
    }
    
    
    answer = dp[0][size - 1];
    
    return answer;
}