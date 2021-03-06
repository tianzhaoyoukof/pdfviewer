/*
 * Copyright (C) 2008, Pino Toscano <pino@kde.org>
 * Copyright (C) 2012, Glad Deschrijver <glad.deschrijver@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "abstractinfodock.h"
#include "documentobserver.h"

AbstractInfoDock::AbstractInfoDock(QWidget *parent)
    : QDockWidget(parent), m_filled(false)
{
    connect(this, SIGNAL(visibilityChanged(bool)), SLOT(slotVisibilityChanged(bool)));
}

AbstractInfoDock::~AbstractInfoDock()
{
}

void AbstractInfoDock::documentLoaded()
{
    if (!isHidden()) {
        fillInfo();
        m_filled = true;
    }
}

void AbstractInfoDock::documentClosed()
{
    m_filled = false;
}

void AbstractInfoDock::pageChanged(double page, PdfView::PositionHandling keepPosition)
{
    Q_UNUSED(page)
    Q_UNUSED(keepPosition)
}

void AbstractInfoDock::slotVisibilityChanged(bool visible)
{
    if (visible && document() && !m_filled) {
        fillInfo();
        m_filled = true;
    }
}
