// 실버 1 - 1932번 : 정수 삼각형
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

// 이동 가능한 경로
// f[n][k] -> f[n+1][k]
// f[n][k] -> f[n+1][k+1]

// f[n][k] = max(f[n-1][k], f[n-1][k-1]) + f[n][k]
int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    vector<vector<int>> triangle(n, vector<int>(n, 0));
    int temp, max_value = 0;

    // 합이 최대가 되는 경로 구하기
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            // f[n][k] = max(f[n-1][k], f[n-1][k-1]) + f[n][k]
            cin >> temp;
            triangle[i][j] += temp;

            // 아래 층으로 대입하되, 더 큰 수를 기록
            // 마지막 층은 더 이상 내려갈 층이 없으므로 제외
            if(i != n - 1)
            {
                if(triangle[i + 1][j] < triangle[i][j])
                {
                    triangle[i + 1][j] = triangle[i][j];
                } 
                if(triangle[i + 1][j + 1] < triangle[i][j])
                {
                    triangle[i + 1][j + 1] = triangle[i][j];
                }
            }
            // 마지막 층에서는 경로에 대한 최댓값을 찾기
            else
            {
                if(max_value < triangle[i][j])
                {
                    max_value = triangle[i][j];
                }
            }
        }
    }
    // 출력
    cout << max_value << "\n";
}