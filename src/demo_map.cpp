#include <map>
#include <vector>
#include <string>
#include <iostream>

std::map<std::string, int> populate_with_iterator(const std::vector<std::string>& words)
{
    std::map<std::string, int> frequencies;

    for (const auto& w : words) {
        auto search = frequencies.find(w);
        if (search == frequencies.end()) {
            frequencies.insert(search, {w, 1});
        } else {
            ++(search->second);
        }
    }

    return frequencies;
}

std::map<std::string, int> populate_with_sq_bracket(const std::vector<std::string>& words)
{
    std::map<std::string, int> frequencies;

    for (const auto& w : words) {
        auto search = frequencies.find(w);
        if (search == frequencies.end()) {
            frequencies[w] = 1;
        } else {
            ++frequencies[w];
        }
    }

    return frequencies;
}

std::map<std::string, int> populate_with_sq_bracket_2(const std::vector<std::string>& words)
{
    std::map<std::string, int> frequencies;

    for (const auto& w : words) {
        auto count = frequencies[w];
        if (count == 0) {
            frequencies[w] = 1;
        } else {
            ++frequencies[w];
        }
    }

    return frequencies;
}

std::map<std::string, int> populate_with_at(const std::vector<std::string>& words)
{
    std::map<std::string, int> frequencies;

    for (const auto& w : words) {
        auto search = frequencies.find(w);
        if (search == frequencies.end()) {
            frequencies.insert(search, {w, 1}); // cannot use at here (because of exception)
        } else {
            ++frequencies.at(w);
        }
    }

    return frequencies;
}

int main()
{
    std::vector<std::string> words = {"to", "be", "or", "not", "to", "be"};

    auto freq_iter = populate_with_sq_bracket_2(words);

    for (const auto& entry : freq_iter) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

}