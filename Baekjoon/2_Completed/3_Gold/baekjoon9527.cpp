// 골드 2 - 9527번 : 1의 개수 세기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a <= x <= b
// a와 b는 1~10^16

// f(n) -> n자리 수에서 이진수를 만들 때, 1이 있는 경우의 수
// sum(n) -> f(1)+...f(n)의 합

// sum(n) = sum(n-1) + f(n)

using ll = long long;

struct Digit
{
    ll num = 0;
    ll each = 0;
    ll sum = 0;
};

vector<Digit> g_digits;

// b에 대한 기준으로 먼저 자릿수에 따른 1의 개수 먼저 구하기
void search(const ll B)
{
    g_digits.reserve(60);

    ll prev = 2;
    ll cur = 4;

    g_digits.push_back({1, 0, 0});
    g_digits.push_back({2, 1, 1});

    int digit = 2;

    while(cur <= (B * 4))
    {
        Digit createDigit;
        createDigit.each = (cur - prev) + g_digits[digit-1].sum;
        createDigit.sum = g_digits[digit-1].sum + createDigit.each;
        createDigit.num = cur;
        g_digits.push_back(createDigit);

        digit++;
        prev = cur;
        cur = cur << 1;
    }

    // cout << "=== each ===\n";
    // for(const Digit& each : g_digits)
    // {
    //     cout << each.num << " : " << each.each << ", " << each.sum << "\n";
    // }
    // cout << "\n";
}

// 해당 수에 대한 1의 개수 구하기
ll simulate(const ll in_num)
{
    ll num = in_num + 1;

    int digit = 0;
    ll count = 0;
    ll times = 0;
    while(num > 0)
    {
        // 자릿수 구하기
        if(g_digits[digit].num <= num)
        {
            digit++;
            continue;
        }

        // 처음으로 초과된 자릿수이므로 하나 제거
        digit--;

        // cout << "====\nnum : " << num << "\n";
        // cout << "digit : " << digit << "\n";

        num -= g_digits[digit].num;

        // 14 -> 처음 8개 제외
        // 7 -> 두 번째 4개 제외 (제일 앞에 1이 붙음)
        // 3 -> 세 번째 2개 제외 (제일 앞 두 글자에 1이 붙음)
        // 1 -> 네 번째 1개 제외 (제일 앞 세 글자에 1이 붙음)
        count += (g_digits[digit].num * times);

        // 이전 자리수에 대한 1의 개수를 더하기
        count += g_digits[digit].sum;

        // 자릿수 초기화
        digit = 0;
        times++;

        //cout << "count : " << count << "\n";
    }

    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 두 자연수 A, B
    ll A, B;
    cin >> A >> B;

    search(B);
    ll result = simulate(B) - simulate(A-1);
    cout << result << "\n";
}