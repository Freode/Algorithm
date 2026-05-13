// Lv.3 - 81303번 : 표 편집
// 작성자 : jeonghoe22(최정호)


#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

// stack 이용
// 0 1 2 3 4 5 6

// 0 1 2 4 5 6
// (3, 2, 4)

// 0 1 4 5 6
// (2, 1, 4)
// (3, 2, 4)

struct Node
{
    int idx = 0;
    int prev = 0;
    int next = 0;
};

string solution(int n, int k, vector<string> cmd) {

    vector<Node> nodes = vector<Node>(n);
    
    for(int i = 0; i < n; i++)
    {
        nodes[i].idx = i;
        nodes[i].prev = i - 1;
        nodes[i].next = i + 1;
    }
    
    nodes[n - 1].next = -1;
    
    stack<Node> s;
    
    for(const string& c : cmd)
    {
        switch(c[0])
        {
            // 위로 이동
            case 'U':
            {
                int move = 0;
                for(int i = 2; i < c.size(); i++)
                {
                    move = move * 10 + (c[i] - '0');
                }
                
                for(int i = 0; i < move; i++)
                {
                    k = nodes[k].prev;
                }
                
                break;
            }
            // 아래로 이동
            case 'D':
            {
                int move = 0;
                for(int i = 2; i < c.size(); i++)
                {
                    move = move * 10 + (c[i] - '0');
                }
                
                for(int i = 0; i < move; i++)
                {
                    k = nodes[k].next;
                }
                break;
            }
                
            // 삭제
            case 'C':
            {
                s.push(nodes[k]);
                
                nodes[k].idx = -1;
                
                if(nodes[k].prev != -1)
                    nodes[nodes[k].prev].next = nodes[k].next;
                
                if(nodes[k].next != -1)
                    nodes[nodes[k].next].prev = nodes[k].prev;
                
                if(nodes[k].next != -1)
                    k = nodes[k].next;
                else
                    k = nodes[k].prev;
                
                break;
            }
                
            // 복원
            case 'Z':
            {
                Node recover = s.top();
                s.pop();
                
                nodes[recover.idx].idx = recover.idx;
                
                if(recover.prev != -1)
                    nodes[recover.prev].next = recover.idx;
                
                if(recover.next != -1)
                    nodes[recover.next].prev = recover.idx;
                break;
            }
            
        }
        
    }
    
    string answer(n, 'O');
    
    for(int i = 0; i < n; i++)
    {
        answer[i] = ((nodes[i].idx == -1) ? 'X' : 'O');
    }
    
    return answer;
}