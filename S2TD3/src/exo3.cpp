#include "ScopedTimer.hpp"
#include "tri.hpp"

int main()
{
    std::cout << "TD 3 - Exercice 3 -> Chrono" << std::endl;

std::vector<int> array = {generate_random_vector(1000)};
    std::sort(array.begin(), array.end());

    {
        ScopedTimer timer("chronomètre bubble sort");
        bubble_sort(array);
    }

    {
        ScopedTimer timer("chronomètre merge sort");
        merge_sort(array);
    }

    {
        ScopedTimer timer("chronomètre std sort");
        std::sort(array.begin(), array.end());
    }

    return 0;
}

// Constat : Le chronomètre du bubble sort est plus lent que celui du merge sort qui est plus lent que celui du std sort
// En conclusion en terme de temps : bubble sort > merge sort > std sort