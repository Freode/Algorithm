// Lv.3 - 43238번 : 입국심사
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <limits>

using namespace std;

// 10^9 * 10^9
// 우선순위 큐 -> 10^9
// 이분탐색 -> 10^5 * log(10^18)

using ll = long long;

long long solution(int n, vector<int> times) {
    ll answer = 0;
    
    ll left = 0;
    ll right = numeric_limits<ll>::max() >> 1;
    
    while(left <= right)
    {
        ll mid = (left + right) >> 1;
        ll num = 0;
        
        for(const int& time : times)
        {
            num += mid / time;
            
            if(num >= n)
                break;
        }
        
        if(num >= n)
        {
            answer = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    
    return answer;
}