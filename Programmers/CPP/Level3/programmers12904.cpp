// Lv.3 - 12904번 : 가장 긴 펠린드롬
// 작성자 : jeonghoe22(최정호)

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// dp[l][r] : l ~ r 구간 팰린드롬인지 확인
// 2'500 * 2'500 = 6'250'000
// 길이 * 시작 위치
// 길이 : 1 = true
// 길이 : 2 = s[l] == s[r]
// 길이 : 3 이상 : (s[l] == s[r] && dp[l+1][r-1])

int solution(string s)
{
    int size = s.size();
    
    vector<vector<bool>> dp = vector<vector<bool>>(size, vector<bool>(size, false));
    
    int answer = 1;
    // 길이가 1
    for(int i = 0; i < size; i++)
        dp[i][i] = true;
    
    // 길이가 2
    for(int i = 0; i < size - 1; i++)
    {
        if(s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            answer = 2;
        }
    }
    
    // 길이가 3 이상
    for(int len = 2; len < size; len++)
    {
        for(int start = 0; start < size - len; start++)
        {
            int end = start + len;
            if(s[start] == s[end] && dp[start+1][end-1])
            {
                dp[start][end] = true;
                answer = max(answer, len + 1);
            }
        }
    }

    return answer;
}