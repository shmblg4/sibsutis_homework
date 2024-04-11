package main

import (
	"fmt"
	"os"
	"sync"
)

type Counter struct {
	mutex sync.Mutex
	count int
}

func (c *Counter) Inc() {
	c.mutex.Lock()
	defer c.mutex.Unlock()
	c.count++
}

func (c *Counter) GetCount() int {
	c.mutex.Lock()
	defer c.mutex.Unlock()
	return c.count
}

func main() {
	counter := &Counter{}

	var wg sync.WaitGroup
	for i := 0; i < 5; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			counter.Inc()
			fmt.Printf("Человек прошел через турникет. Текущее кол-во: %d\n", counter.GetCount())
		}()
	}
	wg.Wait()
	if counter.GetCount() == 0 {
		os.Exit(-1)
	}
	fmt.Printf("Всего людей прошло: %d\n", counter.GetCount())
}
