#ifndef EDITRELATION_H
#define EDITRELATION_H
#include "domain.h"
#include <QDialog>

namespace Ui
{
class editRelation;
}

class editRelation : public QDialog
{
    Q_OBJECT

public:
    explicit editRelation(QWidget *parent = 0);
    ~editRelation();
    void fillComboBoxes();
    void setIDs(int sci, int comp);


private slots:

    void on_pushButton_submit_clicked();

    void on_pushButton_cancel_clicked();

private:

    Ui::editRelation *ui;
    Domain _domain;
    int _sci;
    int _comp;
};

#endif // EDITRELATION_H
