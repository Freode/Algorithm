// 골드 1 - 1311번 : 할 일 정하기 1
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N명 사람, N개 일
// 1명 당 1개 일을 해야 함.
// 모든 일을 하는데, 필요한 비용의 최솟값 구하기

// [현재 선택된 일의 정보(int)][현재 선택한 사람의 수?] = 현재 선택한 일의 값
// [문제 번호][현재 선택한 사람 번호] -> 최소값
// 20 * 10^6 = 20'000'000 -> 80MB

const int MAX_VALUE = numeric_limits<int>::max();

vector<vector<int>> g_works;
vector<vector<int>> g_dp;

// 일 정보 입력
void input(const int N)
{
    g_works = vector<vector<int>>(N, vector<int>(N, 0));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_works[i][j];
        }
    }

    g_dp = vector<vector<int>>(N, vector<int>(1 << N, MAX_VALUE));
}

// 정보 계산
int simulate(const int N, const int idx, const int work)
{
    // 마지막까지 계산을 완료한 경우
    if(N == idx)
        return 0;

    // 이미 방문한 경우는 바로 반환
    if(g_dp[idx][work] != MAX_VALUE)
        return g_dp[idx][work];

    int result = MAX_VALUE;

    // idx번 일을 특정 사람한테 주는 경우
    for(int i = 0; i < N; i++)
    {
        // 현재 해당 사람이 일하고 있지 않는 경우에만 진행
        if(work & (1 << i))
            continue;
            
        // 일 배정 시키기
        g_dp[idx][work] = min(g_dp[idx][work], g_works[i][idx] + simulate(N, idx + 1, (work | (1 << i))));
    }

    return g_dp[idx][work];
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 일의 수 N
    int N;
    cin >> N;

    input(N);
    int result = simulate(N, 0, 0);
    cout << result << "\n";

}
