#include <bits/stdc++.h>
using namespace std;

int main()
{

    string str_input;
    cin >> str_input;
    str_input = str_input + '$';
    map<int, char> symbol = {{0, 'i'}, {1, '+'}, {2, '*'}, {3, '('}, {4, ')'}, {5, '$'}, {6, 'E'}};
    map<char, int> number = {{'i', 0}, {'+', 1}, {'*', 2}, {'(', 3}, {')', 4}, {'$', 5}, {'E', 6}};
    vector<vector<char>> with_step{
        {'s', 'e', 'e', 's', 'e', 'e'},
        {'e', 's', 's', 'e', 'e', 'a'},
        {'s', 'e', 'e', 's', 'e', 'e'},
        {'e', 'r', 'r', 'e', 'r', 'r'},
        {'s', 'e', 'e', 's', 'e', 'e'},
        {'s', 'e', 'e', 's', 'e', 'e'},
        {'e', 's', 's', 'e', 's', 'e'},
        {'e', 'r', 's', 'e', 'r', 'r'},
        {'e', 'r', 'r', 'e', 'r', 'r'},
        {'e', 'r', 'r', 'e', 'r', 'r'}};
    vector<vector<int>> goto_state{
        {3, 1, 1, 2, 2, 1, 1},
        {3, 4, 5, 3, 2, 100, 1},
        {3, 1, 1, 2, 2, 1, 6},
        {3, 4, 4, 3, 4, 4, 1},
        {3, 1, 1, 2, 2, 1, 8},
        {3, 1, 1, 2, 2, 1, 8},
        {3, 4, 5, 3, 9, 4, 1},
        {1, 1, 5, 1, 1, 1, 1},
        {3, 2, 2, 3, 2, 2, 1},
        {3, 3, 3, 3, 3, 3, 1}};

    map<int, char> LHS = {{1, 'E'}, {2, 'E'}, {3, 'E'}, {4, 'E'}};
    map<int, int> rhs_count = {{1, 6}, {2, 6}, {3, 6}, {4, 2}};



    struct structure_ele
    {
        int var1;
        char var2;
    } first_var;

    stack<structure_ele> new_stk;
    first_var.var1 = 0;
    new_stk.push(first_var);

    stack<char> input1;

    for (int i = str_input.length() - 1; i >= 0; i--)
    {
        if (str_input[i] != 'd')
            input1.push(str_input[i]);
    }

    while (true)
    {
        if (input1.empty())
        {
            cout << "Not Accepted\n";
            break;
        }
        int num = new_stk.top().var1;
        char ele = input1.top();
        int k = number[ele];

        if (with_step[num][k] == 'e')
        {
            cout << "Not Accepted\n";
            if (goto_state[num][k] == 1)
                cout << "Operand Missing\n";
            if (goto_state[num][k] == 2)
                cout << "paranthesis unbalanced\n";
            if (goto_state[num][k] == 3)
                cout << "operator missing\n";
            if (goto_state[num][k] == 4)
                cout << "paranthesis missing\n";
            break;
        }
        else if (with_step[num][k] == 'r')
        {
            int r = goto_state[num][k];
            int ct_rhs = rhs_count[r];
            structure_ele char_ele, num_ele;
            while (ct_rhs--)
                new_stk.pop();
            char_ele.var2 = LHS[r];
            num_ele.var1 = goto_state[new_stk.top().var1][number[LHS[r]]];
            new_stk.push(char_ele);
            new_stk.push(num_ele);
        }

        else if (with_step[num][k] == 's')
        {
            int r = goto_state[num][k];
            structure_ele char_ent, num_ent;
            char_ent.var2 = ele;
            num_ent.var1 = r;
            new_stk.push(char_ent);
            new_stk.push(num_ent);
            input1.pop();
        }
        
        else
        {
            cout << "String Accepted\n";
            break;
        }
    }
    return 0;
}