#include <QtQml/qqmlprivate.h>
#include <QtCore/qdir.h>
#include <QtCore/qurl.h>

static const unsigned char qt_resource_tree[] = {
0,
0,0,0,0,2,0,0,0,5,0,0,0,1,0,0,0,
194,0,0,0,0,0,1,0,0,0,0,0,0,0,8,0,
0,0,0,0,1,0,0,0,0,0,0,0,114,0,0,0,
0,0,1,0,0,0,0,0,0,0,58,0,0,0,0,0,
1,0,0,0,0,0,0,0,158,0,0,0,0,0,1,0,
0,0,0};
static const unsigned char qt_resource_names[] = {
0,
1,0,0,0,47,0,47,0,22,5,38,52,188,0,84,0,
111,0,103,0,103,0,108,0,101,0,66,0,117,0,116,0,
116,0,111,0,110,0,87,0,105,0,110,0,100,0,111,0,
119,0,46,0,113,0,109,0,108,0,25,8,115,81,124,0,
81,0,109,0,108,0,67,0,97,0,110,0,118,0,97,0,
115,0,87,0,97,0,118,0,101,0,80,0,114,0,111,0,
103,0,114,0,101,0,115,0,115,0,46,0,113,0,109,0,
108,0,19,6,52,188,252,0,81,0,109,0,108,0,84,0,
111,0,103,0,103,0,108,0,101,0,66,0,117,0,116,0,
116,0,111,0,110,0,46,0,113,0,109,0,108,0,15,14,
89,140,60,0,81,0,109,0,108,0,80,0,114,0,111,0,
103,0,114,0,101,0,115,0,115,0,46,0,113,0,109,0,
108,0,22,3,247,180,60,0,67,0,117,0,115,0,116,0,
111,0,109,0,83,0,119,0,105,0,116,0,99,0,104,0,
66,0,117,0,116,0,116,0,111,0,110,0,46,0,113,0,
109,0,108};
static const unsigned char qt_resource_empty_payout[] = { 0, 0, 0, 0, 0 };
QT_BEGIN_NAMESPACE
extern Q_CORE_EXPORT bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);
QT_END_NAMESPACE
namespace QmlCacheGeneratedCode {
namespace _0x5f__CustomSwitchButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QmlProgress_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QmlToggleButton_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__QmlCanvasWaveProgress_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}
namespace _0x5f__ToggleButtonWindow_qml { 
    extern const unsigned char qmlData[];
    const QQmlPrivate::CachedQmlUnit unit = {
        reinterpret_cast<const QV4::CompiledData::Unit*>(&qmlData), nullptr, nullptr
    };
}

}
namespace {
struct Registry {
    Registry();
    QHash<QString, const QQmlPrivate::CachedQmlUnit*> resourcePathToCachedUnit;
    static const QQmlPrivate::CachedQmlUnit *lookupCachedUnit(const QUrl &url);
};

Q_GLOBAL_STATIC(Registry, unitRegistry)


Registry::Registry() {
        resourcePathToCachedUnit.insert(QStringLiteral("/CustomSwitchButton.qml"), &QmlCacheGeneratedCode::_0x5f__CustomSwitchButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QmlProgress.qml"), &QmlCacheGeneratedCode::_0x5f__QmlProgress_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QmlToggleButton.qml"), &QmlCacheGeneratedCode::_0x5f__QmlToggleButton_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/QmlCanvasWaveProgress.qml"), &QmlCacheGeneratedCode::_0x5f__QmlCanvasWaveProgress_qml::unit);
        resourcePathToCachedUnit.insert(QStringLiteral("/ToggleButtonWindow.qml"), &QmlCacheGeneratedCode::_0x5f__ToggleButtonWindow_qml::unit);
    QQmlPrivate::RegisterQmlUnitCacheHook registration;
    registration.version = 0;
    registration.lookupCachedQmlUnit = &lookupCachedUnit;
    QQmlPrivate::qmlregister(QQmlPrivate::QmlUnitCacheHookRegistration, &registration);
QT_PREPEND_NAMESPACE(qRegisterResourceData)(/*version*/0x01, qt_resource_tree, qt_resource_names, qt_resource_empty_payout);
}
const QQmlPrivate::CachedQmlUnit *Registry::lookupCachedUnit(const QUrl &url) {
    if (url.scheme() != QLatin1String("qrc"))
        return nullptr;
    QString resourcePath = QDir::cleanPath(url.path());
    if (resourcePath.isEmpty())
        return nullptr;
    if (!resourcePath.startsWith(QLatin1Char('/')))
        resourcePath.prepend(QLatin1Char('/'));
    return unitRegistry()->resourcePathToCachedUnit.value(resourcePath, nullptr);
}
}
int QT_MANGLE_NAMESPACE(qInitResources_qml)() {
    ::unitRegistry();
    return 1;
}
Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_qml))
int QT_MANGLE_NAMESPACE(qCleanupResources_qml)() {
    return 1;
}
