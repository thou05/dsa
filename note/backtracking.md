Created: 202501070047
Tags: 

``` tphong
Ý tưởng
- kĩ thuật thiết kế thuật toán dựa trên đệ quy
- tìm lời giải từng bước, tại mỗi bước
	- Nếu có 1 lựa chọn chấp nhận được -> ghi nhận và thử bước tiếp
	- Nếu k có lựa chọn nào khả thi
		- Quay lại bước trước
		- Xóa bỏ ghi nhận
		- Thử các lựa chọn còn lại tại bước này
-Phù hợp bài toán liệt kê

BÀI TOÁN
- Liệt kê dãy nhị phân có độ dài n
- Liệt kê tổ hợp chập k của n
- Liệt kê hoán vị
- Bài toán tổng tập con - subset sum
- Bài toán n quân hậu
- Bài toán mã đi tuần
- Trò chơi sudoku
```

``` TXN
Chiến lược tìm kiếm lời giải cho các bài toán thỏa mãn ràng buộc bằng cách xét mọi tổ hợp

Bài toán tổng quát: 
- Nhị phân: liệt kê mọi chuỗi nhị phân độ dài N
- Tập con: liệt kê mọi cách chọn N phần tử trong số M phần tử
- Hoán vị: liệt kê mọi hoán vị của (1,2,...,N)
- Phân tích: liệt kê mọi cách phân tích số M thành tổng N số nguyên dương
- Đặt hậu: liệt kê mọi cách đặt N quân hậu lên bàn cờ NxN để 2 quân bất kì không ăn nhau 


QUY TẮC
Xây dựng từng thành phần cho đến khi đạt được cấu hình theo yc
Cấu hình đầu tiên là rỗng: A = ()
Tìm cách xây dựng dần các phần tử a[1], a[2],..., a[n]
Quy tắc xây dựng phần tử a[k]
	- Nếu k > n: A hoàn chỉnh -> in ra và quay lui
	- Xâu dựng tập S[k] chứa mọi giá trị có thể có của a[k]
	- Nếu S[k] rỗng, quay lui trở về hàm gọi
	- Nếu S[k] != rỗng
		- Cho a[k] lần lượt nhận các giá trị trong S[k]
		- Gọi đệ quy xây dựng phần tử a[k+1]

VD: Nhị phân - liệt kê mọi chuỗi nhị phân độ dài N

```


``` tphong
1. Biểu thức zero. Cho 1 số tự nhiên N <= 9. Giua các số từ 1 đến N hãy thêm vào các dấu + và - sao cho kết quả thu được bằng 0. Hãy viết chương trình tìm tất cả các khả năng có thể. Áp dụng thuật toán đệ quy quay lui để giải quyết bài toán này

	ký pháp hậu tố, tiền tố
	gặp toán hạng thì đưa vào stack
	toán tử thì lấy từ stack ra cộng trừ rồi đưa lại vào stack

2. Cho 1 số tự nhiên N <= 30. Tìm tất cả các cách phân tích số N thành tổng của các số nguyên dương. Các cách phân tích là hoán vị của nhau thì chỉ tính là 1 cách 
```

-----
## References
1.
