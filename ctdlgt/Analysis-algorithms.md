Tags: #dsa 
## 1. Khái niệm Thuật toán
- là quy trình thực hiện từng bước giải quyết vấn đề trong khoảng thời gian hữu hạn
- Khía cạnh cần phân tích
  - Bộ nhớ (space): xác định tổng dung lượng bộ nhớ cần thiết để lưu trữ toàn bộ dữ liệu đầu vào, trung gian và kết quả đầu ra
  - Thời gian chạy của thuật toán (running time)
## 2. Thời gian chạy của thụât toán
- Thuật toán thực hiện biến đổi các đối tượng đầu vào thành các đối tượng đầu ra
- Thời gian chạy đặc trưng bởi **kích thước của dữ liệu đầu vào**
- đánh giá trong 3 trường hợp: xấu nhất, trung bình và tốt nhất. Tập trung trường hợp nhất **xấu nhất** 
- Phương pháp đánh giá
  - phương pháp thực nghiệm
  - phuong pháp phân tích lý thuyết
  
### 2.1 Phương pháp thực nghiệm
- Các bước thực hiện
  - b1: viết chương trình
  - b2: chạy ctrinh với các dữ liệu đầu vào khác nhau và lấy thời gian chạy 
  - b3: vẽ đồ thị biểu diễn kqua
- thời gian chạy ctrinh mỗi lần khác nhau phụ thuộc vào thời điểm thực thi và môi trường phần cứng, phần mềm

### 2.2 Phương pháp phân tích lý thuyết
- Các bước
  - b1: Mô tả thuật toán bằng giả mã
  - b2: Xác định các phép toán cơ sở
  - b3: Ước lượng thời gian chạy
  - b4: đánh giá thuật toán (running time và space)
  
## 3. Các giả thiết pp phân tích lý thuyết
Mô hình máy truy nhập ngẫu nhiên (Random Access Machine RAM Model)
- CPU
- Ko giới hạn số ô nhớ
- Mỗi ô nhớ có thể lưu 1 số nguyên hoặc ký tự
- Mỗi ô nhớ đc đánh stt
- Thời gian để truy cập đến mỗi ô nhớ đc coi là như nhau, đó là 1 đơn vị thời gian tiêu chuẩn

## 4. Giả mã (Pseudocode)
- Các kí hiệu:
  - <- : phép gán gtri
  - = : phép so sánh bằng
  - $n^2$ : cho phép viết số mũ
  - xuống dòng thay cho dấu { } 
- Câu lệnh điều khiển
  - ìf then else
  - while do
  - for do
- Khai báo hàm, phương thức
```
Algorithm hàm(danh sách đối)
  Input:
  Output:
```
- Gọi hàm, phương thức
`Biến.Pthuc(ds đối)`
- Trả lại giá trị cho hàm 
`return biểu_thức`

## 5. Các phép toán cơ sở và cách xác định
- Các phép toán cơ sở
  - Định giá 1 biểu thức
  - Gán gtri cho 1 biến
  - Truy cập 1 phần tử mảng
  - Gọi hàm
  - Trả lại giá trị cho hàm (return)
  - ![[pheptoancobanc++.png]]
  
- Cách xác định số phép toán cơ sở: duyệt thuật toán giả mã
  -> xác định đc số phép toán tối đa
  -> xây dựng đc hàm thể hiện thời gian chạy 

- Ví dụ
	```
	Algorithm arrayMax(A, n)          Số phép toán
		Max <- A[0]                        2
		for i <- 1 to n - 1 do            2+n
			if A[i] <- Max then           2(n-1)
				Max <- A[i]               2(n-1)  
		return Max                          1
		                            tong: 5n+1
	```

## 6. Ký hiệu Big-O
- ĐN: cho hàm f(n) và g(n), f(n) đgl có Big-O g(n), nếu tồn tại hằng số dương c và số nguyên n0 s/c f(n) <= c.g(n) với mọi n >= n0
KH: O(g(n))
- BigO và tốc độ tăng trưởng giá trị
  - Kí hiệu BigO chỉ ra 1 cận trên của tốc độ tăng trưởng giá trị của 1 hàm
  - "f9(n) có BigO g(n)": tốc độ tăng trưởng giá trị của f(n) không lớn hơn tốc độ tăng trưởng giá trị của g(n)
- Quy tắc xác định BigO
  - Nếu f(n) là đa thức bậc d thì f(n) là O(n^d)
    - bỏ qua các số hạng bậc thấp
    - bỏ qua các hệ số hằng
  - Sử dụng lớp hàm nhỏ nhất có thể
  - Sử dụng lớp hàm đơn giản nhất có thể
## 7. Đánh giá độ phức tạp của thuật toán
- đánh giá thời gian chạy của thuật toán đó, đc xác định bằng ký hiệu bigO

## 8. Các quy tắc cần thiết
- Quy tắc cộng: đoạn ctrinh rời nhau T(n) = O(max(g1(n), g2(n)))
- Quy tắc nhân: đoạn ctrinh lồng nhau T(n) = O(g1(n) * g2(n))

## 9. Đánh giá thuật toán

-------
Độ phức tạp O(n) - lms 
```cpp
long giaithua(int n){    // 2 - khai bao ham va bien n
	long s = 1;          //2 - khai bao va gan 
	int i = 1;           //2
	for(; i <= n;){      //thuc hien n lan, 1 lan so sanh 
		s *= i           // 1
		i++;             // 1
	}                    // tong vong for 3*n va 1 lan so sanh thoat                             vong lap => 3*n + 1
	return s;           //1
}

//T(n) = 2 + 2 + 2 + 3*n + 1 + 1 = 3 * n + 8 = O(n)
```

Độ phức tạp $O(n^2)$
![[Analysis-algorithms.png]]
```cpp
//sap xep doi cho
void sapxep(int n, int a[]){     //3 - khai bao ham, n va a
	int i = 0;
	for()
}
```

-----
SRC
- [Độ phức tạp O(n) - lms ](https://drive.google.com/file/d/1sDVrITgtOdYXqwDXq1menIbVevl95jFo/view?t=4)
- [Độ phức tạp O(n^2)](https://drive.google.com/file/d/17nWaNjV0xJ43YVGLDHaFexWEHmD7qOdm/view)







