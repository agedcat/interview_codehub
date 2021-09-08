#include<iostream>
#include<vector>
using namespace std;

void adjustHeap(vector<int>& num, int len, int index){
    if(index > len) return;

    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int maxChild = index;

    if(left > len) return;
    else if(left <= len && right <= len){
        maxChild = num[left] > num[right] ? left : right;
    }
    else if(left <= right){
        maxChild = left;
    }

    if(num[index] < num[maxChild]){
        swap(num[index], num[maxChild]);
        adjustHeap(num, len, maxChild);
    }
}

void initHeap(vector<int>& num, int len){
    for(int i = num.size() / 2; i >= 0; --i){
        adjustHeap(num, len, i);
    }
}

void heapSort(vector<int>& num, int len){
    if(len < 1) return;
    initHeap(num, len);
    for(int i = len; i >= 1; --i){
        swap(num[0], num[i]);
        adjustHeap(num, i - 1, 0);
    }
}

int main(void)
{
    vector<int>num = {5, 6, 1, 8, 9, 4, 0, -1};
    heapSort(num, num.size() - 1);
    for(auto e : num){
        cout << e << " ";
    }
    return 0;
}