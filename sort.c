#include "sort.h"
#include "stack.h"

void Swap(int* array, int i, int j){
	
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
	
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
// ʱ�临�Ӷ�: �:O(N^1.3) ���(��������,�ڲ�ѭ����ִ��):O(N)(���O(N)ǰ��ϵ�����ڲ�������)
// �ռ临�Ӷ�: O(1) ����Ҫ���ռ�
// �ȶ���: ���ȶ�,Ԥ������ƻ��ȶ���, ���ݿ��ܻᱻ�ֵ���ͬ��
// ��������: ����

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
			// ���ڱ����Ĺ����������˱Ȳ���Ԫ�ش������ �ǾͰѴ�ķ��ں���(����),key�ѱ���ֵ,
			while (end >= 0 && array[end] > key){
				// ��end��Ԫ�ط���end+gap��λ�� �൱��end��λ�ÿ��˳���,
				array[end + gap] = array[end];
				end -= gap;
			}
			// �������� ��Ҳ�Ҳ�����key���ֵʱ(key��С) ֱ�ӽ����Է���end+gap(��ʱendΪ����,��������ѭ��, keyΪ��С end+gap�պ��ڵ�һ��λ��)
			array[end + gap] = key;
		}
	}
}

// 3. ѡ������:�������㷨 ��δ�����������ѡ��һ����ֵ, �����ŵ�����λ��(��Сֵ����δ�������ݵ�ͷ��λ��, ���ֵ����β��λ��)
// ʱ�临�Ӷ�: O(N^2) �κ�����¶���N^2
// �ռ临�Ӷ�: O(1) û�п��ռ� ���Ǿֲ�����
// �ȶ���: ���ȶ�
// ��������: �����е� (��ԭʼ����û��ϵ ����ԭʼ���� ���߱���)
void selectSort(int* array, int n){
	// iΪδ�����Ԫ�ظ���
	for (int i = n; i > 0; --i){
		// ÿ��ѡһ����С��ֵ, ����δ�������ݵ���ʼλ�� n-i(��һ���൱��n-n) 
		// i��ѭ����С ��ʼλ�ú���
		int start = n - i;
		int min = start;
		// ����ʼλ�ÿ�ʼ ������,Ѱ����Сֵ
		for (int j = start; j < n; ++j){
			// �����ǰ����С����Сֵ ����Сֵ��λ�ñ�Ϊj, 
			if (array[j] < array[min])
				min = j;	
		}
        // ������ʼλ�ú���Сλ�õ�Ԫ��
		Swap(array, start, min);
	}
}


// ��2�ȷ�1��
// ÿ��ѡ����ֵ, һ�����(����δ�����β��),һ����С(����δ�������ʼ),
void selectSort2(int* array, int n){
	int begin = 0;// ��ʼλ��
	int end = n - 1;// β��λ��
	int max, min;
	// Ԫ�ز���������
	while (begin < end){
		// ÿ����һ�����ֵ����Сֵ���ڵ�λ�� (������Сֵ�����ֵ��������ʼλ��)
		min = max = begin;
		// �ӵ�ǰλ�õ���һ��Ԫ�ؿ�ʼ����(Ҳ���Դӵ�ǰλ�ÿ�ʼ)
		for (int j = begin + 1; j <= end; ++j){
			// �統ǰλ�ø��� �������ֵ��λ�ñ�Ϊj
			if (array[j] > array[max]) // (arr[j] >= arr[max) ��ʱ���ȶ���
				max = j;     // ���ֵѡǰ��(���ѡ������ȶ���)
			// �統ǰλ�ø�С, ������Сֵ��λ�ñ�Ϊj
			if (array[j] < array[min])
				min = j;     // ��Сֵѡǰ��
		}

		// ��ʱ�ҵ�����ֵ,min��begin���н���, max��end����
		/* Swap(array, begin, min);
		 Swap(array, end, max);*/

		// ���������������� ��������begin��Ϊʣ��δ���������е����ֵ,
		// ������һ����min��begin������, �ᶪʧ���ֵ, ��ʱ������max��ԭmin�� ��ԭmax��ȴ�����min
		// ֱ�ӽ���max��end������ʹ��Сֵ�ŵ�end��,��begin��������δ����֮ǰ�����һ��Ԫ��)
		// �轫
		Swap(array, begin, min);
		// ���ֵ�ͽ���λ�ý��� 
		if (max == begin)
			max = min;
		Swap(array, end, max);

		++begin;
		--end;
	}
}


