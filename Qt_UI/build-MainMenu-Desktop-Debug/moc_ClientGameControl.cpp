/****************************************************************************
** Meta object code from reading C++ file 'ClientGameControl.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Modified_Files/ClientGameControl.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClientGameControl.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ClientGameControl_t {
    QByteArrayData data[16];
    char stringdata0[210];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClientGameControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClientGameControl_t qt_meta_stringdata_ClientGameControl = {
    {
QT_MOC_LITERAL(0, 0, 17), // "ClientGameControl"
QT_MOC_LITERAL(1, 18, 11), // "updatePiece"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 13), // "receiveUpdate"
QT_MOC_LITERAL(4, 45, 15), // "receiveGameMode"
QT_MOC_LITERAL(5, 61, 19), // "receivePlayerColour"
QT_MOC_LITERAL(6, 81, 11), // "receiveTurn"
QT_MOC_LITERAL(7, 93, 14), // "receiveAskMove"
QT_MOC_LITERAL(8, 108, 19), // "receiveAskPromotion"
QT_MOC_LITERAL(9, 128, 8), // "finished"
QT_MOC_LITERAL(10, 137, 10), // "startParty"
QT_MOC_LITERAL(11, 148, 8), // "sendMove"
QT_MOC_LITERAL(12, 157, 11), // "std::string"
QT_MOC_LITERAL(13, 169, 13), // "sendPromotion"
QT_MOC_LITERAL(14, 183, 14), // "setGameOngoing"
QT_MOC_LITERAL(15, 198, 11) // "setRealTime"

    },
    "ClientGameControl\0updatePiece\0\0"
    "receiveUpdate\0receiveGameMode\0"
    "receivePlayerColour\0receiveTurn\0"
    "receiveAskMove\0receiveAskPromotion\0"
    "finished\0startParty\0sendMove\0std::string\0"
    "sendPromotion\0setGameOngoing\0setRealTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClientGameControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   79,    2, 0x06 /* Public */,
       3,    1,   86,    2, 0x06 /* Public */,
       4,    1,   89,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       6,    1,   95,    2, 0x06 /* Public */,
       7,    1,   98,    2, 0x06 /* Public */,
       8,    1,  101,    2, 0x06 /* Public */,
       9,    0,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  105,    2, 0x0a /* Public */,
      11,    1,  106,    2, 0x0a /* Public */,
      13,    1,  109,    2, 0x0a /* Public */,
      14,    1,  112,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QIcon, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, 0x80000000 | 12,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

       0        // eod
};

void ClientGameControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ClientGameControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePiece((*reinterpret_cast< QIcon(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 1: _t->receiveUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->receiveGameMode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->receivePlayerColour((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->receiveTurn((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->receiveAskMove((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->receiveAskPromotion((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->finished(); break;
        case 8: _t->startParty(); break;
        case 9: _t->sendMove((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 10: _t->sendPromotion((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 11: _t->setGameOngoing((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->setRealTime(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ClientGameControl::*)(QIcon , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::updatePiece)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::receiveUpdate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::receiveGameMode)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::receivePlayerColour)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::receiveTurn)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::receiveAskMove)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::receiveAskPromotion)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (ClientGameControl::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ClientGameControl::finished)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ClientGameControl::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ClientGameControl.data,
    qt_meta_data_ClientGameControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ClientGameControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClientGameControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ClientGameControl.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ClientGameControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void ClientGameControl::updatePiece(QIcon _t1, QString _t2, QString _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClientGameControl::receiveUpdate(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ClientGameControl::receiveGameMode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ClientGameControl::receivePlayerColour(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ClientGameControl::receiveTurn(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ClientGameControl::receiveAskMove(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ClientGameControl::receiveAskPromotion(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void ClientGameControl::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
