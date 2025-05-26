// 골드 4 - 19597번 : 문자열 뒤집기
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// N개 문자열 -> Reverse 함수 적용할지 마를지 고를 수 있음.
// 즉, 2^N개 방법 존재
// Reverse 적용 1, 적용 x 0

// N개의 문자열을 사전순으로 정렬할 때, 가장 앞서는 리버스 문자열 출력

vector<string> g_cur_words;
vector<string> g_rev_words;
string g_result = "";

void inputData(const int N)
{
    g_cur_words.resize(0);
    g_rev_words.resize(0);
    g_result = "";

    string cur_input;
    string rev_input;

    for(int i = 0; i < N; i++)
    {
        cin >> cur_input;

        rev_input = cur_input;
        reverse(rev_input.begin(), rev_input.end());
        
        g_cur_words.push_back(cur_input);
        g_rev_words.push_back(rev_input);

        if(cur_input < rev_input)
            g_result += "0";

        else
            g_result += "1";
    }
}

void simulate(const int N)
{
    int count = 0;
    for(int idx = 1; idx < N; idx++)
    {
        // 비교할 문자열 선택
        string& cur_string = (g_result[idx] == '1') ? g_rev_words[idx] : g_cur_words[idx];
        string& prev_string = (g_result[idx-1] == '1') ? g_rev_words[idx-1] : g_cur_words[idx-1];
        
        // 이전과 비교해서, 사전순이 아닐 경우
        if(prev_string > cur_string)
        {
            char state = g_result[idx];
            // 현재 문자열을 reverse 처리
            g_result[idx] = (state == '0') ? '1' : '0';
            // 다시 검사하도록, idx를 1 감소
            if(idx > 1) idx--;
            count++;

            // 둘 다 사전순이 만족하지 않는 경우, 한 칸 더 앞으로 이동
            if(count == 2)
            {
                if(idx > 1) idx--;
                count = 0;
            }
        }

        // 사전순이면, 문제 없이 다음 단계로 진행
        count = 0;
    }

    cout << g_result << "\n";
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 T
    int T;
    cin >> T;
    g_cur_words.reserve(150);
    g_rev_words.reserve(150);

    for(int i = 0; i < T; i++)
    {
        // 단어 개수 N
        int N;
        cin >> N;

        inputData(N);
        simulate(N);
    }
}