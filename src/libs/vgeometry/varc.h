/************************************************************************
 **
 **  @file   varc.h
 **  @author Roman Telezhynskyi <dismine(at)gmail.com>
 **  @date   November 15, 2013
 **
 **  @brief
 **  @copyright
 **  This source code is part of the Valentine project, a pattern making
 **  program, whose allow create and modeling patterns of clothing.
 **  Copyright (C) 2013-2015 Valentina project
 **  <https://bitbucket.org/dismine/valentina> All Rights Reserved.
 **
 **  Valentina is free software: you can redistribute it and/or modify
 **  it under the terms of the GNU General Public License as published by
 **  the Free Software Foundation, either version 3 of the License, or
 **  (at your option) any later version.
 **
 **  Valentina is distributed in the hope that it will be useful,
 **  but WITHOUT ANY WARRANTY; without even the implied warranty of
 **  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 **  GNU General Public License for more details.
 **
 **  You should have received a copy of the GNU General Public License
 **  along with Valentina.  If not, see <http://www.gnu.org/licenses/>.
 **
 *************************************************************************/

#ifndef VARC_H
#define VARC_H

#include "vabstractcurve.h"
#include "vpointf.h"
#include <QCoreApplication>

class QPainterPath;
class VArcData;

/**
 * @brief VArc class for anticlockwise arc.
 */
class VArc: public VAbstractCurve
{
    Q_DECLARE_TR_FUNCTIONS(VArc)
public:
    VArc ();
    VArc (const VPointF &center, qreal radius, const QString &formulaRadius, qreal f1, const QString &formulaF1,
          qreal f2, const QString &formulaF2, quint32 idObject = 0, Draw mode = Draw::Calculation);
    VArc (const VPointF &center, qreal radius, qreal f1, qreal f2);
    VArc (qreal length, const QString &formulaLength, const VPointF &center, qreal radius, const QString &formulaRadius,
          qreal f1, const QString &formulaF1,  quint32 idObject = 0, Draw mode = Draw::Calculation);
    VArc (qreal length, const VPointF &center, qreal radius, qreal f1);
    VArc(const VArc &arc);
    VArc& operator= (const VArc &arc);
    virtual ~VArc() Q_DECL_OVERRIDE;

    QString            GetFormulaF1 () const;
    void               SetFormulaF1 (const QString &formula, qreal value);
    virtual qreal      GetStartAngle () const Q_DECL_OVERRIDE;

    QString            GetFormulaF2 () const;
    void               SetFormulaF2 (const QString &formula, qreal value);
    virtual qreal      GetEndAngle () const Q_DECL_OVERRIDE;

    QString            GetFormulaRadius () const;
    void               SetFormulaRadius (const QString &formula, qreal value);
    qreal              GetRadius () const;

    VPointF            GetCenter () const;
    void               SetCenter (const VPointF &value);

    QString            GetFormulaLength () const;
    void               SetFormulaLength (const QString &formula, qreal value);
    qreal              GetLength () const;

    QPointF            GetP1() const;
    QPointF            GetP2 () const;
    qreal              AngleArc() const;
    QVector<QPointF>   GetPoints () const;
    QPointF            CutArc (const qreal &length, VArc &arc1, VArc &arc2) const;
    QPointF            CutArc (const qreal &length) const;
    virtual void       setId(const quint32 &id) Q_DECL_OVERRIDE;
private:
    QSharedDataPointer<VArcData> d;

    void ArcName();
    void FindF2(qreal length);

    qreal MaxLength() const;
};

Q_DECLARE_TYPEINFO(VArc, Q_MOVABLE_TYPE);

#endif // VARC_H