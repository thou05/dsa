Created: 202410170540
Tags: 

Map key vào value bằng 1 cái gì đó gọi là hasing

![[Pasted image 20241017161708.png]]
- key là unique, không được lặp lại
- value có thể đc lặp lại


Ứng dụng: tìm số lần lặp lại của sth
![[Pasted image 20241017161932.png]]

- Key bắt buộc phải là hash table

----
hash func

hash function : map key với 1 số nào đó nằm trong 1 khoảng

bản chất của hash table là 1 array

để lưu key vào trong hash table thì key sẽ được hash ra
-> khi ngta hash key này sẽ biết đc key nằm chỗ nào trong khoảng đó
-> khi đó đưa key vào 1 slot đúng của nó



![[Pasted image 20241017163322.png]]

Khi hash 1 key -> nhận đc 1 index nằm trong 1 range nhất định 
Hash func map key thành 1 index nằm trong 1 range 

mã SHA

Ứng dụng trong software 

collition trong hash table
![[Pasted image 20241017164140.png]]

Thực tế, khi đụng tới collition => dùng collition revolution như
- sprace chaning: dùng linklist 
- open addressing : khi gặp trùng key thì nhét vào ô tiếp theo, nma ô tiếp theo có thì nhét vào ô tiếp theo tiếp
- unvletsing 

-----
Hash table

Hashtable có tối ưu hiệu quả hay không phụ thuộc vào hash func 

-------------
Hasing là 1 kỹ thuật được sử dụng để lưu trữ và truy xuất thông tin càng nhanh càng tốt.

### Hash table ADT
các operation phổ biến
- CreatHashTable: Tạo bảng băm mới
- HashSearch: Tìm kiếm khóa trong bảng băm
- Hashlnsert: Chèn khóa mới vào bảng băm
- HashDelete: Xóa khóa khỏi bảng băm
- DeleteHashTable: Xóa bảng băm

![[Pasted image 20241017054447.png]]


### Thành phần 
1. [[HashTable]]
2. [[HashFunction]]
3. Collisions
4. collision resolution techniques




-----
## References
1. https://viblo.asia/p/chuong-14-hashing-1ly-thuyet-co-ban-oK9VyxmbLQR
2. https://www.geeksforgeeks.org/c-program-hashing-chaining/
3. https://www.youtube.com/watch?v=uKIFNzqX2a8
4. 
