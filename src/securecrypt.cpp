#include "../include/securecrypt.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

// Constructor
Cipher::Cipher(const std::string& key, PaddingScheme padding)
    : key(key), paddingScheme(padding) {}

// Encrypt string data
std::string Cipher::encrypt(const std::string& plaintext) {
    std::string paddedText = pad(plaintext);
    std::string ciphertext;

    for (size_t i = 0; i < paddedText.size(); ++i) {
        ciphertext += paddedText[i] ^ key[i % key.size()]; // Simple XOR encryption
    }

    return ciphertext;
}

// Decrypt string data
std::string Cipher::decrypt(const std::string& ciphertext) {
    std::string decryptedText;

    for (size_t i = 0; i < ciphertext.size(); ++i) {
        decryptedText += ciphertext[i] ^ key[i % key.size()]; // XOR decryption
    }

    return unpad(decryptedText);
}

// Encrypt binary data
std::vector<unsigned char> Cipher::encrypt(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> paddedData = pad(data);
    std::vector<unsigned char> ciphertext;

    for (size_t i = 0; i < paddedData.size(); ++i) {
        ciphertext.push_back(paddedData[i] ^ key[i % key.size()]); // Simple XOR encryption
    }

    return ciphertext;
}

// Decrypt binary data
std::vector<unsigned char> Cipher::decrypt(const std::vector<unsigned char>& data) {
    std::vector<unsigned char> decryptedData;

    for (size_t i = 0; i < data.size(); ++i) {
        decryptedData.push_back(data[i] ^ key[i % key.size()]); // XOR decryption
    }

    return unpad(decryptedData);
}

// Padding for string data
std::string Cipher::pad(const std::string& input) {
    if (paddingScheme == PaddingScheme::NONE) {
        return input;
    }

    int blockSize = 16;
    int padLength = blockSize - (input.length() % blockSize);
    return input + std::string(padLength, static_cast<char>(padLength));
}

// Unpadding for string data
std::string Cipher::unpad(const std::string& input) {
    if (paddingScheme == PaddingScheme::NONE) {
        return input;
    }

    int padLength = static_cast<unsigned char>(input.back());
    if (padLength > input.length()) {
        throw std::runtime_error("Invalid padding length");
    }
    return input.substr(0, input.length() - padLength);
}

// Padding for binary data
std::vector<unsigned char> Cipher::pad(const std::vector<unsigned char>& input) {
    if (paddingScheme == PaddingScheme::NONE) {
        return input;
    }

    int blockSize = 16;
    int padLength = blockSize - (input.size() % blockSize);
    std::vector<unsigned char> paddedData = input;
    paddedData.insert(paddedData.end(), padLength, static_cast<unsigned char>(padLength));
    return paddedData;
}

// Unpadding for binary data
std::vector<unsigned char> Cipher::unpad(const std::vector<unsigned char>& input) {
    if (paddingScheme == PaddingScheme::NONE) {
        return input;
    }

    int padLength = static_cast<unsigned char>(input.back());
    if (padLength > input.size()) {
        throw std::runtime_error("Invalid padding length");
    }
    return std::vector<unsigned char>(input.begin(), input.end() - padLength);
}

// Encrypt and write to a file
void Cipher::encryptFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!inputFile.is_open() || !outputFile.is_open()) {
        throw std::runtime_error("Failed to open input or output file");
    }

    std::string buffer((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    std::string encrypted = encrypt(buffer);
    outputFile.write(encrypted.c_str(), encrypted.size());

    inputFile.close();
    outputFile.close();
}

// Decrypt and write to a file
void Cipher::decryptFile(const std::string& inputFilePath, const std::string& outputFilePath) {
    std::ifstream inputFile(inputFilePath, std::ios::binary);
    std::ofstream outputFile(outputFilePath, std::ios::binary);
    if (!inputFile.is_open() || !outputFile.is_open()) {
        throw std::runtime_error("Failed to open input or output file");
    }

    std::string buffer((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    std::string decrypted = decrypt(buffer);
    outputFile.write(decrypted.c_str(), decrypted.size());

    inputFile.close();
    outputFile.close();
}