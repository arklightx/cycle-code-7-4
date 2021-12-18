//
// Created by ResistanceJkee on 12.12.2021.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>

#include "../headers/coder.h"
#include "../headers/utilities.h"

const std::vector<int> POL{1, 0, 1, 1};

std::vector<int> encode_message(const std::vector<int>& message) {
    std::vector<int> remainder = get_remainder_division(message, POL);
    std::vector<int> encoded_message = message;
    for (int i = 0; i < message.size(); i++) {
        encoded_message[i] ^= remainder[i];
    }
    return encoded_message;
}

std::vector<int> decode_message(const std::vector<int>& message) {
    std::vector<int> decoded_message = message;
    std::vector<int> remainder = get_remainder_division(decoded_message, POL);
    int errors = count_ones(remainder);
    int shifts = 0;
    for (int i = 0; i < decoded_message.size() && errors > 1; i++) {
        left_shift(decoded_message);
        shifts++;
        remainder = get_remainder_division(decoded_message, POL);
        errors = count_ones(remainder);
    }
    for (int i = 0; i < decoded_message.size(); i++) {
        decoded_message[i] ^= remainder[i];
    }
    for (int i = 0; i < shifts; i++) {
        right_shift(decoded_message);
    }
    return decoded_message;
}