// 골드 4 - 20040번 : 사이클 게임
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> g_parents;

// 부모 노드 찾기
int find_parent(const int idx)
{
    // 부모가 본인이면, 그냥 반환
    if(g_parents[idx] == idx) return idx;

    // 부모가 본인이 아니라면, 가장 높은 부모를 찾고 반환
    g_parents[idx] = find_parent(g_parents[idx]);
    return g_parents[idx];
}

// 연결
void union_city(const int a, const int b)
{
    int p_1 = find_parent(a);
    int p_2 = find_parent(b);

    // 서로 연결되어 있음
    if(p_1 == p_2) return;

    // 연결되어 있지 않음
    g_parents[max(p_1, p_2)] = min(p_1, p_2);
}

int search()
{
    // 서로 다른 부모의 번호를 모두 찾기
    unordered_map<int, int> umap;

    const int size = g_parents.size();
    int result = 0;
    for(int i = 0; i < size; i++)
    {
        
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시 N개
    int N;
    cin >> N;

    // 도시 정보 초기화
    g_parents = vector<int>(N+1);
    for(int i = 0; i < N+1; i++)
    {
        g_parents[i] = i;
    }

    // 도시 연결 정보 입력

}