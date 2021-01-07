CPP_FLAGS=-DREMARKABLE=1 -s -pthread -lpthread

input_demo: input_demo.cpp
				arm-linux-gnueabihf-g++ ${CPP_FLAGS} input_demo.cpp -o input_demo

clean:
				rm input_demo

.PHONY: clean
