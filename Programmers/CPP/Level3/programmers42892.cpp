// Lv.3 - 42892번 : 길 찾기 게임
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 노드 정보
struct Node
{
    int x = 0;
    int y = 0;
    int num = 0;

    Node() = default;
    Node(int num, int y, int x) : num(num), y(y), x(x) {}
};

// 현재 구역에서 가장 높은 y값인 노드 인덱스 찾기
int high_height(vector<Node> &nodes, int start, int end)
{
    // y = 0으로 오는 경우도 존재함. 이것 때문에 오래 걸림.
    int y = -1;
    int idx = -1;

    for(int i = start; i <= end; i++)
    {
        if(nodes[i].y > y)
        {
            idx = i;
            y = nodes[i].y;
        }
    }

    return idx;
}

// 분할-정복
void search(vector<Node> &nodes, int start, int end, bool b_is_prior, vector<int> &answer)
{
    int parent_idx = high_height(nodes, start, end);

    // 전위 순회
    if(b_is_prior)
    {
        answer.push_back(nodes[parent_idx].num);
    }

    // 왼쪽 영역 존재
    if(start <= parent_idx - 1)
    {
        search(nodes, start, parent_idx - 1, b_is_prior, answer);
    }
    // 오른쪽 영역 존재
    if(parent_idx + 1 <= end)
    {
        search(nodes, parent_idx + 1, end, b_is_prior, answer);
    }

    // 후위 순회
    if(!b_is_prior)
    {
        answer.push_back(nodes[parent_idx].num);
    }
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer = {{}, {}};

    // 노드 정보 입력
    vector<Node> nodes;
    for(int i = 0; i < nodeinfo.size(); i++)
    {
        nodes.push_back(Node(i + 1, nodeinfo[i][1], nodeinfo[i][0]));
    }

    // x좌표 기준 오름차순 정렬
    sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b)
    {
        return a.x < b.x;
    });

    // 전위 순회
    search(nodes, 0, nodes.size() - 1, true, answer[0]);
    // 후위 순회
    search(nodes, 0, nodes.size() - 1, false, answer[1]);

    return answer;
}