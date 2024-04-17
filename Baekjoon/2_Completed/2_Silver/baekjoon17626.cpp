// 실버 3 - 17626번 : Four Squares
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 제곱 수 미리 구하기
    vector<int> squares;
    for(int i = 0; i < 500; i++)
    {
        if(i * i <= 50000)
        {
            squares.push_back(i * i);
        }
        else
        {
            break;
        }
    }

    // 입력
    int n;
    cin >> n;

    int num = n;
    int square_num = 1;
    int temp;
    vector<int> cases(num + 1, 5);
    for(int i = 1; i <= num; i++)
    {
        // 제곱수일 때
        if(squares[square_num] == i)
        {
            cases[i] = 1;
            square_num++;
        }
        // 제곱수가 아닐 때
        else
        {
            // 현재 검사하는 수보다 작은 제곱수를 모두 계산
            // 현재 제곱수의 경우인 (1) + [현재 검사하는 수 - 현재 제곱수]의 경우로 계산
            for(int j = square_num - 1; j > 0; j--)
            {
                temp = cases[squares[j]] + cases[i - squares[j]];
                // 최솟값 변경
                if(temp < cases[i]){ cases[i] = temp; }
            }
        }
    }
    cout << cases[n] << "\n";
}