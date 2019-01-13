#include <iostream>
#include <random>
#include <iomanip>

/*Q: ein punkt im rechteck. ist er im kreis? wie haeufig, mal flaeche?
  A: pi

  AK = pi * r * r;
  AR = 4;
  P  = AK / AR;
  AK = AR * P;
*/

std::mt19937 rng;

std::uniform_real_distribution<double> dist(-1.0, 1.0);

int main()
{
    int hits = 0;
    int rolls = 0;
    for (int i = 0; i < 100000000; ++i)
    {
        double x = dist(rng);
        double y = dist(rng);
        if (x * x + y * y <= 1)
        {
            ++hits;
        }
        ++rolls;
        if (i % 5000000 == 0)
        {
            std::cout << std::setprecision(20) << (4.0 * hits) / rolls << "\n";
        }
    }
}

