#ifndef ADDCOMPUTER_H
#define ADDCOMPUTER_H

#include <QDialog>
#include <string>
#include "persons.h"
#include "domain.h"
#include <QWidget>
namespace Ui {
class addComputer;
}

class addComputer : public QDialog
{
    Q_OBJECT

public:
    explicit addComputer(QWidget *parent = 0);
    void typeList();
    ~addComputer();

private slots:
    void on_submitButton_clicked();

    void on_typeDropDown_activated();

    void on_typeDropDown_currentIndexChanged(const QString &arg1);

    void on_cancelButton_clicked();

private:

    Ui::addComputer *ui;

    Domain _domain;
};

#endif // ADDCOMPUTER_H
