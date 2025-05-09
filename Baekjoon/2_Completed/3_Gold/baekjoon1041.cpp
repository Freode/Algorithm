// 골드 5 - 1041번 : 주사위
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N*N*N 크기의 정육면체 만들기
// 5면에 적힌 값들의 합 중 최솟값 구하기

// 꼭지점 3면
// 모서리 2면
// 가운데 1면

// 가운데 -> 6면 중 최솟값
// 모서리 -> AB, AC, AD, AE, BC, BD, BF, CE, CF, DE, DF, EF 중 최솟값
// 꼭지점 -> AED, AEC, ABD, ABC, BFD, BFC, EFD, EFC 중 최솟값

using ll = long long;

const ll MAX_VALUE = numeric_limits<ll>::max();

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 크기 N;
    int N;
    cin >> N;

    // A~F
    ll A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    ll one = MAX_VALUE, two = MAX_VALUE, three = MAX_VALUE;

    // 가운데
    one = min(one, A);
    one = min(one, B);
    one = min(one, C);
    one = min(one, D);
    one = min(one, E);
    one = min(one, F);

    // 모서리 -> AB, AC, AD, AE, BC, BD, BF, CE, CF, DE, DF, EF 중 최솟값
    two = min(two, A + B);
    two = min(two, A + C);
    two = min(two, A + D);
    two = min(two, A + E);
    two = min(two, B + C);
    two = min(two, B + D);
    two = min(two, B + F);
    two = min(two, C + E);
    two = min(two, C + F);
    two = min(two, D + E);
    two = min(two, D + F);
    two = min(two, E + F);

    // 꼭지점 -> AED, AEC, ABD, ABC, BFD, BFC, EFD, EFC 중 최솟값
    three = min(three, A + E + D);
    three = min(three, A + E + C);
    three = min(three, A + B + D);
    three = min(three, A + B + C);
    three = min(three, B + F + D);
    three = min(three, B + F + C);
    three = min(three, E + F + D);
    three = min(three, E + F + C);

    // 
    long long result = 0;

    if(N == 1)
    {
        result = A + B + C + D + E + F;
        result -= max(A, max(B, max(C, max(D, max(E, F)))));
    }
    else
    {
        result += (three * 4);
        result += (two * 4);
        result += (two * 8 * (N - 2));
        result += (one * (N - 2) * (N - 2) * 5);
        result += (one * (N - 2) * 4);
    }

    cout << result << "\n";
}