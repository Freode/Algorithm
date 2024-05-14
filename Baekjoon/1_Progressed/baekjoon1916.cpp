// 골드 5 - 1916번 : 최소비용 구하기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 버스 정보 구조체
struct BusInfo
{
    int start = 0;
    int end = 0;
    int cost = 0;
    BusInfo(){}
    BusInfo(int _start, int _end, int _cost){ start = _start; end = _end; cost = _cost; }
};


// 버스로 연결된 도시 정보 구조체
struct CityInfo
{
    int costs = 0;
    vector<BusInfo> buses;
    bool b_is_in_queue = false;
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
    vector<CityInfo> cities(N);
    BusInfo tempBus;
    for(int i = 0; i < M; i++)
    {
        cin >> tempBus.start >> tempBus.end >> tempBus.cost;
        cities[tempBus.start].buses.push_back(tempBus);
    }

    // 출발지와 도착지 정보 입력
    int destination, departure;
    cin >> departure >> destination;

    // 출발지에서 시작해서 버스 노선 다 돌기
    queue<int> queue;
    int currentCity = departure;
    queue.push(currentCity);

    while(queue.empty() == false)
    {
        currentCity = queue.front();
        cities[currentCity].b_is_in_queue = false;
        for(BusInfo& each : cities[currentCity].buses)
        {
            // 더 적은 비용으로 해당 도시로 이동할 때, 다시 검사
            if(cities[currentCity].costs + each.cost < cities[each.end].costs || cities[each.end].costs == 0)
            {
                // 더 적은 비용으로 업데이트
                cities[each.end].costs = cities[currentCity].costs + each.cost;
                // queue에 중복해서 넣지 않기
                if(cities[each.end].b_is_in_queue == false)
                {
                    cities[each.end].b_is_in_queue = true;
                    queue.push(each.end);
                }
            }
        }
        queue.pop();
    }

    // 출력문
    cout << cities[destination].costs << "\n";
}

