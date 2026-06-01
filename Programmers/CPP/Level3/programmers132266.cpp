// Lv.3 - 132266번 : 부대복귀
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>

using namespace std;

// 최단시간 부대 복귀
// 두 지역 간의 길 통과 시간 : 1
// 주어진 sources 순서대로 복귀할 수 있는 최단 시간
// 복귀 불가능 : -1

// n : 3~100'000
// roads : 2~500'000
// sources 크기 : 1~500
// destination : 1 ~ 100'000

// BFS 탐색 후, 값 대입하기
// 도착지로부터 출발

struct Node
{
    int visit = -1;
    vector<int> lines;
    
    Node()
    {
        lines.reserve(100);
    }
};

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) 
{
    vector<Node> nodes = vector<Node>(n + 1);
    
    for(const vector<int> &road : roads)
    {
        nodes[road[0]].lines.push_back(road[1]);
        nodes[road[1]].lines.push_back(road[0]);
    }
    
    queue<int> q;
    q.push(destination);
    nodes[destination].visit = 0;
    
    while(q.empty() == false)
    {
        int cur = q.front();
        q.pop();
        
        for(const int& line : nodes[cur].lines)
        {
            if(nodes[line].visit != -1)
                continue;
            
            nodes[line].visit = nodes[cur].visit + 1;
            q.push(line);
        }
    }
    
    vector<int> answer;
    for(const int& source : sources)
        answer.push_back(nodes[source].visit);
    
    return answer;
}