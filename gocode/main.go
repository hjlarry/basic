package main

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
