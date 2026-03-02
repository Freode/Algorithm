// 골드 4 - 11657번 : 타임머신
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

// N개 도시, M개 버스
// 시작 도시(A), 도착 도시(B), 버스를 타고 이동하는데 걸리는 시간(C)
// C = 0 : 순간 이동
// C < 0 : 타임머신으로 시간이 되돌아감

// 1번 도시에서 출발해 나머지 도시로 가는 가장 빠른 시간 구하기
// 어떤 도시로 가는 과정에서 시간을 무한히 오래전으로 되돌린다면, -1로 출력
// 그냥 무한 루프발생하면 -1
// 그렇지 않다면 각 줄마다 가는 가장 빠른 시간 순서대로 출력
// 해당 도시로 가는 경로가 없으면, 해당 도시만 -1

const long long MAX_VALUE = numeric_limits<int>::max();

struct Bus
{
    int start = -1;
    int end = -1;
    int cost = 0;
};

vector<Bus> g_buses;
vector<long long> g_cities;

void initData(const int N, const int M)
{
    g_cities = vector<long long>(N + 1, MAX_VALUE);
    g_buses = vector<Bus>(M);

    for(Bus& bus : g_buses)
    {
        cin >> bus.start >> bus.end >> bus.cost;
    }
}

void simulate(const int N)
{
    // 시작점
    g_cities[1] = 0;

    // N-1번 반복 : 1~N까지의 최단 거리 중에서 최대의 간선 개수는 N-1개
    for(int i = 1; i <= N - 1; i++)
    {
        // 모든 간선 확인
        for(const Bus& bus : g_buses)
        {
            // 아직 시작점에 아무런 경로가 들어오지 않음.
            if(g_cities[bus.start] == MAX_VALUE)
                continue;

            // 새로운 최단 거리 발견
            g_cities[bus.end] = min(g_cities[bus.end], g_cities[bus.start] + bus.cost);
        }
    }
}

void printResult(const int N)
{
    // 음수 사이클을 먼저 확인
    for(const Bus& bus : g_buses)
    {
        if(g_cities[bus.start] == MAX_VALUE)
            continue;

        // N-1번째에서 최단 거리를 검사했는데, N번째에서도 줄어들고 있음.
        if(g_cities[bus.end] > g_cities[bus.start] + bus.cost)
        {
            cout << "-1\n";
            return;
        }
    }

    for(int i = 2; i <= N; i++)
    {
        if(g_cities[i] == MAX_VALUE)
            cout << "-1\n";
        else
            cout << g_cities[i] << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // N개 도시, M개 버스
    int N, M;
    cin >> N >> M;

    initData(N, M);
    simulate(N);
    printResult(N);
}
