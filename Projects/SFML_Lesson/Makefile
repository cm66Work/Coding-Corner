CFLAGS = -std=c++17 -O2

a.cout: *.cpp *.hpp
	g++ $(CFLAGS) -o a.out *.cpp

.PHONY: test clean

test: a.out
	./a.out

clean:
	rm -f a.out
