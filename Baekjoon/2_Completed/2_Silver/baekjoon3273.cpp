// 실버 3 - 3273번 : 두 수의 합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 서로 다른 정수로 구성된 수열

vector<int> g_nums;

void inputData(const int n)
{
    g_nums = vector<int>(n);

    for(int& num : g_nums)
        cin >> num;

    sort(g_nums.begin(), g_nums.end());
}

int simulate(const int n, const int x)
{
    int result = 0;

    int start = 0, end = n-1;

    while(start < end)
    {
        int cur = g_nums[start] + g_nums[end];
        // 목표 값 
        if(cur == x)
        {
            result++;
            start++;
            end--;
        }
        // 목표보다 큰 경우
        else if(cur > x)
            end--;
        // 목표보다 작은 경우
        else
            start++;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 수열 크기 n
    int n;
    cin >> n;

    inputData(n);

    // 목표 값 x
    int x;
    cin >> x;

    cout << simulate(n, x) << "\n";
}