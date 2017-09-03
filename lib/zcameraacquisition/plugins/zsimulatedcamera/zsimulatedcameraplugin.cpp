//
// Z3D - A structured light 3D scanner
// Copyright (C) 2013-2016 Nicolas Ulrich <nikolaseu@gmail.com>
//
// This file is part of Z3D.
//
// Z3D is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Z3D is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Z3D.  If not, see <http://www.gnu.org/licenses/>.
//

#include "zsimulatedcameraplugin.h"

#include "zsimulatedcamera.h"

namespace Z3D
{

ZSimulatedCameraPlugin::ZSimulatedCameraPlugin()
{
}

QString ZSimulatedCameraPlugin::id() const
{
    return QString("ZSIMULATED");
}

QString ZSimulatedCameraPlugin::name() const
{
    return QString("Simulated camera");
}

QString ZSimulatedCameraPlugin::version() const
{
    return QString(Z3D_VERSION_STR);
}

QList<ZCameraInfo*> ZSimulatedCameraPlugin::getConnectedCameras()
{
    QList<ZCameraInfo*> list;
    list << new ZCameraInfo(this, "NEW", QVariantMap());
    return list;
}

ZCameraInterface::Ptr ZSimulatedCameraPlugin::getCamera(QVariantMap options)
{
    return ZCameraInterface::Ptr( new Z3D::ZSimulatedCamera(options) );
}

} // namespace Z3D

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(zsimulatedcamera, Z3D::SimulatedCameraPlugin)
#endif
