#include <advent_of_code.h>

std::string parse(std::string input)
{
    // twone
    // eightwo
    // eighthree
    // oneight
    // threeight
    // fiveight
    // nineight
    // sevenine

    std::string out;
    for (std::string::iterator itr = input.begin(); itr < input.end(); ++itr)
    {
        // if (*itr == "o")

    }

    return out;
}

sll part1(strings_t input)
{
    sll out = 0;
    for (auto input_line : input)
    {
        for (auto character : input_line)
        {
            if (character > 47 && character < 58)
            {
                out += (character - 48) * 10;
                // std::cout << "Ten: " << (character - 48) * 10 << "\n";
                break;
            }
        }
        for (std::string::reverse_iterator r_itr = input_line.rbegin(); r_itr != input_line.rend(); ++r_itr)
        {
            if ( *r_itr > 47 && *r_itr < 58)
            {
                out += *r_itr - 48;
                // std::cout << "One: " << *r_itr - 48 << "\n";
                break;
            }
        }
    }
    return out;
}

sll part2(strings_t input)
{
    sll out = 0;
    for (auto& input_line : input)
    {
        // input_line.
        input_line = std::regex_replace(input_line, std::regex("one"), "1");
        input_line = std::regex_replace(input_line, std::regex("two"), "2");
        input_line = std::regex_replace(input_line, std::regex("three"), "3");
        input_line = std::regex_replace(input_line, std::regex("four"), "4");
        input_line = std::regex_replace(input_line, std::regex("five"), "5");
        input_line = std::regex_replace(input_line, std::regex("six"), "6");
        input_line = std::regex_replace(input_line, std::regex("seven"), "7");
        input_line = std::regex_replace(input_line, std::regex("eight"), "8");
        input_line = std::regex_replace(input_line, std::regex("nine"), "9");

        // std::cout << input_line << "\n";
        for (auto character : input_line)
        {
            if (character > 47 && character < 58)
            {
                out += (character - 48) * 10;
                // std::cout << "Ten: " << (character - 48) * 10 << "\n";
                break;
            }
        }
        for (std::string::reverse_iterator r_itr = input_line.rbegin(); r_itr != input_line.rend(); ++r_itr)
        {
            if ( *r_itr > 47 && *r_itr < 58)
            {
                out += *r_itr - 48;
                // std::cout << "One: " << *r_itr - 48 << "\n";
                break;
            }
        }
    }
    return out;
}

int main ()
{
    std::string day_string = "01";
    std::cout << "Day " << day_string << std::endl;
    strings_t test_data = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_test_input.txt");
    strings_t test_data2 = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_test_input_2_parsed.txt");
    strings_t real_data = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_input.txt");
    strings_t real_data2 = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_input_parsed.txt");

    std::cout << "\nPart 1\n\n";
    sll results_test_1 = part1(test_data);
    sll expected_test_result_1 = 142;
    if (aoc::results(results_test_1, expected_test_result_1))
    {
        sll results_real_1 = part1(real_data);
        std::cout << "Real result is " << results_real_1 << std::endl;
    }

    std::cout << "\nPart 2\n\n";
    sll results_test_2 = part2(test_data2);
    sll expected_test_result_2 = 281;
    if (aoc::results(results_test_2, expected_test_result_2))
    {
        sll results_real_2 = part2(real_data2);
        std::cout << "Real result is " << results_real_2 << "\n\nFinished" << std::endl;
        // 54926 is too low. I hadn't switched to the parsed data yet
    }

    return 0;
}
