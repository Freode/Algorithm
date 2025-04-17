// 브론즈 1 - 2775번 : 부녀회장이 될테야
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a층 b호 사람 수 = (a-1)층 1호~b호까지 사람들 수
// 누적합으로 충분히 가능
// f(a,b) = f(a-1, b) + f(a, b-1)
// f(a-1, b) = 0층부터 a-2층까지 1호부터 b호까지 합
// f(a, b-1) = a-1층의 1호부터 b-1호까지의 합
// 0층 i호 = i명

// 14층 14호까지 존재

const int SIZE = 15;

vector<vector<int>> g_apart(SIZE, vector<int>(SIZE, 0));

void simulate()
{
    for(int y = 0; y < SIZE; y++)
    {
        for(int x = 1; x < SIZE; x++)
        {
            // 0층
            if(y == 0)
            {
                g_apart[0][x] = x;
                continue;
            }
            // 나머지 층
            g_apart[y][x] = g_apart[y-1][x] + g_apart[y][x-1];
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    simulate();

    for(int i = 0; i < T; i++)
    {
        // k층 n호
        int k, n;
        cin >> k >> n;

        cout << g_apart[k][n] << "\n";
    }
}