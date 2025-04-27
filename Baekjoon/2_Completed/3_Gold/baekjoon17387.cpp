// 골드 2 - 17387번 : 선분 교차 2
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// CCW

// AB, CD

// 1. ABC와 ABD의 부호 
// 2. CDA와 CDB의 부호

// 1) 둘 다 부호가 반대 -> 무조건 교차
// 둘 중 부호가 반대가 하나인 경우 -> 교차 아님.

// 2) CCW가 0
// 1. B의 좌표가 C좌표와 D좌표 사이에 있는지 확인 -> 교차 판별 가능

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

// 특정 a와 b점 사이에 점c가 존재하는지 확인
bool between(const Loc& a, const Loc& b, const Loc& c)
{
    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
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
    // cout << abc << ", " << abd << ", " << cda << ", " << cdb << "\n";
    // 일직선일 때, 점 A와 B 중 하나가 C와 D 사이에 존재
    // 또는 점 C와 D 중 하나가 A와 B 사이에 존재
    if(abc == 0 && abd == 0 && cda == 0 && cdb == 0)
        return between(c,d,a) || between(c,d,b) || between(a,b,c) || between(a,b,d);

    // 점 하나만 다른 선의 일직선일 때
    // 선분ab -> c,d
    if(abc == 0)
        return between(a,b,c);

    if(abd == 0)
        return between(a,b,d);

    // 선분cd -> a,b
    if(cda == 0)
        return between(c,d,a);

    if(cdb == 0)
        return between(c,d,b);

    // XOR 연산 : 부호가 둘 다 반대일 때만, 참 반환
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