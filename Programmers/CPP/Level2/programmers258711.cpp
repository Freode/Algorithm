// Lv.2 - 258711번 : 도넛과 막대 그래프
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 노드 정보 구조체
struct Node
{
    // 들어오는 노드 정보
    vector<int> inputs;
    // 내보내는 노드 정보
    vector<int> outputs;
    // 방문 여부
    bool b_is_visited = false;
};

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    // 들어오는 노드 개수 0개
    // 나가는 노드 개수 최소 2개 이상 -> 정점

    // 막대 모양 -> 마지막에 이동 불가능
    // 도넛 모양 -> 나가는거 들어오는 간선이 한 개씩
    // 8자 모양 -> 이동할 수 있는 노드 중 하나는 반드시 들어오는 나가는 노드가 2개씩 존재

    // 가장 큰 노드 번호 찾기
    int max_node_num = 0;
    for(vector<int> &edge : edges)
    {   
        max_node_num = max(max(edge[0], edge[1]), max_node_num);
    }

    // 노드 생성
    vector<Node> nodes(max_node_num + 1);

    int in, out;
    // 연결 간선 정보 추가
    for(vector<int> &edge : edges)
    {
        out = edge[0];
        in = edge[1];

        nodes[out].outputs.push_back(in);
        nodes[in].inputs.push_back(out);
    }

    // 모든 노드를 검사해서 정점 찾기
    int top_node = 0;
    for(int i = 1; i < nodes.size(); i++)
    {
        if(nodes[i].inputs.size() == 0 && nodes[i].outputs.size() >= 2)
        {
            top_node = i;
            break;
        }
    }
    // 정답에 정점 정보 추가
    answer.push_back(top_node);

    int num_stick = 0;
    int num_doughnut = 0;
    int num_8 = 0;
    int cur_node = -1;
    // 정점으로부터 검사
    for(int &each : nodes[top_node].outputs)
    {
        cur_node = each;
        // 끝까지 이동
        while(cur_node != -1)
        {
            // 방문했다고 설정
            nodes[cur_node].b_is_visited = true;

            // 8자 모양 그래프 확신
            if(nodes[cur_node].outputs.size() == 2 && nodes[cur_node].inputs.size() >= 2)
            {
                num_8++;
                break;
            }

            bool b_can_next_move = false;
            int next_node_num = 0;
            // 다음 방문 지점으로 이동
            for(int i = 0; i < nodes[cur_node].outputs.size(); i++)
            {
                next_node_num = nodes[cur_node].outputs[i];
                // 다음 방문 지점을 아직 방문 하지 않음
                if(!nodes[next_node_num].b_is_visited)
                {
                    b_can_next_move = true;
                    cur_node = next_node_num;
                    break;
                }
            }

            // 방문 가능한 경우가 없음
            if(!b_can_next_move)
            {
                // 막대기 모양 확신
                if(nodes[cur_node].inputs.size() >= 1 && nodes[cur_node].outputs.size() == 0)
                {
                    num_stick++;
                }
                // 도넛 모양 확신
                else if(nodes[cur_node].inputs.size() >= 1 && nodes[cur_node].outputs.size() == 1)
                {
                    num_doughnut++;
                }
                cur_node = -1;
            }
        }
    }

    // 정답 추가
    answer.push_back(num_doughnut);
    answer.push_back(num_stick);
    answer.push_back(num_8);

    return answer;
}