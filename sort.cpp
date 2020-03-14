#include "sort.h"
using namespace std;

int main(){
	int a[] = {3,7,2,9,6,5,2};
	for(auto i:a)
		cout << i;
	cout << endl;
	QuickSort(a,7,0,6);
	for(auto i:a)
		cout << i;
	cout << endl;
	BubbleSort(a,7);
	for(auto i:a)
		cout << i;
	cout << endl;
	SelectSort(a,7);
	for(auto i:a)
		cout << i;
	cout << endl;
	return 0; 
}


int Partition(int data[], int length, int start, int end){
	if(data == nullptr || length < 0 || start < 0 || end >= length)
		cerr << "Invalid Parameters" << endl;

	int small = start - 1;
	for(int idx = start; idx < end; ++idx){
		if(data[idx] < data[end]){
			small ++;
			if(idx != small)
				std::swap(data[idx], data[small]);
		}
	}
	small++;
	std::swap(data[small], data[end]);
	return small;
}

void QuickSort(int data[], int length, int start, int end){  //快排,时间复杂度O(n*logn)
	if(start == end) return;
	int idx = Partition(data, length, start, end);
	if(idx > start)
		QuickSort(data, length, start, idx-1);
	if(idx < end)
		QuickSort(data, length, idx+1, end);
}


void BubbleSort(int data[], int length){          // 冒泡排序，时间复杂度O(n^2)
	if(data == nullptr || length < 0)
		cerr << "Invalid Parameters" << endl;
	for(int i = 1; i < length - 1; ++i){          //注意i和j的遍历范围
		for(int j = 0; j < length - i; ++j){
			if(data[j] > data[j+1])
				swap(data[j], data[j+1]);
		}

	}
}

void SelectSort(int data[], int length){     //选择排序，时间复杂度O(n^2)
	if(data == nullptr || length < 0)
		cerr << "Invalid Parameters" << endl;
	for(int i = 0; i < length; ++i){
		int small = i;
		for (int j = i+1; j < length; ++j){
			if(data[j] < data[small])
				small = j;
		}
		if(small != i)
			swap(data[i], data[small]);
	}

}


