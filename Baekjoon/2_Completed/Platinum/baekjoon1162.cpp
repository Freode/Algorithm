// 플레티넘 5 - 1162번 : 도로포장
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

// 도시 수 1~10'000
// 도로 수 1~50'000
// 포장 도로 수 1~20
// 걸리는 시간 1~1'000'000

// 도로 : 양방향 도로

// [도시][포장 도로 개수] = 걸리는 시간
// K개 이하의 도로를 포장해 얻을 수 있는 최소 시간 구하기

// 1번 도시(출발) -> N번 도시(도착)

// 최댓값 : 10'000 * 1'000'000 = 10^4 * 10^6 = 10^10

using ll = long long;

const ll MAX_VALUE = ((ll)numeric_limits<int>::max()) << 3;

struct Road
{
    int dest = 0;
    ll time = 0;
    int counts = 0;

    bool operator<(const Road& other) const
    {
        return time > other.time;
    }
};

struct City
{
    vector<ll> times;
    vector<Road> roads;

    City()
    {
        roads.reserve(30);
        times = vector<ll>(21, MAX_VALUE);
    }
};

vector<City> g_cities;

void initAndInputData(const int N, const int M)
{
    g_cities = vector<City>(N+1);

    int start, end, time;
    for(int i = 0; i < M; i++)
    {
        cin >> start >> end >> time;

        g_cities[start].roads.push_back({end, time});
        g_cities[end].roads.push_back({start, time});
    }
}

void simulate(const int N, const int K)
{
    priority_queue<Road> pq;
    pq.push({1, 0, 0});
    g_cities[1].times[0] = 0;

    while(pq.empty() == false)
    {
        Road cur = pq.top();
        pq.pop();

        // 현재 검사하려는 도시 도착 시간이 기존보다 크다면, 무시
        if(g_cities[cur.dest].times[cur.counts] < cur.time)
            continue;

        // 연결된 도로를 모두 검사
        for(const Road& road : g_cities[cur.dest].roads)
        {
            ll next_time = cur.time + road.time;
            int next_count = cur.counts + 1;

            // 해당 도시에 도착하는 비용이 현재보다 저렴한 경우 추가
            if(next_time < g_cities[road.dest].times[cur.counts])
            {
                g_cities[road.dest].times[cur.counts] = next_time;
                pq.push({road.dest, next_time, cur.counts});  
            }

            // 현재 도로를 포장했을 때, 현재보다 저렴한 경우 추가
            if(next_count <= K && cur.time < g_cities[road.dest].times[next_count])
            {
                g_cities[road.dest].times[next_count] = cur.time;
                pq.push({road.dest, cur.time, next_count});
            }
        }
    }
}

ll getResult(const int N)
{
    ll result = MAX_VALUE;

    for(const ll& time : g_cities[N].times)
    {
        result = min(result, time);
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시 수 N, 도로 수 M, 포장 도로 수 K
    int N, M, K;
    cin >> N >> M >> K;

    initAndInputData(N, M);
    simulate(N, K);
    cout << getResult(N) << "\n";
}