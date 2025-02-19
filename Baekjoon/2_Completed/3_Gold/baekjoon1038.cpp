// 골드 5 - 1038번 : 감소하는 수
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <functional>

using namespace std;

typedef long long ll;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // N번째 수, 입력
    int N;
    cin >> N;

    // 우선순위 큐에 하나씩 넣기
    int count = 0;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll result = -1;
    que.push(0);

    // 내림 수를 모두 검사
    while(que.empty() == false)
    {
        ll num = que.top();
        que.pop();

        // 만족하는 수 발견 시, 종료
        if(count == N)
        {
            result = num;
            break;
        }
        count++;

        // 1~9까지 검사 
        for(int i = 1; i < 10; i++)
        {
            string str_num = to_string(num);
            int front = str_num[0] - '0';
            
            // 현재 자리보다 앞 자리가 큰 경우에만 추가
            if(front < i)
            {
                char new_num_front = i + '0';
                string str_new_num; 
                // 앞자리에 더 큰 수를 추가
                if(front != 0) { str_new_num = new_num_front + to_string(num); }
                // 0일 경우, 한 자리 수도 작동하므로 예외 처리
                else
                { 
                    // 한 자리 수 추가
                    str_new_num = new_num_front;
                    que.push(stoll(str_new_num));
                    // 두 자리 수 이상 추가
                    str_new_num = new_num_front + to_string(num);
                }

                que.push(stoll(str_new_num));
            }
        }
    }

    cout << result << "\n";
}