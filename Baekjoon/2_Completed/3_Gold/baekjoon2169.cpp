// 골드 2 - 2169번 : 로봇 조종하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 오른쪽으로만 이동
// 2. 왼쪽으로만 이동
// 두 가지 경우를 비교해서 최댓값을 구하기
// 3. 아래쪽으로 이동

vector<vector<int>> g_area;

void inputData(const int N, const int M)
{
    g_area = vector<vector<int>>(N, vector<int>(M, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> g_area[i][j];
        }
    }
}

void simulate(const int N, const int M)
{
    vector<int> left = vector<int>(M, 0);
    vector<int> right = vector<int>(M, 0);

    // 1번째 줄은 오른쪽으로만 이동 가능
    // 1줄 마지막 칸은 반드시 오른쪽 이동만 해야지 도착 가능
    for(int i = 1; i < M; i++)
    {
        g_area[0][i] += g_area[0][i-1];
    }

    // 2번째 줄부터 N번째 줄까지는 왼쪽과 오른쪽 모두 이동 가능
    for(int i = 1; i < N; i++)
    {
        // 현재 줄의 값으로 초기화
        for(int j = 0; j < M; j++)
        {
            left[j] = g_area[i][j];
            right[j] = g_area[i][j];
        }

        // 왼쪽으로만 이동, (위와 비교)
        left[0] += g_area[i-1][0];
        for(int j = 1; j < M; j++)
        {
            left[j] = max(left[j] + g_area[i-1][j], left[j] + left[j-1]);
        }

        // 오른쪽으로만 이동, (위와 비교)
        right[M-1] += g_area[i-1][M-1];
        for(int j = M-2; j >= 0; j--)
        {
            right[j] = max(right[j] + g_area[i-1][j], right[j] + right[j+1]);
        }

        // 두 방향으로 이동한 결과 중, 최댓값만 대입
        for(int j = 0; j < M; j++)
        {
            g_area[i][j] = max(left[j], right[j]);
        }
    }

    // 마지막에 도착했을 때의 최댓값 출력
    cout << g_area[N-1][M-1] << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 세로 N, 가로 M
    int N, M;
    cin >> N >> M;
    inputData(N, M);
    simulate(N, M);
}