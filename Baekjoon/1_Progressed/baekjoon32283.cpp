// 실버 3 - 32283번 : 진수 정렬 (Easy)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 1의 개수 찾기
int findOne(const string& input)
{
    int result = 0;

    for(const char& each : input)
    {
        if(each == '1')
            result++;
    }

    return result;
}

// 5
// 1

// 5 4
// 2 1

// 5 4 3
// 3 2 1

// 4 3 2 / 3 2 1
// 3 2 / 3 2 1
// 2 / 1

int simulate(const string& input, const int N, const int one)
{
    vector<int> cases(N+1, 0);
    cases[0] = 1;

    vector<int> multiples(N+1, 1);

    int result = 0;

    for(int i = 1; i < one; i++)
    {
        cases[i] = cases[i-1] * (N + 1 - i) / i;
        result += cases[i];
    }

    for(int i = 1; i < N; i++)
    {
        multiples[i] = multiples[i-1] * i;
    }

    int cur_one = one;
    for(int i = 0; i < N; i++)
    {
        if(input[i] != '1')
        {
            cur_one--;
            int remain = N - i - 1;
            result += multiples[remain] / multiples[remain - cur_one] / multiples[cur_one];
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 길이 N
    int N;
    cin >> N;

    // 2진수 입력
    string input;
    cin >> input;

    int one = findOne(input);
    int result = simulate(input, N, one);
    cout << result << "\n";
}