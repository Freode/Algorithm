// 실버 2 - 15810번 : 풍선 공장
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 스태프 수 N, 풍선의 개수 M
    int N, M;
    cin >> N >> M;

    // 스태프 능력 입력
    vector<int> staffs(N);
    for(int& staff : staffs)
    {
        cin >> staff;
    }
    // 풍선 개수를 많이 만들 수 있는 사람부터 앞에 배치
    sort(staffs.begin(), staffs.end());

    ll start = 0;
    ll end = 10e12;
    ll mid;

    ll result = -1;
    while(start + 1 < end)
    {
        mid = (start + end) / 2;

        ll count = 0;
        // 스태프별 풍선의 개수 구하기
        for(const int& staff : staffs)
        {
            count += (mid / (ll)staff);

            // 이미 풍선의 개수를 넘은 경우, 나머지 계산은 무시
            if(count > M) break;
        }

        if(count >= M) end = mid;
        else start = mid;
    }
    // 출력
    result = end;
    cout << result << "\n";

}