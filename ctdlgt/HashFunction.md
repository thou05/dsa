Created: 202410170604
Tags: 

Hash Function được sử dụng để chuyển đổi key thành index.

Với một tập hợp các phần tử, hash function ánh xạ từng mục vào một vị trí duy nhất được gọi là _perfect hash function_(hàm băm hoàn hảo).

Một cách để luôn có một hàm băm hoàn hảo là tăng kích thước của hash table để mỗi giá trị có thể có trong phạm vi phần tử có thể được cung cấp. -> hông khả thi khi số lượng phần tử có thể rất lớn.

Mục tiêu của chúng ta là tạo ra một hàm băm giảm thiểu số lần collisions(xung đột), dễ tính toán và phân bổ đồng đều các phần tử trong bảng băm.

Phương pháp folding(gấp) để xây dựng các hàm băm bắt đầu bằng cách chia các phần tử thành các phần có kích thước bằng nhau (phần cuối cùng có thể không có kích thước bằng nhau). Những phần này sau đó được cộng lại với nhau để tạo ra giá trị băm thu được.



-----
## References
1.
