// Lv.4 - 62050번 : 지형 이동
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <cmath>

using namespace std;

// 완전 탐색 - 그룹 먼저 지정
// 완전 탐색 - 사다리 비용 구하기
// MST로 구하기

// 300 * 300
// 1 <= h <= 10'000

const int dy[] = {1, 0, -1, 0};
const int dx[] = {0, 1, 0, -1};

struct Loc
{
    int y = 0;
    int x = 0;
    int diff = 0;
    
    bool operator<(const Loc& other) const
    {
        return diff > other.diff;
    }
};

vector<int> g_parents;

int findParent(const int idx)
{
    if(idx == g_parents[idx])
        return idx;
    
    g_parents[idx] = findParent(g_parents[idx]);
    return g_parents[idx];
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

bool isInBoard(const int size, const int y, const int x)
{
    return y >= 0 && x >= 0 && y < size && x < size;
}

int solution(vector<vector<int>> land, int height) {
    int answer = 0;
    int size = land.size();
    
    // 그룹 묶기
    vector<vector<int>> groups = vector<vector<int>>(size, vector<int>(size, 0));
    
    int group_num = 0;
    for(int y = 0; y < size; y++)
    {
        for(int x = 0; x < size; x++)
        {
            if(groups[y][x] != 0)
                continue;
            
            ++group_num;
            groups[y][x] = group_num;
            
            queue<Loc> q;
            q.push({y, x});
            
            while(q.empty() == false)
            {
                Loc cur = q.front();
                q.pop();
                
                for(int dir = 0; dir < 4; dir++)
                {
                    int next_y = cur.y + dy[dir];
                    int next_x = cur.x + dx[dir];
                    
                    if(isInBoard(size, next_y, next_x) == false)
                        continue;
                    
                    if(groups[next_y][next_x] != 0)
                        continue;
                    
                    if((abs(land[next_y][next_x] - land[cur.y][cur.x]) <= height) == false)
                        continue;
                    
                    groups[next_y][next_x] = group_num;
                    q.push({next_y, next_x});
                }
            }
        }
    }
    
    // 그룹별로 이어지는 사다리 경우 구하기
    priority_queue<Loc> pq;
    g_parents = vector<int>(group_num + 1, 0);
    for(int i = 0; i <= group_num; i++)
    {
        g_parents[i] = i;
    }
    
    for(int y = 0; y < size; y++)
    {
        for(int x = 0; x < size; x++)
        {
            // 아래쪽, 오른쪽만 검사
            for(int dir = 0; dir < 2; dir++)
            {
                int next_y = y + dy[dir];
                int next_x = x + dx[dir];
                
                if(isInBoard(size, next_y, next_x) == false)
                    continue;
                
                if(groups[next_y][next_x] == groups[y][x])
                    continue;
                
                int diff = abs(land[next_y][next_x] - land[y][x]);
                pq.push({groups[next_y][next_x], groups[y][x], diff});
            }
        }
    }
    
    // MST 구하기
    while(pq.empty() == false)
    {
        Loc cur = pq.top();
        pq.pop();
        
        if(unionGroup(cur.y, cur.x))
        {
            answer += cur.diff;
        }
    }
    
    
    return answer;
}