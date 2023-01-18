#include <iostream>
#include <vector>
#include <algorithm>  // make_heap
#include <queue>      // queue, priority_queue
#include <functional> // greater
#include <set>
#include <unordered_map> 
#include <utility> // pair
using namespace std;

class MaxHeap {
public:
    vector<int> heap;
    int current_size;
    void build_heap() {
        for (int i = current_size / 2; i > 0; --i) {
            percolate_down(i);
        }
    }
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
    void delete_top() {
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
public:
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
    void delete_top() {
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

class MKAverageBad
{
    int M, K;
    MaxHeap s1;
    MinHeap s3;
    multiset<int> s2;
    queue<int> q;
    long long sum2;
public:
    MKAverageBad(int m, int k)
    {
        M = m;
        K = k;
        sum2 = 0;
    }
    void addElement(int num)
    {
        q.push(num);
        if (q.size() <= M) {
            s2.insert(num);
            sum2 += num;
            if (q.size() == M) {
                while(s1.size() < K) {
                    s1.insert(*s2.begin());
                    sum2 -= *s2.begin();
                    s2.erase(s2.begin());
                }
                while (s3.size() < K) {
                    s3.insert(*s2.rbegin());
                    sum2 -= *s2.rbegin();
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }

        if (num < s1.top()) {
            s1.insert(num);
            s2.insert(s1.top());
            sum2 += s1.top();
            s1.delete_top();
        } else if (num > s3.top()) {
            s3.insert(num);
            s2.insert(s3.top());
            sum2 += s3.top();
            s3.delete_top();
        } else {
            s2.insert(num);
            sum2 += num;
        }

        int x = q.front();
        q.pop();
        for (int i = 1; i <= s1.size(); i++) {
            if (s1.heap[i] == x) {
                s1.heap[i] = s1.heap[s1.current_size--];
                s1.percolate_down(i);
                s1.insert(*s2.begin());
                sum2 -= *s2.begin();
                s2.erase(s2.begin());
                return;
            }
        }
        for (int i = 1; i <= s3.size(); i++) {
            if (s3.heap[i] == x) {
                s3.heap[i] = s3.heap[s3.current_size--];
                s3.percolate_down(i);
                s3.insert(*s2.rbegin());
                sum2 -= *s2.rbegin();
                s2.erase(prev(s2.end()));
                return;
            }
        }
        s2.erase(s2.find(x));
        sum2 -= x;
    }
    int calculateMKAverage()
    {
        if (q.size() < M) {
            return -1;
        }
        return sum2 / (M - 2 * K);
    }
};


class MKAverage {
private:
    int m, k;
    queue<int> q;
    multiset<int> s1, s2, s3;
    long long sum2;
public:
    MKAverage(int m, int k) : m(m), k(k) {
        sum2 = 0;
    }

    void addElement(int num) {
        q.push(num);
        if (q.size() <= m) {
            s2.insert(num);
            sum2 += num;
            if (q.size() == m) {
                while (s1.size() < k) {
                    s1.insert(*s2.begin());
                    sum2 -= *s2.begin();
                    s2.erase(s2.begin());
                }
                while (s3.size() < k) {
                    s3.insert(*s2.rbegin());
                    sum2 -= *s2.rbegin();
                    s2.erase(prev(s2.end()));
                }
            }
            return;
        }

        if (num < *s1.rbegin()) {
            s1.insert(num);
            s2.insert(*s1.rbegin());
            sum2 += *s1.rbegin();
            s1.erase(prev(s1.end()));
        } else if (num > *s3.begin()) {
            s3.insert(num);
            s2.insert(*s3.begin());
            sum2 += *s3.begin();
            s3.erase(s3.begin());
        } else {
            s2.insert(num);
            sum2 += num;
        }

        int x = q.front();
        q.pop();
        if (s1.count(x) > 0) {
            s1.erase(s1.find(x));
            s1.insert(*s2.begin());
            sum2 -= *s2.begin();
            s2.erase(s2.begin());
        } else if (s3.count(x) > 0) {
            s3.erase(s3.find(x));
            s3.insert(*s2.rbegin());
            sum2 -= *s2.rbegin();
            s2.erase(prev(s2.end()));
        } else {
            s2.erase(s2.find(x));
            sum2 -= x;
        }
    }

    int calculateMKAverage() {
        if (q.size() < m) {
            return -1;
        }
        return sum2 / (m - 2 * k);
    }
};


void testSolution1() {
    MKAverage sol(3, 1);
    int ans;
    sol.addElement(3);
    sol.addElement(1);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
    sol.addElement(10);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
    sol.addElement(5);
    sol.addElement(5);
    sol.addElement(5);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
}

void testSolution2() {
    MKAverage sol(3, 1);
    int ans;
    sol.addElement(17612);
    sol.addElement(74607);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
    sol.addElement(8272);
    sol.addElement(33433);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
    sol.addElement(15456);
    sol.addElement(64938);
    ans = sol.calculateMKAverage();
    sol.addElement(99741);
    cout << ans << "\n";
}


void testSolution3() {
    MKAverage sol(3, 1);
    int ans;
    sol.addElement(3716);
    sol.addElement(51094);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
    sol.addElement(56724);
    sol.addElement(79619);
    ans = sol.calculateMKAverage();
    cout << ans << "\n";
    sol.addElement(99914);
    sol.addElement(277);
    ans = sol.calculateMKAverage();
    sol.addElement(91205);
    cout << ans << "\n";
}

void testHeap() {
    vector<int> vi{7, 1, 5, 6, 4, 8, 5};
    MaxHeap heap1;
    MinHeap heap2;
    for (int i: vi) {
        heap1.insert(i);
        heap2.insert(i);
    }
    while (!heap1.empty()) {
        cout << heap1.top() << "\t" << heap2.top() << "\n";
        heap1.delete_top();
        heap2.delete_top();
    }
}

int main() {
    testSolution1();
    testSolution2();
    testSolution3();
    // testHeap();
    return 0;
}

/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */