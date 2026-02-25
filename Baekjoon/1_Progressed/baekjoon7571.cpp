// 골드 5 - 15558번 : 점프 게임
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

// 격자 크기 N, 점 개수 M
// 모든 점을 한 곳으로 모을 때, 이동거리 최솟값

// 1 <= N <= 10'000
// 1 <= M <= 100'000

// 1초 , 256MB
// 10'000 * 10'000 * 100'000

// 10'000 * 100'000 = 10^9

// 1 2
// 1 4
// 3 1
// 4 2

// 1 2 -> 0, 2, 3, 3
// 1 4 -> 2, 0, 5, 5
// 3 1 -> 3, 4, 0, 2
// 4 2 -> 3, 5, 2, 0

// 9 9
// 2.25 2.25
// 2 2 -> 1, 3, 2, 2
// 1 2 -> 0, 2, 3, 3

// 5 7
// 2 3 -> 2, 2, 3
// 2 2 -> 1, 3, 2
// 1 2 -> 0, 2, 3

using namespace std;

vector<int> g_y;
vector<int> g_x;

void inputData(const int M)
{
    g_y = vector<int>(M, 0);
    g_x = vector<int>(M, 0);

    for(int i = 0; i < M; i++)
    {
        cin >> g_y[i] >> g_x[i];
    }
}

int simulate(const int M)
{
    sort(g_y.begin(), g_y.end());
    sort(g_x.begin(), g_x.end());

    int base_y = g_y[M >> 1];
    int base_x = g_x[M >> 1];

    int result = 0;
    for(int i = 0; i < M; i++)
    {
        result += abs(g_y[i] - base_y) + abs(g_x[i] - base_x);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 격자 크기 N, 점 개수 M
    int N, M;
    cin >> N >> M;

    inputData(M);
    cout << simulate(M) << "\n";
}