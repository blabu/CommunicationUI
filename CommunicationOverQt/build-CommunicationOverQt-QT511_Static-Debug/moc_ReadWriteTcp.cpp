/****************************************************************************
** Meta object code from reading C++ file 'ReadWriteTcp.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../ReadWriteTcp.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ReadWriteTcp.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ReadWriteTcp_t {
    QByteArrayData data[11];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ReadWriteTcp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ReadWriteTcp_t qt_meta_stringdata_ReadWriteTcp = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ReadWriteTcp"
QT_MOC_LITERAL(1, 13, 11), // "readHandler"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 22), // "closeConnectionHandler"
QT_MOC_LITERAL(4, 49, 5), // "write"
QT_MOC_LITERAL(5, 55, 1), // "m"
QT_MOC_LITERAL(6, 57, 4), // "read"
QT_MOC_LITERAL(7, 62, 31), // "std::function<void(QByteArray)>"
QT_MOC_LITERAL(8, 94, 7), // "handler"
QT_MOC_LITERAL(9, 102, 23), // "registerDisconnectEvent"
QT_MOC_LITERAL(10, 126, 25) // "std::function<void(void)>"

    },
    "ReadWriteTcp\0readHandler\0\0"
    "closeConnectionHandler\0write\0m\0read\0"
    "std::function<void(QByteArray)>\0handler\0"
    "registerDisconnectEvent\0"
    "std::function<void(void)>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ReadWriteTcp[] = {

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
       1,    0,   39,    2, 0x08 /* Private */,
       3,    0,   40,    2, 0x08 /* Private */,
       4,    1,   41,    2, 0x0a /* Public */,
       6,    1,   44,    2, 0x0a /* Public */,
       9,    1,   47,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 10,    8,

       0        // eod
};

void ReadWriteTcp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ReadWriteTcp *_t = static_cast<ReadWriteTcp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->readHandler(); break;
        case 1: _t->closeConnectionHandler(); break;
        case 2: _t->write((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 3: _t->read((*reinterpret_cast< std::function<void(QByteArray)>(*)>(_a[1]))); break;
        case 4: _t->registerDisconnectEvent((*reinterpret_cast< std::function<void(void)>(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ReadWriteTcp::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ReadWriteTcp.data,
      qt_meta_data_ReadWriteTcp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ReadWriteTcp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ReadWriteTcp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ReadWriteTcp.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "middlewareInterface"))
        return static_cast< middlewareInterface*>(this);
    return QObject::qt_metacast(_clname);
}

int ReadWriteTcp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
