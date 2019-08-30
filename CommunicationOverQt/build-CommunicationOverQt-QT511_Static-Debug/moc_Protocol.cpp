/****************************************************************************
** Meta object code from reading C++ file 'Protocol.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Protocol.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Protocol.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ping_t {
    QByteArrayData data[3];
    char stringdata0[20];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ping_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ping_t qt_meta_stringdata_ping = {
    {
QT_MOC_LITERAL(0, 0, 4), // "ping"
QT_MOC_LITERAL(1, 5, 13), // "remoteConnect"
QT_MOC_LITERAL(2, 19, 0) // ""

    },
    "ping\0remoteConnect\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ping[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void ping::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ping *_t = static_cast<ping *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->remoteConnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ping::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ping::remoteConnect)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ping::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ping.data,
      qt_meta_data_ping,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ping::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ping::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ping.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ping::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void ping::remoteConnect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Protocol_t {
    QByteArrayData data[12];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Protocol_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Protocol_t qt_meta_stringdata_Protocol = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Protocol"
QT_MOC_LITERAL(1, 9, 5), // "regOK"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 6), // "initOK"
QT_MOC_LITERAL(4, 23, 11), // "connectToOK"
QT_MOC_LITERAL(5, 35, 5), // "write"
QT_MOC_LITERAL(6, 41, 7), // "message"
QT_MOC_LITERAL(7, 49, 4), // "read"
QT_MOC_LITERAL(8, 54, 38), // "std::function<const void( QBy..."
QT_MOC_LITERAL(9, 93, 7), // "handler"
QT_MOC_LITERAL(10, 101, 23), // "registerDisconnectEvent"
QT_MOC_LITERAL(11, 125, 25) // "std::function<void(void)>"

    },
    "Protocol\0regOK\0\0initOK\0connectToOK\0"
    "write\0message\0read\0"
    "std::function<const void( QByteArray)>\0"
    "handler\0registerDisconnectEvent\0"
    "std::function<void(void)>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Protocol[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   47,    2, 0x0a /* Public */,
       7,    1,   50,    2, 0x0a /* Public */,
      10,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,    6,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11,    9,

       0        // eod
};

void Protocol::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Protocol *_t = static_cast<Protocol *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->regOK(); break;
        case 1: _t->initOK(); break;
        case 2: _t->connectToOK(); break;
        case 3: _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->read((*reinterpret_cast< std::function<const void( QByteArray)>(*)>(_a[1]))); break;
        case 5: _t->registerDisconnectEvent((*reinterpret_cast< std::function<void(void)>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::regOK)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::initOK)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Protocol::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Protocol::connectToOK)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Protocol::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Protocol.data,
      qt_meta_data_Protocol,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Protocol::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Protocol::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Protocol.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "middlewareInterface"))
        return static_cast< middlewareInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int Protocol::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Protocol::regOK()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Protocol::initOK()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Protocol::connectToOK()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
