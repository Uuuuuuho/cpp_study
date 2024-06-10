// <MergeSort>
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1000001

void merge(std::vector<int>& vec, int start, int mid, int end);
void merge_sort(std::vector<int>& vec, int start, int end);

int main()
{
  std::vector<int> v = { 0, 26, 5, 37, 1, 61, 11, 59, 15, 48, 19 };
  int N = 0, i = 0;

  // std::sort(v.begin(), v.end());
  merge_sort(v, 0, v.size());

  for(i = 0; i < v.size(); i++)
    std::cout << v[i] << "\n";
}

void merge(std::vector<int>& vec, int start, int mid, int end)
{
  static std::vector<int> sorted(MAX);
  int i = start;
  int j = mid + 1;
  int k = start;

  while(i <= mid && j <=end)
  {
    if(vec[i] <= vec[j])
    {
      sorted[k] = vec[i];
      i++;
    }
    else
    {
      sorted[k] = vec[j];
      j++;
    }
    k++;
  }

  if(i > mid)
  {
    for(int t = j; t <= end; t++)
    {
      sorted[k] = vec[t];
      k++;
    }
  }
  else
  {
    for(int t = i; t <= mid; t++)
    {
      sorted[k] = vec[t];
      k++;
    }
  }

  for(int t = start; t <= end; t++)
    vec[t] = sorted[t];

}

void merge_sort(std::vector<int>& vec, int start, int end)
{
  if(start < end)
  {
    int mid = (start + end) / 2;
    merge_sort(vec, start, mid);
    merge_sort(vec, mid+1, end);
    merge(vec, start, mid, end);
  }
}