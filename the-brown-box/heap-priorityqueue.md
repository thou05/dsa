Created: 202507111451

Tags: 

## Định nghĩa
> HEAP = binary tree (almost complete) + condition (heap property)

- Heap là 1 cây binare tree (đầy đủ, hoàn chỉnh, gần hoàn chỉnh)
- Heap property
	- node cha >= node con (max-heap)
	- node cha <= node con (min-heap)

- Note
	- Các ví dụ về sau lấy ví dụ là Min-Heap. Max heap chỉ đơn giản là làm ngược lại
	- Để đơn giản các ví dụ trong bài mặc định là các phần tử trong dãy không trùng nhau. Để xử lý trường hợp trùng nhau ta chỉ cần thêm thuộc tính số lượng vào là được

- Min-Heap
	- Gốc luôn luôn là phần tử nhỏ nhất
	- Index luôn đc sắp xếp liên tiếp => Sử dụng mảng/array để lưu trữ (chỉ áp dụng đc với cây heap)
	- Con của node thứ i
		- `leftChildIndex = 2 * i`
		- `rightChildIndex = 2* i + 1`
	- Cha của node con thứ i là: `parentIndex = i / 2`

## Cách thao tác với heap
- `isEmpty()`: heap có rỗng hay không?
- `peek()`: lấy giá trị của root (min)
- `add(v)`: thêm phần tử v vào heap
- `poll(), remove()`: trả về giá trị của root (phần tử min) -> xóa root
- `remove()`: xóa phần tử v ra khỏi heap
- `heapify()`: đảm bảo tính chất đống (heap property) mỗi khi thêm vào (heapify-up) hoặc lấy ra (heapify-down)

### Khởi tạo
```java
public class MyHeap{
	private static int MAX_SIZE = 100000;
	private int[] arr = new int[MAX_SIZE + 1];
	private int size;

	MyHeap(){
		size = 0;
	}
}
```

### `isEmpty()`
Kiểm tra heap có rỗng không

```java
public class MyHeap{
	public boolean isEmpty(){
		return size <= 0;
	}
}
```

### `peek()`
Lấy phần tử ở root

```java
public class MyHeap{
	public int peek(){
		if(isEmpty()){
			//throw exception
			sout("Error: Heap is empty");
			return -1;
		}
		return arr[1];
	}
}
```

### add(v)
Thêm v vào heap

```java
private void swap(int i, int j){
	int t = arr[i];
	arr[i] = arr[j];
	arr[j] = t;
}
public void add(int v){
	size++;
	arr[size] = v;

	//heapify up
	int curIndex = size;
	int parentIndex = curIndex / 2;
	while(parentIndex != 0 && arr[parentIndex] > arr[curIndex]){
		swap(parentIndex, curIndex);
		curIndex = parentIndex;
		parentIndex = curIndex / 2;
	}
	
}
```

### `poll()`
Xóa root

- đảm bảo tính chất cây hoàn chỉnh
- đảm bảo heapify 

```java
private void heapifyDown(int curIndex){
	if((2 * curIndex) <= size){
		int leftChildIndex = 2 * curIndex;
		int rightChildIndex = leftChildIndex + 1;
		
		int smallerChildIndex = leftChildIndex;
		if(rightChildIndex <= size && arr[rightChildIndex] < arr[leftChildIndex]){
			smallerChildIndex = rightChildIndex;
		}
		if(arr[curIndex] > arr[smallerChildIndex]){
			swap(curIndex, smallerChildIndex);
			curIndex = smallerChildIndex;
		}else{
			break;
		}
		
	}
}

public int poll(){
	if(isEmpty()){
		sout("Error: Heap is empty");
		return -1;
	}
	int minRoot = arr[1];
	
	//heapify down
	arr[1] = arr[size];
	size--;
	heapifyDown(1);
	
	return minRoot;
}
```

### `remove(v)`
xóa phần tử v trong heap

```java
public void remove(int v){
	int curIndex = -1;
	for(int i = 1; i <= size; i++){
		if(arr[i] == v){
			curIndex = i;
			break;
		}
	}

	if(curIndex == -1){
		sout("Error: Element is not exist!!");
		return;
	}

	arr[curIndex] = arr[size];
	size--;
	heapifyDown(curIndex);
	
}

```

## Test hackerank QHEAP1
https://www.hackerrank.com/challenges/qheap1/problem

```java
public TestHeap{
	psvm(String[] args){
	Scanner scanner = new Scanner(System.in);
	MyHeap minHeap = new MyHeap();
	int q = scanner.nextInt();
	
	while(q > 0){
		int t = scanner.nextInt();
		if(t == 1){
			//add
			minHeap.add(scanner.nextInt());
		}else if(t == 2){
			//remove
			minHeap.remove(scanner.nextInt());
		}else{
			sout(minHeap.peek());
		}
		q--
	}
}
}

```

### Heap trong Java
- `PrioryQueue`

## Khi nào sử dụng Heap
- Khi bài toán có những đặc điểm sau đây:
	- Có nhiều thao tác thêm/xóa phần tử trong tập hợp
	- Tại mỗi thao tác đó luôn có nhu cầu tìm phần tử min/max

-----
## References
1. https://youtu.be/BXYotZVWBm4?list=PLqLksqdSk4b2ely12ZuwQcujGOYAUlPKz

