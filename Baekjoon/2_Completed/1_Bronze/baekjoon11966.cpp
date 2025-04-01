// 브론즈 3 - 11966번 : 2의 제곱인가?
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 자연수 N
// 2의 제곱수 -> 1, 아니면 -> 0

// 1로 shift left 연산을 0~30번까지 해서 같은지 검사

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 입력 N
    int N;
    cin >> N;

    int check = 1;
    bool b_pass = false;

    // 2^0, 2^1, 2^2, ... 각각 체크
    for(int i = 0; i < 31; i++)
    {
        if(check << i == N) b_pass = true;
    }

    int result = b_pass;

    cout << result << "\n";
}