#ifndef PERSONSMENU_H
#define PERSONSMENU_H

#include "domain.h"
#include <QWidget>

namespace Ui {
class PersonsMenu;
}

class PersonsMenu : public QWidget
{
    Q_OBJECT

public:
    explicit PersonsMenu(QWidget *parent = 0);
    ~PersonsMenu();

private:
    Ui::PersonsMenu *ui;
    Domain _domain;
};

#endif // PERSONSMENU_H
