package main

//go:noinline
//go:npsplit
func add(x,y int) int{
	return x + y
}
func main() {
	x:=0x11
	y:=0x22
	z:=add(x,y)
	println(z)
}
