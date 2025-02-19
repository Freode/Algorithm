// 골드 4 - 1339번 : 단어 수학
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

typedef long long ll;

struct LetterInfo
{
    char letter = 'A';
    vector<int> idx;

    LetterInfo()
    {
        idx = vector<int>(8,0);
    }
};

// 단어 입력
void InputWord(vector<string>& in_words, int& in_max_length)
{
    for(string& word : in_words)
    {
        cin >> word;
        in_max_length = max(in_max_length, (int)word.size());
    }
}

// 단어에 숫자 할당할 순서 저장
void CheckWordSeq(vector<LetterInfo> &in_let_info, vector<string> &in_words, const int in_max_length)
{
    // 글자 정보 초기화
    for(int i = 1; i < in_let_info.size(); i++)
    {
        // B C D..로 초기화
        in_let_info[i].letter += i;
    }

    // 가장 긴 단어의 길이만큼 검사
    for(int i = in_max_length-1; i >= 0; i--)
    {
        // 단어 개수만큼 검사
        for(const string& word : in_words)
        {
            // 검사 길이가 단어 길이보다 길면, 무시
            if(i+1 > word.size()) continue;

            // 글자 검사
            int idx = word.size() - i - 1;
            char letter = word[idx];

            // 등장 시기와 횟수를 모두 기록
            int letter_idx = letter - 'A';
            in_let_info[letter_idx].idx[i]++;

            // 만약에 10번 등장한 경우에는 한 자리를 올리기
            // 단, 제일 앞자리에서는 범위로 인해서 하지 않기
            for(int k = i; k < in_let_info[letter_idx].idx.size() - 1; k++)
            {
                if(in_let_info[letter_idx].idx[k] == 10)
                {
                    in_let_info[letter_idx].idx[k] = 0;
                    in_let_info[letter_idx].idx[k+1]++;
                }
            }
        }
    }
}

// 글자에 숫자를 배정
void RegistLetter(unordered_map<char, int>& in_maps, vector<LetterInfo> &in_let_info)
{
    // 내림차순 정렬
    sort(in_let_info.begin(), in_let_info.end(), [](const LetterInfo &a, const LetterInfo &b)
    {
        for(int i = a.idx.size()-1; i >= 0; i--)
        {
            // 0. 둘 다 해당 시기에 등장하지 않으면, 무시
            if(a.idx[i] == 0 && b.idx[i] == 0) continue;

            // 1. 먼저 등장한 경우
            // 2. 같이 등장했지만, 등장 횟수가 더 많은 경우
            // 3. 횟수가 서로 다를 때까지 비교
            if(a.idx[i] != b.idx[i]) return a.idx[i] > b.idx[i];
        }

        // 두 값이 완전히 동일한 경우, 정렬하지 않음
        return false;
    });

    // 글자에 숫자 배정
    int regist = 9;
    for(LetterInfo& let_info : in_let_info)
    {
        in_maps[let_info.letter] = regist;
        regist--;
    }

}

// 단어를 숫자로 치환
void ChangeLetterToInt(vector<string> &in_words, unordered_map<char, int>& in_maps)
{
    for(string& word : in_words)
    {
        for(char& letter : word)
        {
            letter = in_maps[letter] + '0';
        }
    }
}

// 숫자를 모두 합하기
int AddResult(vector<string>& in_words)
{
    int result = 0;
    for(const string& word : in_words)
    {
        result += stoi(word);
    }
    return result;
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // N개 단어 입력
    int N;
    cin >> N;

    // 단어 입력
    int max_length = 0;
    vector<string> words(N);
    InputWord(words, max_length);

    // 단어에 숫자 할당할 순서를 저장하거나 확인
    unordered_map<char, int> maps;
    vector<LetterInfo> let_info(26);
    CheckWordSeq(let_info, words, max_length);

    // 글자에 숫자를 배정
    RegistLetter(maps, let_info);

    // 단어를 숫자로 치환
    ChangeLetterToInt(words, maps);

    // 숫자를 모두 합하기
    int result = AddResult(words);

    cout << result << "\n";
}