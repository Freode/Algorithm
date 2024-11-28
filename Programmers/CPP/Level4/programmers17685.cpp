// Lv.4 - 17685번 : [3차] 자동완성
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 1. 단어 목록 오름차순
// 2. 바로 앞과 뒤 단어와 비교해서 중복 횟수 세기

int compare_words(string& A, string& B, string& C)
{
    int ab_size = min(A.size(), B.size());
    int bc_size = min(B.size(), C.size());

    int duplicate_a_count = 0, duplicate_b_count = 0;

    // A와 B 비교 - 길이 작은 것으로 비교
    for(int i = 0; i < ab_size; i++)
    {
        // 글자 중복
        if(A[i] == B[i])
        {
            duplicate_a_count++;
        }
        // 다르면, 바로 중단
        else
        {
            break;
        }
    }

    // B와 C 비교 - 길이 작은 것으로 비교
    for(int i = 0; i < bc_size; i++)
    {
        // 글자 중복
        if(B[i] == C[i])
        {
            duplicate_b_count++;
        }
        // 다르면, 바로 중단
        else
        {
            break;
        }
    }

    // 더 많이 중복되는 것으로 반환
    return max(duplicate_a_count, duplicate_b_count);
}

int solution(vector<string> words) {
    int answer = 0;

    sort(words.begin(), words.end());
    vector<int> duplicates(words.size(), 0);

    string empty = "";
    for(int i = 0; i < words.size(); i++)
    {
        // 처음
        if(i == 0)
        {
            duplicates[i] = compare_words(empty, words[0], words[1]);
        }
        // 마지막
        else if(i == words.size() - 1)
        {
            duplicates[i] = compare_words(words[i - 1], words[i], empty);
        }
        // 중간
        else
        {
            duplicates[i] = compare_words(words[i - 1], words[i], words[i + 1]);
        }
    }

    // 중복된 횟수와 글자 길이가 다를 경우에는 + 1
    for(int i = 0; i < duplicates.size(); i++)
    {
        answer += (duplicates[i] == words[i].size() ? duplicates[i] : duplicates[i] + 1);
    }

    return answer;
}