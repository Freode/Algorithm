// 골드 4 - 1988번 : 낮잠 시간
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2s / 128 MB
// 3 <= N <= 3000
// 2 <= B <= N
// 0 <= val <= 200'000

// B 개수
// 반복문 1~N
// M번째 -> [연속 여부][개수][M-1] = 최댓값으로부터 검사

// 현재 M번째
// 사용 O -> [1][개수-1][M-1]에서 더해서 가져오기 / [0][개수-1][M-1]에서 그냥 가져오기
// 사용 X -> [1][개수][M-1]에서 바로 가져오기 / [0][개수][M-1]에서 바로 가져오기

// 2 * 3000 * 3000 * 4 = 72MB
// 3000 * 3000 = 9'000'000 * 4?
// 200'000 * 3'000 = 600'000'000

vector<int> g_vals;
vector<vector<vector<int>>> g_temps;

void inputData(int N)
{
    g_vals = vector<int>(N);

    for(int& val : g_vals)
        cin >> val;
}

void calculate(int N, int B)
{
    g_temps = vector<vector<vector<int>>>(2, vector<vector<int>>(N, vector<int>(N, 0)));

    // i번째
    for(int i = 1; i < N; i++)
    {
        // 사용한 구간 개수별로 검사
        for(int j = 1; j < B; j++)
        {
            // 사용 O
            g_temps[1][j][i] = max(g_temps[0][j-1][i-1], g_temps[1][j-1][i-1] + g_vals[i]);

            // 사용 X
            g_temps[0][j][i] = max(g_temps[0][j][i-1], g_temps[1][j][i-1]);
        }
    }
}

int getResult(int N, int B)
{
    int result = 0;
    for(int i = 0; i < B; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            result = max(result, g_temps[j][i][N-1]);
        }
    }
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 개수 N, 구간 B
    int N, B;
    cin >> N >> B;

    inputData(N);
    calculate(N, B);
    cout << getResult(N, B) << "\n";

    return 0;
}