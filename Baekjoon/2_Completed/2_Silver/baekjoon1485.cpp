// 실버 3 - 1485번 : 정사각형
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ll = long long;

struct Loc
{
    ll y = 0;
    ll x = 0;
};

vector<Loc> g_locs;

void inputData()
{
    for(Loc& loc : g_locs)
    {
        cin >> loc.x >> loc.y;
    }
}

// 두 값의 차에 대한 제곱 구하기
ll getSquare(const ll a, const ll b)
{
    return (a - b) * (a - b);
}

// 길이 구하기
ll getLine(const int idx_1, const int idx_2)
{
    return getSquare(g_locs[idx_1].y, g_locs[idx_2].y) + getSquare(g_locs[idx_1].x, g_locs[idx_2].x); 
}

int simulate()
{
    unordered_map<ll, int> umap;

    // 변 4개와 대각선 2개 구하기
    for(int i = 0; i < 4; i++)
    {
        umap[getLine(i, (i+1) % 4)]++;
    }

    for(int i = 0; i < 2; i++)
    {
        umap[getLine(i, (i+2) % 4)]++;
    }

    // 길이가 3가지 이상인 경우, 정사각형 x
    if(umap.size() != 2)
        return 0;

    // 두 변의 종류가 2로 나누거나 곱했을 때, 같으면, 정사각형
    vector<ll> lines;
    for(const auto& each : umap)
    {
        lines.push_back(each.first);
    }

    return (lines[0] << 1 == lines[1]) || (lines[0] >> 1 == lines[1]);
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;

    g_locs = vector<Loc>(4);
    for(int i = 0; i < T; i++)
    {
        inputData();
        cout << simulate() << "\n";
    }
}