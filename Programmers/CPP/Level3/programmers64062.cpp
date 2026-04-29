// Lv.3 - 64062번 : 징검다리 건너기
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

struct Stone
{
    int parent = 0;
    int count = 1;
};

struct Loc
{
    int idx = 0;
    int remain = 0;
    
    bool operator<(const Loc& other) const
    {
        return remain > other.remain;
    }
};

vector<Stone> g_stones;

int findParent(const int x)
{
    if(g_stones[x].parent == x)
        return x;
    
    g_stones[x].parent = findParent(g_stones[x].parent);
    return g_stones[x].parent;
}

int unionGroup(const int x, const int y)
{
    int px = findParent(x);
    int py = findParent(y);
    
    if(px == py)
        return 0;
    
    g_stones[max(px, py)].parent = min(px, py);
    g_stones[min(px, py)].count += g_stones[max(px, py)].count;
    
    return g_stones[min(px, py)].count;
}


int solution(vector<int> stones, int k) {
    
    int size = stones.size();
    g_stones = vector<Stone>(size + 1);
    
    for(int i = 1; i <= size; i++)
        g_stones[i].parent = i;
    
    priority_queue<Loc> pq;
    for(int i = 0; i < size; i++)
        pq.push({i + 1, stones[i]});
    
    int answer = 0;
    while(pq.empty() == false)
    {
        Loc cur = pq.top();
        pq.pop();
             
        answer = cur.remain;
        int seq = unionGroup(cur.idx, cur.idx - 1);
        
        if(seq > k)
        {
            break;
        }
    }
    
    return answer;
}