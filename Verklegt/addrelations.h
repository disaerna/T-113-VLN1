#ifndef ADDRELATIONS_H
#define ADDRELATIONS_H
#include "domain.h"
#include <QDialog>

namespace Ui
{
class addRelations;
}

class addRelations : public QDialog
{
    Q_OBJECT

public:
    explicit addRelations(QWidget *parent = 0);
    ~addRelations();
    void fillComboBoxes();
    void setIDs(int sci, int comp);


private slots:

    void on_pushButton_submit_clicked();

private:

    Ui::addRelations *ui;
    Domain _domain;
    int _sci;
    int _comp;
};

#endif // ADDRELATIONS_H
