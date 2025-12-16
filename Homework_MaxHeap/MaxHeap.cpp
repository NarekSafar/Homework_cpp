#include <iostream>
#include <vector>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    size_t parent(size_t i) const {
        return (i - 1) / 2;
    }

    size_t leftChild(size_t i) const {
        return 2 * i + 1;
    }

    size_t rightChild(size_t i) const {
        return 2 * i + 2;
    }

    void siftUp(size_t i) {
        while (i > 0 && heap[i] > heap[parent(i)]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(size_t i) {
        size_t n = heap.size();

        while (leftChild(i) < n) {
            size_t largest = leftChild(i);

            if (rightChild(i) < n && heap[rightChild(i)] > heap[largest]) {
                largest = rightChild(i);
            }

            if (heap[i] >= heap[largest]) {
                break;
            }

            std::swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    MaxHeap() = default;

    MaxHeap(const std::vector<T>& data) : heap(data) {
        if (!heap.empty()) {
            for (int i = (int)(heap.size()) / 2 - 1; i >= 0; --i) {
                siftDown(i);
            }
        }
    }

    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        heap[0] = heap.back();
        heap.pop_back();

        if (!heap.empty()) {
            siftDown(0);
        }
    }

    const T& top() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    size_t size() const {
        return heap.size();
    }

    bool empty() const {
        return heap.empty();
    }

    void clear() {
        heap.clear();
    }

    static bool isHeap(const std::vector<T>& data) {
        size_t n = data.size();

        for (size_t i = 0; i < n / 2; ++i) {
            size_t left = 2 * i + 1;
            size_t right = 2 * i + 2;

            if (left < n && data[i] < data[left]) {
                return false;
            }
            if (right < n && data[i] < data[right]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::vector<int> data = {4, 10, 3, 5, 1};
    MaxHeap<int> heap(data); 
    
    std::cout << heap.top() << std::endl;
    std::cout << std::boolalpha << MaxHeap<int>::isHeap(data) << std::endl;
    return 0;
}
