#include "sort.h"

void Swap(int* array, int i, int j){
	
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	
}

// 1. 插入排序:
// 在已经排序的序列中找一个合适的位置, 插入新的元素,插入后保证序列仍然有序
// 时间复杂度: 最坏:O(N^2) 最好(有序数组,内部循环不执行):O(N)
// 空间复杂度(变量的个数): i,n,end,key, --> O(1)
// 稳定性(两个相同的元素 在排序过程中相对位置有无发生变化): 稳定
// 数据敏感(数据的有序无序对排序有无很大的影响, 主要体现在时间上 若有序和无序时的排序时间相差不大 则算法对数据不敏感): 敏感. */

// 从后往前遍历: 如果最后一个元素大于前一个元素 就不需要调整了
// 若后面的元素比前面的小 则挨个比较大小 决定插入在哪个元素前
void insertSort(int* array, int n){
	// 从有序序列的最后一个位置开始和新元素比较,也就是初始无序序列的第一个位置开始遍历
	// 待排序元素为第一个元素end的后一个元素end+1;
	// n-1次排序 
	for (int i = 0; i < n - 1; ++i){
		// 保存元素
		int end = i;
		int key = array[end + 1];

		// 进行end后的第一个元素的比较排序
		// 从后向前找一个合适的位置, 进行插入 升序序列 直到遇到比key小的元素时跳出while循环
		while (end >= 0 && array[end] > key){// 让end>=key时不稳定 
			// 把end的元素放在end+1的位置 --end继续访问end-1的元素, 将end-1的元素与key比较
			array[end + 1] = array[end];
			--end;
		}
		// 遇到 end 位置元素小于 key, 则将 key 放在此时的 end 的下一个位置, 
		// 插入
		array[end + 1] = key;
	}
}

// 2. 希尔排序: 多轮的插入排序.(因为插入排序在接近有序的时候性能是最好的)
// 时间复杂度: 最坏:O(N^1.3) 最好(有序数组,内部循环不执行):O(N)(这个O(N)前的系数大于插入排序)
// 空间复杂度: O(1)
// 稳定性: 不稳定,预排序会破坏稳定性, 数据可能会被分到不同组
// 数据敏感: 敏感

// 数据被分成多组, 组内进行插入排序, 最终整体进行插入排序
// 先做预排序, 多组数据交替进行预排序, 跨度比插入排序大了 元素移动次数也就变少了 提高性能
// 不是一组数据插入排序完成后 再进行另一组的排序, 而是多组数据按照数据的顺序进行交替的排序

void shellSort(int* array, int n){

	int gap = n;
	// (gap > 1)间隔大于1 进行预排序
	while (gap > 1){
		// 元素个数n越多 间隔越大, 移动的次数越多, 间隔最终要等于1
        // 若有15个元素 则间隔为5, 就有5组数据 gap等于多少 就会分成几组数据
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++){
			// 一轮的插入排序
			int end = i;
			// 要插入的元素为当前元素加上间隔后的元素
			int key = array[end + gap];
			// 若在遍历的过程中遇到了比插入元素大的数据 那就把大的放在后面(覆盖),key已保存值,
			while (end >= 0 && array[end] > key){
				// 把end的元素放在end+gap的位置 相当于end的位置空了出来,
				array[end + gap] = array[end];
				end -= gap;
			}
			// 遍历结束 在也找不到比key大的值时(key最小) 直接将可以放在end+gap(此时end为负数,跳出上面循环, key为最小 end+gap刚好在第一个位置)
			array[end + gap] = key;
		}
	}
}

// 3. 选择排序:最慢的算法 从未排序的数据中选择一个最值, 把它放到合适位置(最小值放在未排序数据的头部位置, 最大值放在尾部位置)
// 时间复杂度: O(N^2) 任何情况下都是N^2
// 空间复杂度: O(1) 没有开空间 都是局部变量
// 稳定性: 稳定
// 数据敏感: 不敏感的 (和原始数据没关系 不管原始怎样 都走)
void selectSort(int* array, int n){
	// i为未排序的元素个数
	for (int i = n; i > 0; --i){
		// 每次选一个最小的值, 存入未排序数据的起始位置 n-i(第一次相当于n-n) 
		// i随循环减小 起始位置后移
		int start = n - i;
		int min = start;
		// 从起始位置开始 向后遍历,寻找最小值
		for (int j = start; j < n; ++j){
			// 如果当前数据小于最小值 让最小值的位置变为j, 
			if (array[j] < array[min])
				min = j;	
		}
        // 交换起始位置和最小位置的元素
		Swap(array, start, min);
	}
}


