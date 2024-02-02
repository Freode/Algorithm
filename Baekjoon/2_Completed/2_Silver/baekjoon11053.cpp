// 실버 2 - 11053번 : 가장 긴 증가하는 부분 수열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

// 1965번 : 상자넣기와 동일

// 증가하는 수열 : n-1번째 수 < n번째 수일 때만 작동

// 초기 경우는 1로 모두 초기화
// 자신의 것을 1개로 처리하기 때문

// n번째에 있는 수를 포함해서 가장 긴 부분 수열의 길이
// f(n) = max( n번째 수보다 작은 수의 값 + 1과 모두 비교, f(n) )

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int N;
    cin >> N;

    // 선언 및 초기화
    vector<int> lengths(N);
    vector<int> cases(N, 1);

    for(int& length: lengths)
    {
        cin >> length;
    }

    int max_length = 1;

    // 크기만큼 반복
    for(int i = 1; i < N; i++)
    {
        // i번째 있는 수보다 앞에 있는 값들을 비교
        for(int j = 0; j < i; j++)
        {
            // 현재 i번째 수가 j번째 수보다 크므로
            // 부분 수열의 길이가 하나 더 늘어날 수 있어 최댓값 비교
            if(lengths[j] < lengths[i])
            {
                cases[i] = max(cases[i], cases[j] + 1);
            }
        }
        // 전체 수열에 대한 가장 긴 부분 수열의 길이 비교
        if(max_length < cases[i])
        {
            max_length = cases[i];
        }
    }

    // 출력
    cout << max_length << "\n";
}