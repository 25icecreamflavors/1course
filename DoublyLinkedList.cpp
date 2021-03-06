#include <iostream>

template<typename T>
class Node
{
public:
  Node *prev = nullptr;
  Node *next = nullptr;
  T value;
};

template <typename T>
class LinkedList
{
  Node<T> *Head, *Tail; 
  int m_size = 0;

public:
  LinkedList():Head(nullptr),Tail(nullptr){};
  int size ()
  {
    return m_size;
  }
  
  /*Inserts node with input value to specified position*/
  Node<T> *insert (T value, int pos) 
  {
    Node<T> *temp = new Node<T>;
    if (pos == m_size)
    {
      push_back(value);
    }
    else if (pos > m_size)
    {
      return nullptr;
    }
    else if (pos == 0)
    {
      m_size++;
      temp->prev = nullptr;
      temp->next = Head;
      Head->prev = temp;
      Head = temp;
      temp->value = value;
      return temp;
    }
    else if (pos > 0)
    {
      m_size++;
      int count = 0;
      Node<T> *tmp = Head;
      while (count != pos)
      {
        tmp = tmp->next;
        count++;
      }
      temp->next = tmp;
      temp->prev = tmp->prev;
      tmp->prev->next = temp;
      tmp->prev = temp;
      temp->value = value;
      return temp;
    }
    return nullptr;
  }

  /*Inserts node with input value in the end of the list */
  Node<T> *push_back (T value)
  {
    Node<T> *temp = new Node<T>;
    temp->next = nullptr;
    temp->value = value;
    if (Head != nullptr)
    {
      temp->prev = Tail;
      Tail->next = temp;
      Tail = temp;
    }
    else
    {
      temp->prev = nullptr;
      Head = Tail = temp;
    }
    m_size++;
    return temp;
  }
  
  /*Finds first node from the begin with given value*/
  Node<T> *find (T value)
  {
    Node<T> *temp = Head;
    if(temp == nullptr)
    {
      return nullptr;
    }
    else
    {
      while(temp != nullptr)
      {
        if(temp->value == value)
        {
          return temp;
        }
        temp = temp->next;
      }
      return nullptr;
    }
  }
  
  /*removes input node*/
  void remove (Node<T> *node)
  {
    if (Head == nullptr || node == nullptr)
    {
      return;
    }
    if (Head == node)
    {
      Head = node->next;
    }
    if (node->next != nullptr)
    {
      node->next->prev = node->prev;
    }
    if (node->prev != nullptr)
    {
      node->prev->next = node->next;
    }
    m_size--;
    delete node;
  }

  /*Reverses the list*/
  void reverse ()
  {
    Node<T> *save = Head;
    while(save != nullptr)
    {
      Node<T> *tmp = save->next;
      save->next = save->prev;
      save->prev = tmp;
      if (tmp == nullptr)
      {
        Tail = Head;
        Head = save;
      }
      save = tmp;
    }
  }
  
  /*Clears the list*/
  void clear ()
  {
    while (Head)                     
    {
      Tail = Head->next;
      delete Head;
      Head = Tail;
    }
    m_size = 0;
  }
  
  /*Prints list to stdout*/
  void print_list ()
  {
    Node<T> *temp = Head;
    while (temp != nullptr)
    {
      std::cout << temp->value << " ";
      temp = temp->next;
    }
    std::cout << "\n";
  }

  ~LinkedList ()
  {
  }
};

int main()
{
  Node<int> *temp = new Node<int>;
  LinkedList<int> a;
  a.insert(2, 0);
  a.insert(1, 0);
  a.insert(2, 0);
  a.insert(3, 2);
  a.print_list();
  a.clear();
  a.insert(3, 0);
  a.insert(4, 7);
  a.insert(2, 1);
  temp = a.find(4);
  a.remove(temp);
  a.print_list();
  std::cout<< "\n" << a.size();
}
