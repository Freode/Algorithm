// 골드 3 - 11066번 : 파일 합치기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 파일을 합치자
// 2차원 배열
// [idx][합친 개수]
// 2~5 -> [5][3] -> 2~5까지 합친 최소의 파일 용량
// 뒤로 파일 하나씩 추가해서 확인하기

// 3 <= K <= 500
// 파일 크기 <= 10'000
// 테스트 케이스 T

// [1][6] = 1~6까지 합치기
// [1][2], [2][3], [3][4], [4][5], [5][6]
// [1][3], [2][4], [3][5], [4][6]
// [1][4], [2][5], [3][6]

// [1][5] = min([1][1]+[2][5], [1][2]+[3][5], [1][3]+[4][5], [1][4]+[5][5])

// 500 * 500 * 500 = 125'000'000

vector<int> g_files;
vector<int> g_sums;
vector<vector<int>> g_costs;

void initData(const int N)
{
    g_files = vector<int>(N + 1, 0);
    g_sums = vector<int>(N + 1, 0);
    g_costs = vector<vector<int>>(N + 1, vector<int>(N + 1, (numeric_limits<int>::max() >> 2)));

    for(int i = 1; i <= N; i++)
    {
        cin >> g_files[i];
        g_sums[i] = g_sums[i - 1] + g_files[i];
        g_costs[i][i] = 0;
    }
}

int simulate(const int N)
{
    // 합치는 파일 길이
    for(int len = 2; len <= N; len++)
    {
        for(int left = 1; left + len - 1 <= N; left++)
        {
            int right = left + len - 1;

            for(int cut = left; cut < right; cut++)
            {
                // 파일 합쳐지면서 발생하는 비용
                g_costs[left][right] = min(g_costs[left][right], g_costs[left][cut] + g_costs[cut + 1][right]);
            }

            // 해당 구간의 파일 합
            g_costs[left][right] += (g_sums[right] - g_sums[left - 1]);
        }
    }

    return g_costs[1][N];
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 개수 T, 파일 개수 N
    int T, N;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        cin >> N;
        initData(N);
        cout << simulate(N) << "\n";
    }
}