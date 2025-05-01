// 골드 2 - 2031번 : 이 쿠키 달지 않아!
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시간 1~10억 -> 투 포인터 불가능
// start -> 현재
// end -> upper_bound

// 마시는 타이밍 -> 음식을 먹는 타이밍
// [차 먹는 타이밍][차 먹은 횟수(10)] = 10^7 = 40'000'000 = 40MB

vector<int> g_times;
vector<vector<int>> g_dp;

// 음식 먹는 시간 입력
void inputInfo(const int N)
{
    g_times = vector<int>(N+1, 0);

    for(int i = 1; i <= N; i++)
        cin >> g_times[i];

    sort(g_times.begin(), g_times.end());

    g_dp = vector<vector<int>>(N+1, vector<int>(11, 0));
}

// 차를 마셨을 때, 언제까지 효과 있는지 확인
int search(const int idx, const int D)
{
    int left = 0, right = idx + 1;
    int mid;

    // 0 5 6 6 7 7 9 9 10
    // 5가 들어옴 2에 마심 D = 3
    // F T  

    // 6 -> 3에 마심
    // F T T T

    // 9 -> 6에 마심
    // F T T T T T T F
    // 0 8

    // 유지 시작 시간은 현재 시간도 포함되어야 하므로 +1
    int standard = g_times[idx] - D + 1;

    // 0 1 2 3 4 5 6 7
    // 5 - 4 + 1 = 2

    while(left + 1 < right)
    {
        mid = (left + right) >> 1;

        if(g_times[mid] < standard)
            left = mid;
        else
            right = mid;
    }

    return right;
}

int simulate(const int N, const int D, const int K)
{
    int result = 0;
    // 처음부터 검사
    for(int idx = 1; idx <= N; idx++)
    {
        // 현재부터 - D 시간에서 차를 마셨을 때, 효과를 볼 수 있는 시간의 시작 지점 찾기
        int start = search(idx, D);

        // 현실적으로 가능한 잔 수까지 검사
        int times = min(idx, K);
        for(int count = 1; count <= times; count++)
        {
            // 새롭게 잔을 먹은 경우와 먹지 않는 경우 비교, 새로운 잔은 현재 위치 바로 직전을 기준으로 추가 쿠키 계산
            g_dp[idx][count] = max(g_dp[idx-1][count], g_dp[start-1][count-1] + (idx - start + 1));
            result = max(result, g_dp[idx][count]);
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시간 T, 음식 종류 N, 유지 시간 D, 횟수 K
    int T, N, D, K;
    cin >> T >> N >> D >> K;

    inputInfo(N);
    cout << simulate(N, D, K) << "\n";
}