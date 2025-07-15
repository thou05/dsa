Created: 202409220404
Tags: 

```C++
void extend(int newcap){
			if(newcap < cap){
				return;
			}
			cap = newcap;
			T *temp = new T[cap];
			for(int i = 0; i < num; i++){
				temp[i] = buff[i];
			}
			if(buff){
				delete[] buff; //xoa buff cũ
			}
			buff = temp; //gán buff mới nhiều cap hơn
		}
```
```C++
void reserve(int newMalloc){   //ham tang dung luong mang
			if(space >= newMalloc){
				return;
			}
			space = newMalloc;  //gan mang cu 
			T *temp = new T[newMalloc];  //cap phat mang moi
			for(int i = 0; i < Size; i++){
				temp[i] = elem[i];  //sao chep phan tu cu sang mang moi
			}
			if(elem){
				delete[] elem;  //xoa mang cu
			}
			elem = temp;  //gan mang moi
		}
```

Khi truyền tham số `newCapacity` (biến chứa dung lượng mới của vector) 
- So sánh: nếu đọo dài mới nhỏ hơn độ dài hiện có => ko thực hiện tăng dung lượng
- Cập nhật dung lượng hiện có của mảng
- Cấp phát mảng có độ dài mới 
- Sao chép phần tử mảng cũ sang mảng vừa thêm dung lượng
- Giải phóng bộ nhớ mảng cũ tránh lãng phí bộ nhớ
- Gan mảng vừa sao chép


-----
## References
1. [[Cài đặt vector bằng mảng]]
