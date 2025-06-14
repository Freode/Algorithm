// 실버 1 - 14731번 : 謎紛芥索紀 (Large)
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ll = long long;
const int DIV = 1'000'000'007;

unordered_map<ll, ll> g_umap;

ll prime(const ll K)
{
    // 항의 차수가 음수인 경우는 0 반환
    if(K < 0)
        return 0;

    // 미리 계산한 K 차수 값이 있는 경우, 반환
    if(g_umap[K] != 0)
        return g_umap[K];

    // 없는 경우, 반으로 나눠서 계산
    ll left = K >> 1;
    ll right = K - left;

    ll result = prime(left) * prime(right);
    result %= DIV;

    // 등록 후, 반환
    g_umap[K] = result;
    return result;

}

ll simulate(const int N)
{
    // 항의 계수 C, 항의 차수 N
    ll C, K;
    ll result = 0;
    for(int i = 0; i < N; i++)
    {
        cin >> C >> K;
        result += (C * K % DIV) * prime(K-1);
        result %= DIV;
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 항의 개수 N
    int N;
    cin >> N;

    g_umap[0] = 1;
    g_umap[1] = 2;
    cout << simulate(N) << "\n";
}