// 골드 2 - 12738번 : 가장 긴 증가하는 부분 수열 3
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2번과 달리 음수가 존재

vector<int> g_nums;
vector<int> g_longest;

void inputInfo(const int N)
{
    g_nums = vector<int>(N);
    g_longest.reserve(N);

    for(int& each : g_nums)
        cin >> each;
}

void search(const int idx)
{
    // 비어 있거나, 맨 뒤에 있는 값보다 큰 경우에는 바로 추가
    if(g_longest.empty() || g_longest.back() < g_nums[idx])
    {
        g_longest.push_back(g_nums[idx]);
        return;
    }

    // 맨 앞에 있는 값보다 작으면, 맨 앞에 값을 변경
    if(g_longest.front() >= g_nums[idx])
    {
        g_longest[0] = g_nums[idx];
        return;
    }

    // 변경할 위치를 탐색해서 변경
    int start = 0, end = g_longest.size();
    int mid;

    while(start + 1 < end)
    {
        mid = (start + end) >> 1;

        // 작은 값은 T, 크거나 같은 값은 F

        // 작으면, 시작값을 증가시켜야 함.
        if(g_longest[mid] < g_nums[idx])
            start = mid;

        // 크거나 같으면, 종료값을 감소시켜야 함.
        else
            end = mid;
    }
    // F의 첫 번째에 변경
    g_longest[end] = g_nums[idx];

    return;
}

// 시작점부터 돌기
int simulate(const int N)
{
    int result = 0;

    // 시작점
    for(int i = 0; i < N; i++)
    {
        search(i);
        result = max(result, (int)g_longest.size());
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 수열 A 크기 N
    int N;
    cin >> N;

    inputInfo(N);
    cout << simulate(N) << "\n";
}