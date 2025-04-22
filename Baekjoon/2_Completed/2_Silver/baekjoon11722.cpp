// 실버 2 - 11722번 : 가장 긴 감소하는 부분 수열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_nums;
vector<int> g_dp;

void inputInfo(const int N)
{
    g_nums = vector<int>(N);
    g_dp = vector<int>(N, 0);

    for(int& each : g_nums)
        cin >> each;
}

int search(const int idx)
{
    int& ref = g_dp[idx];

    // 이미 계산한 경우가 있을 때, 미리 반환
    if(ref != 0)
        return ref;
        
    // 자기 자신도 포함
    ref = 1;

    // 자기보다 큰 값과 비교
    for(int i = idx-1; i >= 0; i--)
    {
        // 값이 커질수록 + 1
        if(g_nums[idx] < g_nums[i])
            ref = max(ref, search(i) + 1);
    }

    return ref;
}

// 시작점을 뒤에서부터 하나씩 다 돌기
int simulate(const int N)
{
    int result = 0;

    // 시작점
    for(int i = N-1; i >= 0; i--)
        result = max(result, search(i));

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수열 A 크기 N
    int N;
    cin >> N;

    inputInfo(N);
    cout << simulate(N) << "\n";
}