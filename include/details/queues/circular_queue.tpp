#ifndef _CIRCULAR_Q
#define _CIRCULAR_Q

#include <iostream>
#include <source_location>
#include <vector>
#include <cassert>

namespace timber_line_datastructs
{
    template <typename T>
    class circular_queue
    {
        using size_c_t = typename std::vector<T>::size_type;
    private : 
        std::size_t q_size_;
        size_c_t head_;
        size_c_t tail_;
        std::vector<T> storage_;

    public:
        explicit circular_queue(std::size_t size) : q_size_(size + 1),
                                                    storage_(size + 1),
                                                    head_(0),
                                                    tail_(0){};
        circular_queue() = delete;
        circular_queue(const circular_queue &) = default;
        circular_queue &operator=(const circular_queue &) = default;
        circular_queue(circular_queue &&other) noexcept { cpy_move(std::move(other)); }

        /*************************************
         * @param Utilities
         **************************************/
        void push_back(T &&item)
        {
            if (q_size_ > 0)
            {
                storage_[tail_] = std::move(item);
                tail_ = (tail_ + 1) % q_size_;
                head_ = tail_ == head_ ? ((head_ + 1) % q_size_) : head_;
            }
        }
        void push_back(T item)
        {
            if (q_size_ > 0)
            {
                storage_[tail_] = item;
                tail_ = (tail_ + 1) % q_size_;
                head_ = tail_ == head_ ? ((head_ + 1) % q_size_) : head_;
            }
        }
        void pop_front()
        {
            head_ = (head_ + 1) % q_size_;
        }

        T &top()
        {
            return storage_[head_];
        }
        const T &at(size_c_t i) const
        {
            // Logically impossible
            assert(i < q_size_);
            return storage_[(head_ + i) % q_size_];
        }
        bool is_empty() const
        {
            return tail_ == head_;
        }

        bool is_full() const
        {
            return tail_ == head_ ? false : (tail_ + 1) % q_size_ == head_;
        }
        inline std::size_t size() const
        {
            return q_size_;
        }

    private:
        void cpy_move(circular_queue &&other)
        {
            q_size_ = other.q_size_;
            head_ = other.head_;
            tail_ = other.tail_;
            storage_ = std::move(other.storage_);

            other.max_items_ = 0;
            other.head_ = other.tail_ = 0;
            other.overrun_counter_ = 0;
        }
    };

}

#endif //_CIRCULAR_Q
