// Lv.3 - 43163번 : 단어 변환
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// 두 단어끼리 글자가 몇 개 같은지 확인
bool CompareWords(const string& A, const string& B)
{
    int same_letters = 0;
    for(int i = 0; i < (int)A.size(); i++)
    {
        if(A[i] == B[i]){ same_letters++; }
    }
    // 1글자만 다른 경우에 true 반환
    return same_letters == (int)A.size() - 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    // map에 단어 정보 (방문 여부, 언제 방문)을 초기화
    bool b_is_in_words = false;
    map<string, pair<bool, int>> word_map;
    word_map[begin] = make_pair(true, 0);

    for(string& word : words)
    {
        if(word == target){ b_is_in_words = true; }
        word_map[word] = make_pair(false, 0);
    }
    
    // 현재 단어 목록에 target이 있는 경우에만 queue 실행
    queue<string> queue_word;
    string current_word;
    queue_word.push(begin);
    if(b_is_in_words == true)
    {
        while(queue_word.empty() == false)
        {
            current_word = queue_word.front();
            // 각 단어별로 비교
            for(string& each : words)
            {
                // 방문하지 않고 글자가 1개만 다른 경우
                if(CompareWords(each, current_word)&& word_map[each].first == false)
                {
                    word_map[each].first = true;
                    word_map[each].second = word_map[current_word].second + 1;
                    queue_word.push(each);
                }
            }
            queue_word.pop();
        }
        // 정답 반환
        answer = word_map[target].second;
    }

    return answer;
}