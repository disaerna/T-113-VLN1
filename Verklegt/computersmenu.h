#ifndef COMPUTERSMENU_H
#define COMPUTERSMENU_H

#include <QWidget>

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
};

#endif // COMPUTERSMENU_H
