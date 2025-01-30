// 골드 4 - 1563번 : 개근상
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

// L - 0번 or 1번
// AA 까지는 가능

// f(n)
// 1. O와 A만 사용
// f(n-1)에서 O
// f(n-2)에서 OA
// f(n-3)에서 OAA
// f(n) = f(n-1) + f(n-2) + f(n-3)

// f(1:N) = 2
// f(2:N) = 4
// f(3:N) = 7
// f(4:N) = 13
// f(5:N) = 24

// 2. L 한 번 반드시 사용
// L 위치에 따라 경우의 수 계산
// f(1:L) = 1
// f(2:L) = 4
// f(3:L) = 12
// f(4:L) = 30
// f(5:L) = 70

// f(4:L)
// L 위치 첫 번째 : L + f(3:N)
// L 위치 두 번째 : f(1:N) + L + f(2:N) => f(1:N) * f(2:N)
// L 위치 세 번째 : f(2:N) + L + f(1:N) => f(2:N) * f(1:N)
// L 위치 네 번째 : f(3:N) + L

#define MOD 1000000;

// L 사용하지 않고 경우의 수 구하기
void calculate_not_use_L(vector<ll> &not_L_cases)
{
    for(int i = 1; i < not_L_cases.size(); i++)
    {
        if(i == 1)
        {
            not_L_cases[1] = 2;
        }
        else if(i == 2)
        {
            not_L_cases[2] = 4;
        }
        else if(i == 3)
        {
            not_L_cases[3] = 7;
        }
        else
        {
            not_L_cases[i] = (not_L_cases[i-1] + not_L_cases[i-2] + not_L_cases[i-3]) % MOD;
        }
    }
}

// L을 반드시 사용한 경우의 수 구하기
void calculate_use_L(vector<ll> &not_L_cases, vector<ll> &L_cases)
{
    for(int i = 1; i < L_cases.size(); i++)
    {
        if(i == 1)
        {
            L_cases[1] = 1;
        }
        else
        {
            for(int j = 0; j < i; j++)
            {
                L_cases[i] += (not_L_cases[j] * not_L_cases[i-j-1]);
                L_cases[i] %= MOD;
            }
        }
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력
    int n;
    cin >> n;

    // 할당
    vector<ll> not_L_cases(n+1, 1);
    vector<ll> L_cases(n+1, 0);

    // 계산
    calculate_not_use_L(not_L_cases);
    calculate_use_L(not_L_cases, L_cases);

    // 결과
    ll result = (not_L_cases[n] + L_cases[n]) % MOD;
    cout << result << "\n";
}