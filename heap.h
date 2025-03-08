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

  std::vector<T> data_;
  int m_;
  PComparator comp_;

  void perc_down(size_t idx);
  void perc_up(size_t idx);
};

// Add implementation of member functions here

template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c) : m_(m), comp_(c) {}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() {}

template <typename T, typename PComparator>
void Heap<T, PComparator>::push(const T& item) {
  
  data_.push_back(item);
  perc_up(data_.size() - 1);
}

template <typename T, typename PComparator>
void Heap<T, PComparator>::perc_up(size_t idx) {

  while(idx > 0) {
    size_t parent_idx = (idx - 1) / m_;

    if(comp_(data_[idx], data_[parent_idx])) {
      std::swap(data_[idx], data_[parent_idx]);

      idx = parent_idx;
    }

    else {
      break;
    }
  }
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

    throw std::underflow_error("Heap is empty");

  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element

  return data_[0];
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
    
    throw std::underflow_error("Heap is empty");

  }

  data_[0] = data_.back();
  data_.pop_back();

  if(!empty()) {
    perc_down(0);
  }
}


template <typename T, typename PComparator>
void Heap<T, PComparator>::perc_down(size_t idx) {

  while(true) {
    size_t prio_child = idx * m_ + 1;

    if(prio_child >= data_.size()) break;

    for(size_t i = 1; i < m_; i++) {
      size_t child_idx = idx * m_ + 1 + i;

      if(child_idx < data_.size() && comp_(data_[child_idx], data_[prio_child])) {
        prio_child = child_idx;
      }
    }

    if(comp_(data_[prio_child], data_[idx])) {
      std::swap(data_[prio_child], data_[idx]);

      idx = prio_child;
    }

    else {
      break;
    }
  }
}

template <typename T, typename PComparator>
bool Heap<T, PComparator>::empty() const {

  return data_.empty();
}

template <typename T, typename PComparator>
size_t Heap<T, PComparator>::size() const {

  return data_.size();
}


#endif

