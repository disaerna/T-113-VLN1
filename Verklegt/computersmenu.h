#ifndef COMPUTERSMENU_H
#define COMPUTERSMENU_H

#include "ui_computersmenu.h"
#include <QDialog>
#include <QStackedWidget>
#include <QStackedLayout>
#include <string>
#include "domain.h"
#include <QDialog>
#include <QWidget>
// DFDFS
namespace Ui {
class ComputersMenu;
}

class ComputersMenu : public QDialog
{
    Q_OBJECT

public:
    explicit ComputersMenu(QWidget *parent = 0);
    ~ComputersMenu();

private slots:
    void on_Button_remove_computer_clicked();

    void on_list_computer_clicked(const QModelIndex &index);

private:
    void displayComputer(vector<Computers> comp);
    Ui::ComputersMenu *ui;
    Domain _domain;
};

#endif // COMPUTERSMENU_H
