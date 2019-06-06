/****************************************************************************
** Meta object code from reading C++ file 'DelistedTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../DelistedTool/DelistedTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DelistedTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DelistedTool_t {
    QByteArrayData data[9];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DelistedTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DelistedTool_t qt_meta_stringdata_DelistedTool = {
    {
QT_MOC_LITERAL(0, 0, 12), // "DelistedTool"
QT_MOC_LITERAL(1, 13, 10), // "timeUpdate"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 28), // "on_ZhiDanBox_editTextChanged"
QT_MOC_LITERAL(4, 54, 4), // "arg1"
QT_MOC_LITERAL(5, 59, 23), // "on_IDCtrl_returnPressed"
QT_MOC_LITERAL(6, 83, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 107, 20), // "on_deleteAll_clicked"
QT_MOC_LITERAL(8, 128, 21) // "on_deletePart_clicked"

    },
    "DelistedTool\0timeUpdate\0\0"
    "on_ZhiDanBox_editTextChanged\0arg1\0"
    "on_IDCtrl_returnPressed\0on_pushButton_2_clicked\0"
    "on_deleteAll_clicked\0on_deletePart_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DelistedTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    1,   45,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,
       7,    0,   50,    2, 0x08 /* Private */,
       8,    0,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DelistedTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DelistedTool *_t = static_cast<DelistedTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->timeUpdate(); break;
        case 1: _t->on_ZhiDanBox_editTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_IDCtrl_returnPressed(); break;
        case 3: _t->on_pushButton_2_clicked(); break;
        case 4: _t->on_deleteAll_clicked(); break;
        case 5: _t->on_deletePart_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DelistedTool::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_DelistedTool.data,
      qt_meta_data_DelistedTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DelistedTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DelistedTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DelistedTool.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DelistedTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
