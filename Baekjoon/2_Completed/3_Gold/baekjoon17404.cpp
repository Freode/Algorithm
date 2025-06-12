// 골드 4 - 17404번 : RGB거리 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// i번째 집은 앞의 집과 뒤의 집과의 지붕 색이 다름
// 단, i-1번째 집과 i+1번째 집은 지붕 색이 같아도 됨.

const int MAX_VALUE = numeric_limits<int>::max();

vector<vector<int>> g_colors;
vector<vector<int>> g_dps;

void inputData(const int N)
{
    g_colors = vector<vector<int>>(N, vector<int>(3, 0));
    g_dps = vector<vector<int>>(N, vector<int>(3, 0));

    for(int i = 0; i < N; i++)
    {
        cin >> g_colors[i][0] >> g_colors[i][1] >> g_colors[i][2];
    }
}

int simulate(const int N)
{
    vector<int> selects(3, 0);
    int result = MAX_VALUE;
    // 1번째 줄을 어떤 색으로 선택할지 결정
    for(int color = 0; color < 3; color++)
    {
        // 첫 번째 집에 대해 수 입력
        for(int i = 0; i < 3; i++)
        {
            if(color == i)
                g_dps[0][i] = g_colors[0][i];
            // 선택되지 않는 집은 큰 값으로 설정
            else
                g_dps[0][i] = 15000;
        }

        // 2번째 줄부터 n번째 줄 검사 시작
        for(int i = 1; i < N; i++)
        {
            // 0
            g_dps[i][0] = g_colors[i][0] + min(g_dps[i-1][1], g_dps[i-1][2]);
            // 1
            g_dps[i][1] = g_colors[i][1] + min(g_dps[i-1][0], g_dps[i-1][2]);
            // 2
            g_dps[i][2] = g_colors[i][2] + min(g_dps[i-1][0], g_dps[i-1][1]);
        }

        // 현재 첫 번째로 선택한 집과 비교해서 최솟값 결과 확인
        for(int i = 0; i < 3; i++)
        {
            // 마지막 줄과 첫 번째 줄이 같은 선택이면, 무시
            if(color == i)
                continue;

            result = min(result, g_dps[N-1][i]);
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 집 N
    int N;
    cin >> N;

    inputData(N);
    cout << simulate(N) << "\n";
}