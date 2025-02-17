// 골드 4 - 1477번 : 휴게소 세우기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 현재 휴게소의 개수 N, 추가 휴게소의 개수 M, 고속도로의 개수 L
    int N, M, L;
    cin >> N >> M >> L;

    // 휴게소 위치
    vector<int> rests(N);
    for(int& rest : rests){ cin >> rest; }
    // 처음 위치와 마지막 위치를 휴게소로 생각하고 추가
    rests.push_back(0);
    rests.push_back(L);
    // 오름차순 정렬
    sort(rests.begin(), rests.end());

    // 휴게소 간격 넣기
    vector<int> dists(N+M+1, 0);
    for(int i = 0; i < rests.size()-1; i++)
    {
        dists[i] = rests[i+1] - rests[i];  
    }

    sort(dists.begin(), dists.end());

    for(const int& dist : dists)
    {
        cout << dist << " ";
    }
    cout << "\n";

    // M번 동안 계속 2등분
    int dists_size = dists.size() - 1;
    for(int i = 0; i < M; i++)
    {
        int max_dist = dists[dists_size];

        int half = max_dist / 2;

        // 마지막은 최댓값을 절반으로 자른 것이므로 수정해도 무관
        // 처음은 항상 0이므로 수정해도 무관
        dists[dists_size] = half;
        dists[0] = max_dist - half;

        // 오름차순 갱신
        sort(dists.begin(), dists.end());

        for(const int& dist : dists)
        {
            cout << dist << " ";
        }
        cout << "\n";
    }

    cout << dists[dists_size] << "\n";
}