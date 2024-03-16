// 실버 4 - 2217번 : 로프
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    vector<int> weight(N);
    for(int& each : weight)
    {
        cin >> each;
    }

    // 내림차순 정렬 : greater<>() 임시객체 호출
    sort(weight.begin(), weight.end(), greater<>());

    int result_weight = 0;
    int count = 0;
    for(int& each : weight)
    {
        count++;
        // 로프를 추가했을 때, 더 견딜 수 있으면, 결과값을 새롭게 초기화
        if(result_weight < each * count )
        {
            result_weight = each * count;
        }
    }

    // 출력문
    cout << result_weight << "\n";
}