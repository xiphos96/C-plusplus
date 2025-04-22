/*
 *  Gwork
 *  Copyright (c) 2010 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_COLLAPSIBLELIST_H
#define GWK_CONTROLS_COLLAPSIBLELIST_H

#include <Gwork/Controls/Base.h>
#include <Gwork/Controls/Button.h>
#include <Gwork/Controls/ScrollControl.h>
#include <Gwork/Gwork.h>
#include <Gwork/Skin.h>
#include <Gwork/Controls/CollapsibleCategory.h>


namespace Gwk
{
    namespace Controls
    {
        class GWK_EXPORT CollapsibleList : public Gwk::Controls::ScrollControl
        {
        public:

            Gwk::Event::Caller onSelection;

        public:

            GWK_CONTROL_INLINE(CollapsibleList, Gwk::Controls::ScrollControl)
            {
                SetScroll(false, true);
                SetAutoHideBars(true);
            }

            virtual void Add(Gwk::Controls::CollapsibleCategory* category)
            {
                category->SetParent(this);
                category->Dock(Position::Top);
                category->SetMargin(Margin(1, 0, 1, 1));
                category->SetList(this);
                category->onSelection.Add(this, &ThisClass::OnSelectionEvent);
            }

            virtual Gwk::Controls::CollapsibleCategory* Add(const String& name)
            {
                Gwk::Controls::CollapsibleCategory* category = new CollapsibleCategory(this);
                category->SetText(name);
                Add(category);
                return category;
            }

            void Render(Skin::Base* skin) override
            {
                skin->DrawCategoryHolder(this);
            }

            virtual void UnselectAll()
            {
                Base::List& children = GetChildren();

                for (auto&& control : children)
                {
                    Gwk::Controls::CollapsibleCategory* child =
                        gwk_cast<Gwk::Controls::CollapsibleCategory>(control);

                    if (!child)
                        continue;

                    child->UnselectAll();
                }
            }

            virtual Gwk::Controls::Button* GetSelected()
            {
                Base::List& children = GetChildren();

                for (auto&& control : children)
                {
                    Gwk::Controls::CollapsibleCategory* child =
                        gwk_cast<Gwk::Controls::CollapsibleCategory>(control);

                    if (!child)
                        continue;

                    Gwk::Controls::Button* selected = child->GetSelected();

                    if (selected)
                        return selected;
                }

                return nullptr;
            }

        protected:

            virtual void OnSelection(Gwk::Controls::CollapsibleCategory* control,
                                     Gwk::Controls::Button* selected)
            {
                onSelection.Call(this);
            }

            void OnSelectionEvent(Controls::Base* control)
            {
                Gwk::Controls::CollapsibleCategory* child =
                    gwk_cast<Gwk::Controls::CollapsibleCategory>(control);

                if (!child)
                    return;

                OnSelection(child, child->GetSelected());
            }

        };


    }
}
#endif // ifndef GWK_CONTROLS_COLLAPSIBLELIST_H
