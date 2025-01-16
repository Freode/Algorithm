// 골드 4 - 1967번 : 트리의 지름
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// 노드 정보
struct Node
{
    // 부모와의 연결 비용
    int cost = -1;
    int sum = 0;
    int large = 0;
    vector<int> connects;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 입력
    int n;
    cin >> n;

    vector<Node> nodes(n + 1);
    stack<int> sta_parent;

    int parent, child, cost;
    // 연결 정보 입력
    for(int i = 0; i < n - 1; i++)
    {
        cin >> parent >> child >> cost;

        nodes[parent].connects.push_back(child);
        nodes[child].cost = cost;
    }

    // 부모 순으로 추가
    queue<int> que_seq;
    que_seq.push(1);
    sta_parent.push(1);

    while(!que_seq.empty())
    {
        int front = que_seq.front();
        for(int idx : nodes[front].connects)
        {
            // 자식이 있는 경우에만 추가
            if(nodes[idx].connects.size() != 0)
            {
                sta_parent.push(idx);
                que_seq.push(idx);
            }
        }
        que_seq.pop();
    }

    int max_cost = 0;
    while(!sta_parent.empty())
    {
        int cur_parent = sta_parent.top();
        Node* parent_node = &nodes[cur_parent];
        // 자식으로부터 검사
        int local_large = 0, local_sum = 0;

        // 자식 1개
        if(nodes[cur_parent].connects.size() == 1)
        {
            int left = nodes[cur_parent].connects[0];
            local_large = nodes[left].cost + nodes[left].large;
            local_sum = nodes[left].cost + nodes[left].large;
        }
        // 자식 여러 개
        else
        {
            for(int i = 0; i < nodes[cur_parent].connects.size(); i++)
            {
                int left = nodes[cur_parent].connects[i];
                // 연결이 큰 것 계산
                local_large = max(local_large, nodes[left].cost + nodes[left].large);

                for(int j = i + 1; j < nodes[cur_parent].connects.size(); j++)
                {
                    int right = nodes[cur_parent].connects[j];
                    // 현재 노드를 중심으로 한 지름 구하기
                    local_sum = max(local_sum, nodes[left].cost + nodes[left].large + nodes[right].cost + nodes[right].large);
                }
            }
        }

        parent_node->large = local_large;
        parent_node->sum = local_sum;

        // 현재 노드를 중심으로할 때, 가장 긴 지름인지 확인
        max_cost = max(max_cost, parent_node->sum);

        sta_parent.pop();
    }

    cout << max_cost << "\n";
}