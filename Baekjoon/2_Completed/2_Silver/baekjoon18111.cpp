// 실버 2 - 18111번 : 마인크래프트
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

vector<vector<int>> g_area;

// 맵 입력
void inputArea(const int N, const int M)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> g_area[i][j];
        }
    }
}

// 현재 탐사 가능하다면, 비용이 얼마나 드는지 확인
int search(const int height, const int B)
{
    int result = 0;

    int y_size = g_area.size();
    int x_size = g_area[0].size();
    int inventory = B;
    for(int y = 0; y < y_size; y++)
    {
        for(int x = 0; x < x_size; x++)
        {
            int diff = height - g_area[y][x];
            // 쌓는 경우
            if(diff > 0)
            {
                inventory -= diff;
                result += diff;
            }
            // 제거하는 경우
            else
            {
                inventory += (-1)*diff;
                result += (-2)*diff;
            }
        }
    }
    // 인벤토리에 블럭 수는 항상 0 이상 유지해야 함
    if(inventory < 0) result = -1;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 N, 가로 M, 인벤토리 B
    int N, M, B;
    cin >> N >> M >> B;

    // 입력
    g_area = vector<vector<int>>(N, vector<int>(M));
    inputArea(N, M);

    int result_height = 0, result_time = numeric_limits<int>::max();
    for(int height = 0; height <= 256; height++)
    {
        int temp_time = search(height, B);

        // 가능한 높이 중 최소 시간이면서, 가장 높은 땅의 높이를 구하기
        if(temp_time <= result_time && temp_time != -1)
        {
            result_time = temp_time;
            result_height = height;
        }
    }

    cout << result_time << " " << result_height << "\n";
}