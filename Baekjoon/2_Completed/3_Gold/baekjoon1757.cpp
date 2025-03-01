// 골드 4 - 1757번 : 달려달려
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

    // 운동할 시간 N, 지침 한계 지수 M
    int N, M;
    cin >> N >> M;

    vector<int> dists(N+1);
    vector<vector<int>> results(N+1, vector<int>(M+1, 0));

    // 현재 지침 지수와 시간에 따라 도달할 수 있는 경우
    // 1. 쉰다. -> [n-1][m+1]에서 도달
    // 2. 달렸다. -> [n-1][m-1]에서 도달

    for(int n = 1; n < N+1; n++)
    {
        cin >> dists[n];

        for(int m = 0; m < M+1; m++)
        {
            // 1. 쉰다.
            // [n-1][1], [n-2][2], [n-3][3]... 에서 도달
            // [n-1][0] ~ [1][0] 에서 도달
            if(m == 0) 
            {
                // [n-1][1], [n-2][2], [n-3][3]... 에서 도달
                for(int rest_time = 1; rest_time < M+1; rest_time++)
                {
                    int prev_n = n - rest_time;
                    // 그 이전에는 뛴 경우가 없어서
                    if(prev_n > 0 == false) break;  
                    results[n][0] = max(results[n][m], results[prev_n][rest_time]);
                }
                // [n-1][0] ~ [1][0] 에서 도달
                // 어차피 [n-1][0]에서 [n-2][0]~[1][0] 중 최댓값을 포함
                results[n][0] = max(results[n][0], results[n-1][0]);

            }
            // 2. 달렸다. -> [n-1][m-1]에서 도달
            // 단, 현재 지침 지수가 0이거나 시간과 지침 지수가 이론 상 존재하지 않을 때, 제외
            if(m != 0 && n - m >= 0) results[n][m] = max(results[n][m], results[n-1][m-1] + dists[n]);
        }
    }

    cout << results[N][0] << "\n";
}