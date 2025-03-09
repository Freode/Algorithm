// 실버 2 - 15663번 : N과 M (9)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

vector<int> g_values;
vector<bool> g_visits;
int g_size = 0;

// 경우의 수 모두 찾기
void repeat(vector<int> &result, const int layer, const int target)
{
    // 목표까지 탐색 완료
    if(layer == target)
    {
        int size = result.size();
        for(const int& each : result)
        {
            cout << each << " ";
        }
        cout << "\n";
        return;
    }

    int prev = 0;
    for(int idx = 0; idx < g_size; idx++)
    {
        // 방문한 경우에는 무시
        if(g_visits[idx]) continue;

        // 이전에 방문한 수와 같으면, 무시
        if(prev == g_values[idx]) continue;
        prev = g_values[idx];

        g_visits[idx] = true;
        result[layer] = g_values[idx];
        repeat(result, layer + 1, target);
        g_visits[idx] = false;
        result[layer] = 0;
    }
}


int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, M;
    cin >> N >> M;

    // 수 입력
    g_values = vector<int>(N);
    g_visits = vector<bool>(N, false);
    g_size = N;
    for(int &value : g_values){ cin >> value; }

    // 오름차순 정렬
    sort(g_values.begin(), g_values.end());

    vector<int> result(M, 0);
    repeat(result, 0, M);
}