#include "sort.h"


void swap(int* array, int start, int min){


}


void insertSort(int* array, int n){
	// �������е����һ��λ��
	for (int i = 0; i < n + 1; ++i){
		int end = i;
		int key = array[end + 1];
		// �Ӻ���ǰ��һ�����ʵ�λ��, ���в���
		while (end >= 0 && array[end] >= key){
			array[end + 1] = array[end];
			--end;
		}
		// end λ��С��key,key ����end ����һ��λ��
		// ����
		array[end + 1] = key;
	}
}

void shellSort(int* array, int n){

}

// �������㷨
// ʱ�临�Ӷ�: O(N^2) �κ�����¶���N^2
// �ռ临�Ӷ�: O(1) û�п��ռ� ���Ǿֲ�����
// �ȶ���: �ȶ�
// ��������: �����е� (��ԭʼ����û��ϵ ����ԭʼ���� ����)
void selectSort(int* array, int n){

	for (int i = n; i > 0; --i){
		// ÿ��ѡһ����С��ֵ, ����δ�������ݵ���ʼλ�� n-i(��һ���൱��n-n) ��ʼλ�� i��
		int start = n - i;
		int min = start;
		// ����ʵλ�ÿ�ʼ ������
		for (int j = start; j < n; ++j){
			// �����ǰ����С����Сֵ ����
			if (array[j] < array[min]){
				min = j;
			}
			swap(array, start, min);
		}
	}
}


// ��2�ȷ�1��
void selectSort2(int* array, int n){
	int begin = 0;
	int end = n - 1;
	int max, min;
	// Ԫ�ز���������
	while (begin < end){
		// ÿ����һ�����ֵ����Сֵ���ڵ�λ��
		min = max = begin;
		for (int j = begin + 1; j <= end; ++j){
			if (array[j] > array[max]) // (arr[j] >= arr[max) ��ʱ���ȶ���
				max = j;     // ���ֵѡǰ��(���ѡ������ȶ���)
			if (array[j] < array[min])
				min = j;     // ��Сֵѡǰ��
		}
		// ��Сֵ����ʼλ�ý��н���
		swap(array, begin, min);
		// ���ֵ�ͽ���λ�ý��� ������ֵ��λ����begin��, ��ʱ��Ҫ����
		if (max == begin)
			max = min;
		swap(array, end, max);

		++begin;
		--end;
	}
}



// ���µ���ʱ�临�Ӷ�ΪO(logN)
// �ռ临�Ӷ�ΪO(1)
// �ȶ���: ���ȶ� --> ���µ������ܻ��ƻ����λ��
// ��������: ÿ�ζ�Ҫ�������������µ���, ������(�����Ƿ����������û���Ӱ��)
// nΪsize, parentΪ����� 
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

// ������(����->��С��  ����->�����)
// �����Ǵ����һ����Ҷ�ӽ�㿪ʼ�������µ���
// ���������Ǵ��, �Ѷ�Ϊ��һ��,
// ����(�Ѷ��Ͷ�β) -> ���µ���(�Ѷ�Ϊ�ڶ���) -> ����(�Ѷ��Ͷ�β)
// ����
// ʱ�临�Ӷ�ΪO(nlogn)
void heapSort(int* array, int n){
	int end = n - 1;
	// �����
	for (int i = (n - 2) / 2; i >= 0; --i){
		shiftdown(array, n, i);
	}

	// ѭ������
	while (end > 0){
		// �����Ѷ��Ͷ�β
		swap(array, 0, end);
		// �Ѷ�����β
		shiftDown(array, end, 0);
		--end;
	}
}

// һ������: ����Ԫ�رȽ�, �������ƶ�
// ÿһ��������Ա�֤������ֵ�ƶ���ĩβ(����, ����ǽ���,�պ��෴)
// ʱ�临�Ӷ�: ����ΪO(N). ����ΪO(N^2)
// �ռ临�Ӷ�: O(1)
// �ȶ���: �ȶ�(������򲻻ᷢ������
// ��������: ���� ����ΪO(N). ����ΪO(N^2)
// ����Ϊһ���������еĻ�, �ǲ���Ҫ������ ���Կ�����һ��ѭ���� ͨ���ж��Ƿ����˽��� �������Ƿ�����(û�з������� ��Ϊ���� ����ͣ�� ����Ҫ��ȥ��ð��)
void bubbleSort(int* array, int n){
	// Ԫ�ظ���
	int end = n;
	// ʣ������Ԫ�ظ�����ѭ��
	while (end > 0){
		// һ������
		// ����ѭ��д�� flagֻ�������ж��Ƿ�����˽��� 0�򽻻��� ���۽�������, 1��û����
		int flag = 1;
		for (int i = 1; i < end; ++i){
		//for (int i = 0; i <end - 1; ++i); array[i] > array[i + 1];
			// i - 1(0++ ��Ԫ��)�������ƶ�  ��Ȳ��ᷢ������
			// ֻҪ������һ�ν��� flag �͵���0��,
			if (array[i - 1] > array[i]){
				flag = 0;
				swap(array, i - 1, i);
			}
		}
		// ���ǰ�߲����ں��� ��Ϊ�������� ��flag����Ϊ1
		if (flag)
			break;

		// ÿѭ��һ�� �������ٱ���һ��Ԫ�� ����--end
		--end;
	}
}