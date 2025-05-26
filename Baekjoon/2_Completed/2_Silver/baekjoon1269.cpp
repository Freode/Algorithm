// 실버 4 - 1269번 : 대칭 차집합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

unordered_map<int, int> g_nums;

int inputData(const int N)
{
    int result = 0;
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        g_nums[num]++;

        // 각 집합에서 중복 발견
        if(g_nums[num] == 2)
            result++;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 집합 A 원소 개수, 집합 B 원소 개수
    int A, B;
    cin >> A >> B;

    int twice_cnt = 0;
    twice_cnt += inputData(A);
    twice_cnt += inputData(B);

    cout << A + B - (2 * twice_cnt) << "\n";
}