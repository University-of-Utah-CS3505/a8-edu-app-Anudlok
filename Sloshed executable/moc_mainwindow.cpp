/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../Sloshed/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[40];
    char stringdata0[362];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 22), // "on_startButton_clicked"
QT_MOC_LITERAL(34, 0), // ""
QT_MOC_LITERAL(35, 24), // "on_restartButton_clicked"
QT_MOC_LITERAL(60, 23), // "on_resumeButton_clicked"
QT_MOC_LITERAL(84, 13), // "addWaterToBar"
QT_MOC_LITERAL(98, 17), // "resetHydrationBar"
QT_MOC_LITERAL(116, 13), // "keyPressEvent"
QT_MOC_LITERAL(130, 10), // "QKeyEvent*"
QT_MOC_LITERAL(141, 1), // "k"
QT_MOC_LITERAL(143, 21), // "receiveHydrationTimer"
QT_MOC_LITERAL(165, 11), // "updateLevel"
QT_MOC_LITERAL(177, 5), // "level"
QT_MOC_LITERAL(183, 24), // "on_answerButton1_clicked"
QT_MOC_LITERAL(208, 24), // "on_answerButton2_clicked"
QT_MOC_LITERAL(233, 24), // "on_answerButton3_clicked"
QT_MOC_LITERAL(258, 22), // "on_resetButton_clicked"
QT_MOC_LITERAL(281, 29), // "on_crashedResetButton_clicked"
QT_MOC_LITERAL(311, 25), // "on_winResetButton_clicked"
QT_MOC_LITERAL(337, 24) // "on_winQuitButton_clicked"

    },
    "MainWindow\0on_startButton_clicked\0\0"
    "on_restartButton_clicked\0"
    "on_resumeButton_clicked\0addWaterToBar\0"
    "resetHydrationBar\0keyPressEvent\0"
    "QKeyEvent*\0k\0receiveHydrationTimer\0"
    "updateLevel\0level\0on_answerButton1_clicked\0"
    "on_answerButton2_clicked\0"
    "on_answerButton3_clicked\0"
    "on_resetButton_clicked\0"
    "on_crashedResetButton_clicked\0"
    "on_winResetButton_clicked\0"
    "on_winQuitButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  104,    2, 0x08,    1 /* Private */,
       3,    0,  105,    2, 0x08,    2 /* Private */,
       4,    0,  106,    2, 0x08,    3 /* Private */,
       5,    0,  107,    2, 0x08,    4 /* Private */,
       6,    0,  108,    2, 0x08,    5 /* Private */,
       7,    1,  109,    2, 0x08,    6 /* Private */,
      10,    0,  112,    2, 0x08,    8 /* Private */,
      11,    1,  113,    2, 0x08,    9 /* Private */,
      13,    0,  116,    2, 0x08,   11 /* Private */,
      14,    0,  117,    2, 0x08,   12 /* Private */,
      15,    0,  118,    2, 0x08,   13 /* Private */,
      16,    0,  119,    2, 0x08,   14 /* Private */,
      17,    0,  120,    2, 0x08,   15 /* Private */,
      18,    0,  121,    2, 0x08,   16 /* Private */,
      19,    0,  122,    2, 0x08,   17 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
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
        case 0: _t->on_startButton_clicked(); break;
        case 1: _t->on_restartButton_clicked(); break;
        case 2: _t->on_resumeButton_clicked(); break;
        case 3: _t->addWaterToBar(); break;
        case 4: _t->resetHydrationBar(); break;
        case 5: _t->keyPressEvent((*reinterpret_cast< std::add_pointer_t<QKeyEvent*>>(_a[1]))); break;
        case 6: _t->receiveHydrationTimer(); break;
        case 7: _t->updateLevel((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_answerButton1_clicked(); break;
        case 9: _t->on_answerButton2_clicked(); break;
        case 10: _t->on_answerButton3_clicked(); break;
        case 11: _t->on_resetButton_clicked(); break;
        case 12: _t->on_crashedResetButton_clicked(); break;
        case 13: _t->on_winResetButton_clicked(); break;
        case 14: _t->on_winQuitButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QKeyEvent *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
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
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
