// Lv.3 - 42861번 : 섬 연결하기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> g_parents;

int findParent(const int x)
{
    if(g_parents[x] == x)
        return x;
    
    g_parents[x] = findParent(g_parents[x]);
    return g_parents[x];
}

bool unionGroup(const int x, const int y)
{
    int px = findParent(x);
    int py = findParent(y);
    
    if(px == py)
        return false;
    
    g_parents[max(px, py)] = min(px, py);
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    g_parents = vector<int>(n + 1, 0);
    for(int i = 0; i < g_parents.size(); i++)
        g_parents[i] = i;
    
    // 비용 기준 오름차순
    sort(costs.begin(), costs.end(), 
         [](const vector<int> &a, const vector<int> &b)
         {
             return a[2] < b[2];
         }
    );
    
    for(const vector<int>& cost : costs)
    {
        if(unionGroup(cost[0], cost[1]))
            answer += cost[2];
    }
    
    return answer;
}