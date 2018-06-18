/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../HandProject/mainwindow.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[402];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 14),
QT_MOC_LITERAL(2, 26, 0),
QT_MOC_LITERAL(3, 27, 3),
QT_MOC_LITERAL(4, 31, 18),
QT_MOC_LITERAL(5, 50, 17),
QT_MOC_LITERAL(6, 68, 13),
QT_MOC_LITERAL(7, 82, 13),
QT_MOC_LITERAL(8, 96, 15),
QT_MOC_LITERAL(9, 112, 3),
QT_MOC_LITERAL(10, 116, 3),
QT_MOC_LITERAL(11, 120, 27),
QT_MOC_LITERAL(12, 148, 4),
QT_MOC_LITERAL(13, 153, 25),
QT_MOC_LITERAL(14, 179, 28),
QT_MOC_LITERAL(15, 208, 27),
QT_MOC_LITERAL(16, 236, 29),
QT_MOC_LITERAL(17, 266, 29),
QT_MOC_LITERAL(18, 296, 24),
QT_MOC_LITERAL(19, 321, 28),
QT_MOC_LITERAL(20, 350, 28),
QT_MOC_LITERAL(21, 379, 22)
    },
    "MainWindow\0updatePlayerUI\0\0img\0"
    "updateBackgroundUI\0updateHistogramUI\0"
    "updateMouseUI\0updateArrowUI\0updatePercentUI\0"
    "per\0fps\0on_show_per_cb_stateChanged\0"
    "arg1\0on_sub_bg_cb_stateChanged\0"
    "on_equal_his_cb_stateChanged\0"
    "on_draw_his_cb_stateChanged\0"
    "on_ctrl_mouse_cb_stateChanged\0"
    "on_ctrl_arrow_cb_stateChanged\0"
    "on_change_bg_btn_clicked\0"
    "on_start_program_btn_clicked\0"
    "on_start_process_btn_clicked\0"
    "on_browser_btn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x08 /* Private */,
       4,    1,   97,    2, 0x08 /* Private */,
       5,    1,  100,    2, 0x08 /* Private */,
       6,    1,  103,    2, 0x08 /* Private */,
       7,    1,  106,    2, 0x08 /* Private */,
       8,    2,  109,    2, 0x08 /* Private */,
      11,    1,  114,    2, 0x08 /* Private */,
      13,    1,  117,    2, 0x08 /* Private */,
      14,    1,  120,    2, 0x08 /* Private */,
      15,    1,  123,    2, 0x08 /* Private */,
      16,    1,  126,    2, 0x08 /* Private */,
      17,    1,  129,    2, 0x08 /* Private */,
      18,    0,  132,    2, 0x08 /* Private */,
      19,    0,  133,    2, 0x08 /* Private */,
      20,    0,  134,    2, 0x08 /* Private */,
      21,    0,  135,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    9,   10,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updatePlayerUI((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 1: _t->updateBackgroundUI((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 2: _t->updateHistogramUI((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 3: _t->updateMouseUI((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 4: _t->updateArrowUI((*reinterpret_cast< QImage(*)>(_a[1]))); break;
        case 5: _t->updatePercentUI((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 6: _t->on_show_per_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_sub_bg_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_equal_his_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_draw_his_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_ctrl_mouse_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_ctrl_arrow_cb_stateChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->on_change_bg_btn_clicked(); break;
        case 13: _t->on_start_program_btn_clicked(); break;
        case 14: _t->on_start_process_btn_clicked(); break;
        case 15: _t->on_browser_btn_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
