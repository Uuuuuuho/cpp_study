#include <iostream>
using namespace std;

template <class elemType>
class arrayListType
{
public:
  const arrayListType<elemType> &operator=(const arrayListType<elemType>&);
  bool isEmpty() const;
  bool isFull() const;
  int listSize() const;
  int maxListSize() const;
  void print() const;
  bool isItemAtEqual(int location , const elemType &item)const;
  void insertAt(int location, const elemType &insertItem);
  void insertEnd(const elemType& insertItem);
  void removeAt(int location);
  void retrieveAt(int locaiton, elemType &retItem) const;
  void replaceAt(int locaiton, const elemType &repItem);
  void clearList();
  int seqSearch(const elemType& item) const;
  void insert(const elemType& insertItem);
  void remove(const elemType& insertItem);
  arrayListType(int);
  arrayListType(const arrayListType<elemType> &otherList);
  ~arrayListType();
protected:
  elemType *list;
  int length;
  int maxSize;
};

template <class elemType>
inline const arrayListType<elemType> &arrayListType<elemType>::operator=(const arrayListType<elemType> &otherList)
{
  // TODO: insert return statement here
  if(this != &otherList){
    delete [] list;
    maxSize =otherList.maxSize;
    length = otherList.length;

    list = new elemType[maxSize];
    for(int i = 0; i < length; i++) list[i] = otherList.list[i];
  }  
  return *this;
}

template <class elemType>
inline bool arrayListType<elemType>::isEmpty() const
{
  return (length == 0);
}

template <class elemType>
inline bool arrayListType<elemType>::isFull() const
{
  return (length == maxSize);
}

template <class elemType>
inline int arrayListType<elemType>::listSize() const
{
  return length;
}

template <class elemType>
inline int arrayListType<elemType>::maxListSize() const
{
  return maxSize;
}

template <class elemType>
inline void arrayListType<elemType>::print() const
{
  for(int i = 0; i < length; i++) cout << list[i] << " ";
  cout << endl;
}

template <class elemType>
inline bool arrayListType<elemType>::isItemAtEqual(int location, const elemType &item) const
{
  return (list[location] == item);
}

template <class elemType>
inline void arrayListType<elemType>::insertAt(int location, const elemType &insertItem)
{
  if(location < 0 || location >= maxSize) cerr << "The position of the item to be inserted is out of range" << endl;
  else
    if(length >= maxSize)
      cerr << "cannot insert in a full list" << endl;
    else{
      for(int i = length; i> location; i--) list[i] = list[i-1];
      list[location] = insertItem;
      length++;
    }      
}

template <class elemType>
inline void arrayListType<elemType>::insertEnd(const elemType &insertItem)
{
  if(length >= maxSize) cerr << "cannot insert in a full list" << endl;
  else{
    list[length] = insertItem;
    length++;
  }
}

template <class elemType>
inline void arrayListType<elemType>::removeAt(int location)
{
  if(location < 0 || location >= length) cerr << "the location of the item to be removed is out of range" << endl;
  else{
    for(int i = location; i < length -1; i++) list[i] = list[i+1];

    length--;
  }
}

template <class elemType>
inline void arrayListType<elemType>::retrieveAt(int location, elemType &retItem) const
{
  if(location < 0 || location >= length) cerr << "the location of the item to be removed is out of range" << endl;
  else retItem = list[location];
}

template <class elemType>
inline void arrayListType<elemType>::replaceAt(int location, const elemType &repItem)
{
  if(location < 0 || location >= length) cerr << "the location of the item to be removed is out of range" << endl;
  else                                   list[location] = repItem;
}

template <class elemType>
inline void arrayListType<elemType>::clearList()
{
  length = 0;
}

template <class elemType>
inline void arrayListType<elemType>::insert(const elemType &insertItem)
{
  if(length >= maxSize)
    cerr << "cannot insert in a full list" << endl;
  else{
    list[length++] = insertItem;
  }        
}

template <class elemType>
inline void arrayListType<elemType>::remove(const elemType &insertItem)
{
  if(length <= 0)
    cerr << "cannot remove from a empty list" << endl;
  else
    length--;
}

template <class elemType>
inline arrayListType<elemType>::arrayListType(int size)
{
  if(size < 0){
    cerr << "negative array size is set" << endl;
    maxSize = 100;
  }
  else maxSize = size;

  length = 0;
  list = new elemType[maxSize];
}

template <class elemType>
inline arrayListType<elemType>::arrayListType(const arrayListType<elemType> &otherList)
{
  maxSize = otherList.maxSize;
  length  = otherList.length;
  list    = new elemType[maxSize];

  for(int i = 0; i < length; i++) list[i] = otherList.list[i];
}

template <class elemType>
inline arrayListType<elemType>::~arrayListType()
{
  delete [] list;
}
