// 골드 5 - 1263번 : 시간 관리
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info
{
    int t = 0;
    int s = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 일 N개
    int N;
    cin >> N;

    // Ti 시간 소요, Si 내에 처리
    vector<Info> works(N);
    for(Info& work : works)
    {
        cin >> work.t >> work.s;
    }

    // 가장 늦게 끝낼 수 있는 것부터 종료

    // 끝내는 시간 기준으로 내림차순
    sort(works.begin(), works.end(), [](const Info& a, const Info& b)
    {
        return a.s > b.s;
    });

    int time = works[0].s;

    // 모든 일 순환
    for(const Info& work : works)
    {
        // 시작 시간에 도달 못한 경우
        if(time > work.s) time = work.s;
        time -= work.t;
    }

    // 처음에 시작해도 불가능한 경우
    if(time < 0) time = -1;

    cout << time << "\n";
}