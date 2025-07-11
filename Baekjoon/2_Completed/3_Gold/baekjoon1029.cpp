// 골드 1 - 1029번 : 그림 교환
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 처음에 그림은 0번 사람이 소유
// [i][j] => j번 예술가가 i번 예술가에게 살 때의 가격 
// == i번 예술가가 j번 예술가에게 그림을 팔 때 가격

// 단순한 DFS -> 14!
// 방문기록 저장 -> bool : 2^15 * 15byte
// int로 저장 -> 2^15 * 4byte
// 논리 연산으로 시간 단축 가능

// [소유 했던 사람 정보] = 방문한 사람 수

// 추가
// 판매 순서에 따라 경우가 달라질 수 있음.
// ex) 1->3->2, 1->2->3
// 1->3->2가 더 큼에도 이미 1->2->3으로 판매해서, 무시 당할 경우 존재

// [현재 비용][소유했던 사람 정보] = 방문한 사람 수

// 추가
// 현재 그림을 소유한 사람의 번호가 필요
// 비용과 소유했던 사람 정보가 같을 때, 위 경우를 구분하지 못함

// [현재 비용][현재 그림을 소유한 사람 번호][소유했던 사람 정보] = 방문한 사람 수

const int INIT_VALUE = -1;

vector<vector<int>> g_datas;
vector<vector<vector<int>>> g_costs;

void inputData(const int N)
{
    g_datas = vector<vector<int>>(N, vector<int>(N, 0));
    g_costs = vector<vector<vector<int>>>(10, vector<vector<int>>(15, vector<int>(1 << N, INIT_VALUE)));

    string input;
    for(int i = 0; i < N; i++)
    {
        cin >> input;
        for(int j = 0; j < N; j++)
        {
            g_datas[i][j] = input[j] - '0';
        }
    }
}

int search(const int N, const int visit, const int cost, const int cur)
{
    // 이미 판매했다면, 바로 반환
    // 현재 지점에서 더 팔 수 있는 사람의 수를 반환
    int& ref_check_cost = g_costs[cost][cur][visit];

    if(ref_check_cost != INIT_VALUE)
        return ref_check_cost;

    int count = 0;
    // 판매하지 않았다면, 추가 검사 진행
    for(int idx = 0; idx < N; idx++)
    {
        // 1. 자기 자신한테 파는 경우는 무시
        if(cur == idx)
            continue;

        // 2. 이미 해당 사람한테 팔았다면, 무시
        if(visit & (1 << idx))
            continue;

        // 3. 현재 비용보다 더 비싸게 팔 수 있는 경우가 아니라면, 무시
        if((g_datas[cur][idx] >= cost) == false)
            continue;

        // 기존 횟수와 idx번 사람에게 그림을 팔았을 때, 더 많은 사람이 소유했는지 확인
        count = max(count, 1 + search(N,  visit | (1 << idx), g_datas[cur][idx], idx));
    }

    // cost 비용으로 visit 정보의 사람에게 판매했을 때, 최대 판매 기록 저장
    ref_check_cost = count;
    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 예술가의 수 N
    int N;
    cin >> N;

    inputData(N);
    cout << search(N, 1, 0, 0) + 1 << "\n";

}