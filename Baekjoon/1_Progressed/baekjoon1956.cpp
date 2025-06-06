// 골드 3 - 1613번 : 역사
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Road
{
    int start = 0;
    int end = 0;
    int cost = 0;

    // 비용 기준 오름차순 정렬
    bool operator<(const Road& other) const
    {
        return cost > other.cost;
    }
};

vector<int> g_parents;
priority_queue<Road> g_pq;

int findParent(const int idx)
{
    if(idx == g_parents[idx])
        return idx;

    g_parents[idx] = findParent(g_parents[idx]);
    return g_parents[idx];
}

int simulate(const int V)
{
    // 부모 노드 초기화
    for(int i = 0; i <= V; i++)
        g_parents[i] = i;

    int result = -1;

    // 스패닝 트리로 검사
    while(g_pq.empty() == false)
    {
        Road road = g_pq.top();
        g_pq.pop();

        int p_start = findParent(road.start);
        int p_end = findParent(road.end);

        // 사이클 발생 x
        if(p_start != p_end)
        {

        }
        // 사이클 발생 o
        else
        {
            
        }
    }

    return result;
}

void inputData(const int V, const int E)
{


    int start, end, cost;
    for(int i = 0; i < E; i++)
    {
        cin >> start >> end >> cost;

        g_pq.push({start, end, cost});
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


}