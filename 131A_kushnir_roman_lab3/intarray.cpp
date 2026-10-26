#include "intarray.h"
#include <string>
#include <string_view>
#include <iostream>
#include <cmath>
#include <limits>
#include <cctype>

void fill_in_int_array(std::string_view array_name, int *array, int array_size)
{
    std::cout << "Введіть значення елементів масива " << array_name << std::endl;

    for (int index = 0, *arr_element_pointer = array;
         index < array_size;
         index++, arr_element_pointer++)
    {
        *arr_element_pointer = get_valid_number("Введіть значення елемента #" + std::to_string(index));
    }

}

double get_fract_part(double value)
{
    double int_part;
    double frac_part = std::modf(value, &int_part);
    return frac_part;
}

void process_int_array(std::string_view array_name, const int *array, int array_size, int min_required_score)
{
    const int *arr_element_pointer = array;
    int result_count = 0;
    int max_val = std::numeric_limits<int>::min();
    int min_val = std::numeric_limits<int>::max();
    int max_val_index = -1;
    int min_val_index = -1;

    std::cout << "Перебираємо всі елементи масива " << array_name << " і друкуємо ті елементи, корені яких є цілими числами і більші за "
              << min_required_score << std::endl;
    for (int index = 0; index < array_size; index++, arr_element_pointer++)
    {
        if (*arr_element_pointer >= 0)
        {
            const double element_sqrt = std::sqrt(*arr_element_pointer);
            if (get_fract_part(element_sqrt) == 0 && element_sqrt > min_required_score)
            {
                result_count++;
                if (*arr_element_pointer > max_val)
                {
                    max_val = *arr_element_pointer;
                    max_val_index = index;
                }
                if (*arr_element_pointer < min_val)
                {
                    min_val = *arr_element_pointer;
                    min_val_index = index;
                }
            }
        }
    }

    std::cout << "Знайдено " << result_count << " елементів що відповідають заданому критерію\n";
    if (max_val_index != -1 && min_val_index != -1)
    {
        std::cout << "Різниця індексів максимального і мінімального " << max_val_index - min_val_index << "\n";
    }
}

void clear_input_stream()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool is_buffer_clean()
{
    std::string tail;
    std::getline(std::cin, tail);

    for (char ch : tail)
    {
        if (!std::isspace(static_cast<unsigned char>(ch)))
        {
            return false;
        }
    }
    return true;
}

int get_valid_number(std::string_view prompt)
{
    int value;
    while (true)
    {
        std::cout << prompt;

        if (std::cin >> value)
        {
            if (is_buffer_clean())
            {
                return value;
            }
            std::cout << ERROR_MESSAGE_REPEAT_INPUT;
        }
        else
        {
            std::cout << ERROR_MESSAGE_REPEAT_INPUT;
            clear_input_stream();
        }
    }
}



void fill_in_and_process_int_array(std::string_view array_name, int *array, int array_size) {
    int threshold_value;

    fill_in_int_array(array_name, array, array_size);

    system("clear");

    std::cout << MSG_PROGRAM_THRESHOLD_VAL << array_name << ":";
    std::cin >> threshold_value;

    process_int_array(array_name, array, array_size, threshold_value);
}