// 4. ������(����->��С��  ����->�����)
// ���Ƚ��� --> ��ȡ�Ѷ� --> ���µ���
// ʱ�临�Ӷ�: O(logN)
// �ռ临�Ӷ�: O(1)
// �ȶ���: ���ȶ� --> ���µ������ܻ��ƻ����λ��
// ��������: ÿ�ζ�Ҫ�������������µ���, ������(�����Ƿ����������û���Ӱ��)
// 
// 1. �����Ǵ����һ����Ҷ�ӽ�㿪ʼ�������µ���
// ���������Ǵ��, �Ѷ�Ϊ��һ��,
// 2. ����(�Ѷ��Ͷ�β)
// 3. ��ʣ��Ԫ��(--end)���ɵĶѽ������µ���(�Ѷ�Ϊ�ڶ���)
// 4. ����(�Ѷ��Ͷ�β) 
// 5. ѭ��
// ����
// ʱ�临�Ӷ�ΪO(nlogn)
// nΪsize, parentΪ����� 
void shiftDown(int* array, int n, int parent){
	// ���ҵ����ӵ�λ��
	int child = 2 * parent + 1;
	// child<n �����
	while (child < n){
		// ͬʱҲҪ�ж��Һ����Ƿ����(<n) �ҵ��Һ��Ӵ�������ʱ ȡ�Һ���, ���� ����Ϊ����
		if (child + 1 < n && array[child + 1] > array[child])
			++child;
		// �ȽϺ��Ӻ͸����ֵ
		if (array[child] > array[parent]){
			// �����Ӵ��ڸ���, �򽻻�(ֻ������ֵ)
			Swap(array, child, parent);
			// ���µ���, �����ߵ�����λ��(�Ѻ���λ�ø�������), 
			parent = child; 
			// ���ڸ����ĸ�����������(�����ĸ���㲻һ�������һ����Ҷ�ӽ��) ���������ж�,���Ӽ���������
			child = 2 * parent + 1;
		}
		// ������Ӳ����ڸ��� ���ö�(Ϊ���) ����ѭ��
		else
			break;
	}
}

void heapSort(int* array, int n){
	int end = n - 1;
	// �����(�����һ����Ҷ�ӽ�㿪ʼ�����и����������µ���ֱ������� ---> Ϊ(n - 2) / 2 ).
	for (int i = (n - 2) / 2; i >= 0; --i){
		// shiftdownֻ��һ�ε���(��������㵽Ҷ��)
		shiftDown(array, n, i);
	}

	// ѭ������
	while (end > 0){
		// �Ƚ����Ѷ��Ͷ�β
		Swap(array, 0, end);
		// �ٶ�ʣ��Ԫ�ؽ��жѶ�����β(��ʱ�������Ϊ�����) ����һ��ʼ��n��Ԫ��, ���������end(n-1)�ǶԵ�
		shiftDown(array, end, 0);
		--end;
	}
}

