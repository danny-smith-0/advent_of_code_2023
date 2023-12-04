#include <advent_of_code.h>

bool is_a_number(char input) { return input >= '0' && input <= '9'; }
bool isnt_a_number_nor_period(char input) { return !is_a_number(input) && input != '.'; }

sll part1(strings_t input)
{
    sll sum = 0;
    size_t num_rows = input.size();
    size_t num_cols = input[0].size();
    for (size_t ii = 0; ii < num_rows; ++ii)
    {
        std::optional<size_t> start_col_opt;
        size_t end_col = 0;
        for (size_t jj = 0; jj < num_cols; ++jj)
        {
            char cell = input[ii][jj];
            if (is_a_number(cell))
            {
                if (!start_col_opt.has_value())
                    start_col_opt = jj;
                end_col = jj;
            }
            else
            {
                // If we just found the first non-number cell after 1 or more number cells
                if (start_col_opt.has_value() && end_col == jj - 1)
                {
                    size_t start_col = start_col_opt.value();
                    int the_number = std::stoi(input[ii].substr(start_col, jj - start_col + 1));
                    if (cell != '.')
                    {
                        // If the current cell isn't a period nor a number, it must be a symbol. Add the number
                        sum += the_number;
                    }
                    else if (start_col > 0 && isnt_a_number_nor_period(input[ii][start_col - 1]))
                    {
                        // If there is one, check the cell on this row before the number started
                        sum += the_number;
                    }
                    else
                    {
                        // Check all adjacent cells in rows before and after this row, but don't go off the end of the matrix
                        ints_t row_indices_to_check;
                        if (ii > 0)
                            row_indices_to_check.push_back(static_cast<int>(ii) - 1);
                        if (ii < num_rows - 1)
                            row_indices_to_check.push_back(static_cast<int>(ii) + 1);

                        int start_index_to_check = static_cast<int>(start_col > 0         ? start_col - 1 :            0);
                        int last_index_to_check = static_cast<int>(end_col < num_cols - 1 ?   end_col + 1 : num_cols - 1);
                        ints_t col_indices_to_check = aoc::matlab_colon(start_index_to_check, last_index_to_check);

                        bool found_a_symbol = false;
                        for (auto row_index : row_indices_to_check)
                        {
                            for (auto col_index : col_indices_to_check)
                            {
                                if (isnt_a_number_nor_period(input[row_index][col_index]))
                                {
                                    found_a_symbol = true;
                                    break;
                                }
                            }
                            if (found_a_symbol)
                            {
                                sum += the_number;
                                break;
                            }
                        }
                    }
                    start_col_opt.reset();
                    end_col = 0;
                }
            }
        }
    }
    return sum;
}

sll part2(strings_t input)
{
    sll out = 0;
    return out;
}

int main ()
{
    std::string day_string = "03";
    std::cout << "Day " << day_string << std::endl;
    strings_t test_data = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_test_input.txt");
    strings_t real_data = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_input.txt");

    std::cout << "\nPart 1\n\n";
    sll results_test_1 = part1(test_data);
    sll expected_test_result_1 = 4361;
    if (aoc::results(results_test_1, expected_test_result_1))
    {
        sll results_real_1 = part1(real_data);
        std::cout << "Real result is " << results_real_1 << std::endl;
        // 538293 is too low (the result I'm currently getting)
        // 600000 is too high
        // 540000 is too low
        // If I didn't skip ANY numbers the total would be 597389. Should've checked this before guessing 600000
    }

    std::cout << "\nPart 2\n\n";
    sll results_test_2 = part2(test_data);
    sll expected_test_result_2 = -1;
    if (aoc::results(results_test_2, expected_test_result_2))
    {
        sll results_real_2 = part2(real_data);
        std::cout << "Real result is " << results_real_2 << "\n\nFinished" << std::endl;
    }

    return 0;
}
