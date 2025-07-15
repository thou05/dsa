Created: 202410071326
Tags: 

- Cây nhị phaan là cây mỗi nút trong của nó tối đa 2 cây
- Có cây bên trái và cây bên phải

```
Algorithm preOrder(v)
	if(v!=NULL)
		visit(v)
	if(hasLeft(v))
		preOder(left(v))
	if(hasRight(v))
		preOder(right(v))


Algorithm postOrder(v)
	if(hasLeft(v))
		postOder(left(v))
	if(hasRight(v))
		postOder(right(v))
	if(v!=NULL)
		visit(v)
```

-----
## References
1.
