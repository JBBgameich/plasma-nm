/*
    Copyright 2013-2014 Jan Grulich <jgrulich@redhat.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) version 3, or any
    later version accepted by the membership of KDE e.V. (or its
    successor approved by the membership of KDE e.V.), which shall
    act as a proxy defined in Section 6 of version 3 of the license.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef PLASMA_NM_MODEL_NETWORK_MODEL_ITEM_H
#define PLASMA_NM_MODEL_NETWORK_MODEL_ITEM_H

#include <NetworkManagerQt/ActiveConnection>
#include <NetworkManagerQt/Connection>
#include <NetworkManagerQt/ConnectionSettings>
#include <NetworkManagerQt/Device>
#include <NetworkManagerQt/Utils>

#include "networkmodel.h"

class NetworkModelItem : public QObject
{
Q_OBJECT
public:
    explicit NetworkModelItem(QObject * parent = 0);
    virtual ~NetworkModelItem();

    QString activeConnectionPath() const;
    void setActiveConnectionPath(const QString& path);

    bool available() const;

    QString connectionPath() const;
    void setConnectionPath(const QString& path);

    NetworkManager::ActiveConnection::State connectionState() const;
    void setConnectionState(NetworkManager::ActiveConnection::State state);

    QString details() const;

    QString devicePath() const;
    void setDeviceName(const QString& name);
    void setDevicePath(const QString& path);

    QString icon() const;

    QString lastUsed() const;
    void setLastUsed(const QDateTime& lastUsed);

    QString name() const;
    void setName(const QString& name);

    QString originalName() const;

    QString sectionType() const;

    int signal() const;
    void setSignal(int signal);

    void setShared(bool shared);

    QString specificPath() const;
    void setSpecificPath(const QString& path);

    QString speed() const;
    void setSpeed(int speed);

    QString ssid() const;
    void setSsid(const QString& ssid);

    NetworkManager::ConnectionSettings::ConnectionType type() const;
    void setType(NetworkManager::ConnectionSettings::ConnectionType type);

    NetworkManager::Utils::WirelessSecurityType securityType() const;
    void setSecurityType(NetworkManager::Utils::WirelessSecurityType type);

    QString uni() const;

    QString uuid() const;
    void setUuid(const QString& uuid);

    bool operator==(const NetworkModelItem * item) const;

public Q_SLOTS:
    void updateDetails();

private:
    QString m_activeConnectionPath;
    int m_bitrate;
    QString m_connectionPath;
    NetworkManager::ActiveConnection::State m_connectionState;
    QString m_devicePath;
    QString m_deviceName;
    QString m_details;
    QDateTime m_lastUsed;
    QString m_name;
    QString m_nsp;
    NetworkManager::Utils::WirelessSecurityType m_securityType;
    int m_signal;
    bool m_shared;
    QString m_specificPath;
    QString m_ssid;
    NetworkManager::ConnectionSettings::ConnectionType m_type;
    QString m_uuid;
};

#endif // PLASMA_NM_MODEL_NETWORK_MODEL_ITEM_H