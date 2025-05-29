// 골드 5 - 17609번 : 회문
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

using namespace std;

const int MAX_VALUE = numeric_limits<int>::max();

int simulate(const string& input, int start, int end, int count)
{
    while(start < end)
    {
        // 앞 뒤가 같음
        if(input[start] == input[end])
        {
            // 모두 한 칸씩 이동
            start++;
            end--;
        }
        // 앞 뒤가 다름
        else
        {
            count++;
            // 문자 2개 삭제하는 경우, 바로 반환
            if(count == 2)
                return 2;

            int result = MAX_VALUE;
            // 앞쪽 한 칸 이동
            if(input[start+1] == input[end])
                result = min(result, simulate(input, start + 1, end, count));

            // 뒤쪽 한 칸 이동
            if(input[start] == input[end-1])
                result = min(result, simulate(input, start, end - 1, count));

            // 둘 다 해당하지 않는 경우, 문자 2개 삭제
            if(result == MAX_VALUE)
                return 2;

            count = result;
            break;
        }
    }

    return count;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 문자열 개수 T
    int T;
    cin >> T;

    for(int i = 0; i < T; i++)
    {
        string input;
        cin >> input;

        cout << simulate(input, 0, input.size()-1, 0) << "\n";
    }
}