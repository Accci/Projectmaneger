/****************************************************************************
** Meta object code from reading C++ file 'custitlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../custitlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'custitlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CustitleBar_t {
    QByteArrayData data[8];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CustitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CustitleBar_t qt_meta_stringdata_CustitleBar = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CustitleBar"
QT_MOC_LITERAL(1, 12, 13), // "minBtnClicked"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 13), // "maxBtnClicked"
QT_MOC_LITERAL(4, 41, 12), // "closeClicked"
QT_MOC_LITERAL(5, 54, 15), // "onMinBtnClicked"
QT_MOC_LITERAL(6, 70, 15), // "onMaxBtnClicked"
QT_MOC_LITERAL(7, 86, 14) // "onCloseClicked"

    },
    "CustitleBar\0minBtnClicked\0\0maxBtnClicked\0"
    "closeClicked\0onMinBtnClicked\0"
    "onMaxBtnClicked\0onCloseClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CustitleBar[] = {

 // content:
       8,       // revision
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
       5,    0,   47,    2, 0x0a /* Public */,
       6,    0,   48,    2, 0x0a /* Public */,
       7,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CustitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CustitleBar *_t = static_cast<CustitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->minBtnClicked(); break;
        case 1: _t->maxBtnClicked(); break;
        case 2: _t->closeClicked(); break;
        case 3: _t->onMinBtnClicked(); break;
        case 4: _t->onMaxBtnClicked(); break;
        case 5: _t->onCloseClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CustitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CustitleBar::minBtnClicked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CustitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CustitleBar::maxBtnClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CustitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CustitleBar::closeClicked)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject CustitleBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_CustitleBar.data,
    qt_meta_data_CustitleBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CustitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CustitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CustitleBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CustitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void CustitleBar::minBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CustitleBar::maxBtnClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void CustitleBar::closeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
