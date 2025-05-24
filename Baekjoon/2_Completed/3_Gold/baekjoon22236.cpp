// 골드 4 - 22236번 : 가희와 비행기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이동 1 -> 거리 1 상승 또는 하강
// 시작과 끝은 항상 높이가 0이 되어야 함.
// 중간에 높이가 0이 되는 경우는 제외

// d : 1~4*10^3 -> 16KB
// 높이 2*10^3 -> 32MB -> dp로 해결 가능
// 시간 : 4*10^3 * 2*10^3 = 8*10^6

using ll = long long;

int simulate(const int d, const int m)
{
    vector<vector<ll>> dp(d+1, vector<ll>((d >> 1) + 1, 0));
    dp[0][0] = 1;

    for(int length = 1; length < d+1; length++)
    {
        for(int height = 0; height < dp[0].size(); height++)
        {
            // 현재 높이에 도달할 수 없는 경우
            if(length < height)
                continue;

            // 아래에서 도달하는 경우
            if(height != 0)
                dp[length][height] = dp[length-1][height-1];

            // 위에서 도달하는 경우
            if((height != dp[0].size()-1 && (height != 0)) || (height == 0 && length == d))
                dp[length][height] += dp[length-1][height+1];
            
            dp[length][height] %= m;
        }
    }
    
    return dp[d][0];
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 수평 거리 d, 나머지 m
    int d, m;
    cin >> d >> m;

    cout << simulate(d, m) << "\n";
}