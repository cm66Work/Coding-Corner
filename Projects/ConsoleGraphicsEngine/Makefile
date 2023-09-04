CFLAGS = -std=c++17 -O2 -I -I$(VULKAN_SDK_PATH)/include

a.out: *.cpp *.hpp
	g++ $(CFLAGS) -o a.out *.cpp *.hpp 

.PHONY: test clean

test: a.out
	./a.out

clean:
	rm -f a.out
