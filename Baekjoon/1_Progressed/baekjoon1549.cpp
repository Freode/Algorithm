// 골드 4 - 1549번 : K
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

// s(i,k) = i번째부터 i+k-1번째까지의 합
// i+k <= k -> 즉, s(i,k)와 s(j,k) 범위는 겹치지 않음

// |s(i,k) - s(j,k)| 의 최솟값 구하기
// 차이의 최솟값이 여러 개인 경우, k를 최대로 하기

// n : 2~3'000
// A[i] : 0~1'000'000'000
// k 가능 범위 : 1~1'500

// 완전 탐색 : [(1'500 + 1) / 2 * 1'500] ^ 2 = (2'250'000) ^ 2

// 누적합 -> s(i,k) = S[i+k-1] - S[i]
// 처음 S[i] 구하기 -> 1'500
// k별로 간격 계산 -> (1 ~ 2'250'000) -> 2'250'000 / 2 * 1'500 = 2'250'000 * 750 = 1'687'500'000
// 위 경우보다는 적음

using ll = long long;

vector<ll> g_sum;

void inputData(const int n)
{
    g_sum = vector<ll>(n, 0);
    ll input;
    for(int i = 0; i < n; i++)
    {
        cin >> input;

        if(i != 0)
            g_sum[i] = g_sum[i-1] + input;
    }
}

void simulate(const int n)
{
    int k = 1;
    ll min_diff = numeric_limits<ll>::max();

    for(int cur_k = 1; cur_k <= (n/2); cur_k++)
    {
        for(int i = 0; i < n - 2 * cur_k; i++)
        {
            for(int j = i + cur_k; j < n - cur_k; j++)
            {
                ll cur_diff;
                if(cur_k == 1)
                    cur_diff = abs((g_sum[i+cur_k-1] - g_sum[i]) - (g_sum[j+cur_k-1] - g_sum[j]));
                
                else
                    cur_diff = abs(g_sum[i] - g_sum[j]);
                
                if(cur_diff < min_diff)
                {
                    min_diff = cur_diff;
                    k = cur_k;
                }
                else if(cur_diff == min_diff)
                    k = cur_k;
            }
        }
    }

    cout << k << "\n" << min_diff << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 배열 크기 n
    int n;
    cin >> n;

    inputData(n);
    simulate(n);
}