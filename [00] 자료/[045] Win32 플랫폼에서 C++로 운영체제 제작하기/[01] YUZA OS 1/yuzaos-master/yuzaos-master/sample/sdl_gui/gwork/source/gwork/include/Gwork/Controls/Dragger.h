/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_DRAGGER_H
#define GWK_CONTROLS_DRAGGER_H

#include <Gwork/Controls/Base.h>
#include <Gwork/Gwork.h>
#include <Gwork/Skin.h>


namespace Gwk
{
    namespace ControlsInternal
    {
        class GWK_EXPORT Dragger : public Controls::Base
        {
        public:

            GWK_CONTROL(Dragger, Controls::Base);

            void OnMouseMoved(int x, int y, int deltaX, int deltaY) override;

            void OnMouseClickLeft(int x, int y, bool bDown) override;
            void Render(Skin::Base* skin) override;

            virtual void SetTarget(Controls::Base* base)
            {
                m_target = base;
            }

            virtual bool IsDepressed() const
            {
                return m_bDepressed;
            }

            virtual void SetDoMove(bool b)
            {
                m_bDoMove = b;
            }

            void OnMouseDoubleClickLeft(int x, int y) override;

            Gwk::Event::Caller onDragged;
            Gwk::Event::Caller onDragStart;

            Gwk::Event::Caller onDoubleClickLeft;

        protected:

            bool                m_bDepressed;
            Gwk::Point          m_holdPos;
            Controls::Base*     m_target;
            bool                m_bDoMove;
        };


    }
}
#endif // ifndef GWK_CONTROLS_DRAGGER_H
