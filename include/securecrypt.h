#ifndef SECURECRYPT_H
#define SECURECRYPT_H

#include <string>
#include <vector>

enum class PaddingScheme {
    NONE,
    PKCS7
};

class Cipher {
public:
    Cipher(const std::string& key, PaddingScheme padding = PaddingScheme::NONE);

    // For string encryption
    std::string encrypt(const std::string& plaintext);
    std::string decrypt(const std::string& ciphertext);

    // For binary data encryption
    std::vector<unsigned char> encrypt(const std::vector<unsigned char>& data);
    std::vector<unsigned char> decrypt(const std::vector<unsigned char>& data);

    // For file encryption
    void encryptFile(const std::string& inputFilePath, const std::string& outputFilePath);
    void decryptFile(const std::string& inputFilePath, const std::string& outputFilePath);

private:
    std::string key;
    PaddingScheme paddingScheme;

    // Padding and unpadding for string data
    std::string pad(const std::string& input);
    std::string unpad(const std::string& input);

    // Padding and unpadding for binary data
    std::vector<unsigned char> pad(const std::vector<unsigned char>& input);
    std::vector<unsigned char> unpad(const std::vector<unsigned char>& input);
};

#endif // SECURECRYPT_H