/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_BUTTON_H
#define GWK_CONTROLS_BUTTON_H

#include <Gwork/Controls/Base.h>
#include <Gwork/Controls/Label.h>

namespace Gwk
{
    namespace Controls
    {
        class ImagePanel;

        class GWK_EXPORT Button : public Label
        {
        public:

            GWK_CONTROL(Button, Label);

            void Render(Skin::Base* skin) override;
            void OnMouseClickLeft(int x, int y, bool bDown) override;
            void OnMouseClickRight(int x, int y, bool bDown) override;
            void OnMouseDoubleClickLeft(int x, int y) override;
            bool OnKeySpace(bool bDown) override;

            virtual void OnPress();
            virtual void OnRightPress();

            void AcceleratePressed() override;

            //! Is the button currently being pressed?
            virtual bool IsDepressed() const
            {
                return m_bDepressed;
            }

            virtual void SetDepressed(bool b);

            //
            /// Buttons can be toggle type, which means that it is
            /// toggled on and off. Its toggle status is in IsDepressed.
            //
            virtual void SetIsToggle(bool b)
            {
                m_bToggle = b;
            }

            virtual bool IsToggle() const
            {
                return m_bToggle;
            }

            virtual bool GetToggleState() const
            {
                return m_bToggleStatus;
            }

            virtual void SetToggleState(bool b);
            virtual void Toggle()
            {
                SetToggleState(!GetToggleState());
            }

            virtual void SetImage(const String& strName, bool bCenter = false);

            void SizeToContents() override;
            void PostLayout(Skin::Base* skin) override;
            void UpdateColors() override;

            virtual void SetImageAlpha(float fMultiply);

            void DoAction() override
            {
                OnPress();
            }

            virtual void SetAction(Event::Handler* object,
                                   Handler::FunctionWithInformation function,
                                   const Gwk::Event::Packet& packet) override;

        public:

            Gwk::Event::Caller onPress;
            Gwk::Event::Caller onRightPress;
            Gwk::Event::Caller onDown;
            Gwk::Event::Caller onUp;
            Gwk::Event::Caller onDoubleClick;
            Gwk::Event::Caller onToggle;
            Gwk::Event::Caller onToggleOn;
            Gwk::Event::Caller onToggleOff;

        protected:

            ImagePanel*     m_image;    ///< Optional image to be displayed on button.

            bool m_bDepressed;          ///< Is button currently being pressed?
            bool m_bToggle;             ///< Is this a toggling button, i.e. on or off.
            bool m_bToggleStatus;

            bool m_bCenterImage;        ///< Centre the image in the button?
        };


    }
}
#endif // ifndef GWK_CONTROLS_BUTTON_H
