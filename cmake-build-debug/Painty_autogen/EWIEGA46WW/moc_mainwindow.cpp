/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[21];
    char stringdata0[426];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 27), // "on_actionAbout_Me_triggered"
QT_MOC_LITERAL(4, 64, 21), // "on_colorWhite_clicked"
QT_MOC_LITERAL(5, 86, 21), // "on_colorBlack_clicked"
QT_MOC_LITERAL(6, 108, 19), // "on_colorRed_clicked"
QT_MOC_LITERAL(7, 128, 21), // "on_colorGreen_clicked"
QT_MOC_LITERAL(8, 150, 22), // "on_colorPurple_clicked"
QT_MOC_LITERAL(9, 173, 20), // "on_colorBlue_clicked"
QT_MOC_LITERAL(10, 194, 21), // "on_toolCircle_clicked"
QT_MOC_LITERAL(11, 216, 18), // "on_toolPen_clicked"
QT_MOC_LITERAL(12, 235, 24), // "on_fontSize_valueChanged"
QT_MOC_LITERAL(13, 260, 4), // "arg1"
QT_MOC_LITERAL(14, 265, 21), // "on_toolSquare_clicked"
QT_MOC_LITERAL(15, 287, 19), // "on_toolLine_clicked"
QT_MOC_LITERAL(16, 307, 21), // "on_toolEraser_clicked"
QT_MOC_LITERAL(17, 329, 20), // "on_toolSpray_clicked"
QT_MOC_LITERAL(18, 350, 19), // "on_toolText_clicked"
QT_MOC_LITERAL(19, 370, 22), // "on_actionNew_triggered"
QT_MOC_LITERAL(20, 393, 32) // "on_actionSave_as_Image_triggered"

    },
    "MainWindow\0on_actionQuit_triggered\0\0"
    "on_actionAbout_Me_triggered\0"
    "on_colorWhite_clicked\0on_colorBlack_clicked\0"
    "on_colorRed_clicked\0on_colorGreen_clicked\0"
    "on_colorPurple_clicked\0on_colorBlue_clicked\0"
    "on_toolCircle_clicked\0on_toolPen_clicked\0"
    "on_fontSize_valueChanged\0arg1\0"
    "on_toolSquare_clicked\0on_toolLine_clicked\0"
    "on_toolEraser_clicked\0on_toolSpray_clicked\0"
    "on_toolText_clicked\0on_actionNew_triggered\0"
    "on_actionSave_as_Image_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x08 /* Private */,
       3,    0,  105,    2, 0x08 /* Private */,
       4,    0,  106,    2, 0x08 /* Private */,
       5,    0,  107,    2, 0x08 /* Private */,
       6,    0,  108,    2, 0x08 /* Private */,
       7,    0,  109,    2, 0x08 /* Private */,
       8,    0,  110,    2, 0x08 /* Private */,
       9,    0,  111,    2, 0x08 /* Private */,
      10,    0,  112,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    1,  114,    2, 0x08 /* Private */,
      14,    0,  117,    2, 0x08 /* Private */,
      15,    0,  118,    2, 0x08 /* Private */,
      16,    0,  119,    2, 0x08 /* Private */,
      17,    0,  120,    2, 0x08 /* Private */,
      18,    0,  121,    2, 0x08 /* Private */,
      19,    0,  122,    2, 0x08 /* Private */,
      20,    0,  123,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_actionQuit_triggered(); break;
        case 1: _t->on_actionAbout_Me_triggered(); break;
        case 2: _t->on_colorWhite_clicked(); break;
        case 3: _t->on_colorBlack_clicked(); break;
        case 4: _t->on_colorRed_clicked(); break;
        case 5: _t->on_colorGreen_clicked(); break;
        case 6: _t->on_colorPurple_clicked(); break;
        case 7: _t->on_colorBlue_clicked(); break;
        case 8: _t->on_toolCircle_clicked(); break;
        case 9: _t->on_toolPen_clicked(); break;
        case 10: _t->on_fontSize_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_toolSquare_clicked(); break;
        case 12: _t->on_toolLine_clicked(); break;
        case 13: _t->on_toolEraser_clicked(); break;
        case 14: _t->on_toolSpray_clicked(); break;
        case 15: _t->on_toolText_clicked(); break;
        case 16: _t->on_actionNew_triggered(); break;
        case 17: _t->on_actionSave_as_Image_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
