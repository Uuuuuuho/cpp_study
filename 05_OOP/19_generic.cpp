#include <iostream>

template <typename T, unsigned int N>
class Array
{
  T data[N];
public:
  // Constructor takes a C-style array reference. Note: function parameter
  // syntax `T &arr[N]` actually decays to a pointer type `T* arr` in
  // function parameter position, so this is equivalent to `T* arr` here.
  // The class template's non-type parameter `N` is the array size and is
  // used to copy exactly N elements into the internal buffer.
  Array(T &arr[N])
  {
    for(int i = 0; i < N; i++) data[i] = arr[i];
  }

  T* get_array(){ return data; }
  unsigned int size(){ return N; }
  void print_all()
  {
    for(int i = 0; i < N; i++) std::cout << data[i] << ", ";
    std::cout << std::endl;
  }
};

int main()
{
  int arr[3] = {1,2,3};

  // We explicitly specify the template parameters here: element type int
  // and size 3. The constructor copies the contents of the C-array into
  // the object's internal storage.
  Array<int, 3> arr_w(arr);
  arr_w.print_all();
}