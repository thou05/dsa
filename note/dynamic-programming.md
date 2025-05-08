 Created: 202501070049
Tags: 

QUY HOẠCH ĐỘNG

Phương pháp giải các bài toán cần đưa ra lần lượt một loạt các quyết định tối ưu

### Ba tính chất
- Recursive form 
	Bài toán lớn có thể được phân rã thành những bài toán con đồng dạng, những bài toán con đó có thể phân rã thành những bài toán nhỏ hơn nữa …
- Optimal substructure
	Lời giải tối ưu của các bài toán con có thể được sử dụng để tìm ra lời giải tối ưu của bài toán lớn
- Overlapping subproblems
	Hai bài toán con trong quá trình phân rã có thể có chung một số bài toán con khác

### Kỹ thuật thiết kế
- Phân tích bài toán dùng kĩ thuật chia để trị / quay lui
	- Chia bài toán thành các bài toán con
	- Xác định cơ sở của quy hoạch động 
	- Tìm quan hệ giữa kết quả của bài toán lớn và kết quả của các bài toán con -> công thức truy hồi
- Lập bảng quy hoạch
	- `Quy hoạch động = Chia để trị + Cơ chế lưu trữ nghiệm để sử dụng lại`
	- Số chiều = số biến trong công thức truy hồi
	- Xuất phát từ cơ sở của quy hoạch động -> Thiết lập quy tắc điền kết quả vào bảng quy hoạch theo công thức truy hồi 
	- Tra bảng tìm kết quả 
	- Lần vết trên bảng để tìm lời giải tối ưu

- CHÚ Ý
	- Không có một “thuật toán” nào cho chúng ta biết một bài toán có thể giải bằng phương pháp quy hoạch động hay không
	- Khi gặp một bài toán cụ thể -> phân tích bài toán -> kiểm chứng ba tính chất của một bài toán quy hoạch động -> tìm lời giải

- VD: Tính tổ hợp
```
C(n, k) = 1 nếu (n = k) hoặc k = 0
C(n, k) = C(n-1, k-1) + C(n-1, k)

ĐỆ QUY
int comb(int n, int k) { 
	if((k == 0) || (k == n)) 
		return 1; 
	else 
	return comb(n-1, k-1) + comb(n-1, k); 
}
-> Độ phức tạp quá lớn: T(n) = O(2^n)

QUY HOẠCH ĐỘNG : T(n) = O(n^2)
 int comb(int n, int k) {
	 int c[n][n], i, j;
	 c[0][0] = 1;
	 for(i = 1; i<=n; i++) {
		 c[i][0] = 1; c[i][i] = 1;
		 for(j=1; j<i; j++)
			 c[i][j] = c[i-1][j-1] + c[i-1][j];
	 }
	 return c[n][k];
 }
	
Cách 2: tối ưu hơn
 int comb(int n, int k) {
	 int c[n], i, j, p1, p2;
	 c[0] = 1; c[1] = 1;
	 for (i = 2; i<=n; i++) {
		 p1 = c[0];
		 for (j=1; j<i; j++) {
		 p2 = c[j]; c[j] = p1 + p2; p1 = p2;
		 }
		 c[i] = 1; //j = i
	 }
	 return c[k];
}
```


-----
## References
1. SLIDE BÀI 6 - TS.Phạm Đình Phong UTC
2. https://www.topcoder.com/thrive/articles/Dynamic%20Programming:%20From%20Novice%20to%20Advanced
3. 
