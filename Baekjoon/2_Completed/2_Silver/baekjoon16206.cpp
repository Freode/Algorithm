// 실버 1 - 16206번 : 롤케이크
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
    cout.tie(nullptr);

    // 케이크 개수 N, 자를 수 있는 횟수 M
    int N, M;
    cin >> N >> M;

    vector<int> cakes(N);
    for(int& cake : cakes)
    {
        cin >> cake;
    }
 
    // 10으로 나눠떨어지는 수부터 앞으로 오도록 정렬
    sort(cakes.begin(), cakes.end(), 
    [](const int& a, const int& b)
    {
        bool b_aDiv10 = (a % 10 == 0);
        bool b_bDiv10 = (b % 10 == 0);

        // 둘 다, 10으로 나눠지는 경우에는 오름차순 정렬
        if(b_aDiv10 && b_bDiv10)
        {
            return a < b;
        }

        // 둘 중 하나만 10으로 나눠지는 경우, 10으로 나눠지는 수를 앞으로
        if(b_aDiv10 || b_bDiv10)
        {
            // a가 10으로 나눠 떨어짐. -> true : a를 앞으로
            // b가 10으로 나눠 떨어짐. -> false : b를 앞으로
            return b_aDiv10;
        }

        // 둘 다 10으로 나눠지지 않는 경우, 오름차순 정렬
        return a < b;
    });

    int result = 0;
    int cut_count = 0;

    // 케이크 별로 검사
    for(const int& cake : cakes)
    {
        // 자른 횟수가 최대치인 경우, 종료
        if(cut_count == M) break;

        // 사용 가능한 케이크 조각 수와 자른 횟수 구하기
        int piece = cake / 10;
        int cur_cut = (cake % 10 == 0) ? piece - 1 : piece;

        // 최대 횟수까지 자를 때
        if(M-cut_count < cur_cut)
        {
            cur_cut = M-cut_count;
            piece = cur_cut;
        }

        result += piece;    
        cut_count += cur_cut;
    }

    cout << result << "\n";
}