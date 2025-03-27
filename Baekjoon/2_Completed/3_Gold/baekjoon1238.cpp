// 골드 3 - 1238번 : Silver Cow Party
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits>

using namespace std;

// cow가 놀고 끝날 때, 가장 짧은 시간을 소요해서 돌아가려고 함
// 하나의 소는 파티로 가는 길과 farm으로 돌아오는 길이 다를 수도 있음
// 다른 소끼리는 겹쳐도 괜춘?
// 가장 오래 걸린 시간 구하기

// 해당 노드로 다시 돌아가는 경우는 없음
// 단방향 길

const int MAX_VALUE = numeric_limits<int>::max();

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
    int cost = MAX_VALUE;
    int repeat_time = 0;
    vector<Road> roads;
};

vector<Farm> g_farms;

// 검사할 때 사용한 비용에 대한 초기화
void initFarms(bool b_add)
{
    for(int i = 1; i < g_farms.size(); i++)
    {
        // cout << "dest : " << i << ", cost : " << g_farms[i].cost << "\n";
        if(b_add) g_farms[i].repeat_time += g_farms[i].cost;
        g_farms[i].cost = MAX_VALUE;
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

// 가장 큰 반복 비용 찾기
int findMaxValue()
{
    int result = 0;
    for(const Farm& farm : g_farms)
    {
        result = max(result, farm.repeat_time);
    }
    return result;
}

// start에서 target까지 최소 비용 검사
void search(const int start, const int target)
{
    priority_queue<Road> pq;
    pq.push(Road{start, 0});
    g_farms[start].cost = 0;
    bool b_loop = false;

    while(pq.empty() == false)
    {
        Road move = pq.top();
        pq.pop();

        // 현재 비용이 기준 비용보다 비싼 경우, 무시
        if(move.cost > g_farms[move.dest].cost) continue;

        // 도로별로 검사
        for(const Road& road : g_farms[move.dest].roads)
        {
            int cost = road.cost + move.cost;

            // 비용이 더 크거나 같은 경우, 무시
            if(cost >= g_farms[road.dest].cost) continue;

            // 비용이 더 작은 경우, 추가
            g_farms[road.dest].cost = cost;
            pq.push({road.dest, cost});
        }
    }

    // 목적지에 추가
    if(target != 0) g_farms[start].repeat_time += g_farms[target].cost;
}

int simulate(const int N, const int X)
{
    for(int i = 1; i <= N; i++)
    {
        // cout << "=================\n";
        // cout << "i : " << i << "\n";
        // 다른 사람들이 X로 이동
        if(i != X)
        {
            search(i, X);
            initFarms(false);
        }
        // X에서 각자 집으로 이동
        else
        {
            search(X, 0);
            initFarms(true);
        }
    }

    return findMaxValue();
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

    // 시뮬레이션
    int result = simulate(N, X);

    cout << result << "\n";
}