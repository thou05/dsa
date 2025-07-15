Created: 202411091652
Tags: 

Recursion involves a function calling itself

![[Recursion.png]]

Ứng dụng của hệ thức truy hồi - trr

ví du tinh a mu b
![[Recursion2.png]]
```cpp
int binpow(int a, int b){
	if(b == 0){
		return 1;
	}
	int x = binpow(a, b / 2);
	if(b % 2 == 1){
		return a * x * x;
	}else{
		return x * x;
	}
}
```



-----
## References
1. https://youtu.be/eQ3VpTtc9lE?list=PLux-_phi0Rz0Hq9fDP4TlOulBl8APKp79
2. 
