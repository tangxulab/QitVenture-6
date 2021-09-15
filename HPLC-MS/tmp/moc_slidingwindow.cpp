/****************************************************************************
** Meta object code from reading C++ file 'slidingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../slidingwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'slidingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SlidingWindow_t {
    QByteArrayData data[15];
    char stringdata0[183];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SlidingWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SlidingWindow_t qt_meta_stringdata_SlidingWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SlidingWindow"
QT_MOC_LITERAL(1, 14, 14), // "slotClickedBtn"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "slotSplitterMoved"
QT_MOC_LITERAL(4, 48, 3), // "pos"
QT_MOC_LITERAL(5, 52, 5), // "index"
QT_MOC_LITERAL(6, 58, 7), // "getData"
QT_MOC_LITERAL(7, 66, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(8, 83, 4), // "item"
QT_MOC_LITERAL(9, 88, 12), // "slotBtn_wave"
QT_MOC_LITERAL(10, 101, 15), // "treeItemChanged"
QT_MOC_LITERAL(11, 117, 14), // "QStandardItem*"
QT_MOC_LITERAL(12, 132, 12), // "slotTreeMenu"
QT_MOC_LITERAL(13, 145, 25), // "OnlineTreeViewDoubleClick"
QT_MOC_LITERAL(14, 171, 11) // "QModelIndex"

    },
    "SlidingWindow\0slotClickedBtn\0\0"
    "slotSplitterMoved\0pos\0index\0getData\0"
    "QListWidgetItem*\0item\0slotBtn_wave\0"
    "treeItemChanged\0QStandardItem*\0"
    "slotTreeMenu\0OnlineTreeViewDoubleClick\0"
    "QModelIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SlidingWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    2,   50,    2, 0x08 /* Private */,
       6,    1,   55,    2, 0x08 /* Private */,
       9,    0,   58,    2, 0x08 /* Private */,
      10,    1,   59,    2, 0x08 /* Private */,
      12,    1,   62,    2, 0x08 /* Private */,
      13,    1,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,    8,
    QMetaType::Void, QMetaType::QPoint,    4,
    QMetaType::Void, 0x80000000 | 14,    5,

       0        // eod
};

void SlidingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SlidingWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotClickedBtn(); break;
        case 1: _t->slotSplitterMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->getData((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 3: _t->slotBtn_wave(); break;
        case 4: _t->treeItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 5: _t->slotTreeMenu((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 6: _t->OnlineTreeViewDoubleClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SlidingWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SlidingWindow.data,
    qt_meta_data_SlidingWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SlidingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SlidingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SlidingWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SlidingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
