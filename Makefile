APP_NAME := endian
SRC      := src/main.c
CC       := gcc
CFLAGS   := -Wall -Werror -Wextra \
	    	-pedantic -std=c99 \
		-Ofast -march=native -finline-functions \
			-funroll-loops -fomit-frame-pointer -flto

all: clean build run

clean:
	@rm -rf ${APP_NAME}

build:
	@${CC} ${CFLAGS} ${SRC} -o ${APP_NAME}

run:
	@./${APP_NAME}

.PHONY: all clean build run
