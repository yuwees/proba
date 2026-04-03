#ifndef BIRD_H
#define BIRD_H

#include <QString>

class Bird {
public:
    QString russianName; // Русское название
    QString latinName;   // Латинское название
    float weight;        // Вес
    QString wingspan;    // Размах крыльев
    bool canFly;         // Возможность полета
    QString features;     // Особенности

    // Конструктор заполнения
    Bird(const QString &rName, const QString &lName,
         float w, const QString &ws, bool cf, const QString &feat);
    
    // Метод записи в файл
    void saveToFile();
};

#endif // BIRD_H