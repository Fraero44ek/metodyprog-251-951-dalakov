// =====================================================
// Автор: Далаков Аслан Тимурович, группа 251-951
// Реестр метрик на основе паттерна Singleton
// =====================================================
#ifndef METICREGISTER_H
#define METICREGISTER_H

#include <map>
#include <utility>

class MeticRegister {
public:
    // Доступ к единственному экземпляру (Singleton Мейерса)
    static MeticRegister& getInstance();

    // Запрет копирования и присваивания
    MeticRegister(const MeticRegister&) = delete;
    MeticRegister& operator=(const MeticRegister&) = delete;

    bool add_metr(int resp_t, int wait_t);  // добавить метрику
    bool show_mert();                        // вывести все метрики по возрастанию ключа
    int  coutn_cometr(int key);              // сумма времени отклика и ожидания по ключу

private:
    MeticRegister();

    // Ключ   - момент времени (целое число)
    // Значение - пара <время отклика, время ожидания>
    std::map<int, std::pair<int, int>> metrics;
    int moment; // следующий момент времени (очередной ключ)
};

#endif // METICREGISTER_H
