Created: 202409231323
Tags: 

#### Định nghĩa 
Stack là cách tổ chức lưu trữ các đối tượng dưới dạng 1 danh sách tuyến tính mà việc bổ sung đối tượng và lấy các đối tượng ra được thực hiện ở cùng 1 đầu của danh sách
Stack - danh sách kiểu LIFO - last in first out

Bắt buộc phải lấy theo thứ tự, vào sau ra trước

#### Stack ADT
Cấu trúc dữ liệu Stack là 1 cấu trúc dữ liệu trừu tượng được sử dụng để lưu trữ và truy cập dữ liệu theo nguyên tắc LIFO

- Phép toán chính
	- push(Object o): bổ sung đối tượng o vào cuối stack
	- pop(): xóa phần tử cuối cùng của stack
- Phép toán bổ trợ
	- top(): trả lại tham chiếu đến phần tử được bổ sung vào cuối cùng của stack
	- size(): trả lại số phần tử hiện lưu trữ trong stack
	- empty(): trả lại giá trị kiểu boolean để xác định stack có lưu trữ phần tử nào hay không
	
Note: Với stack rỗng thì pop() và top() không thể thực hiện

----
Các chương trình trong máy tính hoạt động theo stack

t=0 -> size = 1
=> size = t + 1, size = -1 -> rỗng

khi xóa trên ổ cứng, dữ liệu k mất đi trừ khi ghi đè lên



-----
## References
1. [[DSA]]
