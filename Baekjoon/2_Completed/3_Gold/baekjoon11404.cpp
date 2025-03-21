// 골드 4 - 11404번 : 플로이드
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

const int MAX_COST = numeric_limits<int>::max();

// 버스 정보 구조체
struct Bus
{
    int dest = 0;
    int cost = 0;

    // 우선순위 큐에 비용 기준, 오름차순 정렬
    bool operator<(const Bus& other) const
    {
        return cost > other.cost;
    }
};

// 도시 정보 구조체
struct City
{
    int cost = MAX_COST;
    vector<Bus> buses;
};

vector<City> g_cities;

// 버스 정보 입력
void inputBusInfo(const int N, const int M)
{
    g_cities = vector<City>(N+1);

    // 버스 정보 입력
    for(int i = 0; i < M; i++)
    {
        int start;
        Bus bus;

        cin >> start >> bus.dest >> bus.cost;

        g_cities[start].buses.push_back(bus);
    }
}

// 도시 도달 비용 초기화
void initCities()
{
    int size = g_cities.size();

    for(int i = 1; i < size; i++)
    {
        g_cities[i].cost = MAX_COST;
    }
}

// 시뮬레이션
void simulate(const int start)
{
    // 시작점 추가 및,비용 처리
    g_cities[start].cost = 0;
    priority_queue<Bus> pq;
    pq.push({start, 0});

    // 시뮬레이션 시작
    while(pq.empty() == false)
    {
        Bus move = pq.top();
        pq.pop();

        // 현재 비용이 더 크면 같으면, 무시
        if(move.cost > g_cities[move.dest].cost) continue;

        // 도착지에서 갈 수 있는 다음 위치로 이동
        for(const Bus& bus : g_cities[move.dest].buses)
        {
            int cost = bus.cost + g_cities[move.dest].cost;
            // 비용이 더 저렴한 경우에만, 이동 적용 및 시뮬레이션 추가
            if(cost < g_cities[bus.dest].cost)
            {
                g_cities[bus.dest].cost = cost;
                pq.push({bus.dest, cost});
            }
        }
    }
}

// 결과 출력
void printResult()
{
    int size = g_cities.size();
    for(int i = 1; i < size; i++)
    {
        // 도달하지 못하는 경우는 0으로 교체
        if(g_cities[i].cost == MAX_COST) g_cities[i].cost = 0;

        cout << g_cities[i].cost << " ";
    }
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 도시 N, 버스 M
    int N, M;
    cin >> N >> M;

    // 버스 정보 입력
    inputBusInfo(N, M);

    // 출발지를 하나씩 설정해서 돌기
    for(int i = 1; i < N+1; i++)
    {
        // 시뮬레이션
        simulate(i);
        // 결과 출력
        printResult();
        // 도시 비용 도달 정보 초기화
        initCities();
    }
}