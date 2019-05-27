#include <iostream>

template <typename T, typename TPred>
void heapify(T& a, size_t size, size_t i, TPred pred)
{
  int root = i;
  int node1 = 2*i + 1;
  int node2 = 2*i + 2;
  if ((node1 < size) && (pred(a[node1], a[root]) != true))
  {
    root = node1;
  }
  if ((node2 < size) && (pred(a[node2], a[root]) != true))
  {
    root = node2;
  }
  if (root != i)
  {
    std::swap(a[i], a[root]);
    heapify(a, size, root, pred);
  }
}

#include <iostream>

template <typename T, typename TPred>
void heapify(T& a, size_t size, size_t i, TPred pred)
{
  size_t root = i;
  size_t node1 = (size_t)2*i + (size_t)1;
  size_t node2 = (size_t)2*i + (size_t)2;
  if ((node1 < size) && (pred(a[node1], a[root]) != true))
  {
    root = node1;
  }
  if ((node2 < size) && (pred(a[node2], a[root]) != true))
  {
    root = node2;
  }
  if (root != i)
  {
    std::swap(a[i], a[root]);
    heapify(a, size, root, pred);
  }
}

template <typename T, typename TPred>
void buildHeap(T& a, size_t size, TPred pred)
{
  size_t i;
  i = size/(size_t)2 + (size_t)1;
  while(i > 0)
  {
    heapify(a, size, i, pred);
    i = i - (size_t)1;
  }
  heapify(a, size, i, pred); 
}
