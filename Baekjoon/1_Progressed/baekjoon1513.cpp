// 골드 2 - 1513번 : 경로 찾기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// N*M (각 1~50)
// 세준이네 집 위치 1,1 -> 학원 N,M

// 오락실 개수 C -> (0~50)
// 오락실 위치 중복 x
// 오락실 번호는 증가하는 순서대로만 갈 수 있음.
// 2번 오락실 : x -> 2번 or x -> 1번 -> 2번

// 이동 : 아래와 오른쪽만 가능
// 오락실 0개 방문부터 C번 방문까지 모두 출력
// 경우의 수는 1'000'007을 나머지 연산해서 출력

const int DIV = 1'000'007;

struct Area
{
    
};

vector<vector<vector<int>>> g_areas;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 세로 N, 가로 M, 오락실 개수 C

}