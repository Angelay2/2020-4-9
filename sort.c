#include "sort.h"


void swap(int* array, int start, int min){


}


void insertSort(int* array, int n){
	// 有序序列的最后一个位置
	for (int i = 0; i < n + 1; ++i){
		int end = i;
		int key = array[end + 1];
		// 从后向前找一个合适的位置, 进行插入
		while (end >= 0 && array[end] >= key){
			array[end + 1] = array[end];
			--end;
		}
		// end 位置小于key,key 放在end 的下一个位置
		// 插入
		array[end + 1] = key;
	}
}

void shellSort(int* array, int n){

}

// 最慢的算法
// 时间复杂度: O(N^2) 任何情况下都是N^2
// 空间复杂度: O(1) 没有开空间 都是局部变量
// 稳定性: 稳定
// 数据敏感: 不敏感的 (和原始数据没关系 不管原始怎样 都走)
void selectSort(int* array, int n){

	for (int i = n; i > 0; --i){
		// 每次选一个最小的值, 存入未排序数据的起始位置 n-i(第一次相当于n-n) 起始位置 i随
		int start = n - i;
		int min = start;
		// 从其实位置开始 向后遍历
		for (int j = start; j < n; ++j){
			// 如果当前数据小于最小值 交换
			if (array[j] < array[min]){
				min = j;
			}
			swap(array, start, min);
		}
	}
}


// 法2比法1快
void selectSort2(int* array, int n){
	int begin = 0;
	int end = n - 1;
	int max, min;
	// 元素不少于两个
	while (begin < end){
		// 每次找一个最大值和最小值所在的位置
		min = max = begin;
		for (int j = begin + 1; j <= end; ++j){
			if (array[j] > array[max]) // (arr[j] >= arr[max) 此时就稳定了
				max = j;     // 最大值选前面(大的选后面就稳定了)
			if (array[j] < array[min])
				min = j;     // 最小值选前面
		}
		// 最小值和起始位置进行交换
		swap(array, begin, min);
		// 最大值和结束位置交换 如果最大值的位置在begin处, 此时需要更新
		if (max == begin)
			max = min;
		swap(array, end, max);

		++begin;
		--end;
	}
}



// 向下调整时间复杂度为O(logN)
// 空间复杂度为O(1)
// 稳定性: 不稳定 --> 向下调整可能会破坏相对位置
// 数据敏感: 每次都要进行完整的向下调整, 不敏感(数据是否有序对性能没多大影响)
// n为size, parent为父结点 
void shiftDown(int* array, int n, int parent){
	int child = 2 * parent + 1;
	while (child < n){
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
			if (array[child] > array[parent]){
				swap(array, child, parent);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
	}
}

// 堆排序(降序->建小堆  升序->建大堆)
// 建堆是从最后一个非叶子结点开始进行向下调整
// 假如现在是大堆, 堆顶为第一大,
// 交换(堆顶和堆尾) -> 向下调整(堆顶为第二大) -> 交换(堆顶和队尾)
// 升序
// 时间复杂度为O(nlogn)
void heapSort(int* array, int n){
	int end = n - 1;
	// 建大堆
	for (int i = (n - 2) / 2; i >= 0; --i){
		shiftdown(array, n, i);
	}

	// 循环排序
	while (end > 0){
		// 交换堆顶和队尾
		swap(array, 0, end);
		// 堆顶到堆尾
		shiftDown(array, end, 0);
		--end;
	}
}

// 一趟排序: 相邻元素比较, 大的向后移动
// 每一趟排序可以保证把最大的值移动到末尾(升序, 如果是降序,刚好相反)
// 时间复杂度: 有序为O(N). 无序为O(N^2)
// 空间复杂度: O(1)
// 稳定性: 稳定(若相等则不会发生交换
// 数据敏感: 敏感 有序为O(N). 无序为O(N^2)
// 本身为一个递增序列的话, 是不需要交换的 所以可以在一趟循环后 通过判断是否发生了交换 来决定是否有序(没有发生交换 则为有序 可以停掉 不需要再去做冒泡)
void bubbleSort(int* array, int n){
	// 元素个数
	int end = n;
	// 剩余需排元素个数次循环
	while (end > 0){
		// 一趟排序
		// 两种循环写法 flag只是用来判断是否进行了交换 0则交换了 无论交换几次, 1则没交换
		int flag = 1;
		for (int i = 1; i < end; ++i){
		//for (int i = 0; i <end - 1; ++i); array[i] > array[i + 1];
			// i - 1(0++ 左元素)大的向后移动  相等不会发生交换
			// 只要发生了一次交换 flag 就等于0了,
			if (array[i - 1] > array[i]){
				flag = 0;
				swap(array, i - 1, i);
			}
		}
		// 如果前者不大于后者 则为正常升序 则flag依旧为1
		if (flag)
			break;

		// 每循环一趟 可以再少遍历一个元素 所以--end
		--end;
	}
}