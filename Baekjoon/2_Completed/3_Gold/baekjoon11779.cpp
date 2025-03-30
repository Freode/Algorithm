// 골드 3 - 11779번 : 최소비용 구하기 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>
#include <stack>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

struct Bus
{
    int dest = 0;
    int cost = 0;

    // 우선순위 큐에서 비용 기준 오름차순
    bool operator<(const Bus& other) const
    {
        return cost > other.cost;
    }
};

struct City
{
    int prev = 0;
    int cost = MAX_VALUE;
    vector<Bus> buses;
};

vector<City> g_cities;

// 버스 정보 입력
void inputBus(const int M)
{
    int start, end, cost;
    for(int i = 0; i < M; i++)
    {
        cin >> start >> end >> cost;
        g_cities[start].buses.push_back({end, cost});
    }
}

// 이동 시뮬레이션
int simulate(const int start, const int end)
{
    int result = 0;

    priority_queue<Bus> pq;
    pq.push({start, 0});
    g_cities[start].cost = 0;

    // 검사
    while(pq.empty() == false)
    {
        Bus move = pq.top();
        pq.pop();

        // 현재 이동한 비용이 기존보다 더 비싸면, 무시
        if(move.cost > g_cities[move.dest].cost) continue;

        // 버스별로 검사
        for(const Bus& bus : g_cities[move.dest].buses)
        {
            // 이동했을 때, 기존 비용이 더 저렴하면, 무시
            if(bus.cost + move.cost >= g_cities[bus.dest].cost) continue;

            g_cities[bus.dest].cost = bus.cost + move.cost;
            g_cities[bus.dest].prev = move.dest;
            pq.push({bus.dest, g_cities[bus.dest].cost});
        }
    }

    result = g_cities[end].cost;
    return result;
}

// 도착지까지 도시 개수와 경로 출력
void printPath(const int end)
{
    int target = end;
    stack<int> path;
    int count = 0;
    while(target != 0)
    {
        path.push(target);
        target = g_cities[target].prev;
        count++;
    }

    cout << count << "\n";
    while(path.empty() == false)
    {
        cout << path.top() << " ";
        path.pop();
    }
    cout << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 도시 개수 N, 버스 개수 M
    int N, M;
    cin >> N >> M;

    g_cities = vector<City>(N+1);

    // 버스 정보 입력
    inputBus(M);

    int start, end;
    cin >> start >> end;

    // 이동 시뮬레이션
    cout << simulate(start, end) << "\n";

    // 도착지까지 도시 개수와 경로 출력
    printPath(end);
}