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

#include "zbinarypatternprojectionplugin.h"
#include "zbinarypatternprojection.h"
#include "zbinarypatternprojectionconfigwidget.h"

namespace Z3D
{

ZBinaryPatternProjectionPlugin::ZBinaryPatternProjectionPlugin()
{

}

QString ZBinaryPatternProjectionPlugin::id() const
{
    return "ZBinaryPatternProjectionPlugin";
}

QString ZBinaryPatternProjectionPlugin::name() const
{
    return "Binary";
}

QString ZBinaryPatternProjectionPlugin::version() const
{
    return Z3D_VERSION_STR;
}

QList<ZPatternProjection *> ZBinaryPatternProjectionPlugin::getAll()
{
    return QList<ZPatternProjection *>() << new ZBinaryPatternProjection();
}

QWidget *ZBinaryPatternProjectionPlugin::getConfigWidget(ZPatternProjection *patternProjection)
{
    if (auto *binaryPatternProjection = qobject_cast<ZBinaryPatternProjection*>(patternProjection)) {
        /// TODO this assumes there's always only one pattern projection for each type
        static QWidget *widget = nullptr;
        if (!widget) {
            widget = new ZBinaryPatternProjectionConfigWidget(binaryPatternProjection);
        }

        return widget;
    }

    return nullptr;
}

} // namespace Z3D
