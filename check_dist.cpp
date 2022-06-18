#include <random>
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    default_random_engine gen;
    normal_distribution<double> points(75, 14.71960144388);

double f = (double)rand() / RAND_MAX;
    cout << f <<endl;

    for (size_t i = 0; i < 100; i++)
    {
        f = (double)rand() / RAND_MAX;
        cout << f <<endl;
    //     int x = (int)points(gen);
    //     if (x < 50 || x > 100)
    //     {
    //         cout << "Throwed number" << endl;
    //     }

    //     else
    //     {
    //         cout << x << endl;
    //     }
    }

    return 0;
}
