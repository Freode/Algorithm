// Lv.3 - 92343번 : 양과 늑대
// 작성자 : jeonghoe22(최정호)

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 노드마다 자식 노드 정보
struct Node
{
    vector<int> connects;
};

// 최대 양의 수집 가능한 수
int max_sheep_count = 0;

// DFS
void search(vector<int> &info, vector<Node> &nodes, int cur_loc, int sheep, int wolf, vector<int> move_cases)
{
    // 양일 경우
    if(info[cur_loc] == 0)
    {
        sheep++;
    }
    // 늑대일 경우
    else
    {
        wolf++;
    }

    // 늑대 수가 양과 같거나 많을 경우
    if(wolf >= sheep)
    {
        return;
    }

    // 양의 수가 최대인 경우, 초기화
    max_sheep_count = max(max_sheep_count, sheep);

    int next_loc;
    vector<int> next_move_cases;
    // 이동 가능 경우에 대해서 모두 이동
    for(int i = 0; i < move_cases.size(); i++)
    {
        next_loc = move_cases[i];
        // 현재 검사 노드의 자식 노드를 경우의 수로 일단 넣기
        next_move_cases = move_cases;
        // 자식 노드 중 다음으로 이동할 위치는 next_move_cases에서 제외
        next_move_cases.erase(next_move_cases.begin() + i);

        // 자식 노드도 이동 경우의 수로 추가
        for(int& each : nodes[next_loc].connects)
        {
            next_move_cases.push_back(each);
        }

        // 다음 지점 검사하기
        search(info, nodes, next_loc, sheep, wolf, next_move_cases);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;

    vector<Node> nodes(info.size());

    // 자식 연결
    for(vector<int> &each : edges)
    {
        nodes[each[0]].connects.push_back(each[1]);
    }

    // 시작 노드 추가
    vector<int> move_cases;
    for(int& each : nodes[0].connects)
    {
        move_cases.push_back(each);
    }

    // 검사 시작
    search(info, nodes, 0, 0, 0, move_cases);

    answer = max_sheep_count;

    return answer;
}