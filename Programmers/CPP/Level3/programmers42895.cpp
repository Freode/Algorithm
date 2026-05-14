// Lv.3 - 42895번 : N으로 표현
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// n개로 만들 수 있는 수를 모으기

int solution(int N, int number) {
    
    vector<unordered_set<int>> dp(9);
    
    int num = 0;
    // 연속된 N 배치
    for(int i = 1; i < 9; i++)
    {
        num = num * 10 + N;
        dp[i].insert(num);
    }
    
    // 사칙 연산으로 조합 찾기
    for(int i = 1; i < 9; i++)
    { 
        for(int j = 1; j < i; j++)
        {
            for(int front : dp[j])
            {
                for(int back : dp[i - j])
                {
                    dp[i].insert(front + back);
                    dp[i].insert(front - back);
                    dp[i].insert(front * back);
                    
                    if(back != 0)
                        dp[i].insert(front / back);
                }
            }
        }
    }
    
    for(int i = 1; i < 9; i++)
    {
        for(int num : dp[i])
        {
            if(num == number)
                return i;
        }
    }
    
    return -1;
}