// 골드 4 - 1987번 : 알파벳
// 작성자 : free4760(jeonghoe22)

// unordered_map보다 배열로 해결하는게 시간이 빠름.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> g_area;
vector<bool> g_umap;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// 범위 안에 있는지 확인
bool isInBound(int y, int x)
{
    return y >= 0 && x >= 0 && y < g_area.size() && x < g_area[0].length();
}

int search(const int y, const int x, const int depth)
{
    int result = depth;

    // 방향별로 이동
    for(int i = 0; i < 4; i++)
    {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        // 범위 안이 아닐 경우, 무시
        if(isInBound(next_y, next_x) == false) continue;

        int next_c = g_area[next_y][next_x] - 'A';

        // 이미 방문한 글자인 경우에는 무시
        if(g_umap[next_c]) continue;

        // 해당 글자에 대해 방문하기
        g_umap[next_c] = true;
        result = max(result, search(next_y, next_x, depth + 1));
        g_umap[next_c] = false;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    // 세로 R, 가로 C
    int R, C;
    cin >> R >> C;

    // 구역 입력
    g_area = vector<string>(R);
    for(int i = 0; i < R; i++)
    {
        cin >> g_area[i];
    }

    // 왼쪽 상단부터 방문
    char c = g_area[0][0];

    g_umap = vector<bool>(26, false);
    g_umap[c - 'A'] = true;
    int result = search(0, 0, 1);

    cout << result << "\n";
}