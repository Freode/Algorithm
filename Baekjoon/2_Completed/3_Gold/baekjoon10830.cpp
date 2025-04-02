// 골드 4 - 10830번 : 행렬 제곱
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

// 크기 N*N -> 행렬 A
// A의 B제곱 -> 각 원소를 1000으로 나머지 연산

// 행렬 B제곱
// B : 짝수 -> A^(B/2) * A^(B/2)
// B : 홀수 -> A^(B/2) * A^(B/2) * A^(1)

// A^(1) * A^(1) -> A^(2)
// A^(2) * A^(2) -> A^(4)
// ...

vector<vector<int>> g_base;
vector<vector<int>> g_exp_base;

typedef long long ll;

// 행렬 입력
void input(const int N)
{
    g_base = vector<vector<int>>(N, vector<int>(N));
    g_exp_base = vector<vector<int>>(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> g_base[i][j];
            g_base[i][j] %= 1000;
            g_exp_base[i][j] = g_base[i][j];
        }
    }
}

// 행렬 곱
void calculate(const int N, const bool b_odd)
{
    vector<vector<int>> base = vector<vector<int>>(N, vector<int>(N, 0));
    vector<vector<int>>& multiply = b_odd ? g_base : g_exp_base;

    // 계산
    // i행
    for(int i = 0; i < N; i++)
    {
        // j열
        for(int j = 0; j < N; j++)
        {
            // k번째
            for(int k = 0; k < N; k++)
            {
                base[i][j] += (g_exp_base[i][k] * multiply[k][j]);
            }
            // 1,000으로 나머지 연산
            base[i][j] %= 1000;
        }
    }

    g_exp_base = base;
}

void simulate(const int N, const ll B)
{
    ll exp = B;

    // 스택으로 필요한 거듭제곱 수 밀어 넣기
    stack<ll> s;
    while(exp > 1)
    {
        s.push(exp);
        exp /= 2;
    }

    // 거듭제곱
    while(s.empty() == false)
    {
        ll top = s.top();
        s.pop();

        calculate(N, false);
        // 홀수인 경우, 1을 더 거듭제곱
        if(top % 2 == 1)
        {
            calculate(N, true);
        }
    }
}

// 행렬 출력
void print(const int N)
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout << g_exp_base[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 행렬 크기 N, 제곱 B
    int N;
    ll B;
    cin >> N >> B;

    // 행렬 입력
    input(N);

    // 행렬 계산
    simulate(N, B);

    // 출력
    print(N);
}