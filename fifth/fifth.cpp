#include <iostream>
#include <ctime>
#include <cstdlib>

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;
}

int main() {
    srand(time(NULL));
    const int count = 10000;
    int items[count];
    clock_t start, end;

    for (int i = 0;i < count;i++) {
        items[i] = rand() % 101;
    }
    start = clock();
    qsort(items, count, sizeof(int), compare);
    end = clock();
    std::cout << "1: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

    for (int i = 0;i < count;i++) {
        items[i] = i;
    }
    start = clock();
    qsort(items, count, sizeof(int), compare);
    end = clock();
    std::cout << "2: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

    for (int i = 0;i < count;i++) {
        items[i] = count - i;
    }
    start = clock();
    qsort(items, count, sizeof(int), compare);
    end = clock();
    std::cout << "3: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

    for (int i = 0;i < count;i++) {
        if (i < count / 2)
            items[i] = i;
        else
            items[i] = count - i;
    }
    start = clock();
    qsort(items, count, sizeof(int), compare);
    end = clock();
    std::cout << "4: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";
}
