// 골드 4 - 14002번 : 가장 긴 증가하는 부분 수열 4
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_nums;
vector<int> g_dp;
vector<int> g_path;

void inputInfo(const int N)
{
    g_nums = vector<int>(N);
    g_dp = vector<int>(N, 0);
    g_path = vector<int>(N, -1);

    for(int& each : g_nums)
        cin >> each;
}

int search(const int idx)
{
    int& ref = g_dp[idx];

    // 이미 계산한 경우가 있을 때, 미리 반환
    if(ref != 0)
        return ref;
        
    // 자기 자신도 포함
    ref = 1;

    // 자기보다 작은 값과 비교
    for(int i = idx-1; i >= 0; i--)
    {
        // 값이 작아질수록 더하기
        if(g_nums[idx] > g_nums[i])
        {
            int result = search(i) + 1;

            // 새로운 경로가 값이 더 많을 때, 갱신
            if(ref < result)
            {
                ref = result;
                g_path[idx] = i;
            }
        }
    }

    return ref;
}

// 경로 추적
void printPath(const int start)
{
    // 경로 결과값 추가
    vector<int> path;
    path.reserve(start);

    int idx = start;
    while(idx >= 0)
    {
        path.push_back(g_nums[idx]);
        idx = g_path[idx];
    }

    // 반전 후, 출력
    for(int i = path.size()-1; i >= 0; i--)
    {
        cout << path[i] << " ";
    }
    cout << "\n";
}

// 시작점을 뒤에서부터 하나씩 다 돌기
void simulate(const int N)
{
    int result = 0;
    int start = 0;

    // 시작점
    for(int i = N-1; i >= 0; i--)
    {
        int temp = search(i);
        if(result < temp)
        {
            result = temp;
            start = i;
        }
    }

    // 결과 출력
    cout << result << "\n";
    printPath(start);
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
    simulate(N);
}