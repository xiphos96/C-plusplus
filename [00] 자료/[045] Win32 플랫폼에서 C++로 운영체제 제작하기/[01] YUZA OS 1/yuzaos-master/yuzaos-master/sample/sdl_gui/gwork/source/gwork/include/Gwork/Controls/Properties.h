/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_PROPERTIES_H
#define GWK_CONTROLS_PROPERTIES_H

#include <Gwork/Controls/Base.h>
#include <Gwork/Controls/Label.h>
#include <Gwork/Controls/Property/BaseProperty.h>
#include <Gwork/Controls/Property/Text.h>
#include <Gwork/Controls/SplitterBar.h>
#include <Gwork/Gwork.h>
#include <Gwork/Skin.h>


namespace Gwk
{
    namespace Controls
    {
        class PropertyRow;

        class GWK_EXPORT Properties : public Base
        {
        public:

            GWK_CONTROL(Properties, Base);

            void PostLayout(Gwk::Skin::Base* skin) override;

            PropertyRow* Add(const String& text, const String& value = "");
            PropertyRow* Add(const String& text, Property::Base* prop,
                             const String& value = "");
            PropertyRow* Find(const String& text);

            virtual int GetSplitWidth();

            virtual void Clear();

        protected:

            virtual void OnSplitterMoved(Controls::Base* control);

            Controls::SplitterBar*  m_splitterBar;

        };


        class GWK_EXPORT PropertyRow : public Base
        {
        public:

            GWK_CONTROL(PropertyRow, Base);

            virtual Label* GetLabel()
            {
                return m_label;
            }

            virtual void            SetProperty(Property::Base* prop);
            virtual Property::Base* GetProperty()
            {
                return m_property;
            }

            void Layout(Gwk::Skin::Base* skin) override;
            void Render(Gwk::Skin::Base* skin) override;

            virtual bool IsEditing()
            {
                return m_property && m_property->IsEditing();
            }

            bool IsHovered() const override
            {
                return ParentClass::IsHovered() || (m_property && m_property->IsHovered());
            }

            virtual void OnEditingChanged();
            virtual void OnHoverChanged();

            Event::Caller onChange;

        protected:

            void OnPropertyValueChanged(Gwk::Controls::Base* control);

            Label*          m_label;
            Property::Base* m_property;

            bool m_bLastEditing;
            bool m_bLastHover;

        };


    }
}
#endif // ifndef GWK_CONTROLS_PROPERTIES_H
