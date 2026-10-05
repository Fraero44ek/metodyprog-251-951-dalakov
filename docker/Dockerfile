# =====================================================
# Автор: Далаков Аслан Тимурович, группа 251-951
# =====================================================

# Исходный образ Ubuntu 18.04
FROM ubuntu:18.04

# Установка компилятора gcc
RUN apt-get update && apt-get install -y gcc && rm -rf /var/lib/apt/lists/*

# Папка проекта в контейнере
WORKDIR /MyProj_251-951_Dalakov

# Копирование файлов проекта в заданную папку
COPY . /MyProj_251-951_Dalakov

# Компиляция проекта в файл my_Program
RUN gcc main.c -o my_Program

# Значение параметра программы по умолчанию
ENV PARAM="Hello, Docker!"

# Запуск my_Program с параметром
CMD ["sh", "-c", "./my_Program \"$PARAM\""]
