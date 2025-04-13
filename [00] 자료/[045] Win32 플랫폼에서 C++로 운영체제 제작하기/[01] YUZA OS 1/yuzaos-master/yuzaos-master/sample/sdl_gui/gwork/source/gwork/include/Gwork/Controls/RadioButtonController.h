/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_RADIOBOTTONCONTROLLER_H
#define GWK_CONTROLS_RADIOBOTTONCONTROLLER_H

#include <Gwork/Controls/Base.h>
#include <Gwork/Controls/Label.h>
#include <Gwork/Controls/RadioButton.h>


namespace Gwk
{
    namespace Controls
    {
        class GWK_EXPORT RadioButtonController : public Base
        {
        public:

            GWK_CONTROL(RadioButtonController, Base);

            void Render(Skin::Base* /*skin*/) override
            {
            }

            virtual void OnRadioClicked(Base* fromPanel);

            virtual void OnChange();

            virtual LabeledRadioButton* AddOption(const Gwk::String& strText,
                                                  const Gwk::String& strOptionName = "");

            virtual LabeledRadioButton* GetSelected()
            {
                return m_selected;
            }

            virtual const Gwk::String& GetSelectedName()
            {
                return m_selected->GetName();
            }

            virtual const String& GetSelectedLabel()
            {
                return m_selected->GetLabel()->GetText();
            }

            Event::Caller onSelectionChange;

        private:

            LabeledRadioButton* m_selected;
        };


    }
}
#endif // ifndef GWK_CONTROLS_RADIOBOTTONCONTROLLER_H
