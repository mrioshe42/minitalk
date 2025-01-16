# Minitalk

A lightweight client-server communication program implemented in C using UNIX signals. This project demonstrates inter-process communication through SIGUSR1 and SIGUSR2 signals to transmit messages between processes.

## Features
- Client-server architecture
- Signal-based communication
- Binary message encoding
- Error handling
- Unicode character support

## Requirements
- Unix-based system
- GCC compiler
- Make utility

## Installation

git clone https://github.com/mrioshe42/minitalk.git

cd minitalk
make

## Usage
Start the server:

./server
The server will display its PID.

Send messages using the client:

./client [server_pid] [message]
Example:

./client 4242 "Hello, World!"

## Project Structure
- server.c: Server implementation
- client.c: Client implementation
- minitalk.h: Header file with shared definitions
- Makefile: Compilation rules

## License
This project is part of the 42 school curriculum.

