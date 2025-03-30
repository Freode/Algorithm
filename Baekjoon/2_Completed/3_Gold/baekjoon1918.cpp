// 골드 2 - 1167번 : 트리의 지름
// 작성자 : free4760(jeonghoe22)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

// 중위 표기식을 후위 표기식으로 변경

// 괄호 영향

// 연산자를 스택에 넣음.
// 문자는 그대로 출력

// 연산자 push, pop 조건
// 우선 순위가 더 높은 것이 뜨면, psuh
// 우선 순위가 같거나 더 낮으면, 모두 pop

// 우선 순위 
// 1. 괄호)
// 2. *,/
// 3. +,-
// 4. 괄호(

// 괄호)는 괄호(까지 pop 진행

unordered_map<char, int> umap_priority;

void setPriority()
{
    umap_priority['('] = 0;
    umap_priority[')'] = 3;
    umap_priority['+'] = 1;
    umap_priority['-'] = 1;
    umap_priority['*'] = 2;
    umap_priority['/'] = 2;
}

bool isEnglish(const char c)
{
    return c >= 'A' && c <= 'Z';
}

int main()
{
    // 입출력 최적화
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string input;
    cin >> input;

    setPriority();

    stack<char> stk;
    int prev_priority = 0;
    // 글자마다 검사
    for(char& each : input)
    {
        // 문자는 무조건 출력
        if(isEnglish(each))
        {
            cout << each;
            continue;
        }
        // 연산자, 스택과 비교

        // 스택이 비어있음.
        if(stk.empty())
        {
            stk.push(each);
            prev_priority = umap_priority[each];
            continue;
        }

        int cur_priority = umap_priority[each];
        // (가 나올때까지 출력
        if(each == ')')
        {
            while(true)
            {
                char c = stk.top();
                stk.pop();

                if(c == '(') break;
                cout << c;
            }
            prev_priority = stk.empty() ? 0 : umap_priority[stk.top()];
        }
        // 우선 순위가 같은 연산자가 들어온 경우, 자기 자신만 pop
        else if(cur_priority == prev_priority && each != '(')
        {
            cout << stk.top();
            stk.pop();

            prev_priority = umap_priority[each];
            stk.push(each);
        }
        // 우선 순위가 낮은 연산자가 들어온 경우, 조건에 따라 모두 pop
        else if(cur_priority < prev_priority && each != '(')
        {
            char c = stk.top();

            // 우선순위가 같을 때까지 출력
            while(stk.empty() == false && stk.top() != '(')
            {
                c = stk.top();
                stk.pop();
                cout << c;
            }

            prev_priority = umap_priority[each];
            stk.push(each);
        }
        // 추가
        else
        {
            // 이전 연산자의 우선순위가 더 낮으면, pop
            // if(cur_priority > prev_priority)
            // {
            //     cout << stk.top();
            //     stk.pop();
            // }

            prev_priority = umap_priority[each];
            stk.push(each);
        }
    }

    // 마지막에 스택 비우기
    while(stk.empty() == false)
    {
        cout << stk.top();
        stk.pop();
    }
}