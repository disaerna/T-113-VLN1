#ifndef EDITRELATION_H
#define EDITRELATION_H

#include <QDialog>

namespace Ui {
class editRelation;
}

class editRelation : public QDialog
{
    Q_OBJECT

public:
    explicit editRelation(QWidget *parent = 0);
    ~editRelation();

private:
    Ui::editRelation *ui;
};

#endif // EDITRELATION_H
