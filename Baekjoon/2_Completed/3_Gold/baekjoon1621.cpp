// 골드 3 - 1621번 : 조삼모사
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N개 바나나
// 바나나 한 개 가져가기 -> 무게만큼 시간 소모
// 바나나 연속으로 K개 가져가기 -> 상수 C만큼 시간 소모

// N개 바나나를 모두 옮길 때, 걸리는 최소 시간
// 최소 시간이 같으면, K개를 들고 가는 횟수가 가장 적은 것 구하기

// == 출력 ==
// 1. 최소 시간
// 2. K개 들고 가는 횟수
// 3. K개 들고 가는 제일 왼쪽 위치를 오름차순으로 출력

// N 1~1'000'000
// N^2 = 10^6 * 10^6 = 10^12 -> byte -> kb -> mb -> gb -> 불가능

// 수 최대치 -> 10^6 * 10^3 = 10억(int)

// Top-Down -> 뒤에서부터 검사
// 존재하면, dp 배열에서 바로 꺼내서 사용
// 없으면, 추적
// 앞으로 한칸 또는 K개 연속으로 가져 가는 것, 둘 중 비용 더 저렴한 것으로 선택

const int MAX_VALUE = numeric_limits<int>::max();

struct Info
{
    int weight = 0;
    int time = MAX_VALUE;
};

vector<Info> g_dp;
vector<int> g_seqs;

// 정보 입력
void inputInfo(const int N)
{
    g_dp = vector<Info>(N+1);
    g_seqs.reserve(1'000);

    for(int i = 1; i <= N; i++)
    {
        cin >> g_dp[i].weight;
    }
    g_dp[0].time = 0;
}

// 해당 바나나까지 최소 비용으로 가져갈 경우 계산
int simulate(const int idx, const int N, const int K, const int C)
{
    // 이미 방문한 경우, 바로 반환
    if(g_dp[idx].time != MAX_VALUE)
        return g_dp[idx].time;

    // 한 칸 이동
    if(idx - 1 >= 0)
        g_dp[idx].time = min(g_dp[idx].time, simulate(idx - 1, N, K, C) + g_dp[idx].weight);

    // 여러 칸 한 번에 이동
    if(idx - K >= 0)
        g_dp[idx].time = min(g_dp[idx].time, simulate(idx - K, N, K, C) + C);

    return g_dp[idx].time;
}

void findSequence(const int N, const int K, const int C)
{
    int idx = N;

    while(idx > 0)
    {
        // 한 칸 앞으로 이동한 경우는 한 칸 앞으로 이동
        if(g_dp[idx].time - g_dp[idx-1].time == g_dp[idx].weight)
            idx--;

        // 한 칸 앞 x && 여러 칸을 이동한 경우는 여러 칸 앞으로 이동
        else
        {
            idx -= K;
            g_seqs.push_back(idx + 1);
        }
    }
}

void printResult(const int N)
{
    cout << g_dp[N].time << "\n";
    cout << g_seqs.size() << "\n";
    
    for(int i = g_seqs.size()-1; i >=0; i--)
    {
        cout << g_seqs[i] << " ";
    }
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // N개 바나나
    int N;
    cin >> N;

    // 연속 K개, 비용 C
    int K, C;
    cin >> K >> C;

    inputInfo(N);
    simulate(N, N, K, C);
    findSequence(N, K, C);
    printResult(N);

}