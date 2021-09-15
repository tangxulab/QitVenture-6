/****************************************************************************
** Meta object code from reading C++ file 'historydatatodisk.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../historydatatodisk.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'historydatatodisk.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HistoryDataToDisk_t {
    QByteArrayData data[9];
    char stringdata0[102];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistoryDataToDisk_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistoryDataToDisk_t qt_meta_stringdata_HistoryDataToDisk = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HistoryDataToDisk"
QT_MOC_LITERAL(1, 18, 17), // "moveQStandardItem"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 14), // "QStandardItem*"
QT_MOC_LITERAL(4, 52, 11), // "itemProject"
QT_MOC_LITERAL(5, 64, 15), // "HistorySortData"
QT_MOC_LITERAL(6, 80, 4), // "sort"
QT_MOC_LITERAL(7, 85, 10), // "diskMethod"
QT_MOC_LITERAL(8, 96, 5) // "value"

    },
    "HistoryDataToDisk\0moveQStandardItem\0"
    "\0QStandardItem*\0itemProject\0HistorySortData\0"
    "sort\0diskMethod\0value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistoryDataToDisk[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 5,    4,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void HistoryDataToDisk::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HistoryDataToDisk *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moveQStandardItem((*reinterpret_cast< QStandardItem*(*)>(_a[1])),(*reinterpret_cast< HistorySortData(*)>(_a[2]))); break;
        case 1: _t->diskMethod((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HistoryDataToDisk::*)(QStandardItem * , HistorySortData );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&HistoryDataToDisk::moveQStandardItem)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HistoryDataToDisk::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HistoryDataToDisk.data,
    qt_meta_data_HistoryDataToDisk,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HistoryDataToDisk::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistoryDataToDisk::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HistoryDataToDisk.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HistoryDataToDisk::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void HistoryDataToDisk::moveQStandardItem(QStandardItem * _t1, HistorySortData _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
