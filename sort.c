#include "sort.h"
#include "stack.h"
#include "queue.h"
#include <malloc.h>

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
// 空间复杂度: O(1) 不需要开空间
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
// 稳定性: 不稳定
// 数据敏感: 不敏感的 (和原始数据没关系 不管原始怎样 都走遍历)
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


// 4. 堆排序(降序->建小堆  升序->建大堆)
// 首先建堆 --> 获取堆顶 --> 向下调整
// 时间复杂度: O(logN)
// 空间复杂度: O(1)
// 稳定性: 不稳定 --> 向下调整可能会破坏相对位置
// 数据敏感: 每次都要进行完整的向下调整, 不敏感(数据是否有序对性能没多大影响)
// 
// 1. 建堆是从最后一个非叶子结点开始进行向下调整
// 假如现在是大堆, 堆顶为第一大,
// 2. 交换(堆顶和堆尾)
// 3. 对剩余元素(--end)构成的堆进行向下调整(堆顶为第二大)
// 4. 交换(堆顶和队尾) 
// 5. 循环
// 升序
// 时间复杂度为O(nlogn)
// n为size, parent为父结点 
void shiftDown(int* array, int n, int parent){
	// 先找到孩子的位置
	int child = 2 * parent + 1;
	// child<n 则存在
	while (child < n){
		// 同时也要判断右孩子是否存在(<n) 且当右孩子大于左孩子时 取右孩子, 否则 依旧为左孩子
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
		// 比较孩子和父结点值
		if (array[child] > array[parent]){
			// 若孩子大于父亲, 则交换(只交换了值)
			Swap(array, child, parent);
			// 向下调整, 父亲走到孩子位置(把孩子位置赋给父亲), 
			parent = child; 
			// 由于给定的父结点是随机的(给定的父结点不一定是最后一个非叶子结点) 仍需向下判断,孩子继续向下走
			child = 2 * parent + 1;
		}
		// 如果孩子不大于父亲 则不用动(为大堆) 跳出循环
		else
			break;
	}
}

void heapSort(int* array, int n){
	int end = n - 1;
	// 建大堆(从最后一个非叶子结点开始对所有父结点进行向下调整直到根结点 ---> 为(n - 2) / 2 ).
	for (int i = (n - 2) / 2; i >= 0; --i){
		// shiftdown只是一次调整(给定父结点到叶子)
		shiftDown(array, n, i);
	}

	// 循环排序
	while (end > 0){
		// 先交换堆顶和队尾
		Swap(array, 0, end);
		// 再对剩余元素进行堆顶到堆尾(此时给定结点为根结点) 由于一开始是n个元素, 所以这里的end(n-1)是对的
		shiftDown(array, end, 0);
		--end;
	}
}

// 5. 交换排序 
// 5.1 (冒泡排序): 
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
				Swap(array, i - 1, i);
			}
		}
		// 如果前者不大于后者 则为正常升序 则flag依旧为1
		if (flag)
			break;

		// 每循环一趟 可以再少遍历一个元素 所以--end
		--end;
	}
}
// 5.2 快排:交换达到排序(升序)
// 获取中间值(在partion3中用了)
int getMid(int* array, int left, int right){
	int mid = left + (right - left) / 2;

	if (array[mid] > array[left]){  //  left mid
		if (array[mid] < array[right]) // left mid right
			return mid;
		else{
			if (array[left] > array[right]) //  right left mid
				return left;
			else                           // left right mid
				return right;
		}
	}
	else{  //  mid left
		if (array[mid] > array[right])  //  right mid left
			return mid;
		else{     // mid right 
			if (array[left] < array[right])  //  mid left right
				return left;
			else                            // mid right left
				return right;
		}
	}
}
// (1). hoare法:  每次选择一个基准值 大于和小于的分别放置基准值的后面和前面 大放后 小放前
// 然后变换基准值, 从而确定每一个基准值的位置, 逐渐趋近于有序 
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
		// 若是小的没找见,则会被拦在相遇地方 

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

	int mid = getMid(array, begin, end);
	Swap(array, mid, begin);

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
// 理想情况下: 假设递归的深度为n, 递归总次数为2^n-1 
// 假设元素个数为n,高度为logn, 每一层都是对近似n个数进行操作 (满二叉树结点为n,高度为log(n+1)
// 时间复杂度: 平均O(nlogn),每层执行次数不大于n(会去掉关键值), 每层操作个数(n)*高度(logn)
//          数据有序时为O(N^2) (递归深度 = 元素个数 每层有一区间数据为空 每层执行次数为等差数列 比上一层减少1 每次只给基准值把位置确定好 就一直在调递归)
// 时间不能复用 空间(函数栈帧)可以复用 看每一个函数栈帧需要多少 再看需要压几个栈帧 调用结束 释放空间
// 空间复杂度: 为最大的递归调用深度O(logn), 开了多少个局部变量的空间  每个函数内部是O(1) 所以一个递归为O(1)的复杂度 总的复杂度为总共调用的空间 每层O(1) logn层
// 递归调用相当于压栈 出栈 如果一直连续调递归(在压栈) 会造成栈溢出
// 稳定性: 不稳定 --> 划分时数据会产生交换, 可能会导致相对位置发生变化
// 数据敏感:

