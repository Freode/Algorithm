// 골드 1 - 1884번 : 고속도로
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

// 정해진 예산으로 집으로 돌아갈 수 있는지 확인
// 불가능 : -1
// 가능 : 최단 이동 거리

// 교통비 : 0~10'000
// 도시 : 2~100
// 도로 개수 : 1~10'000
// 출발 -> 도착, 도로 길이(1~100), 통행료 0~100
// 1번 도시에서 출발, N번 도시에 도착
// 서로 다른 두 도로가 같은 출발지와 도착지를 가질 수 있음

// [도시][현재 비용] = 거리
// 거리 기준으로 우선순위 큐 진행

const int MAX_VALUE = numeric_limits<int>::max() >> 2;

struct Road
{
    int dest = 0;
    int len = 0;
    int cost = 0;

    // 우선순위 큐에서 거리 기준 오름차순 정렬
    bool operator<(const Road& other) const
    {
        return len > other.len;
    }
};

struct City
{
    vector<int> lens;
    vector<Road> roads;

    City()
    {
        lens = vector<int>(10'001, MAX_VALUE);
    }
};

vector<City> g_cities;

void initAndInputData(const int N, const int R)
{
    g_cities = vector<City>(N+1);

    int start, dest, length, cost;
    for(int i = 0; i < R; i++)
    {
        cin >> start >> dest >> length >> cost;

        g_cities[start].roads.push_back({dest, length, cost});
    }
}

void simulate(const int N, const int K)
{
    priority_queue<Road> pq;
    pq.push({1, 0, 0});
    g_cities[1].lens[0] = 0;

    while(pq.empty() == false)
    {
        Road cur = pq.top();
        pq.pop();

        //cout << cur.dest << " " << cur.len << " " << cur.cost << "\n";

        // 현재 도시에의 거리가 지금 검사하는 거리와 일치하는 경우에만 진행
        if(cur.len > g_cities[cur.dest].lens[cur.cost])
            continue;

        // 현재 도시에서 연결된 도로 모두 검사
        for(const Road& road : g_cities[cur.dest].roads)
        {
            int cost = cur.cost + road.cost;
            int len = cur.len + road.len;

            // 비용이 현재 소지한 값보다 넘어가는 경우는 무시
            if(cost > K)
                continue;

            // 다음으로 이동할 도시와 현재 비용을 기준으로 더 거리가 짧지 않은 경우는 무시
            if(g_cities[road.dest].lens[cost] <= len)
                continue;

            g_cities[road.dest].lens[cost] = len;

            // 다음으로 이동할 도시가 도착지인 경우는 추가 x
            if(road.dest == N)
                continue;

            pq.push({road.dest, len, cost});
        }
    }
}

int getResult(const int N)
{
    int result = MAX_VALUE;
    for(const int& len : g_cities[N].lens)
    {
        result = min(result, len);
    }

    // 불가능한 경우
    if(result == MAX_VALUE)
        result = -1;

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 교통비 K, 도시 숫자 N, 도로 숫자 R
    int K, N, R;
    cin >> K >> N >> R;

    initAndInputData(N, R);
    simulate(N, K);
    cout << getResult(N) << "\n";
}