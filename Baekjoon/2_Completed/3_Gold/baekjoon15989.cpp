// 골드 5 - 15989번 : 1, 2, 3 더하기 4
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_N 15001

typedef long long ll;

struct Cases
{
    ll cases_1 = 0;
    ll cases_2 = 0;
    ll cases_3 = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 경우를 미리 계산
    vector<Cases> cases(MAX_N);

    cases[1].cases_1 = 1;

    cases[2].cases_1 = 1;
    cases[2].cases_2 = 1;

    cases[3].cases_1 = 2;
    cases[3].cases_2 = 0;
    cases[3].cases_3 = 1;

    // cases[4].cases_1 = 3;
    // cases[4].cases_2 = 1;
    // cases[4].cases_3 = 0;

    
    for(int i = 3; i < MAX_N; i++)
    {
        // f(n) = f(n-1) + f(n-2) + f(n-3)
        // 언제 중복될까?
        // f(1) = 1
        // f(2) = 1+1, 2
        // f(3) = 1+1+1, 2+1(1+2), 3
        // f(4) = 1+1+1+1, 1+1+2, 2+2, 3+1
        // f(n) = f(n-1)(1 사용) + f(n-2)(2와 3 사용) + %3(3 사용)
        // 2와3 구성된 경우 
        // 3만 구성된 경우 %3 = 0 -> 1
        // 2와3이 혼합된 경우
        cases[i].cases_1 = cases[i-1].cases_1 + cases[i-1].cases_2 + cases[i-1].cases_3;
        cases[i].cases_2 = cases[i-2].cases_2 + cases[i-2].cases_3;
        cases[i].cases_3 = (i % 3 == 0);
    }

    // 테스트 케이스 개수 입력
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        int n;
        cin >> n;

        cout << cases[n].cases_1 + cases[n].cases_2 + cases[n].cases_3 << "\n";
    }
}