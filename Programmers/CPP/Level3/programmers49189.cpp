// Lv.3 - 49189번 : 단어 변환
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Node
{
    vector<int> connects;
    bool b_is_visited = false;
    int distance = 0;
};

// queue
int search(vector<Node> &nodes)
{
    queue<int> que_loc;
    que_loc.push(1);
    nodes[1].b_is_visited = true;
    
    int cur_loc, max_distance = 0;
    while(!que_loc.empty())
    {
        cur_loc = que_loc.front();
        // 현재 지점에서 이어진 지점까지 모두 검사
        for(int &connect : nodes[cur_loc].connects)
        {
            // 해당 지점을 방문하지 않았을 때만, 이동
            if(!nodes[connect].b_is_visited)
            {
                nodes[connect].b_is_visited = true;
                que_loc.push(connect);
                nodes[connect].distance = nodes[cur_loc].distance + 1;
                max_distance = max(max_distance, nodes[connect].distance);
            }
        }

        que_loc.pop();
    }

    // 가장 먼 지점 개수 찾기
    int count = 0;

    for(int i = 1; i < nodes.size(); i++)
    {
        // 가장 먼 지점일 경우
        if(max_distance == nodes[i].distance)
        {
            count++;
        }
    }

    return count;

}

int solution(int n, vector<vector<int>> edge) {

    // 노드 초기화 및 간선 연결
    vector<Node> nodes(n + 1);
    for(vector<int>& each : edge)
    {
        nodes[each[0]].connects.push_back(each[1]);
        nodes[each[1]].connects.push_back(each[0]);
    }

    int max_distance = 0;
    // 1번 노드부터 순찰
    max_distance = search(nodes);

    return max_distance;
}