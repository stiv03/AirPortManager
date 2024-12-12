# Използваме ARM64 версия на Ubuntu
FROM --platform=linux/arm64 ubuntu:latest

# Инсталираме нужните инструменти за компилация
RUN apt-get update && apt-get install -y \
    build-essential \
    g++ \
    wget \
    software-properties-common

# Инсталираме CMake (най-новата версия)
RUN wget -qO- "https://cmake.org/files/v3.30/cmake-3.30.0-linux-aarch64.sh" -O /tmp/cmake.sh && \
    chmod +x /tmp/cmake.sh && \
    /tmp/cmake.sh --skip-license --prefix=/usr/local && \
    rm /tmp/cmake.sh

# Създаваме директория за кода на приложението
WORKDIR /app

# Копираме всички файлове от проекта
COPY . /app

# Компилираме приложението
RUN cmake . && make

# Указваме командата за стартиране на приложението
CMD ["./AirPort"]
