package main 
import (
	"fmt"
	"runtime"
	"time"
	)

var i int = 0

func thread_increase_i(){
	for j := 0; j < 1000000; j++ {
		i++
	}
}

func thread_decrease_i(){
	for j := 0; j < 1000000; j++ {
		i--
	}
}

func main(){
	runtime.GOMAXPROCS(runtime.NumCPU())
	go thread_decrease_i()
	go thread_increase_i()

	time.Sleep(100*time.Millisecond)
	fmt.Println(i)
}