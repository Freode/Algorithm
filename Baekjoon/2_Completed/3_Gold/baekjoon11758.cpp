// 골드 5 - 11758번 : CCW
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Loc
{
    int y = 0;
    int x = 0;
};

vector<Loc> g_locs(3);

// ax bx cx ax
// ay by cy ay

int ccw(const Loc& a, const Loc& b, const Loc& c)
{
    return a.x*b.y + b.x*c.y + c.x*a.y - a.y*b.x - b.y*c.x - c.y*a.x;
}

int check()
{
    // b를 기준으로 판단
    int bac = ccw(g_locs[1], g_locs[0], g_locs[2]);

    // 일직선
    if(bac == 0)
        return 0;

    // 방향 존재
    // 양수 -> 반시계 : -1
    // 음수 -> 시계 : 1
    return bac > 0 ? -1 : 1;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    for(Loc& loc : g_locs)
        cin >> loc.x >> loc.y;

    cout << check() << "\n";
}