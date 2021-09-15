/****************************************************************************
** Meta object code from reading C++ file 'permissionwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../permissionwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'permissionwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PermissionWindow_t {
    QByteArrayData data[9];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PermissionWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PermissionWindow_t qt_meta_stringdata_PermissionWindow = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PermissionWindow"
QT_MOC_LITERAL(1, 17, 20), // "saveTreeItemSelected"
QT_MOC_LITERAL(2, 38, 0), // ""
QT_MOC_LITERAL(3, 39, 14), // "getItemChanged"
QT_MOC_LITERAL(4, 54, 14), // "QStandardItem*"
QT_MOC_LITERAL(5, 69, 4), // "item"
QT_MOC_LITERAL(6, 74, 15), // "treeItemChanged"
QT_MOC_LITERAL(7, 90, 25), // "OnlineTreeViewDoubleClick"
QT_MOC_LITERAL(8, 116, 11) // "QModelIndex"

    },
    "PermissionWindow\0saveTreeItemSelected\0"
    "\0getItemChanged\0QStandardItem*\0item\0"
    "treeItemChanged\0OnlineTreeViewDoubleClick\0"
    "QModelIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PermissionWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    1,   35,    2, 0x0a /* Public */,
       6,    1,   38,    2, 0x0a /* Public */,
       7,    1,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 8,    2,

       0        // eod
};

void PermissionWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PermissionWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveTreeItemSelected(); break;
        case 1: _t->getItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 2: _t->treeItemChanged((*reinterpret_cast< QStandardItem*(*)>(_a[1]))); break;
        case 3: _t->OnlineTreeViewDoubleClick((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PermissionWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_PermissionWindow.data,
    qt_meta_data_PermissionWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PermissionWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PermissionWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PermissionWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PermissionWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
