Created: 202409220500
Tags: 

bộ lặp, là 1 đối tượng trong lập trình cung cấp cách để duyệt qua các phần tử trong 1 cấu trúc dữ liệu mà không cần biết chi tiết về cách dữ liệu được tổ chức bên trong

Iterator cho phép người dùng truy cập và duyệt qua các phần tử của một cấu trúc dữ liệu theo cách tuần tự và nhất quán. Nó tách biệt việc duyệt qua các phần tử khỏi cấu trúc dữ liệu cụ thể, do đó hỗ trợ việc thay đổi cấu trúc dữ liệu mà không làm thay đổi mã duyệt qua.

Iterator thường có các thành phần sau:
- `begin()`: Trả về một iterator trỏ đến phần tử đầu tiên của cấu trúc dữ liệu.
- `end()`: Trả về một iterator trỏ đến vị trí ngay sau phần tử cuối cùng của cấu trúc dữ liệu (thường được sử dụng để xác định điểm dừng của vòng lặp). 
- `rbegin()`: đặt reverse iterator (trình lặp đảo) đến phần tử cuối cùng trong vector (reverse begin). Nó di chuyển từ phần tử cuối cùng đến phần tử đầu tiên
- `rend()`: đặt reverse iterator (trình lặp đảo) đến phần tử đầu tiên trong vector (reverse end)
- `operator*`: Truy cập giá trị của phần tử mà iterator đang trỏ đến. 
- `operator++`: Di chuyển iterator đến phần tử tiếp theo trong cấu trúc dữ liệu. 
- `operator!=`: So sánh hai iterator để kiểm tra xem chúng có trỏ đến cùng một vị trí hay không.


- Chèn thêm phần tử
	`iterator insert (const_iterator position, const value_type& val)`
	- tạo 1 ô mới có chỉ số r bằng chách đẩy `n-r` phần tử từ `v[r]...v[n-1]` về sau 1 vị trí
	- TH xấu nhất (r=0) phép toán thực hiện trong thời gian O(n)

- Loại bỏ phần tử
	`iterator erase (const_iterator position)`
	- Đẩy `n-r-1` phần tử từ `v[r+1]...v[n-1]` về trước 1 vị trí
	- TH xấu nhất (r=0) phép toán thực hiện trong thời gian O(n)


-----
## References
1. [[DSA]]
2. [[Vector]]
3. https://topdev.vn/blog/vector-trong-c/#vector-tu-ghi-nho-do-dai-cua-minh
4. [[DSA.pdf]]
