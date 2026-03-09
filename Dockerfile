# Use a base image with C++ tools that matches the runtime
FROM debian:bookworm AS builder

RUN apt-get update && apt-get install -y cmake g++

WORKDIR /app

COPY . .

RUN mkdir -p build && cd build && \
    cmake .. -DCMAKE_BUILD_TYPE=Release && \
    make

# Use a smaller base image for the final container
FROM debian:bookworm-slim

RUN apt-get update && apt-get install -y libstdc++6 && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/build/_cpp_test .

EXPOSE 8080

CMD ["./_cpp_test"]
