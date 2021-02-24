#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


vector<int> heap(100002, 0);
int next_free = 0;

void heapify_up(int i)
{
    if (i == 0) return;
    int parent = (i-1)/2;
    if (heap[i] < heap[parent])
    {
        std::swap(heap[i], heap[parent]);
    }
    heapify_up(parent);
}

void heapify_down(int i)
{
    int left = 2*i + 1;
    if (left >= next_free) return;
    
    int right = left + 1;
    if (right >= next_free)
    {
        if (heap[i] > heap[left])
        {
            swap(heap[i], heap[left]);
            heapify_down(left);
        }
        
    } else {
        if (heap[i] < heap[right] && heap[i] < heap[left])
            return;
        if (heap[right] < heap[left])
        {
            swap(heap[i], heap[right]);
            heapify_down(right);
        } else {
            swap(heap[i], heap[left]);
            heapify_down(left);
        }
    }
}

void add(int x)
{
    heap[next_free] = x;
    heapify_up(next_free);
    next_free++;
}

void remove(int x)
{
    auto idx = std::distance(heap.begin(), std::find(heap.begin(), heap.end(), x));
    next_free--;
    
    std::swap(heap[idx], heap[next_free]);
    if (heap[idx] < heap[next_free])
    {
        // heapify_up
        heapify_up(idx);
    } else {
        // heapify down
        heapify_down(idx);
    }
}

void print()
{
    std::cout << heap[0] << "\n";
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t = 0;
    cin >> t;
    for (int ti = 0; ti < t; ++ti) {
        int op;
        cin >> op;
        if (op == 1) {
            int arg;
            cin >> arg;
            add(arg);
        } else if (op == 2) {
            int arg;
            cin >> arg;
            remove(arg);
            
        } else {
            print();
        }
    }
    
    return 0;
}

