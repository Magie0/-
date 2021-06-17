/****************************************************************************
** Meta object code from reading C++ file 'registerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../second/registerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_registerDialog_t {
    QByteArrayData data[7];
    char stringdata0[98];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_registerDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_registerDialog_t qt_meta_stringdata_registerDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "registerDialog"
QT_MOC_LITERAL(1, 15, 23), // "on_userBox_stateChanged"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 24), // "on_storeBox_stateChanged"
QT_MOC_LITERAL(4, 65, 12), // "enableButton"
QT_MOC_LITERAL(5, 78, 10), // "onRegister"
QT_MOC_LITERAL(6, 89, 8) // "onCancle"

    },
    "registerDialog\0on_userBox_stateChanged\0"
    "\0on_storeBox_stateChanged\0enableButton\0"
    "onRegister\0onCancle"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_registerDialog[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a /* Public */,
       3,    1,   42,    2, 0x0a /* Public */,
       4,    0,   45,    2, 0x0a /* Public */,
       5,    0,   46,    2, 0x0a /* Public */,
       6,    0,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void registerDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        registerDialog *_t = static_cast<registerDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_userBox_stateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->on_storeBox_stateChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->enableButton(); break;
        case 3: _t->onRegister(); break;
        case 4: _t->onCancle(); break;
        default: ;
        }
    }
}

const QMetaObject registerDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_registerDialog.data,
      qt_meta_data_registerDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *registerDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *registerDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_registerDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int registerDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
