//
// Created by ResistanceJkee on 12.12.2021.
//
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "../headers/utilities.h"

std::vector<int> convert_string_to_int_vector(const std::string &str) {
    std::vector<int> v(str.length());
    for (int i = 0; i < str.length(); i++) {
        v[i] = str[i] == '1' ? 1 : 0;
    }
    return v;
}

std::vector<int> get_remainder_division(std::vector<int> message, std::vector<int> polynomial) {
    int i = std::distance(message.begin(), std::find(message.begin(), message.end(), 1));
    while (i <= (message.size() - polynomial.size())) {
        bool flag_skip = true;
        int left_shift = 0;
        for (int j = 0; j < polynomial.size(); j++) {
            message[i + j] ^= polynomial[j];
            if (message[i + j] == 0 && flag_skip)
                left_shift++;
            else
                flag_skip = false;
        }
        i += left_shift;
    }
    return message;
}

int count_ones(const std::vector<int> &vec) {
    int cnt = 0;
    for (auto item: vec) {
        if (item == 1)
            cnt++;
    }
    return cnt;
}

std::string convert_vec_to_str(const std::vector<int> &vec) {
    std::string str;
    bool flag = true;
    for (auto i: vec) {
        if (i == 0) {
            if (!flag)
                str.push_back('0');
            else
                continue;
        } else {
            flag = false;
            str.push_back('1');
        }
    }
    std::cout << str << std::endl;
    return str;
}

void left_shift(std::vector<int> &message) {
    int first_element = message[0];
    message.erase(message.begin());
    message.push_back(first_element);
}

void right_shift(std::vector<int> &message) {
    int last_element = message[message.size() - 1];
    message.erase(message.end() - 1);
    message.insert(message.begin(), last_element);
}

template<typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
    for (auto item: vec)
        os << item << " ";
    return os;
}