// 法2比法1快
// 每次选两个值, 一个最大(放在未排序的尾部),一个最小(放在未排序的起始),
void selectSort2(int* array, int n){
	int begin = 0;// 起始位置
	int end = n - 1;// 尾部位置
	int max, min;
	// 元素不少于两个
	while (begin < end){
		// 每次找一个最大值和最小值所在的位置 (先让最小值和最大值都放在起始位置)
		min = max = begin;
		// 从当前位置的下一个元素开始遍历(也可以从当前位置开始)
		for (int j = begin + 1; j <= end; ++j){
			// 如当前位置更大 则让最大值的位置变为j
			if (array[j] > array[max]) // (arr[j] >= arr[max) 此时就稳定了
				max = j;     // 最大值选前面(大的选后面就稳定了)
			// 如当前位置更小, 则让最小值的位置变为j
			if (array[j] < array[min])
				min = j;     // 最小值选前面
		}

		// 此时找到了最值,min和begin进行交换, max和end交换
		/* Swap(array, begin, min);
		 Swap(array, end, max);*/

		// 上面操作会产生错误 忽略了若begin处为剩余未排序数据中的最大值,
		// 经过第一步的min和begin交换后, 会丢失最大值, 此时真正的max在原min处 而原max处却变成了min
		// 直接进行max和end交换会使最小值放到end处,而begin处则变成了未排序之前的最后一个元素)
		// 需将
		Swap(array, begin, min);
		// 最大值和结束位置交换 
		if (max == begin)
			max = min;
		Swap(array, end, max);

		++begin;
		--end;
	}
}


//// 4. 堆排序(降序->建小堆  升序->建大堆)
////  获取堆顶 --> 向下调整
//// 向下调整时间复杂度为O(logN)
//// 空间复杂度为O(1)
//// 稳定性: 不稳定 --> 向下调整可能会破坏相对位置
//// 数据敏感: 每次都要进行完整的向下调整, 不敏感(数据是否有序对性能没多大影响)
//// 
//// 建堆是从最后一个非叶子结点开始进行向下调整
//// 假如现在是大堆, 堆顶为第一大,
//// 交换(堆顶和堆尾) -> 向下调整(堆顶为第二大) -> 交换(堆顶和队尾)
//// 升序
//// 时间复杂度为O(nlogn)
//// n为size, parent为父结点 
//void shiftDown(int* array, int n, int parent){
//	int child = 2 * parent + 1;
//	while (child < n){
//		if (child + 1 < n && array[child + 1] > array[child])
//			++child;
//			if (array[child] > array[parent]){
//				swap(array, child, parent);
//				parent = child;
//				child = 2 * parent + 1;
//			}
//			else
//				break;
//	}
//}
//

