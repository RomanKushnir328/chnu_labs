#ifndef INTARRAY_H
#define INTARRAY_H

#include <string_view>
#include <string>

const std::string MSG_PROGRAM_THRESHOLD_VAL = "\nВведіть необхідне порогове значення для масиву ";
const std::string ERROR_MESSAGE_REPEAT_INPUT = "Помилка!!! Введено некоректне значення. Спробуйте ще раз.\n";

bool is_buffer_clean();
void clear_input_stream();
int get_valid_number(std::string_view);
double get_valid_number(std::string_view, double);


void fill_in_int_array(std::string_view, int*, int);
void process_int_array(std::string_view, const int*, int, int);

void fill_in_and_process_int_array(std::string_view, int*, int);

#endif