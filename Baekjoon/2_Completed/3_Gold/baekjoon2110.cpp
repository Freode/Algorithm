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
    int left = 1, right = 0, pivot = 0, temp = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> temp;
        locs[i] = temp;
        // 공유기 인접 거리가 가장 먼 경우를 가장 멀리 있는 집의 좌표로 설정.
        if(right < temp){ right = temp; }
    }

    // 집 위치 정렬
    sort(locs.begin(), locs.end());

    // 이분 탐색
    int last_location, count, result = 0;
    while(left <= right)
    {
        cout << "left : " << left << ", right : " << right << "\n";

        pivot = (left + right) / 2;

        // 처음에는 반드시 설치
        last_location = locs[0];
        count = 1;

        // 공유기 몇 개를 설치할 수 있는지 검사
        for(int i = 1; i < (int)locs.size(); i++)
        {
            // 거리를 현재 조건보다 만족했을 때만, 공유기 설치
            if(locs[i] - last_location >= pivot)
            {
                last_location = locs[i];
                count++;
            }

            // 만약에 공유기 개수가 조건보다 더 많이 설치할 때는 바로 통과
            if(count > C){ break; }
        }

        // 공유기 개수로 판단
        // 공유기 개수가 조건보다 더 많을 때, 최소 거리를 늘림
        if(count > C){ left = pivot + 1; }
        // 공유기 개수가 조건보다 더 적을 때, 최소 거리를 줄임
        else if(count < C){ right = pivot - 1;}
        // 공유기 개수가 현재 조건을 만족할 때, 거리를 저장하고 다음 검사 진행
        else
        {
            result = pivot;
            left = pivot + 1;
        }

        cout << "pivot : " << pivot << ", count : " << count << "\n";
    }

    // 출력
    if(result > 0){ cout << result << "\n"; }
    else{ cout << right << "\n"; }
}