/****************************************************************************
** Meta object code from reading C++ file 'player.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HandProject/player.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[12];
    char stringdata[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 14),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 5),
QT_MOC_LITERAL(4, 29, 19),
QT_MOC_LITERAL(5, 49, 18),
QT_MOC_LITERAL(6, 68, 14),
QT_MOC_LITERAL(7, 83, 14),
QT_MOC_LITERAL(8, 98, 4),
QT_MOC_LITERAL(9, 103, 16),
QT_MOC_LITERAL(10, 120, 3),
QT_MOC_LITERAL(11, 124, 3)
    },
    "Player\0processedImage\0\0image\0"
    "processedBackground\0processedHistogram\0"
    "processedMouse\0processedArrow\0imge\0"
    "processedPercent\0per\0fps"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       4,    1,   47,    2, 0x06 /* Public */,
       5,    1,   50,    2, 0x06 /* Public */,
       6,    1,   53,    2, 0x06 /* Public */,
       7,    1,   56,    2, 0x06 /* Public */,
       9,    2,   59,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,   10,   11,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Player *_t = static_cast<Player *>(_o);
        switch (_id) {
        case 0: _t->processedImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->processedBackground((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->processedHistogram((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 3: _t->processedMouse((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 4: _t->processedArrow((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 5: _t->processedPercent((*reinterpret_cast< const int(*)>(_a[1])),(*reinterpret_cast< const double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Player::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::processedImage)) {
                *result = 0;
            }
        }
        {
            typedef void (Player::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::processedBackground)) {
                *result = 1;
            }
        }
        {
            typedef void (Player::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::processedHistogram)) {
                *result = 2;
            }
        }
        {
            typedef void (Player::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::processedMouse)) {
                *result = 3;
            }
        }
        {
            typedef void (Player::*_t)(const QImage & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::processedArrow)) {
                *result = 4;
            }
        }
        {
            typedef void (Player::*_t)(const int & , const double & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Player::processedPercent)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Player::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Player.data,
      qt_meta_data_Player,  qt_static_metacall, 0, 0}
};


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata))
        return static_cast<void*>(const_cast< Player*>(this));
    return QThread::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void Player::processedImage(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Player::processedBackground(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Player::processedHistogram(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Player::processedMouse(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Player::processedArrow(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Player::processedPercent(const int & _t1, const double & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
