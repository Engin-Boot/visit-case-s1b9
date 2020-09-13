#pragma once
#include<vector>
#include<string>
#include<random>
#include<time.h>
#include<algorithm>

#define MINUTES_PER_DAY 1440.0

class RandomGenerator 
{
private:
    unsigned long _rand_seed;
    std::default_random_engine _generator;
    double _min;
    double _max;
    std::normal_distribution<double> _distribution;

    bool numberIsInRange(double num);

public:
    RandomGenerator(double min, double max, unsigned long seed);
    int operator ()();
};

std::vector<int> generateRandomNumbers(int size);

class DayTimestamps
{
private:
    std::vector<int> _time[2];

public:
    explicit DayTimestamps(std::vector<int>);
    std::vector<int> GetDailyHours();
    std::vector<int> GetDailyMinutes();
};