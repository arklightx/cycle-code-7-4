#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

#include "headers/utilities.h"
#include "headers/coder.h"

template<typename T>
std::ostream &operator << (std::ostream &os, const std::vector<T> &vec) {
    for (auto elem: vec)
        os << elem << " ";
    return os;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    const int FULL_WORD = 7, WORD = 4;
    std::vector<int> vector(FULL_WORD);
    std::string str;
    std::cout << "Введите число: ";
    std::cin >> str;
    std::vector<int> v = convert_string_to_int_vector(str);
    for (int i = 0; i < WORD; i++)
        vector[i] = v[i];
    std::vector<int> encoded_message = encode_message(vector);
    std::cout << "Закодированное сообщение: " << encoded_message << std::endl;
    std::cout << "Введите сообщение для декодирования: ";
    std::cin >> str;
    std::vector<int> decoded_message = decode_message(convert_string_to_int_vector(str));
    std::cout << "Раскодированное сообщение: " << decoded_message << std::endl;
    return 0;
}
