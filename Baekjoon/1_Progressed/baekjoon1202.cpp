// 골드 2 - 1202번 : 보석 도둑
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 보석, 가방 개수 1~300'000

// 보석 정보 M, V (0~1'000'000)
// 가방에 담을 수 있는 최대 무게 C (1~100'000'000)

// 보석 가격이 높은 순서, 같다면, 무게가 낮은 순서
// 가방 크기가 여유 있는 순서부터

struct Bag
{
    int idx = 0;
    int cur_weight = 0;
    int max_weight = 0;
    int value = 0;

    bool operator<(const Bag& other) const
    {
        return (max_weight - cur_weight) > 
    }
};

struct Jewel
{
    int value = 0;
    int weight = 0;
};

vector<int> g_jewel;


// 정보 입력
void inputInfo(const int N, const int K)
{
    
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 보석 개수 N, 가방 개수 k
    int N, K;
    cin >> N >> K;


}