// 5. �������� 
// 5.1 (ð������): 
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
				Swap(array, i - 1, i);
			}
		}
		// ���ǰ�߲����ں��� ��Ϊ�������� ��flag����Ϊ1
		if (flag)
			break;

		// ÿѭ��һ�� �������ٱ���һ��Ԫ�� ����--end
		--end;
	}
}
// 5.2 ����:�����ﵽ����(����)
// ��ȡ�м�ֵ(��partion3������)
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
// (1). hoare��:  ÿ��ѡ��һ����׼ֵ ���ں�С�ڵķֱ���û�׼ֵ�ĺ����ǰ�� ��ź� С��ǰ
// Ȼ��任��׼ֵ, �Ӷ�ȷ��ÿһ����׼ֵ��λ��, ������������ 
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
		// ����С��û�Ҽ�,��ᱻ���������ط� 

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

	int mid = getMid(array, begin, end);
	Swap(array, mid, begin);

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
// ���������: ����ݹ�����Ϊn, �ݹ��ܴ���Ϊ2^n-1 
// ����Ԫ�ظ���Ϊn,�߶�Ϊlogn, ÿһ�㶼�ǶԽ���n�������в��� (�����������Ϊn,�߶�Ϊlog(n+1)
// ʱ�临�Ӷ�: ƽ��O(nlogn),ÿ��ִ�д���������n(��ȥ���ؼ�ֵ), ÿ���������(n)*�߶�(logn)
//          ��������ʱΪO(N^2) (�ݹ���� = Ԫ�ظ��� ÿ����һ��������Ϊ�� ÿ��ִ�д���Ϊ�Ȳ����� ����һ�����1 ÿ��ֻ����׼ֵ��λ��ȷ���� ��һֱ�ڵ��ݹ�)
// ʱ�䲻�ܸ��� �ռ�(����ջ֡)���Ը��� ��ÿһ������ջ֡��Ҫ���� �ٿ���Ҫѹ����ջ֡ ���ý��� �ͷſռ�
// �ռ临�Ӷ�: Ϊ���ĵݹ�������O(logn), ���˶��ٸ��ֲ������Ŀռ�  ÿ�������ڲ���O(1) ����һ���ݹ�ΪO(1)�ĸ��Ӷ� �ܵĸ��Ӷ�Ϊ�ܹ����õĿռ� ÿ��O(1) logn��
// �ݹ�����൱��ѹջ ��ջ ���һֱ�������ݹ�(��ѹջ) �����ջ���
// �ȶ���: ���ȶ� --> ����ʱ���ݻ��������, ���ܻᵼ�����λ�÷����仯
// ��������:

// δ�Ż�
void quickSort(int* array, int begin, int end){
	if (begin >= end)
		return;
	int mid = partion(array, begin, end);
	// int mid = partion2(array, begin, end);
	// int mid = partion3(array, begin, end);

	// ��������(���һ��������ֻ��һ��Ԫ��)
	// �ȸ���׼ֵ����߻���
	quickSort(array, begin, mid - 1);
	// �ٸ���׼ֵ���ұ߻���
	quickSort(array, mid + 1, end);

}

// ���������Ż�(�������������������ջ���):
// 1. С�����Ż�: С����ֱ�ӵ������������㷨, ��ִ�еݹ� 
// ���ò����� ��Ϊ�༭�������Լ򵥵ݹ�����Ż�
// 2. ����ȡ�з�: �Ӵ����ֵ�������, ѡȡ������, ����������ѡ���м�ֵ��Ϊ��׼ֵ 
// Ŀ����������Ļ��ָ��Ӿ���, ���ٵݹ�����
void quickSort2(int* array, int begin, int end){
	
	if (begin >= end)
		return;

	if (end - begin + 1 < 10){
		shellSort(array + begin, end - begin + 1);
	}

	else{
		int mid = partion3(array, begin, end);

	// ��������(���һ��������ֻ��һ��Ԫ��)
	// �ȸ���׼ֵ����߻���
	quickSort(array, begin, mid - 1);
	// �ٸ���׼ֵ���ұ߻���
	quickSort(array, mid + 1, end);
	
	}
}

// �ǵݹ�: ��¼ÿһ��ȷ������ʼ�ͽ���λ��, Ȼ�����Ȼ��ִ�����, �ٻ���С�����˳��������еĻ���
// 1. ��ջ�����������ʼ�ͽ���λ��
void quickSortNor(int* array, int n){
	Stack st;
	stackInit(&st, 10);

	// ���ȱ��������
	if (n > 0){
		stackPush(&st, n - 1);
		stackPush(&st, 0);
		// ������������л���	
		}
	while (stackEmpty(&st) != 1){
		// ��������û�л���
		// ȡ��һ���������ʼ�ͽ���λ��
		int left = stackTop(&st);
		stackPop(&st);
		int right = stackTop(&st);
		stackPop(&st); 
		// ���ֵ�ǰ����
		int div = partion3(array, left, right);
		// ������ȡ������ʼ�ͽ���λ��
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