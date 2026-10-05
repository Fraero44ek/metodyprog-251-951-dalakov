// =====================================================
// Автор: Далаков Аслан Тимурович, группа 251-951
// Реализация класса MeticRegister
// =====================================================
#include "MeticRegister.h"
#include <iostream>

MeticRegister::MeticRegister() : moment(0) {}

MeticRegister& MeticRegister::getInstance() {
    static MeticRegister instance; // создаётся один раз при первом вызове
    return instance;
}

// Добавление метрики. Ключ (момент времени) назначается автоматически.
bool MeticRegister::add_metr(int resp_t, int wait_t) {
    if (resp_t < 0 || wait_t < 0)
        return false;                 // некорректные значения не добавляем
    ++moment;
    metrics[moment] = std::make_pair(resp_t, wait_t);
    return true;
}

// Вывод всех метрик, упорядоченных по ключу (std::map хранит ключи по возрастанию)
bool MeticRegister::show_mert() {
    if (metrics.empty()) {
        std::cout << "Реестр метрик пуст." << std::endl;
        return false;
    }
    std::cout << "Ключ\tВремя отклика\tВремя ожидания" << std::endl;
    for (const auto& m : metrics) {
        std::cout << m.first << "\t"
                  << m.second.first << "\t\t"
                  << m.second.second << std::endl;
    }
    return true;
}

// Вспомогательная метрика: сумма времени отклика и ожидания для ключа.
// Если ключ не найден, возвращается -1.
int MeticRegister::coutn_cometr(int key) {
    auto it = metrics.find(key);
    if (it == metrics.end())
        return -1;
    return it->second.first + it->second.second;
}
