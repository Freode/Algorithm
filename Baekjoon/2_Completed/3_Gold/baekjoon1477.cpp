// 골드 4 - 1477번 : 휴게소 세우기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// 현재 조건을 만족하는지 확인
bool isP(const vector<int> &in_dists, const int in_M, const int in_mid)
{
    int add_rest_counts = 0;

    // 현재 간격에서 in_mid(현재 최대 거리라고 가정)를 나눠서 추가로 필요한 휴게소 개수
    for(const int& dist : in_dists)
    {
        // 휴게소를 추가할려면, 1의 공간이 필요
        add_rest_counts += (dist-1) / in_mid;
    }
    
    // 추가로 필요한 휴게소 개수가 더 적을 때, 최소 거리를 증가
    return add_rest_counts <= in_M;
}

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
    vector<int> dists(N+1, 0);
    for(int i = 0; i < rests.size()-1; i++)
    {
        dists[i] = rests[i+1] - rests[i];  
    }
    sort(dists.begin(), dists.end());

    int left = 0;
    int right = dists[N];
    int mid;

    // 거리를 기준으로 측정
    // T T T T F F
    while(left + 1 < right)
    {
        mid = left + ((right - left) >> 1);

        // 거리가 mid라고 가정할 때, 휴게소가 더 필요하므로 최대 거리르 감소
        // mid -> 휴게소간 간격 감소
        if(isP(dists, M, mid))
        {
            right = mid;
        }
        // 휴게소가 더 필요 없으므로 최소 거리를 증가
        // mid -> 휴게소간 간격 증가
        else
        {
            left = mid;
        }
    }

    cout << right << "\n";

    return 0;
}