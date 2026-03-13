// 골드 4 - 25571번 : 지그재그 부분배열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// + - +
// - + -
// 1. 조건 만족 => 오른쪽 포인터 한 칸 이동
// 2. 조건 불만족 => 왼쪽 포인터 한 칸 이동(길이가 1일 경우 오른쪽 포인터도 이동)

// 1 <= T <= 10
// 1 <= n <= 100'000
// -10억 <= A[i] <= 10억
// 100'000 * 50'000 = 10만 * 5만 = 50억

vector<int> g_nums;

void initData(const int N)
{
        g_nums = vector<int>(N, 0);

        for(int& num : g_nums)
            cin >> num;
}

int getSign(int x)
{
    if(x > 0)
        return 1;
    if(x < 0)
        return -1;
    return 0;
}

long long simulate(const int N)
{
    long long result = 0;
    // 마지막 부호
    int last = 0;
    // 지그재그 길이
    int len = 1;

    for(int idx = 1; idx < N; idx++)
    {
        int diff = getSign(g_nums[idx] - g_nums[idx - 1]);

        // 같은 수 발견
        if(diff == 0)
        {
            len = 1;
            last = 0;
        }
        // 같은 방향 발견
        else if(diff == last)
        {
            len = 2;
            last = diff;
        }
        // 지그재그 발견
        else
        {
            ++len;
            last = diff;
        }

        result += (len - 1);
    }

    return result;
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

    for(int i = 0; i < T; i++)
    {
        // 개수 N
        int N;
        cin >> N;

        initData(N);
        cout << simulate(N) << "\n";
    }
}