#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QRadioButton>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRegExpValidator>
#include <QMessageBox>
#include "bird.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onResetClicked();
    void onSaveClicked();

private:
    QWidget *centralWidget;
    QLabel *labelTitle;
    QLineEdit *editRName, *editLName, *editWeight, *editWingspan;
    QRadioButton *radioCanFlyYes, *radioCanFlyNo;
    QCheckBox *checkboxMigrating, *checkboxWaterproof, *checkboxDomestic;
    QPushButton *buttonReset, *buttonSave;

    void setupUI();
    bool validateFields();
};

#endif // MAINWINDOW_H