// 골드 4 - 1197번 : 최소 스패닝 트리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> g_points;

struct Line
{
    int start = 0;
    int end = 0;
    int cost = 0;
};

// 부모 노드 찾기
int find_parent(const int num)
{
    if(g_points[num] == num) return num;

    // 자기 자신이 아닐 때 까지
    // 설정이 완료됐으면, 1 -> 1
    g_points[num] = find_parent(g_points[num]);
    return g_points[num];
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 정점 개수 V, 간선 개수 E
    int V, E;
    cin >> V >> E;

    // 간선 개수
    vector<Line> lines(E);
    for(Line &line : lines)
    {
        cin >> line.start >> line.end >> line.cost;
    } 
    // 간선 비용을 오름차순으로 정렬
    sort(lines.begin(), lines.end(), [](const Line& a, const Line& b)
    {
        return a.cost < b.cost;
    });

    // 정점 + 자기 자신으로 지정
    g_points = vector<int>(V+1);
    for(int i = 0; i < V+1; i++){ g_points[i] = i; }

    // 3 -> 1 -> 2
    int result = 0;
    int line_count = 0;
    for(const Line &line : lines)
    {
        // 출발지와 도착지가 같으면, 무시
        if(line.start == line.end) continue;

        int start_parent = find_parent(line.start);
        int end_parent = find_parent(line.end);

        // 부모가 다르면, 순환 발생 x -> 연결
        if(start_parent != end_parent)
        {
            // 본인의 가장 높은 부모로 연결
            g_points[end_parent] = start_parent;
            result += line.cost;

            // 연결 간선 개수가 정점 개수 -1 일 때
            if(++line_count == V-1) break;
        }
        // 부모가 같으면, 순환 발생 o -> 무시

    }
    cout << result << "\n";
}