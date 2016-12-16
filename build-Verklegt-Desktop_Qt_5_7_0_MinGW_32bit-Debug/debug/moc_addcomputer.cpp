/****************************************************************************
** Meta object code from reading C++ file 'addcomputer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Verklegt/addcomputer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'addcomputer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_addComputer_t {
    QByteArrayData data[7];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_addComputer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_addComputer_t qt_meta_stringdata_addComputer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "addComputer"
QT_MOC_LITERAL(1, 12, 23), // "on_submitButton_clicked"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 25), // "on_typeDropDown_activated"
QT_MOC_LITERAL(4, 63, 35), // "on_typeDropDown_currentIndexC..."
QT_MOC_LITERAL(5, 99, 4), // "arg1"
QT_MOC_LITERAL(6, 104, 23) // "on_cancelButton_clicked"

    },
    "addComputer\0on_submitButton_clicked\0"
    "\0on_typeDropDown_activated\0"
    "on_typeDropDown_currentIndexChanged\0"
    "arg1\0on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addComputer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       6,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,

       0        // eod
};

void addComputer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        addComputer *_t = static_cast<addComputer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_submitButton_clicked(); break;
        case 1: _t->on_typeDropDown_activated(); break;
        case 2: _t->on_typeDropDown_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject addComputer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_addComputer.data,
      qt_meta_data_addComputer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *addComputer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addComputer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_addComputer.stringdata0))
        return static_cast<void*>(const_cast< addComputer*>(this));
    return QDialog::qt_metacast(_clname);
}

int addComputer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
