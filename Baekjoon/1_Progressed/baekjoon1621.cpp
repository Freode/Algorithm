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

const int MAX_VALUE = numeric_limits<int>::max();

struct Best
{
    int prev = 0;
    int best_time = 0;
};

struct Info
{
    int time = 0;
    vector<Best> bests;
    
    Info()
    {
        bests.reserve(10'000);
        bests.push_back({0, 0});
    }
};

vector<Info> g_infoes;

// 바나나 정보 입력
void inputInfo(const int N)
{
    g_infoes = vector<Info>(N+1);

    for(int i = 1; i <= N; i++)
    {
        cin >> g_infoes[i].time;
        g_infoes[i].bests[0].best_time = g_infoes[i-1].bests[0].best_time + g_infoes[i].time;
    }
}

// 시뮬레이션 시작
void simulate(const int N, const int K, const int C)
{
    for(int i = 1; i <= N; i++)
    {
        for(int count = 1; count < g_infoes[i].bests.size(); count++)
        {
            // 연속으로 가져온 경우 & 그냥 가져온 경우 비교
            int seq = g_infoes[i-K].bests[count-1].best_time + C;
            
            // 그냥 가져올 수 있는지 확인
            int one = MAX_VALUE;
            if(g_infoes[i-1].bests.size() > count)
                one = g_infoes[i-1].bests[count].best_time + g_infoes[i].time;
            
            // 연속으로 가져오는 경우면, prev를 기록
            if(seq < one)
                g_infoes[i].bests[count] = {seq, i-K+1};

            else
                g_infoes[i].bests[count] = {one, 0};
        }
        // 마지막에, 연속 K개 한꺼번에 가져온 경우 비교
        if(i >= K)
        {
            int size = g_infoes[i-K].bests.size();
            g_infoes[i].bests.push_back({i-K+1, g_infoes[i-K].bests[size-1].best_time + C});
        }
    }
}

void printResult(const int N)
{
    int count = 0;
    int times = MAX_VALUE;

    for(int idx = 0; idx < g_infoes[N].bests.size(); idx++)
    {
        //cout << "idx : " << idx << ", time : " << g_infoes[N].bests[idx].best_time << "\n";
        if(times > g_infoes[N].bests[idx].best_time)
        {
            count = idx;
            times = g_infoes[N].bests[idx].best_time;
        }
    }

    cout << times << "\n";
    cout << count << "\n";

    // 연속으로 담는 바나나 index 추적해서 출력
    vector<int> prevs;
    for(int idx = N; idx > 0; idx--)
    {
        int prev = g_infoes[idx].bests[count].prev;
        if(prev != 0)
        {
            prevs.push_back(prev);
            count--;
            idx = prev;
        }
    }
    for(int i = prevs.size()-1; i >= 0; i--)
        cout << prevs[i] << " ";
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

    // 
    inputInfo(N);

    simulate(N, K, C);

    printResult(N);
}