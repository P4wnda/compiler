# MyCompiler: Simple LLVM IR Generator

This project demonstrates how to generate LLVM Intermediate Representation (IR) using the LLVM C API. It’s a starting point for building your own compiler or programming language with LLVM.

---

## Prerequisites

- **LLVM**: Install LLVM and its development libraries.
  - On macOS: `brew install llvm`
  - On Linux: `sudo apt install llvm clang llvm-dev`
  - On Windows: Download and install LLVM from the [official website](https://llvm.org/).

- **Clang**: Ensure Clang is installed to compile the project.

---

## Building the Project

1. Clone this repository:
   ```bash
   git clone https://github.com/your-username/MyCompiler.git
   cd MyCompiler
   ```
2. Compile the program:
    ```bash
    clang generate_ir.c -o generate_ir `llvm-config --cflags --ldflags --libs core`clang generate_ir.c -o generate_ir `llvm-config --cflags --ldflags --libs core`
    ```
3. Run the program:
    ```bash
    ./generate_ir
    ```

---

## What does this Program do?

The program generates LLVM IR for a simple main function that returns the value 42. The generated IR looks like this:
    
    define i32 @main() {
      ret i32 42
    }

---

## Project Strucutre
- `generate_ir.c`: The main C program that uses the LLVM C API to generate LLVM IR.
- `README.md`: This file

---

## License

This project is licensed under the [MIT License](). 

You are free to use, modify, and distribute this software in accordance with the terms of the license. See the [LICENSE](LICENSE) file for more details.
