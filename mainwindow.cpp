#include "mainwindow.h"
#include <QApplication>
#include <QRegExp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    setWindowTitle("Птица"); // Устанавливаем заголовок окна
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
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
    
    // Кнопки без иконок
    buttonReset = new QPushButton("Сброс", centralWidget);
    buttonSave = new QPushButton("Сохранить", centralWidget);
    
    // Стили кнопок
    buttonReset->setStyleSheet("background-color: red;");
    buttonSave->setStyleSheet("background-color: green;");
    
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
   