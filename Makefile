CPP_FLAGS=-DREMARKABLE=1 -s -pthread -lpthread

input_demo: input_demo.cpp second.cpp rmkit.h
				arm-linux-gnueabihf-g++ ${CPP_FLAGS} input_demo.cpp second.cpp -c
				arm-linux-gnueabihf-g++ ${CPP_FLAGS} -xc++ - -c -DRMKIT_IMPLEMENTATION -fpermissive -o rmkit.o < rmkit.h
				arm-linux-gnueabihf-g++ ${CPP_FLAGS} *.o -o input_demo


clean:
				rm *.o
				rm input_demo

.PHONY: clean
