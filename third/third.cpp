#include <iostream>
#include <ctime>

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (j >= 0) && (x < items[j]); j -= gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right)
{
	int i, j;
	int x, y;
	i = left; j = right;
	x = items[(left + right) / 2];
	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;
		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);
	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int main() {
	const int count = 10000;
	int items[count];
	clock_t start, end;
	for (int i = 0;i < count;i++) {
		items[i] = count - i;
	}

	start = clock();
	shell(items, count);
	end = clock();
	std::cout << "Shell: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

	for (int i = 0;i < count;i++) {
		items[i] = count - i;
	}
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	std::cout << "Quick sort: " << (double)(end - start) / CLOCKS_PER_SEC << "\n";

}