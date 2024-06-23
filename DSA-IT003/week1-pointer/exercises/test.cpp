#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

// Hàm tạo số ngẫu nhiên thực trong khoảng (-268, 339) với 2 chữ số sau dấu chấm
double generateRandomNumber()
{
	// Khởi tạo bộ sinh số ngẫu nhiên
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> distrib(-268.0, 339.0);

	// Sinh số ngẫu nhiên
	double random_number = distrib(gen);

	// Làm tròn số ngẫu nhiên tới 2 chữ số thập phân
	random_number = std::round(random_number * 100.0) / 100.0;

	return random_number;
}

// Hàm tạo mảng ngẫu nhiên với số lượng phần tử trong khoảng [10, 20]
std::vector<double> generateRandomArray()
{
	// Khởi tạo bộ sinh số ngẫu nhiên
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib_size(10, 20);

	// Sinh số lượng phần tử ngẫu nhiên trong khoảng [10, 20]
	int size = distrib_size(gen);

	// Tạo mảng và điền các số ngẫu nhiên
	std::vector<double> array(size);
	for (int i = 0; i < size; ++i)
	{
		array[i] = generateRandomNumber();
	}

	return array;
}

// Hàm in mảng
void printArray(const std::vector<double> &array)
{
	for (double num : array)
	{
		std::cout << std::fixed << std::setprecision(2) << num << " ";
	}
	std::cout << std::endl;
}

int main()
{
	// Tạo mảng ngẫu nhiên
	std::vector<double> randomArray = generateRandomArray();

	// In mảng ra màn hình
	printArray(randomArray);

	return 0;
}
