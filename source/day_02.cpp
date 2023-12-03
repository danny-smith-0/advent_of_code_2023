#include <advent_of_code.h>

enum class Color : uint8_t
{
    RED,
    GREEN,
    BLUE
};

struct Handful
{
    int red = 0;
    int green = 0;
    int blue = 0;
};

struct Game
{
    int id = 0;
    std::vector<Handful> handfuls;

    int max_cubes(Color color)
    {
        int max_cubes = 0;
        for (auto handful : handfuls)
        {
            if (color == Color::RED)
                max_cubes = std::max(max_cubes, handful.red);
            else if (color == Color::GREEN)
                max_cubes = std::max(max_cubes, handful.green);
            else if (color == Color::BLUE)
                max_cubes = std::max(max_cubes, handful.blue);
        }
        return max_cubes;
    }

    int power()
    {
        return this->max_cubes(Color::RED) * this->max_cubes(Color::GREEN) * this->max_cubes(Color::BLUE);
    }
};


std::vector<Game> parse(strings_t input)
{
    std::vector<Game> games;
    // strings_t strs = substrings_to_strings
    for (auto line : input)
    {
        Game game;
        auto strs = aoc::substrings_to_strings(line, ":");
        game.id = std::stoi(aoc::substrings_to_strings(strs[0], " ")[1]);

        strings_t handful_strs = aoc::substrings_to_strings(strs[1],";");
        for (auto handful_str : handful_strs)
        {
            strings_t color_strs = aoc::substrings_to_strings(handful_str, ", ");
            Handful handful;
            for (auto color_str : color_strs)
            {
                strings_t num_and_color = aoc::substrings_to_strings(color_str, " ");
                if (num_and_color[1] == "red")
                    handful.red = std::stoi(num_and_color[0]);
                else if (num_and_color[1] == "green")
                    handful.green = std::stoi(num_and_color[0]);
                else if (num_and_color[1] == "blue")
                    handful.blue = std::stoi(num_and_color[0]);
            }
            game.handfuls.push_back(handful);
        }
        int c = 0;
        games.push_back(game);
        // for (auto my_char :games line) {}
    }
    return games;
}

sll part1(std::vector<Game> games)
{
    sll sum_of_ids = 0;
    for (auto game : games)
    {
        if (game.max_cubes(Color::RED) <= 12 && game.max_cubes(Color::GREEN) <= 13 && game.max_cubes(Color::BLUE) <= 14)
        {
            sum_of_ids += game.id;
        }
    }
    return sum_of_ids;
}

sll part2(std::vector<Game> games)
{
    sll out = 0;
    for (auto game : games)
    {
        out += game.power();
    }
    return out;
}

int main ()
{
    std::string day_string = "02";
    std::cout << "Day " << day_string << std::endl;
    strings_t test_data = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_test_input.txt");
    strings_t real_data = aoc::get_strings_from_file("../puzzle_inputs/day_" + day_string + "_input.txt");
    std::vector<Game> test_data_parsed = parse(test_data);
    std::vector<Game> real_data_parsed = parse(real_data);

    std::cout << "\nPart 1\n\n";
    sll results_test_1 = part1(test_data_parsed);
    sll expected_test_result_1 = 8;
    if (aoc::results(results_test_1, expected_test_result_1))
    {
        sll results_real_1 = part1(real_data_parsed);
        std::cout << "Real result is " << results_real_1 << std::endl;
    }

    std::cout << "\nPart 2\n\n";
    sll results_test_2 = part2(test_data_parsed);
    sll expected_test_result_2 = 2286;
    if (aoc::results(results_test_2, expected_test_result_2))
    {
        sll results_real_2 = part2(real_data_parsed);
        std::cout << "Real result is " << results_real_2 << "\n\nFinished" << std::endl;
    }

    return 0;
}