// 未优化
void quickSort(int* array, int begin, int end){
	if (begin >= end)
		return;
	int mid = partion(array, begin, end);
	// int mid = partion2(array, begin, end);
	// int mid = partion3(array, begin, end);

	// 划分区间(最后一层区间中只有一个元素)
	// 先给基准值的左边划分
	quickSort(array, begin, mid - 1);
	// 再给基准值的右边划分
	quickSort(array, mid + 1, end);

}

// 快速排序优化(避免有序数据排序产生栈溢出):
// 1. 小区间优化: 小区间直接调用其他排序算法, 不执行递归 
// 作用不明显 因为编辑器本身会对简单递归进行优化
// 2. 三数取中法: 从待划分的数据中, 选取三个数, 从三个数中选择中间值作为基准值 
// 目的是让区间的划分更加均衡, 减少递归的深度
void quickSort2(int* array, int begin, int end){
	
	if (begin >= end)
		return;

	if (end - begin + 1 < 10){
		shellSort(array + begin, end - begin + 1);
	}

	else{
		int mid = partion3(array, begin, end);

	// 划分区间(最后一层区间中只有一个元素)
	// 先给基准值的左边划分
	quickSort(array, begin, mid - 1);
	// 再给基准值的右边划分
	quickSort(array, mid + 1, end);
	}
}

// 非递归: 记录每一个确定的起始和结束位置, 然后按照先划分大区间, 再划分小区间的顺序完成所有的划分
// 1. 用栈保存区间的起始和结束位置
// 空间复杂度: logn(树的高度 压栈出栈)
void quickSortNor1(int* array, int n){
	Stack st;
	stackInit(&st, 10);

	// 首先保存大区间
	if (n > 0){
		stackPush(&st, n - 1);
		stackPush(&st, 0);
		// 给所有区间进行划分	
		}
	while (stackEmpty(&st) != 1){
		// 还有区间没有划分
		// 取出一个区间的起始和结束位置
		int left = stackTop(&st);
		stackPop(&st);
		int right = stackTop(&st);
		stackPop(&st); 
		// 划分当前区间
		int div = partion3(array, left, right);
		// 保存自取件的起始和结束位置
		if (left < div - 1){
			stackPush(&st, div - 1);
			stackPush(&st, left);
		}
		if (div + 1 < right){
			stackPush(&st, right);
			stackPush(&st, div + 1);

		}
	}
}
// 快排非递归
// 2. 用队列保存区间的起始和结束位置
// 
void quickSortNor2(int* array, int n){
	//初始队列
	Queue q;
	queueInit(&q);
	if (n > 1){
		// 存放顺序: 先左后右
		queuePush(&q, 0);
		queuePush(&q, n - 1);
	}
	while (queueEmpty(&q) != 1){
		// 从队头获取区间信息
		int left = queueFront(&q);
		queuePop(&q);
		int right = queueFront(&q);
		queuePop(&q);

		// 划分
		int div = partion3(array, left, right);
		// 划分之后的区间入队
		if (left < div - 1){
			queuePush(&q, left);
			queuePush(&q, div - 1);
		}
		if (div + 1 < right){
			queuePush(&q, div + 1);
			queuePush(&q, right);
		}
	}
}

// 归并排序: 合并已经有序的子区间(从底层开始归并, 先归并小区间, 再归并大区间 且都是相邻区间进行归并.
// 适用于外排序(内存不能一次完整处理的排序)
/*
时间复杂度: 最好最坏都是 N(nlogn), 非常对称平衡的划分(不像快排是根据关键字划分), 因为是按照元素位置进行划分 
空间复杂度: O(N) (借助了辅助空间 有多少的元素 借多少个空间) 递归仍然是O(logn) 但是小于N 取最大为O(N),
稳定性: 稳定(相等的先放在最左边的, 
数据敏感: 不敏感(都要走划分过程, 效率相同)
*/

