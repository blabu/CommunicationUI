/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[23];
    char stringdata0[256];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 10), // "tryConnect"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 11), // "Credentials"
QT_MOC_LITERAL(4, 35, 3), // "ctx"
QT_MOC_LITERAL(5, 39, 17), // "pressedDisconnect"
QT_MOC_LITERAL(6, 57, 8), // "sendText"
QT_MOC_LITERAL(7, 66, 3), // "msg"
QT_MOC_LITERAL(8, 70, 17), // "sessionKeyChanged"
QT_MOC_LITERAL(9, 88, 13), // "sendEverybody"
QT_MOC_LITERAL(10, 102, 14), // "sendPropSignal"
QT_MOC_LITERAL(11, 117, 15), // "ModemProperties"
QT_MOC_LITERAL(12, 133, 1), // "m"
QT_MOC_LITERAL(13, 135, 20), // "connectButtonPressed"
QT_MOC_LITERAL(14, 156, 8), // "showText"
QT_MOC_LITERAL(15, 165, 12), // "isSendedByMe"
QT_MOC_LITERAL(16, 178, 12), // "sendPropSlot"
QT_MOC_LITERAL(17, 191, 11), // "receiveText"
QT_MOC_LITERAL(18, 203, 7), // "message"
QT_MOC_LITERAL(19, 211, 10), // "disconnect"
QT_MOC_LITERAL(20, 222, 14), // "connectionFine"
QT_MOC_LITERAL(21, 237, 9), // "connectBy"
QT_MOC_LITERAL(22, 247, 8) // "userName"

    },
    "MainWindow\0tryConnect\0\0Credentials\0"
    "ctx\0pressedDisconnect\0sendText\0msg\0"
    "sessionKeyChanged\0sendEverybody\0"
    "sendPropSignal\0ModemProperties\0m\0"
    "connectButtonPressed\0showText\0"
    "isSendedByMe\0sendPropSlot\0receiveText\0"
    "message\0disconnect\0connectionFine\0"
    "connectBy\0userName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       5,    0,   82,    2, 0x06 /* Public */,
       6,    1,   83,    2, 0x06 /* Public */,
       8,    1,   86,    2, 0x06 /* Public */,
       9,    0,   89,    2, 0x06 /* Public */,
      10,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,   93,    2, 0x08 /* Private */,
      14,    2,   94,    2, 0x08 /* Private */,
      16,    0,   99,    2, 0x08 /* Private */,
      17,    1,  100,    2, 0x0a /* Public */,
      19,    0,  103,    2, 0x0a /* Public */,
      20,    0,  104,    2, 0x0a /* Public */,
      21,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   12,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   22,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->tryConnect((*reinterpret_cast< const Credentials(*)>(_a[1]))); break;
        case 1: _t->pressedDisconnect(); break;
        case 2: _t->sendText((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sessionKeyChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->sendEverybody(); break;
        case 5: _t->sendPropSignal((*reinterpret_cast< ModemProperties(*)>(_a[1]))); break;
        case 6: _t->connectButtonPressed(); break;
        case 7: _t->showText((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: _t->sendPropSlot(); break;
        case 9: _t->receiveText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->disconnect(); break;
        case 11: _t->connectionFine(); break;
        case 12: _t->connectBy((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)(const Credentials & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::tryConnect)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::pressedDisconnect)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendText)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sessionKeyChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendEverybody)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MainWindow::*)(ModemProperties );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::sendPropSignal)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void MainWindow::tryConnect(const Credentials & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::pressedDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::sendText(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::sessionKeyChanged(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::sendEverybody()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void MainWindow::sendPropSignal(ModemProperties _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
