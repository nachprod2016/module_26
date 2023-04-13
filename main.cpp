#include "ArraySum.h"

int main()
{
    size_t sizeArr, sizeSubArr;
    std::string buf;
    while (true)
    {
        std::cout << "Введите размер массива: ";
        std::cin >> buf;
        sizeArr = atoi(&buf[0]);
        std::cout << "Введите размер подмассива: ";
        std::cin >> buf;
        sizeSubArr = atoi(&buf[0]);
        if (sizeArr > 0 && sizeSubArr > 0)
        {
            break;
        }
        std::cout << "Неверный ввод!" << std::endl;
    } 
    ArraySum a(sizeArr, sizeSubArr);
    a.showArrayElements();
    a.calculate();
    a.showSumElements();
    return 0;
}