//void heapSort(int* array, int n){
//	int end = n - 1;
//	// 建大堆
//	for (int i = (n - 2) / 2; i >= 0; --i){
//		shiftdown(array, n, i);
//	}
//
//	// 循环排序
//	while (end > 0){
//		// 交换堆顶和队尾
//		swap(array, 0, end);
//		// 堆顶到堆尾
//		shiftDown(array, end, 0);
//		--end;
//	}
//}
//
//// 5. 交换排序 
//// 5.1 (冒泡排序): 
//// 一趟排序: 相邻元素比较, 大的向后移动
//// 每一趟排序可以保证把最大的值移动到末尾(升序, 如果是降序,刚好相反)
//// 时间复杂度: 有序为O(N). 无序为O(N^2)
//// 空间复杂度: O(1)
//// 稳定性: 稳定(若相等则不会发生交换
//// 数据敏感: 敏感 有序为O(N). 无序为O(N^2)
//// 本身为一个递增序列的话, 是不需要交换的 所以可以在一趟循环后 通过判断是否发生了交换 来决定是否有序(没有发生交换 则为有序 可以停掉 不需要再去做冒泡)
//void bubbleSort(int* array, int n){
//	// 元素个数
//	int end = n;
//	// 剩余需排元素个数次循环
//	while (end > 0){
//		// 一趟排序
//		// 两种循环写法 flag只是用来判断是否进行了交换 0则交换了 无论交换几次, 1则没交换
//		int flag = 1;
//		for (int i = 1; i < end; ++i){
//		//for (int i = 0; i <end - 1; ++i); array[i] > array[i + 1];
//			// i - 1(0++ 左元素)大的向后移动  相等不会发生交换
//			// 只要发生了一次交换 flag 就等于0了,
//			if (array[i - 1] > array[i]){
//				flag = 0;
//				swap(array, i - 1, i);
//			}
//		}
//		// 如果前者不大于后者 则为正常升序 则flag依旧为1
//		if (flag)
//			break;
//
//		// 每循环一趟 可以再少遍历一个元素 所以--end
//		--end;
//	}
//}
// 5.2 快排:交换达到排序(升序)
// (1). hoare法:  每次选择一个基准值 大于和小于的分别放置基准值的后面和前面 大放后 小放前
// 然后变换基准值, 从而确定每一个基准值的位置, 逐渐趋近于有序 
// 
// 如果第一个值为key, 首先从后向前找小于key的值, 相遇位置的数据一定小于key
// 如果最后一个值为key, 首先从前往后找大于key的值, 相遇位置的数据大于key,
int partion(int* array, int begin, int end){
	// 第一个数据作为基准值
	int key = array[begin];
	int start = begin;
	// 相遇时跳出循环 相遇时的值必定小于key,
	while (begin < end){
		// 先从后向前找小的 如果后面(end)的值大于key,则--end,继续往前, 找到第一个小于key的值时, 跳出循环(不会进行--end)
		while (begin < end && array[end] >= key)
			--end;
		// 从前向后找大的,如果前面(begin)的值小于key,则++begin, 继续往后,找到第一个大于key的值时, 跳出循环(不会进行++begin)
		while (begin < end && array[begin] <= key)
			++begin;
		// 此时array[end]为第一个小于key的值, array[begin]为第一个大于key的值,
		// 位置的元素进行交换 小的在begin的位置, 大的在end的位置, 
		// 若两者(end和begin)还没相遇, 继续循环 先找小于key的值,
		// 大的或者小的有一个没找到 才会相遇, 
		// 若是大的没找见 则会被小的end拦截 相遇在end处,
		// 若是小的没找见,则会被拦在

		Swap(array, begin, end);
	}
	// 交换基准值和相遇位置的值, 将第一个数据和较小的交换
	Swap(array, start, begin);
	return begin;
}


// (2) 挖坑法
int partion2(int* array, int begin, int end){
	int key = array[begin];
	while (begin <= end){
		// 从后向前找小的
		while (begin < end && array[end] >= key)
			--end;
		// 此时找到的end处的小值覆盖到第一个元素begin的位置
		array[begin] = array[end];
		while (begin < end && array[begin] <= key)
			++begin;
		// 此时找到的begin处的大值覆盖到刚才空出来的end的位置
		array[end] = array[begin];
	}
	// 相遇了, key 放入相遇的坑, 最后一个坑
	array[begin] = key;
	return begin;
}

// (3) 前后指针法
// cur 下一个小于 key 的位置(放在第一个元素或者第二个元素的位置)
// prev 最后一个小于 key 的位置(放在NULL或放在第一个元素的位置)
// prev和cur连续式 说明中间没有大于key的值 若不连续 说明 中间有大于key的值
// 不连续时  将cur的位置的元素和prev+1的值交换 循环 当cur>=end时, 让array[prev] = key
int partion3(int* array, int begin, int end){
	
	int prev = begin;
	int cur = begin + 1;
	int key = array[begin];
	while (cur <= end){
		// 如果下一个小于key的位置和最后一个小于key的位置不连续
		// 说明cur和prev中间是有大于key的值, 则需要大小元素进行交换\
		// 当array[cur] < key时, prev一定需要向前更新一个位置
		// 当array[cur] >= key时, prev不需要更新
		if (array[cur] < key && ++prev != cur)
			Swap(array, cur, prev);
		++cur;
	}
	Swap(array, begin, prev);
	// array[prev] = key; 这个会覆盖prev的值
	return prev;
}
void quickSort(int* array, int begin, int end){
	if (begin >= end)
		return;
	int mid = partion(array, begin, end);
	// 划分区间
	// 先给基准值的左边划分
	quickSort(array, begin, mid - 1);
	// 再给基准值的右边划分
	quickSort(array, mid + 1, end);

}