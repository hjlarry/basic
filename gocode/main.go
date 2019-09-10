package main

/*
一、同名遮蔽示例
var x = 100

func main() {
	x := x               // 0x18中的x = main.x
	if x := 20; x > 10 { // 0x10中的x赋值20
		println(x) // 打印0x10中的x
		x := x     // 0x8中的x赋值0x10中的x
		println(x) // 打印0x8中的x
	}
	println(x) // 打印0x18中的x
}
*/

/*
二、退化赋值示例
反汇编技巧：编译时使用默认的优化模式，但源码中针对某个方法定义禁止内联，这样这个方法就成了一个标志，方便查找和阅读
*/

//go:noinline
func test() (int, int) {
	return 1, 2
}

func main() {
	a, x := test()
	println(a, x)
	b, x := test()
	println(b, x)
}
