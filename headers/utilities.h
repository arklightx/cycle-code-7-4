//
// Created by ResistanceJkee on 12.12.2021.
//

#ifndef CYCLE_CODE_UTILITIES_H
#define CYCLE_CODE_UTILITIES_H
std::vector<int> convert_string_to_int_vector(const std::string &str);
std::vector<int> get_remainder_division(std::vector<int> message, std::vector<int> polynomial);
int count_ones(const std::vector<int> &vec);
//std::string convert_vec_to_str(const std::vector<int> &vec);
template <typename T>
std::ostream &operator << (std::ostream &os, const std::vector<T> &vec);
void left_shift(std::vector<int> &message);
void right_shift(std::vector<int> &message);
#endif //CYCLE_CODE_UTILITIES_H
