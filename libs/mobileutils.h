#ifndef MOBILEUTILS_H
#define MOBILEUTILS_H

#include <QDBusInterface>

#include <NetworkManagerQt/Connection>
#include <NetworkManagerQt/Settings>
#include <NetworkManagerQt/ConnectionSettings>
#if WITH_MODEMMANAGER_SUPPORT
#include <ModemManagerQt/GenericTypes>
#endif


class Q_DECL_EXPORT MobileUtils : public QObject
{
    Q_OBJECT
public:
    explicit MobileUtils(QObject *parent = nullptr);

public Q_SLOTS:
    QVariantMap getConnectionSettings(const QString &connection, const QString &type);
    QVariantMap getActiveConnectionInfo(const QString &connection);
    void addConnectionFromQML(const QVariantMap &QMLmap);
    void updateConnectionFromQML(const QString &path, const QVariantMap &map);
};

#endif // MOBILEUTILS_H