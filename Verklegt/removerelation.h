#ifndef REMOVERELATION_H
#define REMOVERELATION_H

#include <QDialog>

namespace Ui {
class removeRelation;
}

class removeRelation : public QDialog
{
    Q_OBJECT

public:
    explicit removeRelation(QWidget *parent = 0);
    ~removeRelation();

private:
    Ui::removeRelation *ui;
};

#endif // REMOVERELATION_H
