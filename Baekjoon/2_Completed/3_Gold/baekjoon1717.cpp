// 골드 5 - 1717번 : 집합의 표현
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<int> g_parents;

// 부모 찾기
int find_parent(const int idx)
{
    // 자신이 부모인 경우
    if(g_parents[idx] == idx) return idx;

    // 가장 높은 부모 노드를 찾고, 이를 설정 - 시간 단축
    g_parents[idx] = find_parent(g_parents[idx]);
    // 부모 노드를 찾으러 이동
    return g_parents[idx];
}

// 집합끼리 합치기
void union_set(const int first, const int second)
{
    int parent_1 = find_parent(first);
    int parent_2 = find_parent(second);

    // 부모가 같으면, 무시
    if(parent_1 == parent_2) return;

    // 더 높은 값의 노드 부모를 더 작은 값의 노드로 설정
    g_parents[max(parent_1, parent_2)] = min(parent_1, parent_2);
}

// 부모가 같다면, 같은 집합(배열)에 위치
bool search(const int first, const int second)
{
    return find_parent(first) == find_parent(second);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 집합 개수 n, 연산 개수 m
    int n, m;
    cin >> n >> m;
    
    // 부모 노드 정도 초기화
    g_parents = vector<int>(n+1, 0);
    for(int i = 0; i < n+1; i++)
    {
        g_parents[i] = i;
    }

    // 연산에 대한 입력
    int oper, a, b;
    for(int i = 0; i < m; i++)
    {
        cin >> oper >> a >> b;

        // 합집합 연산
        if(oper == 0)
        {
            union_set(a, b);
        }
        // 같은 배열에 속한지 찾기
        else
        {
            string result = search(a, b) ? "YES" : "NO";
            cout << result << "\n";
        }
    }
}