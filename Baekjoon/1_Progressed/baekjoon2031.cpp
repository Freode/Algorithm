// 골드 2 - 2031번 : 이 쿠키 달지 않아!
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시간 1~10억 -> 투 포인터 불가능
// start -> 현재
// end -> upper_bound

// 마시는 타이밍 -> 음식을 먹는 타이밍
// [차 먹는 타이밍][차 먹은 횟수(10)] = 10^7 = 40'000'000 = 40MB

vector<int> g_times;
vector<vector<int>> g_dp;

// 음식 먹는 시간 입력
void inputInfo(const int N)
{
    g_times = vector<int>(N+1, 0);

    for(int i = 1; i <= N; i++)
        cin >> g_times[i];

    sort(g_times.begin(), g_times.end());

    g_dp = vector<vector<int>>(N+1, vector<int>(11, 0));
}

// 차를 마셨을 때, 언제까지 효과 있는지 확인
int search(const int idx, const int D)
{
    int left = 0, right = idx + 1;
    int mid;

    int standard = g_times[idx] - D;
    while(left + 1 < right)
    {
        mid = (left + right) >> 1;

        // 6 <=
        // 5 6 6 7 7 9 9 10
        // T T T T F F
        if(g_times[mid] <= standard)
            left = mid;
        else
            right = mid;
    }

    return right;
}

int simulate(const int N, const int D, const int K)
{
    for(int idx = 1; idx <= N; idx++)
    {
        int cur_cnt = search(idx, D);

        for(int count = 1; count <= K; count++)
        {
            
        }
    }
}



int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 시간 T, 음식 종류 N, 유지 시간 D, 횟수 K
    int T, N, D, K;
    cin >> T >> N >> D >> K;

}