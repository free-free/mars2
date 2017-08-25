/****************************************************************************
** Meta object code from reading C++ file 'marscommandline.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../marscommandline.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marscommandline.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MarsCommandLine_t {
    QByteArrayData data[16];
    char stringdata0[178];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarsCommandLine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarsCommandLine_t qt_meta_stringdata_MarsCommandLine = {
    {
QT_MOC_LITERAL(0, 0, 15), // "MarsCommandLine"
QT_MOC_LITERAL(1, 16, 6), // "dataIn"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "errors"
QT_MOC_LITERAL(4, 31, 9), // "MarsError"
QT_MOC_LITERAL(5, 41, 5), // "error"
QT_MOC_LITERAL(6, 47, 17), // "dataImportRequest"
QT_MOC_LITERAL(7, 65, 17), // "dataExportRequest"
QT_MOC_LITERAL(8, 83, 7), // "focusIn"
QT_MOC_LITERAL(9, 91, 16), // "MarsCommandLine*"
QT_MOC_LITERAL(10, 108, 10), // "focusInObj"
QT_MOC_LITERAL(11, 119, 23), // "createCustomContextMenu"
QT_MOC_LITERAL(12, 143, 3), // "pos"
QT_MOC_LITERAL(13, 147, 8), // "clearAll"
QT_MOC_LITERAL(14, 156, 10), // "exportData"
QT_MOC_LITERAL(15, 167, 10) // "importData"

    },
    "MarsCommandLine\0dataIn\0\0errors\0MarsError\0"
    "error\0dataImportRequest\0dataExportRequest\0"
    "focusIn\0MarsCommandLine*\0focusInObj\0"
    "createCustomContextMenu\0pos\0clearAll\0"
    "exportData\0importData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarsCommandLine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,
       7,    0,   64,    2, 0x06 /* Public */,
       8,    1,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,   68,    2, 0x0a /* Public */,
      13,    0,   71,    2, 0x0a /* Public */,
      14,    0,   72,    2, 0x0a /* Public */,
      15,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MarsCommandLine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MarsCommandLine *_t = static_cast<MarsCommandLine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->dataIn(); break;
        case 1: _t->errors((*reinterpret_cast< MarsError(*)>(_a[1]))); break;
        case 2: _t->dataImportRequest(); break;
        case 3: _t->dataExportRequest(); break;
        case 4: _t->focusIn((*reinterpret_cast< MarsCommandLine*(*)>(_a[1]))); break;
        case 5: _t->createCustomContextMenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 6: _t->clearAll(); break;
        case 7: _t->exportData(); break;
        case 8: _t->importData(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MarsCommandLine* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MarsCommandLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsCommandLine::dataIn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MarsCommandLine::*_t)(MarsError );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsCommandLine::errors)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MarsCommandLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsCommandLine::dataImportRequest)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MarsCommandLine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsCommandLine::dataExportRequest)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MarsCommandLine::*_t)(MarsCommandLine * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsCommandLine::focusIn)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MarsCommandLine::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_MarsCommandLine.data,
      qt_meta_data_MarsCommandLine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MarsCommandLine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarsCommandLine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MarsCommandLine.stringdata0))
        return static_cast<void*>(const_cast< MarsCommandLine*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int MarsCommandLine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MarsCommandLine::dataIn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void MarsCommandLine::errors(MarsError _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MarsCommandLine::dataImportRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void MarsCommandLine::dataExportRequest()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void MarsCommandLine::focusIn(MarsCommandLine * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
