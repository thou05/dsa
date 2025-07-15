Created: 202409150026
Tags: #dsa 

Hạn chế lớn của mảng và chuỗi kí tự: thay đổi kích thước của mảng khi thực hiện chương trình => giải quyết vấn đề này bằng linked list
## 1. KN
- Danh sách liên kết (Linked List) là một cấu trúc dữ liệu động bao gồm một chuỗi các phần tử, trong đó mỗi phần tử chứa dữ liệu và một hoặc nhiều tham chiếu (liên kết) tới các phần tử khác => mở rộng hoặc thu gọn một cách linh hoạt mà không cần cấp phát bộ nhớ cố định từ đầu.

- Mô hình ctdl trừu tượng linked list là **1 dãy các vị trí lưu trữ các đối tượng với số lượng tùy ý**
- thiết lập 1 mối quan hệ trước/sau giữa các vị trí
- Mỗi phần tử có 2 thành phần
	- Data: phần chứa dữ liệu
	- Next: phần chỉ vị trí của phần tử tiếp theo trong danh sách

- Ưu điểm: hiệu quả trong việc chèn, trích xuất và di chuyển đến các phần tử ở bất kì vị trí nào trong cấu trúc => các thuật toán sắp xếp hay sử dịnh list
- Nhược điểm
	- thiếu quyền truy cập trực tiếp vào các phần tử theo vị trí của mảng
	- việc lưu giữ thông tin liên kết của mỗi phần tử tốn bộ nhớ

## 2. List trong c++
![[Pasted image 20240915001246.png]]

## 3. [[Singly linked list]]
- con trỏ header, trỏ vào node đầu list
- con trỏ trailer, trỏ vào node cuối list
	![[Pasted image 20240915001708.png]]
	
- các node bao gồm
  - phần tử lưu trữ trong nó
  - 1 liên kết đến nút kế tiếp
	![[Pasted image 20240915001751.png]]

### 3.1 Cấu trúc của 1 node
- Các thuộc tính
  - `Element elem;`
  - `Node *next;`
- Các phương thức
  - `Node *getnext()` : trả lại địa chỉ của node kế tiếp
  - `Element getElem()` : trả lại gtri phần tử lưu trữ trong node
  - `void setNext(Node *)` : gán địa chỉ cho thuộc tính next
  - `void setElem(Element e)` : gán gtri e cho thuộc tính elem
### 3.2 Cấu trúc danh sách lk đơn
- Thuộc tính
  - `Node *header`
  - `Node *trailer`
- Phương thức
  - int size()
  - bool empty()
- Modifiers: front(), back(), insert, erase, push_front(T e), push_back(T e), pop_front(), pop_back()
- Bộ lặp: begin, end, =  !=  ++  `*`(lấy giá trị tham chiếu)

## 4. Danh sách liên kết kép (doubly-linked lists)
![[Pasted image 20240915002345.png]]
![[Pasted image 20240915002358.png]]
![[Pasted image 20240915002418.png]]


----
SFIT
- push_font 
	- tạo node
	- gán con trỏ node mới vào head
	- gán head vào cái mới

- push_back
	- tạo node mới
	- con trỏ trailer gán vào node mới
	- con trỏ node gán null
	- trailer trỏ đến node 

- insert
	- tạo node mới
	- trỏ số 2 gán vô node mới
	- trỏ node mới gán vô số 3

![[Pasted image 20240911184910.png]]

- khong hieu phan nay 
	![[Pasted image 20240911194934.png]]

-----
## References
1. https://youtu.be/CpSE7zsdOVc?si=fs5N3HDH_-nt8mwC
2. https://cuuduongthancong.com/atc/2060/cau-truc-du-lieu-mang-va-danh-sach-lien-ket
3. 


