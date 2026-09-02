#include <cstdlib>
#include <iostream>
#include <vector>

// [-6,2,4]
std::vector<int> asteroidCollision(std::vector<int> &asteroids) {
    std::vector<int> output;

    for (int &i : asteroids) {
        if (i > 0)
            output.push_back(i);

        else {
            bool boothDestroyed = false;
            while (!output.empty() && output.back() > 0) {
                if (std::abs(i) == std::abs(output.back())) {
                    output.pop_back();
                    boothDestroyed = true;
                    break;
                } else if (std::abs(i) > std::abs(output.back()))
                    output.pop_back();
                else
                    break;
            }
            if ((output.empty() || output.back() < 0) && !boothDestroyed)
                output.push_back(i);
        }
    }

    return output;
}

int main(void) {
    std::vector<int> asteroids = {3, 5, -6, 2, -1, 4};
    asteroids = asteroidCollision(asteroids);

    for (int &i : asteroids) {
        std::cout << i << ",";
    }
    std::cout << std::endl;

    return 0;
}
