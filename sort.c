#include "sort.h"

void Swap(int* array, int begin, int end){
	
	int tmp;
	tmp = array[begin];
	array[begin] = array[end];
	array[end] = tmp;
	
}

// 1. ��������:
// ���Ѿ��������������һ�����ʵ�λ��, �����µ�Ԫ��,�����֤������Ȼ����
// ʱ�临�Ӷ�: �:O(N^2) ���(��������,�ڲ�ѭ����ִ��):O(N)
// �ռ临�Ӷ�(�����ĸ���): i,n,end,key, --> O(1)
// �ȶ���(������ͬ��Ԫ�� ��������������λ�����޷����仯): �ȶ�
// ��������(���ݵ�����������������޺ܴ��Ӱ��, ��Ҫ������ʱ���� �����������ʱ������ʱ������ ���㷨�����ݲ�����): ����. */

// �Ӻ���ǰ����: ������һ��Ԫ�ش���ǰһ��Ԫ�� �Ͳ���Ҫ������
// �������Ԫ�ر�ǰ���С �򰤸��Ƚϴ�С �����������ĸ�Ԫ��ǰ
void insertSort(int* array, int n){
	// ���������е����һ��λ�ÿ�ʼ����Ԫ�رȽ�,Ҳ���ǳ�ʼ�������еĵ�һ��λ�ÿ�ʼ����
	// ������Ԫ��Ϊ��һ��Ԫ��end�ĺ�һ��Ԫ��end+1;
	// n-1������ 
	for (int i = 0; i < n - 1; ++i){
		// ����Ԫ��
		int end = i;
		int key = array[end + 1];

		// ����end��ĵ�һ��Ԫ�صıȽ�����
		// �Ӻ���ǰ��һ�����ʵ�λ��, ���в��� �������� ֱ��������keyС��Ԫ��ʱ����whileѭ��
		while (end >= 0 && array[end] > key){// ��end>=keyʱ���ȶ� 
			// ��end��Ԫ�ط���end+1��λ�� --end��������end-1��Ԫ��, ��end-1��Ԫ����key�Ƚ�
			array[end + 1] = array[end];
			--end;
		}
		// ���� end λ��Ԫ��С�� key, �� key ���ڴ�ʱ�� end ����һ��λ��, 
		// ����
		array[end + 1] = key;
	}
}

// 2. ϣ������: ���ֵĲ�������.(��Ϊ���������ڽӽ������ʱ����������õ�)
// ���ݱ��ֳɶ���, ���ڽ��в�������, ����������в�������
// ����Ԥ����, �������ݽ������Ԥ����, ��ȱȲ���������� Ԫ���ƶ�����Ҳ�ͱ����� �������
// ����һ�����ݲ���������ɺ� �ٽ�����һ�������, ���Ƕ������ݰ������ݵ�˳����н��������

