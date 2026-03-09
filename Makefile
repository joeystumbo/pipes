# Makefile for C++ Web Server
export DOCKER_DEFAULT_PLATFORM=linux/amd64
BUILD_DIR = build
DOCKER_IMAGE = cpp-web-server

.PHONY: all build run test clean docker-build docker-run format lint

all: build

build:
	mkdir -p $(BUILD_DIR)
	cd $(BUILD_DIR) && cmake .. && make

run: build
	./$(BUILD_DIR)/_cpp_test

test: build
	cd $(BUILD_DIR) && ctest --output-on-failure

format:
	find . -name "*.cpp" -o -name "*.h" | xargs clang-format -i

lint:
	cppcheck --enable=all --suppress=missingIncludeSystem -iinclude/external -icmake-build-debug -ibuild --suppress=*:include/external/* .

clean:
	rm -rf $(BUILD_DIR)

docker-build:
	docker build -t $(DOCKER_IMAGE) .

docker-run:
	docker run -p 8080:8080 $(DOCKER_IMAGE)
