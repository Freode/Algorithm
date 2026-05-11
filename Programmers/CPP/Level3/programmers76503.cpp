// Lv.3 - 76503번 : 모두 0으로 만들기
// 작성자 : jeonghoe22(최정호)


#include <string>
#include <vector>
#include <iostream>

using namespace std;

struct Edge
{
    bool visit = false;
    vector<int> connects;
    
    Edge()
    {
        connects.reserve(30);
    }
};

vector<Edge> g_edges;

long long dfs(vector<long long>& values, const int idx)
{
    long long count = 0;
    g_edges[idx].visit = true;
    
    for(const int& connect : g_edges[idx].connects)
    {
        if(g_edges[connect].visit)
            continue;
        
        count += dfs(values, connect);
        count += abs(values[connect]);
        values[idx] += values[connect];
        values[connect] = 0;
    }
    
    return count;
}


long long solution(vector<int> a, vector<vector<int>> edges) {
    
    g_edges = vector<Edge>(a.size());
    vector<long long> values(a.begin(), a.end());
    
    for(const vector<int>& edge : edges)
    {
        g_edges[edge[0]].connects.push_back(edge[1]);
        g_edges[edge[1]].connects.push_back(edge[0]);
    }
    
    long long answer = 0;
    answer = dfs(values, 0);
    
    if(values[0] != 0)
        answer = -1;
    
    return answer;
}