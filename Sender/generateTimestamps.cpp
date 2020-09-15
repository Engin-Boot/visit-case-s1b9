#include "generateTimestamps.h"

RandomGenerator::RandomGenerator(double min, double max, unsigned long seed) :
    _rand_seed(seed),
    _generator(seed), 
    _min(min), 
    _max(max), 
    _distribution((min + max) / 2, (max - min) / 4) {} 
//(max-min)/4 - this term can be adjusted for std dev.Iincrease denominator for lesser deviation.

int RandomGenerator::operator() ()
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

void DayTimestamps::generateRandomNumbers(int size)
{
    srand(time(NULL));
    int random_seed_value = (rand() % 10);
    RandomGenerator gen(0.0, MINUTES_PER_DAY, (unsigned long)random_seed_value);
 
    for (int i = 0; i < size; i++)
        _random_numbers.push_back(gen());

    std::sort(_random_numbers.begin(), _random_numbers.end());

}

DayTimestamps::DayTimestamps(int size)
{
    generateRandomNumbers(size);
    for (int i = 0; i < size; i++)
    {
        _time[0].push_back(_random_numbers[i] / 60);
        _time[1].push_back(_random_numbers[i] % 60);
    }
}

std::vector<int> DayTimestamps::GetDailyHours() { return _time[0]; }
std::vector<int> DayTimestamps::GetDailyMinutes() { return _time[1]; }

