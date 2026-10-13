# BankVault — Thread-Safe Banking & Concurrency Simulator

BankVault is a C-based concurrency project that demonstrates race conditions in shared account balance updates and how mutex-based synchronization prevents lost updates.

## Features

- Multithreaded execution using POSIX threads (`pthreads`).
- Demonstrates race conditions through an intentionally unsafe deposit operation.
- Implements mutex-protected deposits for thread-safe balance updates.
- Compares expected and actual balances to validate synchronization correctness.
- Uses a Makefile to simplify compilation and cleanup.

## How It Works

The program creates four worker threads, each performing 200,000 deposits into a shared account, for a total of 800,000 transactions.

- **Unsafe mode:** Updates the shared balance without synchronization, allowing concurrent operations to overwrite one another.
- **Safe mode:** Uses a POSIX mutex to protect the balance update and prevent concurrent modifications.

## Tech Stack

- C
- POSIX Threads (pthreads)
- Mutexes

## Getting Started

### Build

```bash
make
```

### Run the unsafe version

```bash
./bankvault
```

### Run the thread-safe version

```bash
./bankvault safe
```

### Clean generated files

```bash
make clean
```

## Project Structure

```text
BankVault/
├── main.c
├── account.c
├── account.h
├── worker.c
├── worker.h
├── Makefile
├── .gitignore
└── README.md
```

## Concepts Demonstrated

- Race conditions and lost updates
- Thread synchronization
- Critical sections and mutex locks
- Thread creation and joining
- Concurrent access to shared state

**Note:** The unsafe implementation is intentionally designed for demonstrating concurrency bugs and should not be used in production banking systems.