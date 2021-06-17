/****************************************************************************
** Meta object code from reading C++ file 'searchgoodsdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../second/searchgoodsdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'searchgoodsdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_searchgoodsDialog_t {
    QByteArrayData data[7];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_searchgoodsDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_searchgoodsDialog_t qt_meta_stringdata_searchgoodsDialog = {
    {
QT_MOC_LITERAL(0, 0, 17), // "searchgoodsDialog"
QT_MOC_LITERAL(1, 18, 23), // "on_searchButton_clicked"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 21), // "on_sortButton_clicked"
QT_MOC_LITERAL(4, 65, 36), // "on_searchcomboBox_currentText..."
QT_MOC_LITERAL(5, 102, 4), // "arg1"
QT_MOC_LITERAL(6, 107, 23) // "on_cancelButton_clicked"

    },
    "searchgoodsDialog\0on_searchButton_clicked\0"
    "\0on_sortButton_clicked\0"
    "on_searchcomboBox_currentTextChanged\0"
    "arg1\0on_cancelButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_searchgoodsDialog[] = {

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

void searchgoodsDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        searchgoodsDialog *_t = static_cast<searchgoodsDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_searchButton_clicked(); break;
        case 1: _t->on_sortButton_clicked(); break;
        case 2: _t->on_searchcomboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_cancelButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject searchgoodsDialog::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_searchgoodsDialog.data,
      qt_meta_data_searchgoodsDialog,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *searchgoodsDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *searchgoodsDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_searchgoodsDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int searchgoodsDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
