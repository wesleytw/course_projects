/****************************************************************************
** Meta object code from reading C++ file 'main_window.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "main_window.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "open",
    "",
    "quit",
    "createRectangle",
    "createBoundary",
    "createPath",
    "zoomIn",
    "zoomOut",
    "zoomFit",
    "panUp",
    "panDown",
    "panLeft",
    "panRight",
    "clear",
    "deleteObject",
    "query"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[34];
    char stringdata0[11];
    char stringdata1[5];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[16];
    char stringdata5[15];
    char stringdata6[11];
    char stringdata7[7];
    char stringdata8[8];
    char stringdata9[8];
    char stringdata10[6];
    char stringdata11[8];
    char stringdata12[8];
    char stringdata13[9];
    char stringdata14[6];
    char stringdata15[13];
    char stringdata16[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 4),  // "open"
        QT_MOC_LITERAL(16, 0),  // ""
        QT_MOC_LITERAL(17, 4),  // "quit"
        QT_MOC_LITERAL(22, 15),  // "createRectangle"
        QT_MOC_LITERAL(38, 14),  // "createBoundary"
        QT_MOC_LITERAL(53, 10),  // "createPath"
        QT_MOC_LITERAL(64, 6),  // "zoomIn"
        QT_MOC_LITERAL(71, 7),  // "zoomOut"
        QT_MOC_LITERAL(79, 7),  // "zoomFit"
        QT_MOC_LITERAL(87, 5),  // "panUp"
        QT_MOC_LITERAL(93, 7),  // "panDown"
        QT_MOC_LITERAL(101, 7),  // "panLeft"
        QT_MOC_LITERAL(109, 8),  // "panRight"
        QT_MOC_LITERAL(118, 5),  // "clear"
        QT_MOC_LITERAL(124, 12),  // "deleteObject"
        QT_MOC_LITERAL(137, 5)   // "query"
    },
    "MainWindow",
    "open",
    "",
    "quit",
    "createRectangle",
    "createBoundary",
    "createPath",
    "zoomIn",
    "zoomOut",
    "zoomFit",
    "panUp",
    "panDown",
    "panLeft",
    "panRight",
    "clear",
    "deleteObject",
    "query"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
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
       7,    0,  109,    2, 0x08,    6 /* Private */,
       8,    0,  110,    2, 0x08,    7 /* Private */,
       9,    0,  111,    2, 0x08,    8 /* Private */,
      10,    0,  112,    2, 0x08,    9 /* Private */,
      11,    0,  113,    2, 0x08,   10 /* Private */,
      12,    0,  114,    2, 0x08,   11 /* Private */,
      13,    0,  115,    2, 0x08,   12 /* Private */,
      14,    0,  116,    2, 0x08,   13 /* Private */,
      15,    0,  117,    2, 0x08,   14 /* Private */,
      16,    0,  118,    2, 0x08,   15 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'open'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'quit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createRectangle'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createBoundary'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createPath'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomIn'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomOut'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'zoomFit'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'panUp'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'panDown'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'panLeft'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'panRight'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'clear'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'deleteObject'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'query'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->open(); break;
        case 1: _t->quit(); break;
        case 2: _t->createRectangle(); break;
        case 3: _t->createBoundary(); break;
        case 4: _t->createPath(); break;
        case 5: _t->zoomIn(); break;
        case 6: _t->zoomOut(); break;
        case 7: _t->zoomFit(); break;
        case 8: _t->panUp(); break;
        case 9: _t->panDown(); break;
        case 10: _t->panLeft(); break;
        case 11: _t->panRight(); break;
        case 12: _t->clear(); break;
        case 13: _t->deleteObject(); break;
        case 14: _t->query(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
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
