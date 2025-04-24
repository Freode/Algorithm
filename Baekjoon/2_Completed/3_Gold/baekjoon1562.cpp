// 골드 1 - 1562번 : 계단 수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 계단수 : 인접한 모든 자리의 차이가 1
// 길이 N -> 0부터 9까지 모두 등장하는 계단 수가 총 몇 개?
// 0으로 시작하는 수는 계단 수 X

// N -> 1~100

// 10 -> 1
// 9876543210 -> 0과 9는 이어져 있지 않음.

// 0~9 존재 여부 -> 10bit -> 4byte
// 크거나 작을 때 -> 총 2가지의 길
// 2^100 = 10^30..

// [현재 숫자][0~9 사용 여부] -> 100 * 2^10 = 10^5

// 89 와 98 구분 못하는 문제
// [현재 위치][현재 숫자][0~9 사용 여부] -> 10^6

const int DIV = 1'000'000'000;

vector<vector<vector<int>>> g_cases;

int simulate(const int N, const int idx, const int use, const int cur)
{
    // 끝까지 도달했다면, 이미 계단수이지만, 숫자를 모두 사용한 경우에만 1개로 반환
    if(N == idx)
        return use == ((1 << 10) - 1);


    int& ref = g_cases[idx][cur][use];

    // 이미 검사했다면, 반환
    if(ref != -1)
        return ref;

    ref = 0;
    // 차이가 -1로 검사
    if(cur != 0)
    {
        ref += simulate(N, idx + 1, use | (1 << (cur - 1)), cur - 1);
        ref %= DIV;
    }

    // 차이가 +1로 검사
    if(cur != 9)
    {
        ref += simulate(N, idx + 1, use | (1 << (cur + 1)), cur + 1);
        ref %= DIV;
    }

    return ref;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 길이 N
    int N;
    cin >> N;

    g_cases = vector<vector<vector<int>>>(N, vector<vector<int>>(10 ,vector<int>(1 << 10, -1)));

    int result = 0;
    // 첫 번째 자리는 정해서 대입
    for(int i = 1; i <= 9; i++)
    {
        result += simulate(N, 1, 1 << i, i);
        result %= DIV;
    }
    cout << result << "\n";
}