#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class Node
{
public:
  std::vector<int> left;
  std::vector<int> right;
  int value;
  int high = 2;
};

void show(int a, std::vector<Node> store, std::vector<int> &c)
{
    if (store[a].left.size() != 0)
    {
        show(store[a].left[0], store, c);
    }
    c.push_back(store[a].value);
    if (store[a].right.size() != 0)
    {
        show(store[a].right[0], store, c);
    }
}

int main()
{
    std::ifstream file("input.txt");
    int all, value, count = 1, index;
    char q;
    std::string s;
    std::vector<Node> store;
    std::vector<int> check;
    while(getline(file, s))
    {
        if (count == 1)
        {
            all = s[0] - '0';
        }
        if (count == 2)
        {
            std::vector<Node> a (all);
            store = a;
            index = 0;
            int i = 0;
            while(index < s.length())
            {
                value = s[index] - '0';
                store[i].value = value;
                index = index + 2;
                i++;
            }
        }
        if (count >= 3)
        {
            index = s[0] - '0' - 1;
            q = s[2];
            value = s[4] - '0' - 1;
            if (q == 'R')
            {
                store[index].right.push_back(value);
                store[value].high = 1;
            }
            if (q == 'L')
            {
                store[index].left.push_back(value);
                store[value].high = 1;
            }
        }
        count++;
    }
    count = 0;
    for (int i = 0; i < store.size(); i++)
    {
        if (store[i].high == 2)
        {
            count = i;
            break;
        }
    }
    show(count, store, check);
    count = 0;
    for (int i = 1; i < check.size(); i++)
    {
        if(check[i] < check[i - 1])
        {
            count = 5;
        }
    }
    if (count == 5)
    {
        std::cout << "NO";
    }
    else
    {
        std::cout << "YES";
    }
}

//3
//1 2 3
//2 L 1
//1 R 3
