/****************************************************************************
** Meta object code from reading C++ file 'pin_dll.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../bankautomat/pin_DLL/pin_DLL/pin_dll.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pin_dll.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pin_DLL_t {
    QByteArrayData data[18];
    char stringdata0[251];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pin_DLL_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pin_DLL_t qt_meta_stringdata_Pin_DLL = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Pin_DLL"
QT_MOC_LITERAL(1, 8, 12), // "sendPinToExe"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 15), // "sendSymbolToExe"
QT_MOC_LITERAL(4, 38, 13), // "recvB0clicked"
QT_MOC_LITERAL(5, 52, 13), // "recvB1clicked"
QT_MOC_LITERAL(6, 66, 13), // "recvB2clicked"
QT_MOC_LITERAL(7, 80, 13), // "recvB3clicked"
QT_MOC_LITERAL(8, 94, 13), // "recvB4clicked"
QT_MOC_LITERAL(9, 108, 13), // "recvB5clicked"
QT_MOC_LITERAL(10, 122, 13), // "recvB6clicked"
QT_MOC_LITERAL(11, 136, 13), // "recvB7clicked"
QT_MOC_LITERAL(12, 150, 13), // "recvB8clicked"
QT_MOC_LITERAL(13, 164, 13), // "recvB9clicked"
QT_MOC_LITERAL(14, 178, 16), // "recvClearclicked"
QT_MOC_LITERAL(15, 195, 20), // "recvBackspaceclicked"
QT_MOC_LITERAL(16, 216, 15), // "recvPinToEngine"
QT_MOC_LITERAL(17, 232, 18) // "recvSymbolToEngine"

    },
    "Pin_DLL\0sendPinToExe\0\0sendSymbolToExe\0"
    "recvB0clicked\0recvB1clicked\0recvB2clicked\0"
    "recvB3clicked\0recvB4clicked\0recvB5clicked\0"
    "recvB6clicked\0recvB7clicked\0recvB8clicked\0"
    "recvB9clicked\0recvClearclicked\0"
    "recvBackspaceclicked\0recvPinToEngine\0"
    "recvSymbolToEngine"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pin_DLL[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       3,    1,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  100,    2, 0x0a /* Public */,
       5,    0,  101,    2, 0x0a /* Public */,
       6,    0,  102,    2, 0x0a /* Public */,
       7,    0,  103,    2, 0x0a /* Public */,
       8,    0,  104,    2, 0x0a /* Public */,
       9,    0,  105,    2, 0x0a /* Public */,
      10,    0,  106,    2, 0x0a /* Public */,
      11,    0,  107,    2, 0x0a /* Public */,
      12,    0,  108,    2, 0x0a /* Public */,
      13,    0,  109,    2, 0x0a /* Public */,
      14,    0,  110,    2, 0x0a /* Public */,
      15,    0,  111,    2, 0x0a /* Public */,
      16,    1,  112,    2, 0x08 /* Private */,
      17,    1,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

       0        // eod
};

void Pin_DLL::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pin_DLL *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendPinToExe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendSymbolToExe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->recvB0clicked(); break;
        case 3: _t->recvB1clicked(); break;
        case 4: _t->recvB2clicked(); break;
        case 5: _t->recvB3clicked(); break;
        case 6: _t->recvB4clicked(); break;
        case 7: _t->recvB5clicked(); break;
        case 8: _t->recvB6clicked(); break;
        case 9: _t->recvB7clicked(); break;
        case 10: _t->recvB8clicked(); break;
        case 11: _t->recvB9clicked(); break;
        case 12: _t->recvClearclicked(); break;
        case 13: _t->recvBackspaceclicked(); break;
        case 14: _t->recvPinToEngine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->recvSymbolToEngine((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pin_DLL::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pin_DLL::sendPinToExe)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pin_DLL::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pin_DLL::sendSymbolToExe)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Pin_DLL::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Pin_DLL.data,
    qt_meta_data_Pin_DLL,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Pin_DLL::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pin_DLL::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pin_DLL.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Pin_DLL::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Pin_DLL::sendPinToExe(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Pin_DLL::sendSymbolToExe(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
