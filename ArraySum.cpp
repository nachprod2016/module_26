#include "ArraySum.h"

ArraySum::ArraySum(size_t size, size_t count) : arrSize(size), sizeSubArrays(count), sumElements(0)
{
    subArrays = arrSize / sizeSubArrays;
    if (arrSize % subArrays != 0)
    {
        subArrays++;
    }
    srand(time(NULL));
    arr = new int[arrSize];
    for (size_t i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 11;
    }
    std::cout << "Количество подмассивов: " << subArrays << std::endl;
}

ArraySum::~ArraySum() 
{
    delete [] arr;
}

void ArraySum::showArrayElements()
{
    std::cout << "Элементы исходного массива: " << std::endl;
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

void ArraySum::calculate()
{
    //потоки закончившие вычисление
    size_t streamEnd = 0;
    //id потока
    size_t count = 0;
    //индекс первого элемента подмассива
    size_t start = 0;
    while (true)
    {
        std::thread t([=, &streamEnd]()
        {
            sumElements += sum(count, start, streamEnd);
        });
        t.detach();
        count++;
        start += sizeSubArrays;
        if(count == subArrays)
        {
            break;
        }
    }
    while (true)
    {
        if (streamEnd == subArrays)
        {
            break;
        }
    }
}

int ArraySum::sum(size_t id, size_t start, size_t & streamEnd)
{
    std::cout << "Подмассив потока - " << id << " : "; 
    int res = 0;
    for (size_t i = start; i < start + sizeSubArrays; i++)
    {
        std::cout << arr[i] << " ";
        res += arr[i];
        if (start == arrSize - 1)
        {
            break;
        }
    }
    std::cout << std::endl;
    std::cout << "Поток - " << id << " результат расчета: " << res << std::endl;
    streamEnd++;
    return res;
}

void ArraySum::showSumElements()
{
    std::cout << "Сумма элементов массива " << sumElements << std::endl;
}