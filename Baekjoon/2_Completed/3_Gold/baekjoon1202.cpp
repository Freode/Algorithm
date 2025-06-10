// 골드 2 - 1202번 : 보석 도둑
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 보석, 가방 개수 1~300'000

// 보석 정보 M, V (0~1'000'000)
// 가방에 담을 수 있는 최대 무게 C (1~100'000'000)
// 가방에는 하나의 보석만 넣을 수 있음.

// 보석 -> 무게 기준으로 오름차순
// 가방 -> 용량 기준으로 오름차순
// 무게로 현재 가방에 넣을 수 있는 보석을 탐색해, 가장 가치가 높은 보석을 넣기

using ll = long long;

struct Jewel
{
    int weight = 0;
    int value = 0;
};

vector<Jewel> g_jewel;
vector<int> g_bag;
priority_queue<int> g_pq;
int g_jewel_idx = 0;

// 정보 입력
void inputInfo(const int N, const int K)
{
    g_jewel.reserve(N);
    g_bag.reserve(N);

    // 보석 정보 입력
    int m, v;
    for(int i = 0; i < N; i++)
    {
        cin >> m >> v;
        g_jewel.push_back({m, v});
    }

    // 가방 정보 입력
    for(int i = 0; i < K; i++)
    {
        cin >> v;
        g_bag.push_back(v);
    }
}

int putJewel(const int N, const int bag_idx)
{
    // 현재 가방에 추가로 넣을 수 있는 보석이 있는 경우, 우선순위 큐에 추가
    while(g_jewel_idx < N && g_jewel[g_jewel_idx].weight <= g_bag[bag_idx])
    {
        g_pq.push(g_jewel[g_jewel_idx].value);
        g_jewel_idx++;
    }

    // 우선순위 큐 중 가치가 가장 높은 보석 하나를 현재 가방에 추가
    // 만약에 추가할 수 있는 보석이 없으면, 0을 반환
    if(g_pq.empty() == true)
        return 0;

    int cur = g_pq.top();
    g_pq.pop();

    return cur;
}

ll simulate(const int N, const int K)
{
    // 가방 - 용량 기준 오름차순
    sort(g_bag.begin(), g_bag.end());
    // 보석 - 무게 기준 오름차순
    sort(g_jewel.begin(), g_jewel.end(), [](const Jewel& a, const Jewel& b)
    {
        return a.weight < b.weight;
    });

    // 모든 가방에 보석 넣을 수 있는지 검사
    ll result = 0;
    for(int i = 0; i < K; i++)
        result += putJewel(N, i);

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 보석 개수 N, 가방 개수 k
    int N, K;
    cin >> N >> K;

    inputInfo(N, K);
    cout << simulate(N, K) << "\n";
}