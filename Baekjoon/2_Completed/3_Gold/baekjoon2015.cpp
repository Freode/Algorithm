// 골드 4 - 2015번 : 수들의 합 4
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <limits>

using namespace std;

// N : 200'000 * 100'000 => 2*10^10
// 200'000 * 10'000 = 10^9 * 2 < int

// S[i-1] = 1~[i-1]까지 합, S[j] = 1~[j]까지 합
// S[j] - S[i-1] = K -> 1개
// S[j]를 기준으로 앞에 있는 S[i-1]에 들어갈 i의 개수 구하기
// S[i-1] = S[j] - K
// 

vector<int> g_nums;
vector<int> g_sums;
unordered_map<int, int> g_counts;

const int MAX_VALUE = numeric_limits<int>::max();
const int MIN_VALUE = numeric_limits<int>::min();

using ll = long long;

void inputData(const int N)
{
    g_nums = vector<int>(N);
    g_sums = vector<int>(N);

    for(int i = 0; i < N; i++)
    {
        cin >> g_nums[i];

        g_sums[i] = g_nums[i];
        if(i != 0)
            g_sums[i] += g_sums[i-1];
    }
}

ll simulate(const int N, const int K)
{
    int start = 0, end = 0;
    ll result = 0;
    
    // 음수도 있어서 윈도우 슬라이싱 불가능
    for(int i = 0; i < N; i++)
    {
        ll diff = g_sums[i] - K;
        if(diff > MAX_VALUE || diff < MIN_VALUE)
            continue;

        // 0~i-1까지 구간에 대해서 추가 가능
        if(g_sums[i] == K)
            result++;

        // 이전 구간에 대해 같은 수가 있는 경우 추가
        result += g_counts[diff];

        // 다음 구간에서는 현재 구간(0~i-1까지 합)도 이전 구간으로 취급하므로, 추가
        g_counts[g_sums[i]]++;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 배열 크기 N, 목표 K
    int N, K;
    cin >> N >> K;

    inputData(N);
    cout << simulate(N, K) << "\n";
}