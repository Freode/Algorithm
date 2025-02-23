// 골드 4 - 1197번 : 최소 스패닝 트리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line
{
    int start = 0;
    int end = 0;
    int cost = 0;
};

// 부모 노드 찾기
int find_parent(const vector<int> &in_points, const int num)
{
    int parent = num;
    // 자기 자신이 아닐 때 까지
    // 0이면 -> 0 => 어차피 루트
    // 설정이 완료됐으면, 1 -> 1
    while(in_points[parent] != parent)
    {
        // 0이 아니라면, 해당 노드로 옮겨서 부모 찾기
        parent = in_points[parent];
    }
    return in_points[parent];
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

    // 정점
    vector<int> points(V+1, 0);

    // 3 -> 1 -> 2
    int result = 0;
    for(const Line &line : lines)
    {
        // 출발지와 도착지가 같으면, 무시
        if(line.start == line.end) continue;

        int start_parent = find_parent(points, line.start);
        int end_parent = find_parent(points, line.end);

        // 둘 다 0일 경우 -> 처음 연결
        if(start_parent == end_parent && start_parent == 0)
        {
            // start가 항상 더 작음
            points[line.start] = line.start;
            points[line.end] = line.start;
            result += line.cost;
        }
        // 부모가 다르면, 순환 발생 x
        else if(start_parent != end_parent)
        {
            // 둘 중 부모가 더 작은 쪽으로 이동
            if(end_parent < start_parent)
            {
                points[line.end] = line.start;
            }
            else
            {
                points[line.start] = line.end;
            }
            result += line.cost;
        }
        // 부모가 같으면, 순환 발생 o -> 무시
    }
    cout << result << "\n";
}