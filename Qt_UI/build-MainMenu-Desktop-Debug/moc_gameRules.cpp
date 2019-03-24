/****************************************************************************
** Meta object code from reading C++ file 'gameRules.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MainMenu/gameRules.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gameRules.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_GameRules_t {
    QByteArrayData data[11];
    char stringdata0[289];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_GameRules_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_GameRules_t qt_meta_stringdata_GameRules = {
    {
QT_MOC_LITERAL(0, 0, 9), // "GameRules"
QT_MOC_LITERAL(1, 10, 28), // "on_classicPushButton_pressed"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 25), // "on_darkPushButton_pressed"
QT_MOC_LITERAL(4, 66, 26), // "on_hordePushButton_pressed"
QT_MOC_LITERAL(5, 93, 26), // "on_alicePushButton_pressed"
QT_MOC_LITERAL(6, 120, 36), // "on_realTimeClassicPushButton_..."
QT_MOC_LITERAL(7, 157, 33), // "on_realTimeDarkPushButton_pre..."
QT_MOC_LITERAL(8, 191, 34), // "on_realTimeHordePushButton_pr..."
QT_MOC_LITERAL(9, 226, 34), // "on_realTimeAlicePushButton_pr..."
QT_MOC_LITERAL(10, 261, 27) // "on_returnPushButton_pressed"

    },
    "GameRules\0on_classicPushButton_pressed\0"
    "\0on_darkPushButton_pressed\0"
    "on_hordePushButton_pressed\0"
    "on_alicePushButton_pressed\0"
    "on_realTimeClassicPushButton_pressed\0"
    "on_realTimeDarkPushButton_pressed\0"
    "on_realTimeHordePushButton_pressed\0"
    "on_realTimeAlicePushButton_pressed\0"
    "on_returnPushButton_pressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GameRules[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void GameRules::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameRules *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_classicPushButton_pressed(); break;
        case 1: _t->on_darkPushButton_pressed(); break;
        case 2: _t->on_hordePushButton_pressed(); break;
        case 3: _t->on_alicePushButton_pressed(); break;
        case 4: _t->on_realTimeClassicPushButton_pressed(); break;
        case 5: _t->on_realTimeDarkPushButton_pressed(); break;
        case 6: _t->on_realTimeHordePushButton_pressed(); break;
        case 7: _t->on_realTimeAlicePushButton_pressed(); break;
        case 8: _t->on_returnPushButton_pressed(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject GameRules::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_GameRules.data,
    qt_meta_data_GameRules,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *GameRules::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GameRules::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GameRules.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int GameRules::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
