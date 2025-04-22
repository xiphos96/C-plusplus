/*
 *  Gwork
 *  Copyright (c) 2012 Facepunch Studios
 *  Copyright (c) 2013-2018 Billy Quith
 *  See license in Gwork.h
 */

#pragma once
#ifndef GWK_CONTROLS_PAGECONTROL_H
#define GWK_CONTROLS_PAGECONTROL_H

#include <Gwork/Controls/Base.h>
#include <Gwork/Controls/Button.h>

namespace Gwk
{
    namespace Controls
    {
        class GWK_EXPORT PageControl : public Base
        {
            static const unsigned int MaxPages = 64;

            GWK_CONTROL(PageControl, Base);

            virtual void         SetPageCount(unsigned int i);
            virtual unsigned int GetPageCount()
            {
                return m_pageCount;
            }

            virtual void         ShowPage(unsigned int i);
            virtual unsigned int GetPageNumber()
            {
                return m_currentPage;
            }

            virtual Controls::Base* GetPage(unsigned int i);
            virtual Controls::Base* GetCurrentPage();

            virtual void NextPage();
            virtual void PreviousPage();
            virtual void Finish();

            Controls::Button* NextButton()
            {
                return m_next;
            }

            Controls::Button* BackButton()
            {
                return m_back;
            }

            Controls::Button* FinishButton()
            {
                return m_finish;
            }

            Controls::Label* Label()
            {
                return m_label;
            }

            void SetUseFinishButton(bool b)
            {
                m_bFinish = b;
            }

            bool GetUseFinishButton()
            {
                return m_bFinish;
            }

            Event::Caller onPageChanged;
            Event::Caller onFinish;

        protected:

            virtual void HideAll();

            unsigned int m_currentPage;
            unsigned int m_pageCount;
            Controls::Base*         m_pages[MaxPages];

            Controls::Button*       m_next;
            Controls::Button*       m_back;
            Controls::Button*       m_finish;
            Controls::Label*        m_label;

            bool m_bFinish;

        };


    }
}
#endif // ifndef GWK_CONTROLS_PAGECONTROL_H
