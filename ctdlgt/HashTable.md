Created: 202410170539
Tags: 

![[Pasted image 20241024125307.png]]

![[Pasted image 20241024125545.png]]

![[Pasted image 20241024125643.png]]
- để thiết kế được hash func thì cần dựa vào: key type, key range, numbẻ of buckets

![[Pasted image 20241024130537.png]]
Cách giải quyết xung đột: dùng link list hoặc array để kết nối 2 dữ liệu

![[Pasted image 20241024130657.png]]
![[Pasted image 20241024130823.png]]
![[Pasted image 20241024130911.png]]
![[Pasted image 20241024131320.png]]
 



-----

 mỗi phần tử trong bảng băm là một cặp (khóa, giá trị). Nếu so sánh với mảng, khóa được xem như chỉ số của mảng, còn giá trị giống như giá trị mà ta lưu tại chỉ số tương ứng.
 
Hash table là một tổng quát của mảng. Với mảng, ta lưu phần tử có key là k tại vị trí k của mảng. Tức, tìm phần tử có khóa k bằng cách tìm vị trí thứ k - direct addressing địa chỉ trực tiếp - áp dụng khi có đủ khả năng phân bổ một mảng với một vị trí cho mọi key có thể.


Hash table hoặc Hash map là một cấu trúc dữ liệu lưu trữ các key và giá trị được liên kết của chúng 
hash table sử dụng [[HashFunction]] để ánh xạ các khóa tới các giá trị được liên kết của chúng.

Quy ước chung là chúng ta sử dụng bảng băm khi số lượng key thực sự được lưu trữ là nhỏ so với số lượng key có thể tồn tại.

----
![[Pasted image 20241017171831.png]]
![[Pasted image 20241017172158.png]]
![[Pasted image 20241017172421.png]]
![[Pasted image 20241017172457.png]]
![[Pasted image 20241017180655.png]]
![[Pasted image 20241017180833.png]]
![[Pasted image 20241017180915.png]]
![[Pasted image 20241017180950.png]]
![[Pasted image 20241017181043.png]]

![[Pasted image 20241017181124.png]]
![[Pasted image 20241017181203.png]]
![[Pasted image 20241017181341.png]]



-----
## References
1. https://wiki.vnoi.info/algo/data-structures/hash-table
2.  https://topdev.vn/blog/bang-bam-trong-c/
3. https://wiki.vnoi.info/algo/data-structures/hash-table
4. https://youtu.be/dMyhU07qcgs?list=PLqLksqdSk4b2ely12ZuwQcujGOYAUlPKz
