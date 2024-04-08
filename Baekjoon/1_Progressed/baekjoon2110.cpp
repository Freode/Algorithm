// 골드 4 - 2110번 : 공유기 설치
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 기준 : 가장 인접한 두 공유기의 거리

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N, C;
    cin >> N >> C;

    vector<int> locs(N, 0);
    int left = 0, right = 0, pivot = 0, temp = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        locs[i] = temp;
        // 공유기 인접 거리가 가장 먼 경우를 가장 멀리 있는 집의 좌표로 설정.
        if(i == N - 1){ right = temp; }
    }

    // 이분 탐색
    while(left <= right)
    {
        pivot = (left + right) / 2;

        
    }

}