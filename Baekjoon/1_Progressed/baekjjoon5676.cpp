// 골드 1 - 5676번 : 음주 코딩
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// C : 배열의 값을 하나만 바꾸기
// P : 배열의 곱을 출력 -> 0 or + or -
// 음수와 0의 개수로만 출력 가능할 듯?

// 수열의 크기 N, 게임의 라운드 수 K (1~10^5)

vector<int> g_vec;

// 입력 데이터 전처리
void inputData(const int N, const int K)
{
    int num;
    for(int i = 0; i < N; i++)
    {
        cin >> num;
        g_vec[i] = num;
    }
}

void simulate(const int N, const int K)
{
    char c;
    for(int i = 0; i < K; i++)
    {

    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 수열의 크기 N, 게임의 라운드 수 K
    int N, K;
    cin >> N >> K;

    g_vec = vector<int>(100'000, 0);
    while(cin >> N >> K)
    {

    }

}