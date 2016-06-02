/** *************************************************************************
                          polynode.h  -  K Desktop Planetarium
                             -------------------
    begin                : 28/05/2016
    copyright            : (C) 2016 by Artem Fedoskin
    email                : afedoskin3@gmail.com
 ***************************************************************************/
/** *************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef POLYNODE_H_
#define POLYNODE_H_
#include <QSGOpacityNode>
#include <QSGGeometry>
#include <QSGFlatColorMaterial>

/** @class PolyNode
 *
 * A QSGOpacityNode derived class used for representing stars and planets as stars. Upon
 * construction loads the texture of star cached in parentNode
 *
 *@short QSGOpacityNode derived class that represents stars and planets using cached QSGTexture
 *@author Artem Fedoskin
 *@version 1.0
 */

class RootNode;
class QSGGeometryNode;
class QSGGeometry;

class PolyNode : public QSGOpacityNode  {
public:
    PolyNode();

    void setColor(QColor color);
    inline void setLineWidth(int width) { m_geometry->setLineWidth(width); }

    void updateGeometry(QPolygonF polygon, bool filled);

    inline QColor getColor() { return m_material->color(); }

    void show();
    void hide();
private:
    QSGGeometryNode *m_geometryNode;
    QSGGeometry *m_geometry;
    QSGFlatColorMaterial *m_material;
};

#endif

