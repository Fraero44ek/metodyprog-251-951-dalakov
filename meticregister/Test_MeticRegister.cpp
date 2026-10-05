// =====================================================
// Автор: Далаков Аслан Тимурович, группа 251-951
// UnitTest для метода coutn_cometr класса MeticRegister
// 10 различных входных значений
// =====================================================
#include "MeticRegister.h"
#include <iostream>
#include <cassert>

int main() {
    MeticRegister& reg = MeticRegister::getInstance();

    // 10 различных входных значений: <время отклика, время ожидания>
    int data[10][2] = {
        {120,  30}, { 90,  15}, {200,  50}, { 75,  10}, { 60,   5},
        {300, 100}, { 45,  20}, {180,  40}, { 25,   8}, {500, 250}
    };

    // Заполняем реестр. Ключи назначаются автоматически: 1..10
    for (int i = 0; i < 10; ++i)
        reg.add_metr(data[i][0], data[i][1]);

    std::cout << "UnitTest метода coutn_cometr" << std::endl;
    std::cout << "Ключ\tОжидается\tПолучено\tРезультат" << std::endl;

    int passed = 0;
    for (int i = 0; i < 10; ++i) {
        int key      = i + 1;
        int expected = data[i][0] + data[i][1];
        int actual   = reg.coutn_cometr(key);
        bool ok      = (expected == actual);
        if (ok) ++passed;

        std::cout << key << "\t" << expected << "\t\t"
                  << actual << "\t\t" << (ok ? "PASS" : "FAIL") << std::endl;

        assert(ok); // прерывает тест при несовпадении
    }

    std::cout << "\nПройдено " << passed << " из 10 тестов." << std::endl;
    std::cout << (passed == 10 ? "ВСЕ ТЕСТЫ ПРОЙДЕНЫ" : "ЕСТЬ ОШИБКИ") << std::endl;
    return 0;
}
