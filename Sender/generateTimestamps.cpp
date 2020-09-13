#include "generateTimestamps.h"

RandomGenerator::RandomGenerator(double min, double max, unsigned long seed) :
        _rand_seed(seed), _generator(seed), _min(min), _max(max), _distribution((min + max) / 2, (max - min) / 4) {}

int RandomGenerator::operator ()()
{
    int return_number = 0;
    double gen_number = 0;
    while (!return_number) 
    {
            gen_number = this->_distribution(_generator);
            if (gen_number >= this->_min && gen_number <= this->_max)
                return_number = (int)gen_number;
    }
    return return_number;
}

std::vector<int> generateRandomNumbers(int size)
{
    //srand(time(0));
    //int random_seed_value = (rand() % 10);
    //RandomGenerator gen(0.0, MINUTES_PER_DAY, (unsigned long)random_seed_value);
    RandomGenerator gen(0.0, MINUTES_PER_DAY, 1);

    std::vector<int> numbers;

    for (int i = 0; i < size; i++)
        numbers.push_back(gen());

    std::sort(numbers.begin(), numbers.end());
    return numbers;
}

int main()
{
    std::vector<int> nums = generateRandomNumbers(10);

    for (int i = 0; i < 10; i++)
        std::cout << nums[i] << std::endl;
}