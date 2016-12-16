#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <domain.h>

namespace Ui
{
class editComputer;
}

class editComputer : public QDialog
{
    Q_OBJECT

public:
    explicit editComputer(QWidget *parent = 0);
    ~editComputer();
    void setPath(const int &index);
    int getPath();
   void initializeFields();
   void typeList();

private slots:
    void on_submitButton_clicked();
    void on_cancelButton_clicked();


    void on_typeSelection_currentIndexChanged(const QString &arg1);

private:
    Ui::editComputer *ui;
    Domain _domain;
    int _index;

    //test
};

#endif // EDITCOMPUTER_H
