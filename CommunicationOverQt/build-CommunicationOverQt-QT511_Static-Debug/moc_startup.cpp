/****************************************************************************
** Meta object code from reading C++ file 'startup.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../startup.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'startup.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_StartUp_t {
    QByteArrayData data[10];
    char stringdata0[89];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_StartUp_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_StartUp_t qt_meta_stringdata_StartUp = {
    {
QT_MOC_LITERAL(0, 0, 7), // "StartUp"
QT_MOC_LITERAL(1, 8, 11), // "tryRegister"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 11), // "Credentials"
QT_MOC_LITERAL(4, 33, 3), // "ctx"
QT_MOC_LITERAL(5, 37, 7), // "tryInit"
QT_MOC_LITERAL(6, 45, 16), // "enableMainWindow"
QT_MOC_LITERAL(7, 62, 17), // "disableMainWindow"
QT_MOC_LITERAL(8, 80, 4), // "init"
QT_MOC_LITERAL(9, 85, 3) // "reg"

    },
    "StartUp\0tryRegister\0\0Credentials\0ctx\0"
    "tryInit\0enableMainWindow\0disableMainWindow\0"
    "init\0reg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_StartUp[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   50,    2, 0x0a /* Public */,
       7,    0,   51,    2, 0x0a /* Public */,
       8,    0,   52,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void StartUp::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        StartUp *_t = static_cast<StartUp *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tryRegister((*reinterpret_cast< const Credentials(*)>(_a[1]))); break;
        case 1: _t->tryInit((*reinterpret_cast< const Credentials(*)>(_a[1]))); break;
        case 2: _t->enableMainWindow(); break;
        case 3: _t->disableMainWindow(); break;
        case 4: _t->init(); break;
        case 5: _t->reg(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (StartUp::*)(const Credentials & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartUp::tryRegister)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (StartUp::*)(const Credentials & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&StartUp::tryInit)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject StartUp::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_StartUp.data,
      qt_meta_data_StartUp,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *StartUp::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *StartUp::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_StartUp.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int StartUp::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void StartUp::tryRegister(const Credentials & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void StartUp::tryInit(const Credentials & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
