#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <functional>
#include <random>
#include <iomanip>

enum class Insect {
    ClassicBee,
    Ladybug,
    Butterfly,
    Dragonfly,
    Ant,
    Grasshopper,
    Beetle,
    Wasp,
    Caterpillar,
    Spider,
    GuimielBee
};

const std::vector<Insect> insect_values {
    Insect::ClassicBee,
    Insect::Ladybug,
    Insect::Butterfly,
    Insect::Dragonfly,
    Insect::Ant,
    Insect::Grasshopper,
    Insect::Beetle,
    Insect::Wasp,
    Insect::Caterpillar,
    Insect::Spider,
    Insect::GuimielBee
};

const std::unordered_map<Insect, std::string> insect_to_string = {
    {Insect::ClassicBee, "ClassicBee"},
    {Insect::Ladybug, "Ladybug"},
    {Insect::Butterfly, "Butterfly"},
    {Insect::Dragonfly, "Dragonfly"},
    {Insect::Ant, "Ant"},
    {Insect::Grasshopper, "Grasshopper"},
    {Insect::Beetle, "Beetle"},
    {Insect::Wasp, "Wasp"},
    {Insect::Caterpillar, "Caterpillar"},
    {Insect::Spider, "Spider"},
    {Insect::GuimielBee, "GuimielBee"}
};

const std::vector<int> expected_insect_counts {
    75, // ClassicBee
    50, // Ladybug
    100, // Butterfly
    20, // Dragonfly
    400, // Ant
    150, // Grasshopper
    60, // Beetle
    10, // Wasp
    40, // Caterpillar
    90, // Spider 
    5, // GuimielBee
};

std::vector<std::pair<Insect, int>> get_insect_observations(
    const size_t number_of_observations,
    std::vector<float> const& insect_probabilities,
    const unsigned int seed = std::random_device{}()) {
    // Create a random engine with a given seed
    std::default_random_engine random_engine(seed);

    auto randInsectIndex { std::bind(std::discrete_distribution<size_t>{insect_probabilities.begin(), insect_probabilities.end()}, random_engine) };
    
    std::vector<std::pair<Insect, int>> observations {};
    observations.reserve(number_of_observations);

    for(size_t i {0}; i < number_of_observations; ++i) {
        size_t const random_insect_index { randInsectIndex() };
        Insect const random_insect { insect_values[random_insect_index] };
        
        //If we have already seen the same insect, increment the count on the last observation
        auto& previous_observation { observations.back() };
        if(previous_observation.first == random_insect) {
            previous_observation.second++;
            i -= 1;
        } else {
            observations.push_back({random_insect, 1});
        }
    }

    return observations;
}

std::vector<float> probabilities_from_count(std::vector<int> const& counts)
{
    int sum_count {0};
    for (int count : counts)
    {
        sum_count += count;
    }
    std::vector<float> probabilities {};
    for (int count : counts)
    {
        probabilities.push_back(static_cast<float>(count) / static_cast<float>(sum_count));
    }
    return probabilities;
}

int main()
{
    auto probabilities = probabilities_from_count(expected_insect_counts);
    auto observations = get_insect_observations(10000, probabilities);

    std::unordered_map<Insect, int> insect_count {};
    for (const auto& obs : observations)
    {
        insect_count[obs.first] += obs.second;
    }

    std::vector<int> observed_counts {};
    for (const auto& insect : insect_values)
    {
        observed_counts.push_back(insect_count[insect]);
    }

    auto observed_probabilities = probabilities_from_count(observed_counts);
    std::cout << "Probabilities of observed insects vs expected probabilities\n";
    for (size_t i = 0; i < insect_values.size(); i++)
    {
        std::cout << insect_to_string.at(insect_values[i]) << " : ";
        std::cout << std::fixed << std::setprecision(3);
        std::cout << observed_probabilities[i] << " vs " << probabilities[i] << " ";
        if (std::abs(observed_probabilities[i] - probabilities[i]) > 0.01)
        {
            std::cout << "BAD";
        }
        else
        {
            std::cout << "OK";
        }
        std::cout << std::endl;
    }

    return 0;
}