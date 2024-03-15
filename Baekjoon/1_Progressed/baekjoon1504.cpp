// 골드 4 - 1504번 : 특정한 최단 경로
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

}