// 골드 5 - 14719번 : 빗물
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 고이는 빗물의 총량
// 세로 H, 가로 W -> 1 <= H,W <= 500
// 블록 높이 -> 0 <= h <= H
// 바닥은 막혀있음

// 한 칸의 용량은 1
// 비가 충분히 많이 올 때, 고이는 양을 생각

// 블록이 양쪽으로 막혀있을 때만 유효

// 4 8
// 3 1 2 3 4 1 1 2
//         1
// 1 0 0 1 1
// 1 0 1 1 1 0 0 1
// 1 1 1 1 1 1 1 1

// 한 줄마다 검사하면 될 듯?
// 500 * 500 => 250'000

vector<int> g_blocks;

void initData(const int W)
{
    g_blocks = vector<int>(W, 0);

    for(int& block : g_blocks)
        cin >> block;
}

int simulate(const int H, const int W)
{
    int result = 0;
    for(int height = 1; height <= H; height++)
    {
        int prev_idx = -1;

        for(int idx = 0; idx < W; idx++)
        {
            // 빗물 고이는지 판단
            if(g_blocks[idx] >= height)
            {
                // 처음으로 블록이 있음. (고이기 불가능)
                if(prev_idx == -1)
                {
                    prev_idx = idx;
                }
                // 양쪽으로 블록이 있음. (고이기 가능)
                else
                {
                    result += (idx - prev_idx - 1);
                    prev_idx = idx;
                }
            }
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 H, 가로 W
    int H, W;
    cin >> H >> W;

    initData(W);
    cout << simulate(H, W) << "\n";
}