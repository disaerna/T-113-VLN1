/****************************************************************************
** Meta object code from reading C++ file 'mainmenu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Verklegt/mainmenu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainMenu_t {
    QByteArrayData data[17];
    char stringdata0[431];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainMenu_t qt_meta_stringdata_MainMenu = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MainMenu"
QT_MOC_LITERAL(1, 9, 31), // "on_Mainmenu_tabs_currentChanged"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 5), // "index"
QT_MOC_LITERAL(4, 48, 34), // "on_Input_Search_Person_textCh..."
QT_MOC_LITERAL(5, 83, 31), // "on_pushButton_AddPerson_clicked"
QT_MOC_LITERAL(6, 115, 31), // "on_table_Scientists_cellPressed"
QT_MOC_LITERAL(7, 147, 3), // "row"
QT_MOC_LITERAL(8, 151, 32), // "on_pushButton_EditPerson_clicked"
QT_MOC_LITERAL(9, 184, 6), // "getRow"
QT_MOC_LITERAL(10, 191, 34), // "on_pushButton_RemovePerson_cl..."
QT_MOC_LITERAL(11, 226, 33), // "on_pushButton_AddComputer_cli..."
QT_MOC_LITERAL(12, 260, 36), // "on_Input_Search_Computer_text..."
QT_MOC_LITERAL(13, 297, 36), // "on_pushButton_RemoveComputer_..."
QT_MOC_LITERAL(14, 334, 30), // "on_table_Computers_cellPressed"
QT_MOC_LITERAL(15, 365, 34), // "on_pushButton_EditComputer_cl..."
QT_MOC_LITERAL(16, 400, 30) // "on_Mainmenu_tabs_tabBarClicked"

    },
    "MainMenu\0on_Mainmenu_tabs_currentChanged\0"
    "\0index\0on_Input_Search_Person_textChanged\0"
    "on_pushButton_AddPerson_clicked\0"
    "on_table_Scientists_cellPressed\0row\0"
    "on_pushButton_EditPerson_clicked\0"
    "getRow\0on_pushButton_RemovePerson_clicked\0"
    "on_pushButton_AddComputer_clicked\0"
    "on_Input_Search_Computer_textChanged\0"
    "on_pushButton_RemoveComputer_clicked\0"
    "on_table_Computers_cellPressed\0"
    "on_pushButton_EditComputer_clicked\0"
    "on_Mainmenu_tabs_tabBarClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x08 /* Private */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    1,   84,    2, 0x08 /* Private */,
       8,    0,   87,    2, 0x08 /* Private */,
       9,    0,   88,    2, 0x08 /* Private */,
      10,    0,   89,    2, 0x08 /* Private */,
      11,    0,   90,    2, 0x08 /* Private */,
      12,    0,   91,    2, 0x08 /* Private */,
      13,    0,   92,    2, 0x08 /* Private */,
      14,    1,   93,    2, 0x08 /* Private */,
      15,    0,   96,    2, 0x08 /* Private */,
      16,    1,   97,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void MainMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainMenu *_t = static_cast<MainMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_Mainmenu_tabs_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_Input_Search_Person_textChanged(); break;
        case 2: _t->on_pushButton_AddPerson_clicked(); break;
        case 3: _t->on_table_Scientists_cellPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_pushButton_EditPerson_clicked(); break;
        case 5: { int _r = _t->getRow();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 6: _t->on_pushButton_RemovePerson_clicked(); break;
        case 7: _t->on_pushButton_AddComputer_clicked(); break;
        case 8: _t->on_Input_Search_Computer_textChanged(); break;
        case 9: _t->on_pushButton_RemoveComputer_clicked(); break;
        case 10: _t->on_table_Computers_cellPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_pushButton_EditComputer_clicked(); break;
        case 12: _t->on_Mainmenu_tabs_tabBarClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainMenu::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainMenu.data,
      qt_meta_data_MainMenu,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainMenu.stringdata0))
        return static_cast<void*>(const_cast< MainMenu*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
