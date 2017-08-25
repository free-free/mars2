/****************************************************************************
** Meta object code from reading C++ file 'marsplot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../marsplot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'marsplot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MarsPlot_t {
    QByteArrayData data[22];
    char stringdata0[228];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MarsPlot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MarsPlot_t qt_meta_stringdata_MarsPlot = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MarsPlot"
QT_MOC_LITERAL(1, 9, 7), // "focusIn"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 9), // "MarsPlot*"
QT_MOC_LITERAL(4, 28, 10), // "focusInObj"
QT_MOC_LITERAL(5, 39, 11), // "mouseMoveOn"
QT_MOC_LITERAL(6, 51, 3), // "obj"
QT_MOC_LITERAL(7, 55, 1), // "x"
QT_MOC_LITERAL(8, 57, 1), // "y"
QT_MOC_LITERAL(9, 59, 21), // "changeGraphLegendName"
QT_MOC_LITERAL(10, 81, 10), // "QCPLegend*"
QT_MOC_LITERAL(11, 92, 6), // "legend"
QT_MOC_LITERAL(12, 99, 22), // "QCPAbstractLegendItem*"
QT_MOC_LITERAL(13, 122, 4), // "item"
QT_MOC_LITERAL(14, 127, 19), // "changeAxisLabelName"
QT_MOC_LITERAL(15, 147, 8), // "QCPAxis*"
QT_MOC_LITERAL(16, 156, 4), // "axis"
QT_MOC_LITERAL(17, 161, 23), // "QCPAxis::SelectablePart"
QT_MOC_LITERAL(18, 185, 11), // "changeTitle"
QT_MOC_LITERAL(19, 197, 12), // "QMouseEvent*"
QT_MOC_LITERAL(20, 210, 5), // "event"
QT_MOC_LITERAL(21, 216, 11) // "onMouseMove"

    },
    "MarsPlot\0focusIn\0\0MarsPlot*\0focusInObj\0"
    "mouseMoveOn\0obj\0x\0y\0changeGraphLegendName\0"
    "QCPLegend*\0legend\0QCPAbstractLegendItem*\0"
    "item\0changeAxisLabelName\0QCPAxis*\0"
    "axis\0QCPAxis::SelectablePart\0changeTitle\0"
    "QMouseEvent*\0event\0onMouseMove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MarsPlot[] = {

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
       5,    3,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    2,   54,    2, 0x09 /* Protected */,
      14,    2,   59,    2, 0x09 /* Protected */,
      18,    1,   64,    2, 0x09 /* Protected */,
      21,    1,   67,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Double, QMetaType::Double,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, 0x80000000 | 15, 0x80000000 | 17,   16,    2,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void MarsPlot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MarsPlot *_t = static_cast<MarsPlot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->focusIn((*reinterpret_cast< MarsPlot*(*)>(_a[1]))); break;
        case 1: _t->mouseMoveOn((*reinterpret_cast< MarsPlot*(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3]))); break;
        case 2: _t->changeGraphLegendName((*reinterpret_cast< QCPLegend*(*)>(_a[1])),(*reinterpret_cast< QCPAbstractLegendItem*(*)>(_a[2]))); break;
        case 3: _t->changeAxisLabelName((*reinterpret_cast< QCPAxis*(*)>(_a[1])),(*reinterpret_cast< QCPAxis::SelectablePart(*)>(_a[2]))); break;
        case 4: _t->changeTitle((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 5: _t->onMouseMove((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MarsPlot* >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< MarsPlot* >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAbstractLegendItem* >(); break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPLegend* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis* >(); break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QCPAxis::SelectablePart >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MarsPlot::*_t)(MarsPlot * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsPlot::focusIn)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MarsPlot::*_t)(MarsPlot * , double , double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MarsPlot::mouseMoveOn)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MarsPlot::staticMetaObject = {
    { &QCustomPlot::staticMetaObject, qt_meta_stringdata_MarsPlot.data,
      qt_meta_data_MarsPlot,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MarsPlot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MarsPlot::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MarsPlot.stringdata0))
        return static_cast<void*>(const_cast< MarsPlot*>(this));
    return QCustomPlot::qt_metacast(_clname);
}

int MarsPlot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCustomPlot::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void MarsPlot::focusIn(MarsPlot * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MarsPlot::mouseMoveOn(MarsPlot * _t1, double _t2, double _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
