#include "generateTimestamps.h"
#include<iostream>
#include<iomanip>

RandomGenerator::RandomGenerator(double min, double max, unsigned long seed) :
        _rand_seed(seed), _generator(seed), _min(min), _max(max), _distribution((min + max) / 2, (max - min) / 4) {}

int RandomGenerator::operator ()()
{
    int return_number = 0;
    while (!return_number) 
    {
        double gen_number = 0;
        gen_number = this->_distribution(_generator);
        if (numberIsInRange(gen_number))
            return_number = (int)gen_number;
    }
    return return_number;
}

bool  RandomGenerator::numberIsInRange(double num) { return ((_min <= num) && (num <= _max)); }

std::vector<int> generateRandomNumbers(int size)
{
    srand(time(NULL));
    int random_seed_value = (rand() % 10);
    RandomGenerator gen(0.0, MINUTES_PER_DAY, (unsigned long)random_seed_value);
 
    std::vector<int> numbers;

    for (int i = 0; i < size; i++)
        numbers.push_back(gen());

    std::sort(numbers.begin(), numbers.end());
    return numbers;
}

DayTimestamps::DayTimestamps(std::vector<int> timestamps)
{
    for (int i = 0; i < timestamps.size(); i++)
    {
        _time[0].push_back(timestamps[i] / 60);
        _time[1].push_back(timestamps[i] % 60);
    }
}

std::vector<int> DayTimestamps::GetDailyHours() { return _time[0]; }
std::vector<int> DayTimestamps::GetDailyMinutes() { return _time[1]; }

