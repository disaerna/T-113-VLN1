#ifndef ADDSCIENTIST_H
#define ADDSCIENTIST_H

#include <QDialog>
#include <string>
#include "persons.h"
#include "domain.h"
#include "personsmenu.h"
#include "computersmenu.h"
#include <QWidget>


namespace Ui {
class addScientist;
}

class addScientist : public QDialog
{
    Q_OBJECT

public:
    explicit addScientist(QWidget *parent = 0);
    ~addScientist();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    //void on_chooseImage_clicked();

    void on_deadButton_clicked();

    void on_aliveButton_clicked();

private:
    Ui::addScientist *ui;

    Domain _domain;
};

#endif // ADDSCIENTIST_H
