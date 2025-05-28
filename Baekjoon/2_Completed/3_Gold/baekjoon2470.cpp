// 골드 5 - 2470번 : 두 용액
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 산성 1~10억
// 알칼리성 -1~-10억
// 두 용액 혼합해서 특성값의 합으로 정의
// 0에 가장 가까운 용액 만들기

// 되는 경우 아무거나 출력
// 오름차순으로 출력

const int MAX_VALUE = numeric_limits<int>::max();

vector<int> g_nums;

void inputData(const int N)
{
    g_nums = vector<int>(N);

    for(int& num : g_nums)
        cin >> num;

    sort(g_nums.begin(), g_nums.end());
}

void simulate(const int N)
{
    int start = 0, end = N-1;
    int sum = MAX_VALUE;
    int first = 0, second = 0;

    while(start < end)
    {
        int cur = g_nums[start] + g_nums[end];

        // 합이 0에 더 가까운 값이 나온 경우
        if(abs(cur) < abs(sum))
        {
            sum = cur;
            first = start;
            second = end;
        }

        // 합이 0보다 큰 경우, 감소
        if(cur > 0)
            end--;
        // 합이 0보다 작은 경우, 증가
        else if(cur < 0)
            start++;
        // 합이 0인 경우
        else
            break;
    }

    cout << g_nums[first] << " " << g_nums[second] << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 용액 수 N
    int N;
    cin >> N;

    inputData(N);
    simulate(N);
}