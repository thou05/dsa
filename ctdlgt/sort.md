Created: 202411290235
Tags: 


## Heap sort
#### Complete Binary Tree - cây nhị phân hoàn chỉnh [^1]
![[heapsort.png]]

#### Cấu trúc dữ liệu heap
- Heap là một cây nhị phân hoàn chỉnh
- TH: 
	- nút gốc > 2 con => max heap
		![[maxheap.png]]
	- nút gốc < 2 con => min heap
		![[minheap.png]]
	- Note: thứ tự con bên trái hay phải k quan trọng

- Thao tác `heapify` xây dựng max heap
	``` cpp
	void heapify(int a[], int n, int i){
		int leargest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if(left < n && a[left] > a[largest]){
			largest = left
		}
		if(right < n && a[right] > a[largest]){
			largest = right;
		}
		//khi tim duoc vi tri lon nhat, hoan vi max voi root
		if(largest != i){  
			swap(&a[i], &a[largest]);
			heapify(a, n, largest);
		}
	}
	```

- Xét tất cả các nút không phải nút lá : n/2 - 1 -> 0

#### heap sort
Ý tưởng:
- Sau khi xây dựng đc max heap từ mảng đầu vào  -> hoán vị max với phần tử cuối trong mảng -> heapify tiep trừ những max đã tìm đc
Các bước:
- B1: Vì cây thỏa mãn thuộc tính max heap, nên mục lớn nhất được lưu trữ tại nút gốc
- B2: Hoán đổi: loại bỏ phần tử gốc và đặt cuối mảng
- B3: Giảm kích thước của heap đi 1
- B4: Heapify lại phần tử gốc để có max ở root
- B5: Lặp lại cho đến khi tất cả các mục của danh sách đc sắp xếp
```cpp
void heapsort(int a[], int n){
	//build max heap
	for(int i = n / 2 - 1; i >= 0; i--){
		heapify(a, n, i);
	}
	//heap sort
	for(int i = n - 1; i >= 0; i--){
		swap(a[0], a[i]);
		heapify(a, i , 0);
	}
}
```


-----
## References
1. https://cuuduongthancong.com/atc/2514/chuong-trinh-c++-cai-dat-thuat-toan-merege-sort
2. https://cuuduongthancong.com/atc/2504/chuong-trinh-c-cai-dat-thuat-toan-quicksort
3. https://cuuduongthancong.com/atc/2515/chuong-trinh-c++-cai-dat-thuat-toan-heap-sort

[^1] https://youtu.be/XFI96Z7i3LE?list=PLux-_phi0Rz0Hq9fDP4TlOulBl8APKp79
