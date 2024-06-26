.PHONY: all clean
all: build/ebpf_decoder
clean:
	rm -rf build

CC = clang
CXX = clang++
LD = lld

LIBBPF_DIR = submodule/libbpf
LIBBPF_INC = $(LIBBPF_DIR)/src
LIBBPF_LIB = $(LIBBPF_DIR)/src

CXXFLAGS = -I$(LIBBPF_INC) -stdlib=libc++ -std=c++20
LDFLAGS = -Wl,-rpath,$(LIBBPF_LIB) -L$(LIBBPF_LIB) -lbpf -lelf 

build/ebpf_decoder: src/main.cpp
	mkdir -p build
	$(CXX) $(CXXFLAGS) -o $@ $< $(LDFLAGS)
