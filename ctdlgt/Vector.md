Tags: #dsa
## 1. [[Array]]

## 2. Vector
- Vector là **cấu trúc lưu trữ liên tục giống mảng nhưng có thể thay đổi kích thước**
- Đặc điểm chính
	- *Kích thước động*: có thể thay đổi kích thước trong thời gian thực, có thể thêm hoặc xóa mà k cần phải xác định kích thước
	- *Random Access* - truy cập ngẫu nhiên: có thể truy cập bất kỳ phần tử nào của vector trực tiếp thông qua chỉ số, tương tự [[Array]]
	- *Quản lý bộ nhớ*: khi kích thước của vector thay đổi, bộ nhớ được cấp phát hoặc giải phóng tự động
	- *Hiệu suất tốt*: thao tác push_back rất nhanh nhưng chèn hoặc xóa tốn thời gian hơn vì phải dịch chuyển phần tử khác

- So sánh với mảng
  - Giống: các phần tử được lưu trữ ở vị trí liên tục trong bộ nhớ, truy cập giá trị các phần tử bằng chỉ số
  - Khác: kích thước của vector có thể thay đổi động, tiêu thụ nhiều bộ nhớ hơn để quản lý lưu trữ và phát triển động


## 3. Cấu trúc vector
- Khai báo
	- `vector vec_name(n); `
	- `vector vec_name(n, value);` 
	- `T arr = {a1, a2, .., an};`
	- `vector vec_name(arr, arr + n);`
	- `vector vec_name(arr, arr + sizeof(arr)/sizeof(T));`

![[Pasted image 20240904214410.png]]

###### Các nhóm thao tác [[Commonly Used Member Functions Vector]]



---------
## 4. [[Cài đặt vector bằng mảng]]

## 5. [[Phát triển mảng]]
- Khi thực hiện phép toán mà mảng đầy, để thêm phần tử ta phải mở rộng mảng
- How to mở rộng mảng
	- Chiến lược phát triển theo hằng số
	- Chiến lược gấp đôi

## 6. [[Iterator]]
- Được sử dụng để duyệt lần lượt các phần tử của các ADT: vector, list, tree

----
## Reference
- https://www.geeksforgeeks.org/vector-in-cpp-stl/
- [[DSA.pdf]]
- 

