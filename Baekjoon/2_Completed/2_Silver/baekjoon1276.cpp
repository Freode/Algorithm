// 실버 1 - 1276번 : PLATFORME
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 플랫폼 정보 구조체
struct Platform
{
    int y = 0;
    int x1 = 0;
    int x2 = 0;
};

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 플랫폼 개수 N
    int N;
    cin >> N;

    // 플랫폼 정보 입력
    vector<Platform> platforms(N);
    int max_x = 0;
    for(Platform& platform : platforms)
    {
        cin >> platform.y >> platform.x1 >> platform.x2;
        platform.x2--;
        max_x = max(max_x, platform.x2);
    }

    // 높이 기준으로 오름차순 정렬
    sort(platforms.begin(), platforms.end(), [](const Platform& a, const Platform& b)
    {
        return a.y < b.y;
    });

    // 높이 시뮬레이션 
    vector<int> heights(max_x+1, 0);
    int result = 0;

    for(const Platform& platform : platforms)
    {
        result += (platform.y - heights[platform.x1]);
        result += (platform.y - heights[platform.x2]);

        // 높이 초기화
        for(int i = platform.x1; i <= platform.x2; i++)
        {
            heights[i] = platform.y;
        }
    }

    cout << result << "\n";

}