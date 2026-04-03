#include "bird.h"
#include <QFile>
#include <QTextStream>

Bird::Bird(const QString &rName, const QString &lName,
           float w, const QString &ws, bool cf, const QString &feat)
    : russianName(rName), latinName(lName),
      weight(w), wingspan(ws), canFly(cf), features(feat) {}

void Bird::saveToFile() {
    QFile file("result.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << "Ошибка открытия файла!";
        return;
    }
    
    QTextStream out(&file);
    out << "Русское название: " << russianName << "\n"
        << "Латинское название: " << latinName << "\n"
        << "Вес: " << weight << "\n"
        << "Размах крыльев: " << wingspan << "\n"
        << "Может летать: " << (canFly ? "Да" : "Нет") << "\n"
        << "Особенности: " << features << "\n\n";
}