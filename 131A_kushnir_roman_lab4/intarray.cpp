#include "intarray.hpp"
#include <string>
#include <string_view>
#include <iostream>
#include <cmath>
#include <limits>
#include <cctype>
#include <span>
#include <vector>
#include <algorithm>

void fill_in_int_array(std::string_view, std::span<float>);
double get_fract_part(double);
void print_int_array(std::string_view, std::span<const float>);
void process_int_array(std::string_view, std::span<const float>, int, std::vector<float> &filtered_vect);
void clear_input_stream();
bool is_buffer_clean();
int get_valid_number(std::string_view);

void fill_in_int_array(std::string_view array_name, std::span<float> array)
{
    std::cout << "Введіть значення елементів масива " << array_name << std::endl;

    for (int index = 0; index < array.size(); ++index)
    {
        array[index] = static_cast<float>(get_valid_number("Введіть значення елемента #" + std::to_string(index+1) + ": "));
    }
}

double get_fract_part(double value)
{
    double int_part;
    double frac_part = std::modf(value, &int_part);
    return frac_part;
}

void print_int_array(std::string_view name, std::span<const float> array)
{
    std::cout << "Елементи масива " << name << ": ";
    for (const auto &element : array)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

void process_int_array(std::string_view array_name, std::span<const float> container, int min_required_score, std::vector<float> &filtered_vect)
{
    std::cout << "Перебираємо всі елементи масива " << array_name << " і друкуємо ті елементи, корені яких є цілими числами і більші за "
              << min_required_score << std::endl;

    for (auto temp : container)
    {
        if (temp >= 0)
        {
            const double element_sqrt = std::sqrt(temp);
            if (get_fract_part(element_sqrt) == 0 && element_sqrt > min_required_score)
            {
                filtered_vect.push_back(temp);
            }
        }
    }

    if (!filtered_vect.empty())
    {
        std::cout << "Знайдено " << filtered_vect.size() << " елементів що відповідають заданому критерію\n";

        auto [min_it, max_it] = std::minmax_element(filtered_vect.begin(), filtered_vect.end());

        std::cout << "Мінімальний елемент: " << *min_it << std::endl;
        std::cout << "Максимальний елемент: " << *max_it << std::endl;
    }
    else
    {
        
        std::cout << "Немає елементів, що відповідають критерію.\n";
        return;
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

void fill_in_and_process_int_array(std::string_view array_name, std::span<float> array)
{
    int threshold_value;

    fill_in_int_array(array_name, array);

    system("clear");

    threshold_value = get_valid_number(std::string(MSG_PROGRAM_THRESHOLD_VAL) + std::string(array_name) + ": ");

    std::vector<float> filtered_vect;

    process_int_array(array_name, array, threshold_value, filtered_vect);

    print_int_array(array_name, filtered_vect);
}