// 先分解
// 1. 先把大区间分解成子区间 
// 2. 包含多个元素的子区间不一定有序
// 3. 继续分解 
// 4. 直到不能再分解(区间只有一个元素时不能再分解)
// 5. 只有一个元素的子区间有序
// 6. 合并有序的子区间
// 再合并
// 借助辅助空间进行归并, 最终进行拷贝
void mergeInternal(int* array, int left, int mid, int right, int* tmp){// 假设mid为第一个区间的结束位置
	// 有序子区间:[left,mid]和[mid+1, right]归并
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int idx = left;
	// 归并
	while (begin1 <= end1 && begin2 <= end2){
		if (array[begin1] <= array[begin2])
			tmp[idx++] = array[begin1++];
		else
			tmp[idx++] = array[begin2++];
	}
	// 保存剩余元素
	if (begin1 <= end1)
		memcpy(tmp + idx, array + begin1, sizeof(int)* (end1 - begin1 + 1));
	if (begin2 <= end2)
		memcpy(tmp + idx, array + begin2, sizeof(int)* (end2 - begin2 + 1));
	// 当前区间已有序, 把辅助空间对应位置的元素拷回去
	memcpy(array + left, tmp + left, sizeof(int)* (right - left + 1));
}
void merge(int* array, int left, int right, int* tmp){

	// 区间只有一个元素 不需要分解 也不需要归并
	if (left >= right)
		return;

	int mid = left + (right - left) / 2;
	// 1. 分解
	// 先分别进行子区间的归并排序
	// 左子区间[left, mid]
	merge(array, left, mid, tmp);
	// 当左边的分为单个时 再到右边 再到单个 再合并 然后进行上层的分解左边
	// 右子区间[mid+1, right]
	merge(array, mid + 1, right, tmp);

	// 2. 合并
	// 前提: [left,mid], [mid+1, right]有序
	// 归并: [left,mid], [mid+1, right]
	// 变成有序大区间
	mergeInternal(array, left, mid, right, tmp);
}
void mergeSort(int* array, int n){
	int* tmp = (int*)malloc(sizeof(int)* n);
	merge(array, 0, n - 1, tmp);
	free(tmp);
}

// 非递归归并排序(不需要走分解)
// 每次待归并的子区间的元素个数都是上一层的二倍(当奇数个数数据时 最后一个是被单独划分的 不参与归并 只在最后一层参与归并) 仍满足 1,2,4,8...
void mergeSortNor(int* array, int n){
	// 每次待归并的子区间元素个数
	int num = 1;
	int* tmp = (int*)malloc(sizeof(int)* n);
	while (num < n){
		// 每次都要把整个区间的元素进行归并
		// 下一次归并 是下一批元素的归并
		for (int i = 0; i < n; i += 2 * num){
			int left = i;
			int mid = i + num - 1;
			
			if (mid >= n - 1)// 表示剩下元素只能构建一个区间
				//没有第二个区间, 不需要归并, 剩余的一个区间不需要归并
				continue;

			int right = i + 2 * num - 1;
			// 判断第二个区间的结束位置是否越界
			if (right >= n)
				right = n - 1;

			mergeInternal(array, left, mid, right, tmp);
		}
		num *= 2;
	}
	free(tmp);
}

// 计数排序(两个变量一个记录最大值, 一个记录最小值 用来计算数据范围 决定开多大的元素空间 )  不适合范围较大的排序 会造成很多的空间浪费 只适合小范围紧凑的
// 统计每一个数据出现的次数
/* 
时间复杂度: O(N) max(长度 范围)的遍历次数  
空间复杂度: range  
稳定性:  没办法保证稳定, 都保存在计数数组的同一个位置
数据敏感: 不敏感
*/
void countSort(int* array, int n){
	// 先找到最大值和最小值
	int max = array[0], min = array[0];
	int range;
	int* countArr;
	int idx = 0;
	for (int i = 1; i < n; ++i){
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	//数据范围
	range = max - min + 1;
	// 申请计数数组空间
	countArr = (int*)malloc(sizeof(int)* range);
	// calloc可以完成申请和0的初始化
	// countArr = (int*)calloc(sizeof(int)*range);
	memset(countArr, 0, sizeof(int)*range);
	//记录每一个数据出现的次数
	for (int i = 0; i < n; ++i){
		countArr[array[i] - min]++;
	}
	// 遍历计数数组
	for (int i = 0; i < range; ++i){
		// 有可能有重复的数据 
		while (countArr[i]--){
			array[idx++] = i + min;
		}
	}
}
