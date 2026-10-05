// =====================================================
// Автор: Далаков Аслан Тимурович, группа 251-951
// Демонстрация работы класса MeticRegister (без Qt)
// =====================================================
#include "MeticRegister.h"
#include <iostream>

int main() {
    // Получаем единственный экземпляр реестра
    MeticRegister& reg = MeticRegister::getInstance();

    // Добавляем несколько метрик <время отклика, время ожидания>
    reg.add_metr(120, 30);
    reg.add_metr(90, 15);
    reg.add_metr(200, 50);
    reg.add_metr(75, 10);

    std::cout << "Все метрики реестра:" << std::endl;
    reg.show_mert();

    int key = 3;
    std::cout << "\nВспомогательная метрика для ключа " << key << ": "
              << reg.coutn_cometr(key) << std::endl;

    // Проверка Singleton: второй вызов возвращает тот же объект
    MeticRegister& reg2 = MeticRegister::getInstance();
    std::cout << "Singleton (один и тот же экземпляр): "
              << ((&reg == &reg2) ? "да" : "нет") << std::endl;

    return 0;
}
