// 골드 5 - 9084번 : 동전
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 개수 T
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        // 동전 가지 수 N
        int N;
        cin >> N;

        // 동전 입력
        vector<int> costs(N);
        for(int& cost : costs)
        {
            cin >> cost;
        }

        // 목표 금액 M
        int M;
        cin >> M;
        
        vector<vector<int>> dp(N+1, vector<int>(M+1, 0));
        dp[0][0] = 1;

        for(int i = 1; i <= N; i++)
        {
            int cost = costs[i-1];
            for(int j = 0; j <= M; j++)
            {
                // 0원을 만드는 경우는 1
                if(j == 0)
                {
                    dp[i][0] = 1;
                    continue;
                }

                // 기존 경우 + 현재 동전을 1개 추가하는 경우
                dp[i][j] = dp[i-1][j];
                if(j - cost >= 0)
                    dp[i][j] += dp[i][j-cost];
            }
        }

        cout << dp[N][M] << "\n";
    }
}