#ifndef PERSONSMENU_H
#define PERSONSMENU_H

#include "domain.h"
#include <QDialog>
#include <QStackedWidget>
#include <QStackedLayout>
#include <string>
#include <QDialog>

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
    void on_listWidget_activated(const QModelIndex &index);

    void on_button_OK_Cancel_accepted();

private:
    Ui::PersonsMenu *ui;
    Domain _domain;
};

#endif // PERSONSMENU_H
