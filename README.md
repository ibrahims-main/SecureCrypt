# SecureCrypt

A simple and flexible C++ encryption library for encrypting and decrypting text, binary data, and files using a custom XOR-based cipher with PKCS7 padding. It supports both string and file encryption.

## Features

- Encrypt and decrypt strings and binary data.
- Encrypt and decrypt files.
- PKCS7 padding for proper block alignment.
- Simple XOR-based encryption mechanism for demonstration purposes.
- Flexible to add your own encryption algorithm if needed.

## Installation

### Prerequisites

Make sure you have the following installed on your system:

- A C++ compiler (e.g., `g++` or `clang++`)
- CMake (optional, if you want to use CMake for building)
- A text editor or IDE (e.g., Visual Studio Code, Code::Blocks, or any other IDE)

### Clone the repository

To use this library, clone the repository to your local machine using the following command:

```bash
git clone https://github.com/your-username/SecureCrypt.git
```

## Build Instructions

- Copy the `securecrypt.h` and `securecrypt.cpp` files into your project.
- Compile your project using your C++ compiler.

### Compiling with SecureCrypt

You can compile your code with the encryption library like this:

```bash
g++ -o my_program main.cpp src/securecrypt.cpp -std=c++11
```

## Usage

### Example Code

Here’s an example of how to use the `SecureCrypt` library in your project for encrypting and decrypting text, binary data, and files:

```c++
#include <iostream>
#include <vector>
#include "include/securecrypt.h"

int main() {
    try {
        std::string key = "mysecretkey"; // Your encryption key
        Cipher cipher(key);

        // Example with string
        std::string plaintext = "Hello, World!";
        std::string ciphertext = cipher.encrypt(plaintext);
        std::string decrypted = cipher.decrypt(ciphertext);

        std::cout << "Original Plaintext: " << plaintext << std::endl;
        std::cout << "Ciphertext (hex): ";
        for (char c : ciphertext) {
            std::cout << std::hex << (static_cast<int>(c) & 0xff) << " ";
        }
        std::cout << std::endl;
        std::cout << "Decrypted Text: " << decrypted << std::endl;

        // Example with binary data
        std::vector<unsigned char> binaryData = { 'H', 'e', 'l', 'l', 'o' };
        std::cout << "Original Binary Data: ";
        for (auto c : binaryData) {
            std::cout << c;
        }
        std::cout << std::endl;

        auto encryptedBinary = cipher.encrypt(binaryData);
        std::cout << "Encrypted Binary Data (hex): ";
        for (auto c : encryptedBinary) {
            std::cout << std::hex << (static_cast<int>(c) & 0xff) << " ";
        }
        std::cout << std::endl;

        auto decryptedBinary = cipher.decrypt(encryptedBinary);
        std::cout << "Decrypted Binary Data: ";
        for (auto c : decryptedBinary) {
            std::cout << c;
        }
        std::cout << std::endl;

        // Example with file encryption
        std::string inputFile = "text.txt";
        std::string encryptedFile = "encrypted.txt";
        std::string decryptedFile = "decrypted.txt";

        cipher.encryptFile(inputFile, encryptedFile);
        cipher.decryptFile(encryptedFile, decryptedFile);

        std::cout << "File encryption and decryption completed." << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
```

### Example Text File (`text.txt`)

For the file encryption example, you can use the following content in a file named `text.txt`:

```txt
Hello, this is a test file for encryption.
This file will be encrypted and then decrypted.
```

### Expected Output

After running the above program, you will get output like:

```bash
Original Plaintext: Hello, World!
Ciphertext (hex): 25 1c 1f 9 c 5e 45 23 4 17 15 9 58 70 66 60
Decrypted Text: Hello, World!
Original Binary Data: Hello
Encrypted Binary Data (hex): 25 1c 1f 9 c 79 6e 7f 60 6e 72 66 72 78 6e 68
Decrypted Binary Data: Hello
File encryption and decryption completed.
```

The encrypted text from the file `text.txt` will be saved to `encrypted.txt`, and the decrypted output will be saved to `decrypted.txt`.

## Customization

You can modify the encryption key, padding scheme, or even the encryption algorithm itself if required. The library currently uses a simple XOR encryption for demonstration purposes but can be expanded to support more complex algorithms.

## License

This project is licensed under the [MIT License](LICENSE) - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Feel free to submit issues or pull requests.