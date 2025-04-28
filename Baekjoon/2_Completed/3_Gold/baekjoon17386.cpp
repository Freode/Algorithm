// 골드 3 - 17386번 : 선분 교차 1
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 일직선이 존재하지 않음.

using ll = long long;

struct Loc
{
    ll y = 0;
    ll x = 0;
};

vector<Loc> g_locs(4);

// a.x b.x c.x a.x
// a.y b.y c.y a.y
// 최대 3*10^14

// CCW
ll ccw(const Loc& a, const Loc& b, const Loc& c)
{
    return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

// 교차 여부 확인
int check()
{
    const Loc& a = g_locs[0];
    const Loc& b = g_locs[1];
    const Loc& c = g_locs[2];
    const Loc& d = g_locs[3];

    ll abc = ccw(a, b, c);
    ll abd = ccw(a, b, d);
    ll cda = ccw(c, d, a);
    ll cdb = ccw(c, d, b);

    // 교차 상태 - XOR 연산 : 부호가 둘 다 반대일 때만, 참 반환
    if((abc ^ abd) < 0 && (cda ^ cdb) < 0)
        return 1;

    return 0;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 좌표 A~D 입력
    for(Loc& loc : g_locs)
        cin >> loc.x >> loc.y;
    
    cout << check() << "\n";
}