void shellSort(int* array, int n){

	int gap = n;
	// (gap > 1)�������1 ����Ԥ����
	while (gap > 1){
		// Ԫ�ظ���nԽ�� ���Խ��, �ƶ��Ĵ���Խ��, �������Ҫ����1
        // ����15��Ԫ�� ����Ϊ5, ����5������ gap���ڶ��� �ͻ�ֳɼ�������
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; i++){
			// һ�ֵĲ�������
			int end = i;
			// Ҫ�����Ԫ��Ϊ��ǰԪ�ؼ��ϼ�����Ԫ��
			int key = array[end + gap];
			while (end >= 0 && array[end] > key){
				// ��end��Ԫ�ط���end+gap��λ��
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}

//// 3. ѡ������:�������㷨
//// ʱ�临�Ӷ�: O(N^2) �κ�����¶���N^2
//// �ռ临�Ӷ�: O(1) û�п��ռ� ���Ǿֲ�����
//// �ȶ���: �ȶ�
//// ��������: �����е� (��ԭʼ����û��ϵ ����ԭʼ���� ����)
//void selectSort(int* array, int n){
//
//	for (int i = n; i > 0; --i){
//		// ÿ��ѡһ����С��ֵ, ����δ�������ݵ���ʼλ�� n-i(��һ���൱��n-n) ��ʼλ�� i��
//		int start = n - i;
//		int min = start;
//		// ����ʵλ�ÿ�ʼ ������
//		for (int j = start; j < n; ++j){
//			// �����ǰ����С����Сֵ ����
//			if (array[j] < array[min]){
//				min = j;
//			}
//			swap(array, start, min);
//		}
//	}
//}
//
//
//// ��2�ȷ�1��
//void selectSort2(int* array, int n){
//	int begin = 0;
//	int end = n - 1;
//	int max, min;
//	// Ԫ�ز���������
//	while (begin < end){
//		// ÿ����һ�����ֵ����Сֵ���ڵ�λ��
//		min = max = begin;
//		for (int j = begin + 1; j <= end; ++j){
//			if (array[j] > array[max]) // (arr[j] >= arr[max) ��ʱ���ȶ���
//				max = j;     // ���ֵѡǰ��(���ѡ������ȶ���)
//			if (array[j] < array[min])
//				min = j;     // ��Сֵѡǰ��
//		}
//		// ��Сֵ����ʼλ�ý��н���
//		swap(array, begin, min);
//		// ���ֵ�ͽ���λ�ý��� ������ֵ��λ����begin��, ��ʱ��Ҫ����
//		if (max == begin)
//			max = min;
//		swap(array, end, max);
//
//		++begin;
//		--end;
//	}
//}
//
//
//// 4. ������(����->��С��  ����->�����)
////  ��ȡ�Ѷ� --> ���µ���
//// ���µ���ʱ�临�Ӷ�ΪO(logN)
//// �ռ临�Ӷ�ΪO(1)
//// �ȶ���: ���ȶ� --> ���µ������ܻ��ƻ����λ��
//// ��������: ÿ�ζ�Ҫ�������������µ���, ������(�����Ƿ����������û���Ӱ��)
//// 
//// �����Ǵ����һ����Ҷ�ӽ�㿪ʼ�������µ���
//// ���������Ǵ��, �Ѷ�Ϊ��һ��,
//// ����(�Ѷ��Ͷ�β) -> ���µ���(�Ѷ�Ϊ�ڶ���) -> ����(�Ѷ��Ͷ�β)
//// ����
//// ʱ�临�Ӷ�ΪO(nlogn)
//// nΪsize, parentΪ����� 
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
//	// �����
//	for (int i = (n - 2) / 2; i >= 0; --i){
//		shiftdown(array, n, i);
//	}
//
//	// ѭ������
//	while (end > 0){
//		// �����Ѷ��Ͷ�β
//		swap(array, 0, end);
//		// �Ѷ�����β
//		shiftDown(array, end, 0);
//		--end;
//	}
//}
//
//// 5. �������� 
//// 5.1 (ð������): 
//// һ������: ����Ԫ�رȽ�, �������ƶ�
//// ÿһ��������Ա�֤������ֵ�ƶ���ĩβ(����, ����ǽ���,�պ��෴)
//// ʱ�临�Ӷ�: ����ΪO(N). ����ΪO(N^2)
//// �ռ临�Ӷ�: O(1)
//// �ȶ���: �ȶ�(������򲻻ᷢ������
//// ��������: ���� ����ΪO(N). ����ΪO(N^2)
//// ����Ϊһ���������еĻ�, �ǲ���Ҫ������ ���Կ�����һ��ѭ���� ͨ���ж��Ƿ����˽��� �������Ƿ�����(û�з������� ��Ϊ���� ����ͣ�� ����Ҫ��ȥ��ð��)
//void bubbleSort(int* array, int n){
//	// Ԫ�ظ���
//	int end = n;
//	// ʣ������Ԫ�ظ�����ѭ��
//	while (end > 0){
//		// һ������
//		// ����ѭ��д�� flagֻ�������ж��Ƿ�����˽��� 0�򽻻��� ���۽�������, 1��û����
//		int flag = 1;
//		for (int i = 1; i < end; ++i){
//		//for (int i = 0; i <end - 1; ++i); array[i] > array[i + 1];
//			// i - 1(0++ ��Ԫ��)�������ƶ�  ��Ȳ��ᷢ������
//			// ֻҪ������һ�ν��� flag �͵���0��,
//			if (array[i - 1] > array[i]){
//				flag = 0;
//				swap(array, i - 1, i);
//			}
//		}
//		// ���ǰ�߲����ں��� ��Ϊ�������� ��flag����Ϊ1
//		if (flag)
//			break;
//
//		// ÿѭ��һ�� �������ٱ���һ��Ԫ�� ����--end
//		--end;
//	}
//}
// 5.2 ����:�����ﵽ����(����)
// (1). hoare��:  ÿ��ѡ��һ����׼ֵ ���ں�С�ڵķֱ���û�׼ֵ�ĺ����ǰ�� ��ź� С��ǰ
// Ȼ��任��׼ֵ, �Ӷ�ȷ��ÿһ����׼ֵ��λ��, ������������ 
// 
// �����һ��ֵΪkey, ���ȴӺ���ǰ��С��key��ֵ, ����λ�õ�����һ��С��key
// ������һ��ֵΪkey, ���ȴ�ǰ�����Ҵ���key��ֵ, ����λ�õ����ݴ���key,
int partion(int* array, int begin, int end){
	// ��һ��������Ϊ��׼ֵ
	int key = array[begin];
	int start = begin;
	// ����ʱ����ѭ�� ����ʱ��ֵ�ض�С��key,
	while (begin < end){
		// �ȴӺ���ǰ��С�� �������(end)��ֵ����key,��--end,������ǰ, �ҵ���һ��С��key��ֵʱ, ����ѭ��(�������--end)
		while (begin < end && array[end] >= key)
			--end;
		// ��ǰ����Ҵ��,���ǰ��(begin)��ֵС��key,��++begin, ��������,�ҵ���һ������key��ֵʱ, ����ѭ��(�������++begin)
		while (begin < end && array[begin] <= key)
			++begin;
		// ��ʱarray[end]Ϊ��һ��С��key��ֵ, array[begin]Ϊ��һ������key��ֵ,
		// λ�õ�Ԫ�ؽ��н��� С����begin��λ��, �����end��λ��, 
		// ������(end��begin)��û����, ����ѭ�� ����С��key��ֵ,
		// ��Ļ���С����һ��û�ҵ� �Ż�����, 
		// ���Ǵ��û�Ҽ� ��ᱻС��end���� ������end��,
		// ����С��û�Ҽ�,��ᱻ����

		Swap(array, begin, end);
	}
	// ������׼ֵ������λ�õ�ֵ, ����һ�����ݺͽ�С�Ľ���
	Swap(array, start, begin);
	return begin;
}


// (2) �ڿӷ�
int partion2(int* array, int begin, int end){
	int key = array[begin];
	while (begin <= end){
		// �Ӻ���ǰ��С��
		while (begin < end && array[end] >= key)
			--end;
		// ��ʱ�ҵ���end����Сֵ���ǵ���һ��Ԫ��begin��λ��
		array[begin] = array[end];
		while (begin < end && array[begin] <= key)
			++begin;
		// ��ʱ�ҵ���begin���Ĵ�ֵ���ǵ��ղſճ�����end��λ��
		array[end] = array[begin];
	}
	// ������, key ���������Ŀ�, ���һ����
	array[begin] = key;
	return begin;
}

// (3) ǰ��ָ�뷨
// cur ��һ��С�� key ��λ��(���ڵ�һ��Ԫ�ػ��ߵڶ���Ԫ�ص�λ��)
// prev ���һ��С�� key ��λ��(����NULL����ڵ�һ��Ԫ�ص�λ��)
// prev��cur����ʽ ˵���м�û�д���key��ֵ �������� ˵�� �м��д���key��ֵ
// ������ʱ  ��cur��λ�õ�Ԫ�غ�prev+1��ֵ���� ѭ�� ��cur>=endʱ, ��array[prev] = key
int partion3(int* array, int begin, int end){
	
	int prev = begin;
	int cur = begin + 1;
	int key = array[begin];
	while (cur <= end){
		// �����һ��С��key��λ�ú����һ��С��key��λ�ò�����
		// ˵��cur��prev�м����д���key��ֵ, ����Ҫ��СԪ�ؽ��н���\
		// ��array[cur] < keyʱ, prevһ����Ҫ��ǰ����һ��λ��
		// ��array[cur] >= keyʱ, prev����Ҫ����
		if (array[cur] < key && ++prev != cur)
			Swap(array, cur, prev);
		++cur;
	}
	Swap(array, begin, prev);
	// array[prev] = key; ����Ḳ��prev��ֵ
	return prev;
}
void quickSort(int* array, int begin, int end){
	if (begin >= end)
		return;
	int mid = partion(array, begin, end);
	// ��������
	// �ȸ���׼ֵ����߻���
	quickSort(array, begin, mid - 1);
	// �ٸ���׼ֵ���ұ߻���
	quickSort(array, mid + 1, end);

}