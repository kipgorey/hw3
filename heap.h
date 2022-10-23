#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>


template <typename T, typename PComparator = std::less<T> >
class Heap
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;

private:
  /// Add whatever helper functions and data members you need below

  void heapify_up();
  void heapify_down();

  void location_swap(int index, int parent_index);
  int greatest_child(int index, bool is_greater);

  int m_;
  PComparator c_;
  std::vector<T> heap;



};

// Add implementation of member functions here



template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{
  m_ = m;
  c_ = c;

}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap()
{
  
  


}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item)
{
  heap.push_back(item);
  heapify_up();

}

// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The heap is empty");

  } else {
    return heap[0];
  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element
  

}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================
    throw std::underflow_error("The Heap is empty.");

  }

  T temp = heap.back();
  heap[0] = temp;

  heap.pop_back(); // gets rid of the duplicate back element

  heapify_down();

  
}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
  if(heap.size() == 0)
  {
    return true;
  } else {
    return false;
  }

}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const
{
  return heap.size();

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_up(){
  // take the last element in the vector and run heapify up with item

  int index = this->heap.size() - 1; // last element in the vector

  int parent_index = (index-1)/this->m_;
  while(parent_index >= 0 && c_(heap[index], heap[parent_index]) && index > 0)
  {
    location_swap(index, parent_index);
    index = parent_index;
    parent_index = (index-1) / m_;

  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::heapify_down()
{
  int index = 0; // first element
  bool is_greater = true;

  if(empty())
  {
    return;
  }

  while(heap.size() > (index * m_) + 1 && is_greater) // the heap / vector is not empty
  {
    int next = greatest_child(index, is_greater);

    if((index * m_) + m_ >= heap.size() || index == next)
    {
      is_greater = false; // this means that the tree is not full so you know your at the end
    // of the heap tree
    }

    if(next > index) // need to swap
    {
      location_swap(index, next);
      index = next;
    }
  }

}

template <typename T, typename PComparator>
void Heap<T, PComparator>::location_swap(int index, int parent_index)
{
  T temp = heap[index];
  heap[index] = heap[parent_index];
  heap[parent_index] = temp;

  // delete temp if necessary

}

template <typename T, typename PComparator>
int Heap<T, PComparator>::greatest_child(int index, bool is_greater)
{
  T parent = heap[index];
  T return_child = parent; // preset to assume no swapping
  int return_c_index = index; // preset to assume no swapping
  for(int i = 1; i <= m_; i++)
  {
    if(heap.size() > (index * m_) + i) // if the child exists
    {
      T temp_child = heap[(index*m_) + i];
      // check to see if you shoudld swap 
      if(c_(temp_child, return_child))
      {
        return_child = temp_child;
        return_c_index = (index*m_) + i;
      }
    }

  }

  if((index * m_) + m_ >= heap.size() || parent == return_child)
  {
    is_greater = false; // this means that the tree is not full so you know your at the end
    // of the heap tree
  }

  return return_c_index;
}




#endif

