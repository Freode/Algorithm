// 골드 4 - 11054번 : 가장 긴 바이토닉 부분 수열
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 증가하는 수열
// 감소하는 수열

// 입력 N -> 최대 1000
// N^2 = 1'000'000

// 1. 증가하는 수열
// 1 5 2 1 4 3 4 5 2 1
// 1 2 2 1 3 3 4 5 2 1

// 2. 감소하는 수열
// 1 5 2 1 4 3 4 5 2 1
// 1 5 2 1 4 3 3 3 2 1

// 1과 2를 더해서
// 최댓값이 정답
// -1 필요 -> 자기 자신에 대한 중복 제거

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 크기 N
    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> in_case(N, 0);
    vector<int> de_case(N, 0);

    // 데이터 입력
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    in_case[0] = 1;
    de_case[N-1] = 1;

    // 수열 검사
    for(int i = 1; i < N; i++)
    {
        // 앞에 검사
        for(int idx = i-1; idx >= 0; idx--)
        {
            // 증가하는 수 만족
            if(arr[i] > arr[idx])
                in_case[i] = max(in_case[i], in_case[idx] + 1);
        }
        // 뒤에 검사
        int de_idx = N-1-i;
        for(int idx = N-i; idx < N; idx++)
        {
             // 감소하는 수 만족
             if(arr[de_idx] > arr[idx])
                de_case[de_idx] = max(de_case[de_idx], de_case[idx] + 1);
        }
        // 0이면, 1로 설정
        if(in_case[i] == 0) in_case[i]++;
        if(de_case[de_idx] == 0) de_case[de_idx]++;
    }

    // 두 경우 합쳐서 max인 경우 확인
    int result = 0;
    for(int i = 0; i < N; i++)
    {
        result = max(result, in_case[i] + de_case[i] - 1);
    }

    cout << result << "\n";
}