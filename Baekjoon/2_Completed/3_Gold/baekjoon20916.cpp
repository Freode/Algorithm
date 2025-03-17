// 골드 4 - 20916번 : 이동하기 5
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 N, 가로 M
    int N, M;
    cin >> N >> M;

    // A(i)와 B(i) 입력
    vector<int> A(N);
    vector<int> B(M);

    set<int> set_a;
    int sum_a = 0, sum_b = 0;
    int max_a = 0, max_b = 0;

    for(int& each : A)
    {
        cin >> each;
        sum_a += each;
        set_a.insert(each);
        max_a = max(max_a, each);
    }
    for(int& each : B)
    {
        cin >> each;
        sum_b += each;
        max_b = max(max_b, each);
    }

    // 무조건, 지나는 길을 한 쪽으로 밀면, 세로 한 줄과 가로 한 줄 완성

    int result_a = 0, result_b = 0;
    // a 값이 모두 같으면, b로 판단
    if(set_a.size() == 1)
    {
        result_a = max_a * (N + M - 1);
        result_b = sum_b + max_b * (N - 1);
    }
    // a 값이 다르면, a 값이 가장 큰 것이 최대값으로 판단
    else
    {
        result_a = sum_a + max_a * (M - 1);
        // 이게 문제네?
        // 같은 a 값이 있으면, 그 사이 중, b값이 가장 큰 것으로 이동
        int b_min_idx = 100000, b_max_idx = 0;
        for(int i = 0; i < N; i++)
        {
            if(A[i] == max_a)
            {
                b_min_idx = min(b_min_idx, i);
                b_max_idx = max(b_max_idx, i);
            }
        }

        // a값이 하나밖에 없음.
        if(b_min_idx == b_max_idx)
            result_b = sum_b + b_min_idx * B[0] + (N - b_min_idx - 1) * B[M-1];
        // a값이 여러 개
        else
            result_b = sum_b + b_min_idx * B[0] + (b_max_idx - b_min_idx) * max_b + (N - b_max_idx - 1) * B[M-1];
        
    }
    ll result = (ll)result_a * (ll)(1'000'000'000) + (ll)result_b;
    cout << result << "\n";
}