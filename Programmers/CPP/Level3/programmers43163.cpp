// Lv.2 - 42583번 : 다리를 지나는 트럭 
// 작성자 : jeonghoe22(최정호)

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>

using namespace std;

bool CompareWords(const string& A, const string& B)
{
    int same_letters = 0;
    for(int i = 0; i < (int)A.size(); i++)
    {
        if(A[i] == B[i]){ same_letters++; }
    }
    cout << "A : " << A << ", B : " << B << ", same letter : " << same_letters << "\n";
    return same_letters == (int)A.size() - 1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    bool b_is_in_words = false;
    map<string, pair<bool, int>> word_map;
    word_map[begin] = make_pair(true, 0);

    for(string& word : words)
    {
        if(word == target){ b_is_in_words = true; }
        word_map[word] = make_pair(false, 0);
    }

    queue<string> queue_word;
    string current_word;
    queue_word.push(begin);
    if(b_is_in_words == true)
    {
        while(queue_word.empty() == false)
        {
            current_word = queue_word.front();
            for(string& each : words)
            {
                if(CompareWords(each, current_word)&& word_map[each].first == false)
                {
                    word_map[each].first = true;
                    word_map[each].second = word_map[current_word].second + 1;
                    queue_word.push(each);
                }
            }
            queue_word.pop();
        }
        answer = word_map[target].second;
    }

    return answer;
}