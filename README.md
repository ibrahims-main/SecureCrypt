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
#include "../include/securecrypt.h"
#include <iostream>
#include <vector>

int main() {
    // Define a key and padding scheme
    std::string key = "mysecretkey";
    Cipher cipher(key, PaddingScheme::PKCS7);

    // Test string encryption and decryption
    std::string plaintext = "Hello, this is a test!";
    std::string encryptedText = cipher.encrypt(plaintext);
    std::string decryptedText = cipher.decrypt(encryptedText);

    std::cout << "Original Text: " << plaintext << "\n";
    std::cout << "Encrypted Text: " << encryptedText << "\n";
    std::cout << "Decrypted Text: " << decryptedText << "\n\n";

    // Test binary encryption and decryption
    std::vector<unsigned char> binaryData = {'H', 'e', 'l', 'l', 'o', ' ', 'B', 'i', 'n', 'a', 'r', 'y'};
    std::vector<unsigned char> encryptedBinaryData = cipher.encrypt(binaryData);
    std::vector<unsigned char> decryptedBinaryData = cipher.decrypt(encryptedBinaryData);

    std::cout << "Original Binary Data: ";
    for (unsigned char c : binaryData) {
        std::cout << c;
    }
    std::cout << "\nEncrypted Binary Data: ";
    for (unsigned char c : encryptedBinaryData) {
        std::cout << c;
    }
    std::cout << "\nDecrypted Binary Data: ";
    for (unsigned char c : decryptedBinaryData) {
        std::cout << c;
    }
    std::cout << "\n\n";

    // Test padding and unpadding for string data
    std::string paddedText = cipher.pad(plaintext);
    std::string unpaddedText = cipher.unpad(paddedText);

    std::cout << "Padded Text: " << paddedText << "\n";
    std::cout << "Unpadded Text: " << unpaddedText << "\n\n";

    // Test padding and unpadding for binary data
    std::vector<unsigned char> paddedBinaryData = cipher.pad(binaryData);
    std::vector<unsigned char> unpaddedBinaryData = cipher.unpad(paddedBinaryData);

    std::cout << "Padded Binary Data: ";
    for (unsigned char c : paddedBinaryData) {
        std::cout << c;
    }
    std::cout << "\nUnpadded Binary Data: ";
    for (unsigned char c : unpaddedBinaryData) {
        std::cout << c;
    }
    std::cout << "\n\n";

    // File encryption and decryption
    const std::string inputFilePath = "example.txt";
    const std::string encryptedFilePath = "encrypted_example.txt";
    const std::string decryptedFilePath = "decrypted_example.txt";

    // Encrypt file
    try {
        cipher.encryptFile(inputFilePath, encryptedFilePath);
        std::cout << "File encrypted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error encrypting file: " << e.what() << "\n";
    }

    // Decrypt file
    try {
        cipher.decryptFile(encryptedFilePath, decryptedFilePath);
        std::cout << "File decrypted successfully.\n";
    } catch (const std::exception& e) {
        std::cerr << "Error decrypting file: " << e.what() << "\n";
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