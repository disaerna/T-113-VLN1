#ifndef EDITPERSON_H
#define EDITPERSON_H

#include <QDialog>
#include <domain.h>

namespace Ui {
class editPerson;
}

class editPerson : public QDialog
{
    Q_OBJECT

public:
    explicit editPerson(QWidget *parent = 0);
    ~editPerson();
    void setPath(const int &index);
    int getPath();
    void initializeFields();

private slots:
    void on_submitButton_clicked();

private:
    Ui::editPerson *ui;
    Domain _domain;
    int _index;
};

#endif // EDITPERSON_H
