#ifndef PERSONSMENU_H
#define PERSONSMENU_H

#include "domain.h"
#include <QDialog>
#include <QStackedWidget>
#include <QStackedLayout>
#include <string>
#include <QWidget>
#include <QDialog>
#include <vector>

namespace Ui {
class PersonsMenu;
}

class PersonsMenu : public QDialog
{
    Q_OBJECT

public:
    explicit PersonsMenu(QWidget *parent = 0);
    ~PersonsMenu();

private slots:
    void on_Scientists_mainmenu_activated(const QModelIndex &index);

    void on_list_scientists_clicked(const QModelIndex &index);

    void on_Button_remove_scientist_clicked();

private:
    //void displayScientist(std::vector<Persons> person);
    void displayAllScientists();

    Ui::PersonsMenu *ui;
    Domain _domain;

    std::vector<Persons> currentlyDisplayedScientists;
};

#endif // PERSONSMENU_H
