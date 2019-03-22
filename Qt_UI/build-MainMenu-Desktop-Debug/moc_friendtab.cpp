/****************************************************************************
** Meta object code from reading C++ file 'friendtab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainMenu/friendtab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'friendtab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FriendTab_t {
    QByteArrayData data[9];
    char stringdata0[205];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FriendTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FriendTab_t qt_meta_stringdata_FriendTab = {
    {
QT_MOC_LITERAL(0, 0, 9), // "FriendTab"
QT_MOC_LITERAL(1, 10, 27), // "on_removePushButton_pressed"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 27), // "on_cancelPushButton_pressed"
QT_MOC_LITERAL(4, 67, 27), // "on_acceptPushButton_pressed"
QT_MOC_LITERAL(5, 95, 25), // "on_denyPushButton_pressed"
QT_MOC_LITERAL(6, 121, 24), // "on_addPushButton_pressed"
QT_MOC_LITERAL(7, 146, 30), // "on_inputLineEdit_returnPressed"
QT_MOC_LITERAL(8, 177, 27) // "on_returnPushButton_pressed"

    },
    "FriendTab\0on_removePushButton_pressed\0"
    "\0on_cancelPushButton_pressed\0"
    "on_acceptPushButton_pressed\0"
    "on_denyPushButton_pressed\0"
    "on_addPushButton_pressed\0"
    "on_inputLineEdit_returnPressed\0"
    "on_returnPushButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FriendTab[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FriendTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FriendTab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_removePushButton_pressed(); break;
        case 1: _t->on_cancelPushButton_pressed(); break;
        case 2: _t->on_acceptPushButton_pressed(); break;
        case 3: _t->on_denyPushButton_pressed(); break;
        case 4: _t->on_addPushButton_pressed(); break;
        case 5: _t->on_inputLineEdit_returnPressed(); break;
        case 6: _t->on_returnPushButton_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FriendTab::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_FriendTab.data,
    qt_meta_data_FriendTab,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FriendTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FriendTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FriendTab.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int FriendTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
