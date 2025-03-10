// 골드 5 - 1916번 : 최소비용 구하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// 버스 정보 구조체
struct BusInfo
{
    int end = 0;
    int cost = 0;
    BusInfo() = default;
    BusInfo(int _end, int _cost) : end(_end), cost(_cost) {}

    bool operator<(const BusInfo& other) const
    {
        return cost < other.cost;
    }
};

// 버스로 연결된 도시 정보 구조체
struct CityInfo
{
    int costs = numeric_limits<int>::max();
    vector<BusInfo> buses;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시와 버스 개수 입력
    int N, M;
    cin >> N >> M;

    // 버스 정보 입력
    vector<CityInfo> cities(N+1);
    int in_start, in_end, in_cost;
    for(int i = 0; i < M; i++)
    {
        cin >> in_start >> in_end >> in_cost;
        cities[in_start].buses.push_back(BusInfo(in_end, in_cost));
    }

    // 출발지와 도착지 정보 입력
    int destination, departure;
    cin >> departure >> destination;

    // 출발지에서 시작해서 버스 노선 다 돌기
    priority_queue<BusInfo> pq;
    pq.push(BusInfo(departure, 0));
    cities[departure].costs = 0;

    while(pq.empty() == false)
    {
        BusInfo bus = pq.top();
        int start = bus.end;
        int cost = bus.cost;
        pq.pop();

        // 이미 거리가 더 짧은 경우이면, 무시
        if(cost > cities[start].costs) continue;

        for(BusInfo& each : cities[start].buses)
        {
            // 더 적은 비용으로 해당 도시로 이동할 때, 다시 검사
            if(each.cost + cost >= cities[each.end].costs) continue;

            cities[each.end].costs = each.cost + cost;
            pq.push(BusInfo(each.end, each.cost + cost));
        }
    }

    // 출력문
    cout << cities[destination].costs << "\n";
}

