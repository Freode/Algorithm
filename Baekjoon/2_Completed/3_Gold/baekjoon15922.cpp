// 골드 5 - 15922번 : 아우으 우아으이야!!
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 정렬된 상태에서 x_start과 x_end입력
// 기존 범위를 저장
// 1. x_start가 cur_end보다 큰 경우, 기존 길이를 저장
// 2. x_start가 cur_start보다 크고 cur_end보다 작은 경우, 

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cur_start = 0, cur_end = 0;
    int result = 0;

    // 구간 개수 N
    int N;
    cin >> N;

    int x_start, x_end;
    for(int i = 0; i < N; i++)
    {
        cin >> x_start >> x_end;

        // 첫 초기화
        if(cur_start == cur_end)
        {
            cur_start = x_start;
            cur_end = x_end;
        }

        // 겹치지 않는 새로운 구간 등장
        if(cur_end < x_start)
        {
            result += (cur_end - cur_start);
            cur_start = x_start;
            cur_end = x_end;
        }
        // 겹치는 구간 등장
        else
        {
            // 기존 구간에서 뒤로 연장이 가능한 경우
            if(cur_end < x_end)
                cur_end = x_end;

            // 기존 구간과 겹치는 경우는 무시
        }
    }

    // 마지막 구간 추가
    result += (cur_end - cur_start);
    cout << result << "\n";
}
