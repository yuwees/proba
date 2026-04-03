#include "mainwindow.h"
#include <QApplication>
#include <QResource>
#include <QPixmap>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Птица"); // Устанавливаем заголовок окна
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Загружаем ресурсы
    Q_INIT_RESOURCE(resources);
    
    setupUI();
}

MainWindow::~MainWindow() {
}

void MainWindow::setupUI() {
    labelTitle = new QLabel("<h2>Вариант 5</h2>", centralWidget);
    
    editRName = new QLineEdit(centralWidget);
    editLName = new QLineEdit(centralWidget);
    editWeight = new QLineEdit(centralWidget);
    editWingspan = new QLineEdit(centralWidget);
    
    radioCanFlyYes = new QRadioButton("Да", centralWidget);
    radioCanFlyNo = new QRadioButton("Нет", centralWidget);
    
    checkboxMigrating = new QCheckBox("Перелетные", centralWidget);
    checkboxWaterproof = new QCheckBox("Водоплавающие", centralWidget);
    checkboxDomestic = new QCheckBox("Домашние", centralWidget);
    
    // Кнопка "Сброс" с большой иконкой
    buttonReset = new QPushButton("", centralWidget); // Без текста
    buttonReset->setIconSize(QSize(48, 48)); // Большой размер иконки
    buttonReset->setIcon(QIcon(":/big_reset_icon.png")); // Большая иконка
    buttonReset->setToolTip("Сброс"); // Подсказка
    connect(buttonReset, &QPushButton::clicked, this, &MainWindow::onResetClicked);
    
    // Кнопка "Сохранить" с маленькой иконкой
    buttonSave = new QPushButton("", centralWidget); // Без текста
    buttonSave->setIconSize(QSize(32, 32)); // Малый размер иконки
    buttonSave->setIcon(QIcon(":/small_save_icon.png")); // Маленькая иконка
    buttonSave->setToolTip("Сохранить"); // Подсказка
    connect(buttonSave, &QPushButton::clicked, this, &MainWindow::onSaveClicked);
    
    // Регулярные выражения для валидаторов
    QRegExp rxRus("[A-ZА-ЯЁ][a-zа-яё]+"); // Первая заглавная русская буква
    QRegExp rxEng("[A-Z][a-z]+"); // Первая заглавная английская буква
    QRegExp rxFloat("\\d+\\.\\d+"); // Дробное число с точкой
    QRegExp rxRange("\\d+-\\d+"); // Диапазон чисел через дефис
    
    editRName->setValidator(new QRegExpValidator(rxRus));
    editLName->setValidator(new QRegExpValidator(rxEng));
    editWeight->setValidator(new QRegExpValidator(rxFloat));
    editWingspan->setValidator(new QRegExpValidator(rxRange));
    
    // Макеты
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->addWidget(labelTitle);
    
    mainLayout->addWidget(new QLabel("Название (P)", centralWidget));
    mainLayout->addWidget(editRName);
    
    mainLayout->addWidget(new QLabel("Название (Л)", centralWidget));
    mainLayout->addWidget(editLName);
    
    mainLayout->addWidget(new QLabel("Вес", centralWidget));
    mainLayout->addWidget(editWeight);
    
    mainLayout->addWidget(new QLabel("Размах крыльев", centralWidget));
    mainLayout->addWidget(editWingspan);
    
    mainLayout->addWidget(new QLabel("Возможность летать", centralWidget));
    QHBoxLayout *flyLayout = new QHBoxLayout();
    flyLayout->addWidget(radioCanFlyYes);
    flyLayout->addWidget(radioCanFlyNo);
    mainLayout->addLayout(flyLayout);
    
    mainLayout->addWidget(new QLabel("Особенности", centralWidget));
    QVBoxLayout *featuresLayout = new QVBoxLayout();
    featuresLayout->addWidget(checkboxMigrating);
    featuresLayout->addWidget(checkboxWaterproof);
    featuresLayout->addWidget(checkboxDomestic);
    mainLayout->addLayout(featuresLayout);
    
    mainLayout->addStretch();
    
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(buttonReset);
    buttonsLayout->addWidget(buttonSave);
    mainLayout->addLayout(buttonsLayout);
    
    centralWidget->setLayout(mainLayout);
}

void MainWindow::onResetClicked() {
    // Улучшенная реализация сброса
    editRName->clear();          // Русское название
    editLName->clear();          // Латинское название
    editWeight->clear();         // Вес
    editWingspan->clear();       // Размах крыльев

    // Чекбоксы
    checkboxMigrating->setChecked(false);  // Перелетные
    checkboxWaterproof->setChecked(false); // Водоплавающие
    checkboxDomestic->setChecked(false);   // Домашние

    // Радиокнопки
    radioCanFlyYes->setAutoExclusive(false); // Временное отключение исключительности
    radioCanFlyNo->setAutoExclusive(false);
    radioCanFlyYes->setChecked(false);      // Снять выделение
    radioCanFlyNo->setChecked(false);
    radioCanFlyYes->setAutoExclusive(true); // Включить обратно
    radioCanFlyNo->setAutoExclusive(true);

    // Установка фокуса на первое поле
    editRName->setFocus();
}

bool MainWindow::validateFields() {
    if (editRName->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните русское название!");
        return false;
    }
    
    if (editWeight->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните вес!");
        return false;
    }
    
    if (editWingspan->text().isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Заполните размах крыльев!");
        return false;
    }
    
    if (!(radioCanFlyYes->isChecked() || radioCanFlyNo->isChecked())) {
        QMessageBox::warning(this, "Ошибка", "Выберите возможность полета!");
        return false;
    }
    
    return true;
}

void MainWindow::onSaveClicked() {
    if (!validateFields())
        return;
        
    QString features;
    if (checkboxMigrating->isChecked()) features += "Перелетные ";
    if (checkboxWaterproof->isChecked()) features += "Водоплавающие ";
    if (checkboxDomestic->isChecked()) features += "Домашние ";
    
    Bird bird(editRName->text(),
              editLName->text(),
              editWeight->text().toFloat(),
              editWingspan->text(),
              radioCanFlyYes->isChecked(),
              features.trimmed());
              
    bird.saveToFile();
    
    QMessageBox::information(this, "Успех", "Данные сохранены успешно!");
}