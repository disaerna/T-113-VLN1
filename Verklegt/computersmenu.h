#ifndef COMPUTERSMENU_H
#define COMPUTERSMENU_H

#include <QDialog>
#include <QStackedWidget>
#include <QStackedLayout>
#include <string>
#include "domain.h"
//#include <QWidget>
// DFDFS
namespace Ui {
class ComputersMenu;
}

class ComputersMenu : public QWidget
{
    Q_OBJECT

public:
    explicit ComputersMenu(QWidget *parent = 0);
    ~ComputersMenu();

private:
    Ui::ComputersMenu *ui;
    Domain _domain;
};

#endif // COMPUTERSMENU_H
