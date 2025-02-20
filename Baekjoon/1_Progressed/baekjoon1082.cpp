// 골드 3 - 1082번 : 방 번호
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 숫자 종류 N, 준비한 금액 M
    int N, M;
    cin >> N;

    // 각 번호 별로의 금액
    vector<int> costs(N);
    for(int& cost : costs) { cin >> cost; }
    cin >> M;

    // 1. 숫자 개수가 많을 수록 높은 수
    // 2. 개수가 같을 경우, 높은 수일수록 우선순위가 앞
    
}