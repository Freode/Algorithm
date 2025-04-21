// 골드 1 - 2098번 : 외판원 순회
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

vector<vector<int>> g_cities;
vector<vector<int>> g_dp;

// 각 도시 방문 정보 [방문 도시 번호][이동 경로(2^16)] = 최소 이동 비용
// 2^16 < 10^5 => 10만개 * 20개 = 2'000'000 -> 8MB

// 시간 복잡도 : 10만 * 2?

// 각 성분 최대값 : 1'000'000 => * 20 = 2천만

// 아래 코드 반례 : 해당 도시에서 출발지를 제외하고 이동할 수 없는 경우 -> max값으로 반환되어 오류 발생

// 도시 정보 입력
void inputInfo(const int N)
{
    g_cities = vector<vector<int>>(N, vector<int>(N));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_cities[i][j];
        }
    }

    g_dp = vector<vector<int>>(N, vector<int>(1 << N, MAX_VALUE));
}

// 시뮬레이션
int simulate(const int N, const int num, const int visit, const int cur)
{
    // 모든 도시를 방문한 경우, 출발지로 이동하는 비용 반환
    // 단, 출발지로 이동하지 못하는 경우에는 큰 수를 둬 제한
    if(N == num)
        return g_cities[cur][0] == 0 ? 1'000'000'000 : g_cities[cur][0];

    int& ref = g_dp[cur][visit];

    // 이미 해당 경우를 검사한 경우에는 반환
    if(ref != MAX_VALUE)
        return ref;

    // 해당 경로로 방문하지 않은 경우는 추가 검사
    for(int i = 0; i < N; i++)
    {
        // 이미 해당 도시를 방문한 경우
        if(visit & (1 << i))
            continue;
        
        // 갈 수 없는 경우 무시
        if(g_cities[cur][i] == 0)
            continue;

        // 비용이 더 적은 경로로 탐색
        ref = min(ref, g_cities[cur][i] + simulate(N, num+1, visit | (1 << i), i));
    }

    return ref == MAX_VALUE ? 1'000'000'000 : ref;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 도시 개수 N
    int N;
    cin >> N;

    inputInfo(N);

    // 출발 도시는 방문되었다고 처리
    cout << simulate(N, 1, 1, 0) << "\n";
}