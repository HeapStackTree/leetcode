#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;
    int current_size;
    void percolate_down(int hole) {
        int child;
        int tmp = heap[hole];
        for (; hole * 2 <= current_size; hole = child) {
            child = hole * 2;
            if (child < current_size && heap[child + 1] > heap[child]) {
                ++child;
            }
            if (heap[child] > tmp) {
                heap[hole] = heap[child];
            } else {
                break;
            }
        }
        heap[hole] = tmp;
    }
    void build_heap() {
        for (int i = current_size / 2; i > 0; --i) {
            percolate_down(i);
        }
    }
public:
    MaxHeap(): heap(1), current_size(0) {}
    MaxHeap(int *begin, int *end) {
        while (begin != end) {
            heap.push_back(*begin);
            ++begin;
            ++current_size;
        }
        build_heap();
    }
    bool empty() {
        return current_size <= 0;
    }
    void insert(int num) {
        while (current_size >= heap.size() - 1) {
            heap.resize(heap.size() * 2 + 1);
        }
        int hole = ++current_size;
        heap[0] = num;
        for (; num > heap[hole / 2]; hole /= 2) {
            heap[hole] = heap[hole / 2];
        }
        heap[hole] = num;

    }
    void delete_max() {
        if (empty()) {
            return;
        }
        heap[1] = heap[current_size--];
        percolate_down(1);
    }

    int top() {
        return heap[1];
    }
   
    int size() {
        return current_size;
    }
};


class MinHeap {
private:
    vector<int> heap;
    int current_size;
    void percolate_down(int hole) {
        int child;
        int tmp = heap[hole];
        for (; hole * 2 <= current_size; hole = child) {
            child = hole * 2;
            if (child < current_size && heap[child + 1] < heap[child]) {
                ++child;
            }
            if (heap[child] < tmp) {
                heap[hole] = heap[child];
            } else {
                break;
            }
        }
        heap[hole] = tmp;
    }
    void build_heap() {
        for (int i = current_size / 2; i > 0; --i) {
            percolate_down(i);
        }
    }
public:
    MinHeap(): heap(1), current_size(0) {}
    MinHeap(int *begin, int *end) {
        while (begin != end) {
            heap.push_back(*begin);
            ++begin;
            ++current_size;
        }
        build_heap();
    }
    bool empty() {
        return current_size <= 0;
    }
    void insert(int num) {
        while (current_size >= heap.size() - 1) {
            heap.resize(heap.size() * 2 + 1);
        }
        int hole = ++current_size;
        heap[0] = num;
        for (; num < heap[hole / 2]; hole /= 2) {
            heap[hole] = heap[hole / 2];
        }
        heap[hole] = num;

    }
    void delete_max() {
        if (empty()) {
            return;
        }
        heap[1] = heap[current_size--];
        percolate_down(1);
    }

    int top() {
        return heap[1];
    }
   
    int size() {
        return current_size;
    }
};