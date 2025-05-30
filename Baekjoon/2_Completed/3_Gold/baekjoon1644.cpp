// 골드 3 - 1644번 : 소수의 연속합
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cmath>

using namespace std;

const int MAX_SIZE = 4'000'000;

vector<int> g_primes;

// 소수 목록 구하기
int getPrimes(const int N)
{
    g_primes.reserve(MAX_SIZE);

    vector<bool> checks(MAX_SIZE+1, true);
        checks[1] = false;

    // 소수 판별
    for(int i = 2; i * i <= MAX_SIZE; i++)
    {
        if(checks[i] == true)
        {
            for(int j = (i << 1); j <= MAX_SIZE; j += i)
            {
                checks[j] = false;
            }
        }
    }

    int start = 0;
    // 소수만 따로 목록으로 만들기
    for(int i = 2; i <= MAX_SIZE; i++)
    {
        if(checks[i] == true)
        {
            g_primes.push_back(i);
            
            if(i <= N)
                start = g_primes.size()-1;
        }
    }

    return start;
}

int simulate(const int N, const int _start)
{
    int start = _start, end = _start;
 
    int result = 0;
    int sum = g_primes[start];

    while(start <= end)
    {
        int size = end - start + 1;
        
        // 현재 수와 일치하는지 
        if(sum == N)
            result++;

        // 현재 개수 한 개
        if(size == 1)
        {
            start--;
            if(start < 0)
                break;

            sum += g_primes[start];
        }
        
        // 현재 개수가 여러 개
        else
        {
            // 값이 더 크면, 끝에 하나 감소
            if(sum > N)
            {
                sum -= g_primes[end];
                end--;
            }
            // 값이 더 작으면, 앞에 하나 추가
            else if(sum <= N)
            {
                start--;
                if(start < 0)
                    break;
                
                sum += g_primes[start];
            }
        }
    }

    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 자연수 N
    int N;
    cin >> N;

    int start = getPrimes(N);
    cout << simulate(N, start) << "\n";

}