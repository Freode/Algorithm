// 골드 3 - 1238번 : Silver Cow Party
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// cow가 놀고 끝날 때, 가장 짧은 시간을 소요해서 돌아가려고 함
// 하나의 소는 파티로 가는 길과 farm으로 돌아오는 길이 달라야 함.
// 다른 소끼리는 겹쳐도 괜춘?
// 가장 오래 걸린 시간 구하기

// 해당 노드로 다시 돌아기는 경우는 없음

// 도로 정보
struct Road
{
    int dest = 0;
    int cost = 0;

    // 우선순위 큐에서 비용 기준 오름차순 정렬
    bool operator<(const Road& other) const
    {
        return cost > other.cost;
    }
};

// 팜 정보
struct Farm
{
    int cost = numeric_limits<int>::max();
    int repeat_time = 0;
    vector<Road> roads;
};

vector<Farm> g_farms;

// 검사할 때 사용한 비용에 대한 초기화
void initFarms()
{
    for(Farm& farm : g_farms)
    {
        farm.cost = numeric_limits<int>::max();
    }
}

// 연결 정보에 대한 입력
void inputInfo(const int N, const int M)
{
    g_farms = vector<Farm>(N+1);
    
    int start, dest, cost;
    for(int i = 0; i < M; i++)
    {
        cin >> start >> dest >> cost;
        g_farms[start].roads.push_back(Road{dest, cost});
    }
}

// start에서 target까지 최소 비용 검사
int search(const int start, const int target)
{
    priority_queue<Road> pq;
    pq.push(Road{start, 0});
    g_farms[start].cost = 0;

    while(pq.empty() == false)
    {
        Road road = pq.top();
        pq.pop();

        // 도로별로 검사

    }
}

int simulate(const int N, const int X)
{
    for(int i = 1; i <= N; i++)
    {

    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // farm 수 N, 길의 수 M, 파티가 열리는 farm X
    int N, M, X;
    cin >> N >> M >> X;

    // 연결 정보에 대한 입력
    inputInfo(N, M);



}