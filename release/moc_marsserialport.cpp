/****************************************************************************
** Meta object code from reading C++ file 'marsserialport.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../marsserialport.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marsserialport.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MarsSerialPort_t {
    QByteArrayData data[21];
    char stringdata0[216];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarsSerialPort_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarsSerialPort_t qt_meta_stringdata_MarsSerialPort = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MarsSerialPort"
QT_MOC_LITERAL(1, 15, 12), // "disconnected"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 9), // "connected"
QT_MOC_LITERAL(4, 39, 6), // "errors"
QT_MOC_LITERAL(5, 46, 9), // "MarsError"
QT_MOC_LITERAL(6, 56, 5), // "error"
QT_MOC_LITERAL(7, 62, 17), // "dataFrameReceived"
QT_MOC_LITERAL(8, 80, 7), // "connect"
QT_MOC_LITERAL(9, 88, 18), // "SerialPortSettings"
QT_MOC_LITERAL(10, 107, 4), // "stts"
QT_MOC_LITERAL(11, 112, 10), // "disconnect"
QT_MOC_LITERAL(12, 123, 12), // "sendByteData"
QT_MOC_LITERAL(13, 136, 4), // "data"
QT_MOC_LITERAL(14, 141, 12), // "sendFileData"
QT_MOC_LITERAL(15, 154, 6), // "QFile&"
QT_MOC_LITERAL(16, 161, 4), // "file"
QT_MOC_LITERAL(17, 166, 14), // "updateSettings"
QT_MOC_LITERAL(18, 181, 8), // "settings"
QT_MOC_LITERAL(19, 190, 13), // "readDataFrame"
QT_MOC_LITERAL(20, 204, 11) // "QByteArray&"

    },
    "MarsSerialPort\0disconnected\0\0connected\0"
    "errors\0MarsError\0error\0dataFrameReceived\0"
    "connect\0SerialPortSettings\0stts\0"
    "disconnect\0sendByteData\0data\0sendFileData\0"
    "QFile&\0file\0updateSettings\0settings\0"
    "readDataFrame\0QByteArray&"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarsSerialPort[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    1,   71,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   75,    2, 0x0a /* Public */,
       8,    1,   76,    2, 0x0a /* Public */,
      11,    0,   79,    2, 0x0a /* Public */,
      12,    1,   80,    2, 0x0a /* Public */,
      14,    1,   83,    2, 0x0a /* Public */,
      17,    1,   86,    2, 0x0a /* Public */,
      19,    1,   89,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 9,   18,
    QMetaType::Void, 0x80000000 | 20,   13,

       0        // eod
};

void MarsSerialPort::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MarsSerialPort *_t = static_cast<MarsSerialPort *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->disconnected(); break;
        case 1: _t->connected(); break;
        case 2: _t->errors((*reinterpret_cast< MarsError(*)>(_a[1]))); break;
        case 3: _t->dataFrameReceived(); break;
        case 4: _t->connect(); break;
        case 5: _t->connect((*reinterpret_cast< SerialPortSettings(*)>(_a[1]))); break;
        case 6: _t->disconnect(); break;
        case 7: _t->sendByteData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->sendFileData((*reinterpret_cast< QFile(*)>(_a[1]))); break;
        case 9: _t->updateSettings((*reinterpret_cast< SerialPortSettings(*)>(_a[1]))); break;
        case 10: _t->readDataFrame((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MarsSerialPort::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsSerialPort::disconnected)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MarsSerialPort::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsSerialPort::connected)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MarsSerialPort::*_t)(MarsError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsSerialPort::errors)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MarsSerialPort::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsSerialPort::dataFrameReceived)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject MarsSerialPort::staticMetaObject = {
    { &QSerialPort::staticMetaObject, qt_meta_stringdata_MarsSerialPort.data,
      qt_meta_data_MarsSerialPort,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MarsSerialPort::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarsSerialPort::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MarsSerialPort.stringdata0))
        return static_cast<void*>(const_cast< MarsSerialPort*>(this));
    return QSerialPort::qt_metacast(_clname);
}

int MarsSerialPort::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSerialPort::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MarsSerialPort::disconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MarsSerialPort::connected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void MarsSerialPort::errors(MarsError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MarsSerialPort::dataFrameReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
